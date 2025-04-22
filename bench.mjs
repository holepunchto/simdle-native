import { test } from 'brittle'
import { cnt, clz } from './index.js'
import {
  cnt as jscnt,
  clz as jsclz
} from 'simdle-universal/fallback.js'

test('cnt-16', t => {
  let nativeOps, jsOps
  const N = 2e7

  const result = new Uint16Array(8)
  const input = Uint16Array.of(
    0b0000000000000000, 0b0000000000000001,
    0b0000000000000011, 0b0000000000000111,
    0b0000000000001111, 0b0000000000011111,
    0b0000000000111111, 0b0000000001111111
  )

  t.test('native', t => {
    const measure = benchmark(t.comment)

    for (let i = 0; i < N; i++) {
      cnt(input, result)
      measure(1)
    }
    nativeOps = measure(-1)
  })

  t.test('js', t => {
    const measure = benchmark(t.comment)
    for (let i = 0; i < N; i++) {
      jscnt(input, result)
      measure(1)
    }
    jsOps = measure(-1)
  })

  t.test('comparison', t => {
    const r = (nativeOps / jsOps) - 1
    t.comment(`native ${nativeOps.toExponential(2)} vs. js ${jsOps.toExponential(2)}; ${(r * 100).toFixed(2)}%`)
  })
})

test('clz-32', t => {
  let nativeOps, jsOps
  const N = 1e6

  const width = 256
  const result = new Uint32Array(width)
  const input = Uint32Array.of(
    ...Array.from(new Array(width)).map((_, i) => 1 * (2 ** (i % 32)))
  )

  t.test('native', t => {
    const measure = benchmark(t.comment)

    for (let i = 0; i < N; i++) {
      clz(input, result)
      measure(1)
    }

    nativeOps = measure(-1)
  })

  t.test('js', t => {
    const measure = benchmark(t.comment)

    for (let i = 0; i < N; i++) {
      jsclz(input, result)
      measure(1)
    }

    jsOps = measure(-1)
  })

  t.test('comparison', t => {
    const r = (nativeOps / jsOps) - 1
    t.comment(`native ${nativeOps.toExponential(2)} vs. js ${jsOps.toExponential(2)}; ${(r * 100).toFixed(2)}%`)
  })
})

function benchmark (log = console.log, interval = 2000) {
  let prev
  const start = prev = Date.now()
  let n = 0
  let total = n

  return function measure (qty = 1) {
    const now = Date.now()
    const delta = now - prev

    if (qty > 0) {
      n += qty
      total += qty
    }

    if ((interval && interval < delta) || qty < 0) {
      const ops = (n / delta) * 1000
      const runtime = now - start
      const avg = (total / runtime) * 1000
      log('ops', ops.toExponential(2), 'avg', Math.round(avg), 'total', total, 'runtime', runtime)
      prev = now
      n = 0
      return ops
    }
  }
}
