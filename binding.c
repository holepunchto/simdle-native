#include <napi-macros.h>
#include <node_api.h>
#include <simd.h>

#define SIMD_NAPI_UNARY(fn) \
  NAPI_ARGV(2); \
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0); \
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1); \
\
  for (size_t i = 0, n = buf_len / 16; i < n; i++) { \
    result[i] = fn(buf[i]); \
  } \
\
  return NULL;

#define SIMD_NAPI_BINARY(fn) \
  NAPI_ARGV(3); \
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, a, 0); \
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, b, 1); \
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 2); \
\
  for (size_t i = 0, n = result_len / 16; i < n; i++) { \
    result[i] = fn(a[i], b[i]); \
  } \
\
  return NULL;

#define SIMD_NAPI_REDUCE(fn) \
  NAPI_ARGV(1); \
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0); \
\
  uint64_t result = 0; \
\
  for (size_t i = 0, n = buf_len / 16; i < n; i++) { \
    result += fn(buf[i]); \
  } \
\
  napi_value napi_result; \
  NAPI_STATUS_THROWS(napi_create_bigint_uint64(env, result, &napi_result)) \
  return napi_result;

NAPI_METHOD(simd_napi_and_v128_u8) {
  SIMD_NAPI_BINARY(simd_and_v128_u8);
}

NAPI_METHOD(simd_napi_and_v128_u16) {
  SIMD_NAPI_BINARY(simd_and_v128_u16);
}

NAPI_METHOD(simd_napi_and_v128_u32) {
  SIMD_NAPI_BINARY(simd_and_v128_u32);
}

NAPI_METHOD(simd_napi_clear_v128_u8) {
  SIMD_NAPI_BINARY(simd_clear_v128_u8);
}

NAPI_METHOD(simd_napi_clear_v128_u16) {
  SIMD_NAPI_BINARY(simd_clear_v128_u16);
}

NAPI_METHOD(simd_napi_clear_v128_u32) {
  SIMD_NAPI_BINARY(simd_clear_v128_u32);
}

NAPI_METHOD(simd_napi_clo_v128_u8) {
  SIMD_NAPI_UNARY(simd_clo_v128_u8);
}

NAPI_METHOD(simd_napi_clo_v128_u16) {
  SIMD_NAPI_UNARY(simd_clo_v128_u16);
}

NAPI_METHOD(simd_napi_clo_v128_u32) {
  SIMD_NAPI_UNARY(simd_clo_v128_u32);
}

NAPI_METHOD(simd_napi_clz_v128_u8) {
  SIMD_NAPI_UNARY(simd_clz_v128_u8);
}

NAPI_METHOD(simd_napi_clz_v128_u16) {
  SIMD_NAPI_UNARY(simd_clz_v128_u16);
}

NAPI_METHOD(simd_napi_clz_v128_u32) {
  SIMD_NAPI_UNARY(simd_clz_v128_u32);
}

NAPI_METHOD(simd_napi_cnt_v128_u8) {
  SIMD_NAPI_UNARY(simd_cnt_v128_u8);
}

NAPI_METHOD(simd_napi_cnt_v128_u16) {
  SIMD_NAPI_UNARY(simd_cnt_v128_u16);
}

NAPI_METHOD(simd_napi_cnt_v128_u32) {
  SIMD_NAPI_UNARY(simd_cnt_v128_u32);
}

NAPI_METHOD(simd_napi_cto_v128_u8) {
  SIMD_NAPI_UNARY(simd_cto_v128_u8);
}

NAPI_METHOD(simd_napi_cto_v128_u16) {
  SIMD_NAPI_UNARY(simd_cto_v128_u16);
}

NAPI_METHOD(simd_napi_cto_v128_u32) {
  SIMD_NAPI_UNARY(simd_cto_v128_u32);
}

NAPI_METHOD(simd_napi_ctz_v128_u8) {
  SIMD_NAPI_UNARY(simd_ctz_v128_u8);
}

NAPI_METHOD(simd_napi_ctz_v128_u16) {
  SIMD_NAPI_UNARY(simd_ctz_v128_u16);
}

NAPI_METHOD(simd_napi_ctz_v128_u32) {
  SIMD_NAPI_UNARY(simd_ctz_v128_u32);
}

NAPI_METHOD(simd_napi_not_v128_u8) {
  SIMD_NAPI_UNARY(simd_not_v128_u8);
}

NAPI_METHOD(simd_napi_not_v128_u16) {
  SIMD_NAPI_UNARY(simd_not_v128_u16);
}

NAPI_METHOD(simd_napi_not_v128_u32) {
  SIMD_NAPI_UNARY(simd_not_v128_u32);
}

NAPI_METHOD(simd_napi_or_v128_u8) {
  SIMD_NAPI_BINARY(simd_or_v128_u8);
}

NAPI_METHOD(simd_napi_or_v128_u16) {
  SIMD_NAPI_BINARY(simd_or_v128_u16);
}

NAPI_METHOD(simd_napi_or_v128_u32) {
  SIMD_NAPI_BINARY(simd_or_v128_u32);
}

NAPI_METHOD(simd_napi_sum_v128_u8) {
  SIMD_NAPI_REDUCE(simd_sum_v128_u8);
}

NAPI_METHOD(simd_napi_sum_v128_u16) {
  SIMD_NAPI_REDUCE(simd_sum_v128_u16);
}

NAPI_METHOD(simd_napi_sum_v128_u32) {
  SIMD_NAPI_REDUCE(simd_sum_v128_u32);
}

NAPI_METHOD(simd_napi_xor_v128_u8) {
  SIMD_NAPI_BINARY(simd_xor_v128_u8);
}

NAPI_METHOD(simd_napi_xor_v128_u16) {
  SIMD_NAPI_BINARY(simd_xor_v128_u16);
}

NAPI_METHOD(simd_napi_xor_v128_u32) {
  SIMD_NAPI_BINARY(simd_xor_v128_u32);
}

NAPI_INIT() {
  NAPI_EXPORT_FUNCTION(simd_napi_and_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_and_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_and_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_clear_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_clear_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_clear_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_clo_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_clo_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_clo_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_clz_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_clz_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_clz_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_cnt_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_cnt_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_cnt_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_cto_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_cto_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_cto_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_ctz_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_ctz_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_ctz_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_not_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_not_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_not_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_or_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_or_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_or_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_sum_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_sum_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_sum_v128_u32);

  NAPI_EXPORT_FUNCTION(simd_napi_xor_v128_u8);
  NAPI_EXPORT_FUNCTION(simd_napi_xor_v128_u16);
  NAPI_EXPORT_FUNCTION(simd_napi_xor_v128_u32);
}
