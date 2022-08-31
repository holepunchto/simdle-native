const binding = require('node-gyp-build')(__dirname)
const b4a = require('b4a')

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
