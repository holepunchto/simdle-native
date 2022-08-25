import test from 'brittle'

import { cnt } from './index.js'

test('cnt', async (t) => {
  const ops = 1000000

  const buf = new Uint32Array(2048).fill(0xffffffff)
  const expected = new Uint32Array(2048).fill(32)

  await t.test('simd', async (t) => {
    const result = new Uint32Array(2048)

    const elapsed = await t.execution(() => {
      for (let i = 0; i < ops; i++) {
        cnt(buf, result)
      }
    })

    t.alike(result, expected)

    t.comment(Math.round(ops / elapsed * 1e3) + ' ops/s')
  })

  await t.test('non-simd', async (t) => {
    const cnt = (n) => {
      n = n - ((n >> 1) & 0x55555555)
      n = (n & 0x33333333) + ((n >> 2) & 0x33333333)
      return ((n + (n >> 4) & 0xf0f0f0f) * 0x1010101) >> 24
    }

    const result = new Uint32Array(2048)

    const elapsed = await t.execution(() => {
      for (let i = 0; i < ops; i++) {
        for (let j = 0; j < 2048; j += 4) {
          result[j] = cnt(buf[j])
          result[j + 1] = cnt(buf[j + 1])
          result[j + 2] = cnt(buf[j + 2])
          result[j + 3] = cnt(buf[j + 3])
        }
      }
    })

    t.alike(result, expected)

    t.comment(Math.round(ops / elapsed * 1e3) + ' ops/s')
  })
})
