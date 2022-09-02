const binding = require('node-gyp-build')(__dirname)
const b4a = require('b4a')

function unary (u8, u16, u32) {
  return function unary (buf, result = b4a.allocUnsafe(buf.byteLength)) {
    if (buf.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
    if (buf.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

    const n = buf.BYTES_PER_ELEMENT

    if (n === 1) u8(buf, result)
    else if (n === 2) u16(buf, result)
    else u32(buf, result)

    return result
  }
}

function binary (u8, u16, u32) {
  return function binary (a, b, result = b4a.allocUnsafe(a.byteLength)) {
    if (a.byteLength !== b.byteLength) throw new Error('Buffers must be the same length')
    if (a.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')
    if (a.byteLength > result.byteLength) throw new Error('Length of result buffer is insufficient')

    const n = a.BYTES_PER_ELEMENT

    if (n === 1) u8(a, b, result)
    else if (n === 2) u16(a, b, result)
    else u32(a, b, result)

    return result
  }
}

function reduce (u8, u16, u32) {
  return function reduce (buf) {
    if (buf.byteLength % 16 !== 0) throw new Error('Buffer length must be a multiple of 16')

    const n = buf.BYTES_PER_ELEMENT

    if (n === 1) return u8(buf)
    if (n === 2) return u16(buf)
    return u32(buf)
  }
}

exports.and = binary(
  binding.simd_napi_and_v128_u8,
  binding.simd_napi_and_v128_u16,
  binding.simd_napi_and_v128_u32
)

exports.clear = binary(
  binding.simd_napi_clear_v128_u8,
  binding.simd_napi_clear_v128_u16,
  binding.simd_napi_clear_v128_u32
)

exports.clo = unary(
  binding.simd_napi_clo_v128_u8,
  binding.simd_napi_clo_v128_u16,
  binding.simd_napi_clo_v128_u32
)

exports.clz = unary(
  binding.simd_napi_clz_v128_u8,
  binding.simd_napi_clz_v128_u16,
  binding.simd_napi_clz_v128_u32
)

exports.cnt = unary(
  binding.simd_napi_cnt_v128_u8,
  binding.simd_napi_cnt_v128_u16,
  binding.simd_napi_cnt_v128_u32
)

exports.cto = unary(
  binding.simd_napi_cto_v128_u8,
  binding.simd_napi_cto_v128_u16,
  binding.simd_napi_cto_v128_u32
)

exports.ctz = unary(
  binding.simd_napi_ctz_v128_u8,
  binding.simd_napi_ctz_v128_u16,
  binding.simd_napi_ctz_v128_u32
)

exports.not = unary(
  binding.simd_napi_not_v128_u8,
  binding.simd_napi_not_v128_u16,
  binding.simd_napi_not_v128_u32
)

exports.or = binary(
  binding.simd_napi_or_v128_u8,
  binding.simd_napi_or_v128_u16,
  binding.simd_napi_or_v128_u32
)

exports.sum = reduce(
  binding.simd_napi_sum_v128_u8,
  binding.simd_napi_sum_v128_u16,
  binding.simd_napi_sum_v128_u32
)

exports.xor = binary(
  binding.simd_napi_xor_v128_u8,
  binding.simd_napi_xor_v128_u16,
  binding.simd_napi_xor_v128_u32
)
