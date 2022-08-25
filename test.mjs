import test from 'brittle'

import { cnt } from './index.js'

test('cnt', (t) => {
  t.test('uint8array', (t) => {
    const result = new Uint8Array(16)

    cnt(Uint8Array.of(
      0b00000000, 0b00000001, 0b00000011, 0b00000111,
      0b00001111, 0b00011111, 0b00111111, 0b01111111,
      0b11111111, 0b00000000, 0b00000000, 0b00000000,
      0b00000000, 0b00000000, 0b00000000, 0b00000000
    ), result)

    t.alike(result, Uint8Array.of(0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 0, 0, 0, 0, 0, 0))
  })

  t.test('uint16array', (t) => {
    const result = new Uint16Array(8)

    cnt(Uint16Array.of(
      0b0000000000000000, 0b0000000000000001,
      0b0000000000000011, 0b0000000000000111,
      0b0000000000001111, 0b0000000000011111,
      0b0000000000111111, 0b0000000001111111
    ), result)

    t.alike(result, Uint16Array.of(0, 1, 2, 3, 4, 5, 6, 7))
  })

  t.test('uint32array', (t) => {
    const result = new Uint32Array(4)

    cnt(Uint32Array.of(
      0b00000000000000000000000000000000,
      0b00000000000000000000000000000001,
      0b00000000000000000000000000000011,
      0b00000000000000000000000000000111
    ), result)

    t.alike(result, Uint32Array.of(0, 1, 2, 3))
  })
})
