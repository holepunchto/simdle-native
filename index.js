const binding = require('node-gyp-build')(__dirname)
const b4a = require('b4a')

exports.and = function and (a, b, result = b4a.allocUnsafe(a.byteLength)) {
  if (a.byteLength !== b.byteLength) throw new Error('Buffers must be the same length')
  if (a.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (a.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = a.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_and_v128_u8(a, b, result)
  else if (n === 2) binding.simd_napi_and_v128_u16(a, b, result)
  else binding.simd_napi_and_v128_u32(a, b, result)

  return result
}

exports.clear = function clear (a, b, result = b4a.allocUnsafe(a.byteLength)) {
  if (a.byteLength !== b.byteLength) throw new Error('Buffers must be the same length')
  if (a.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (a.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = a.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_clear_v128_u8(a, b, result)
  else if (n === 2) binding.simd_napi_clear_v128_u16(a, b, result)
  else binding.simd_napi_clear_v128_u32(a, b, result)

  return result
}

exports.clo = function clo (buf, result = b4a.allocUnsafe(buf.byteLength)) {
  if (buf.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (buf.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = buf.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_clo_v128_u8(buf, result)
  else if (n === 2) binding.simd_napi_clo_v128_u16(buf, result)
  else binding.simd_napi_clo_v128_u32(buf, result)

  return result
}

exports.clz = function clz (buf, result = b4a.allocUnsafe(buf.byteLength)) {
  if (buf.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (buf.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = buf.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_clz_v128_u8(buf, result)
  else if (n === 2) binding.simd_napi_clz_v128_u16(buf, result)
  else binding.simd_napi_clz_v128_u32(buf, result)

  return result
}

exports.cnt = function cnt (buf, result = b4a.allocUnsafe(buf.byteLength)) {
  if (buf.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (buf.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = buf.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_cnt_v128_u8(buf, result)
  else if (n === 2) binding.simd_napi_cnt_v128_u16(buf, result)
  else binding.simd_napi_cnt_v128_u32(buf, result)

  return result
}

exports.cto = function cto (buf, result = b4a.allocUnsafe(buf.byteLength)) {
  if (buf.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (buf.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = buf.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_cto_v128_u8(buf, result)
  else if (n === 2) binding.simd_napi_cto_v128_u16(buf, result)
  else binding.simd_napi_cto_v128_u32(buf, result)

  return result
}

exports.ctz = function ctz (buf, result = b4a.allocUnsafe(buf.byteLength)) {
  if (buf.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (buf.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = buf.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_ctz_v128_u8(buf, result)
  else if (n === 2) binding.simd_napi_ctz_v128_u16(buf, result)
  else binding.simd_napi_ctz_v128_u32(buf, result)

  return result
}

exports.not = function not (buf, result = b4a.allocUnsafe(buf.byteLength)) {
  if (buf.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (buf.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = buf.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_not_v128_u8(buf, result)
  else if (n === 2) binding.simd_napi_not_v128_u16(buf, result)
  else binding.simd_napi_not_v128_u32(buf, result)

  return result
}

exports.or = function or (a, b, result = b4a.allocUnsafe(a.byteLength)) {
  if (a.byteLength !== b.byteLength) throw new Error('Buffers must be the same length')
  if (a.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (a.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = a.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_or_v128_u8(a, b, result)
  else if (n === 2) binding.simd_napi_or_v128_u16(a, b, result)
  else binding.simd_napi_or_v128_u32(a, b, result)

  return result
}

exports.sum = function sum (buf) {
  if (buf.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')

  const n = buf.BYTES_PER_ELEMENT

  if (n === 1) return binding.simd_napi_sum_v128_u8(buf)
  if (n === 2) return binding.simd_napi_sum_v128_u16(buf)
  return binding.simd_napi_sum_v128_u32(buf)
}

exports.xor = function xor (a, b, result = b4a.allocUnsafe(a.byteLength)) {
  if (a.byteLength !== b.byteLength) throw new Error('Buffers must be the same length')
  if (a.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
  if (a.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

  const n = a.BYTES_PER_ELEMENT

  if (n === 1) binding.simd_napi_xor_v128_u8(a, b, result)
  else if (n === 2) binding.simd_napi_xor_v128_u16(a, b, result)
  else binding.simd_napi_xor_v128_u32(a, b, result)

  return result
}
