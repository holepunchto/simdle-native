#include <napi-macros.h>
#include <node_api.h>
#include <simd.h>

NAPI_METHOD(simd_napi_clo_v128_u8) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_clo_v128_u8(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_clo_v128_u16) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_clo_v128_u16(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_clo_v128_u32) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_clo_v128_u32(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_clz_v128_u8) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_clz_v128_u8(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_clz_v128_u16) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_clz_v128_u16(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_clz_v128_u32) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_clz_v128_u32(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_cnt_v128_u8) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_cnt_v128_u8(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_cnt_v128_u16) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_cnt_v128_u16(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_cnt_v128_u32) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_cnt_v128_u32(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_cto_v128_u8) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_cto_v128_u8(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_cto_v128_u16) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_cto_v128_u16(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_cto_v128_u32) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_cto_v128_u32(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_ctz_v128_u8) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_ctz_v128_u8(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_ctz_v128_u16) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_ctz_v128_u16(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_ctz_v128_u32) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_ctz_v128_u32(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_not_v128_u8) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_not_v128_u8(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_not_v128_u16) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_not_v128_u16(buf[i]);
  }

  return NULL;
}

NAPI_METHOD(simd_napi_not_v128_u32) {
  NAPI_ARGV(2);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, buf, 0);
  NAPI_ARGV_BUFFER_CAST(simd_v128_t *, result, 1);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    result[i] = simd_not_v128_u32(buf[i]);
  }

  return NULL;
}

NAPI_INIT() {
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
}
