#include <bare.h>
#include <js.h>
#include <jstl.h>
#include <stdint.h>
#include <simdle.h>

template<auto fn, typename W>
struct simdle_op {
  static inline void
  unary (
    js_env_t *env,
    js_receiver_t,
    js_typedarray_t<W> buf,
    js_typedarray_t<W> result
  ) {
    int err;

    simdle_v128_t *buf_data;
    size_t buf_len = 0;

    err = js_get_typedarray_info(env, buf, reinterpret_cast<W *&>(buf_data), buf_len);
    assert(err == 0);

    simdle_v128_t *result_data;
    size_t result_len;

    err = js_get_typedarray_info(env, result, reinterpret_cast<W *&>(result_data), result_len);
    assert(err == 0);

    for (size_t i = 0, n = buf_len * sizeof(W) / 16; i < n; i++) {
      result_data[i] = fn(buf_data[i]);
    }
  }

  static inline void
  binary (
    js_env_t *env,
    js_receiver_t,
    js_typedarray_t<W> a_buf,
    js_typedarray_t<W> b_buf,
    js_typedarray_t<W> result_buf
  ) {
    int err;

    size_t len = 0;

    simdle_v128_t *a;
    err = js_get_typedarray_info(env, a_buf, reinterpret_cast<W *&>(a), len);
    assert(err == 0);

    simdle_v128_t *b;
    err = js_get_typedarray_info(env, b_buf, reinterpret_cast<W *&>(b), len);
    assert(err == 0);

    simdle_v128_t *result;
    err = js_get_typedarray_info(env, result_buf, reinterpret_cast<W *&>(result), len);
    assert(err == 0);

    for (size_t i = 0, n = len * sizeof(W) / 16; i < n; i++) {
      result[i] = fn(a[i], b[i]);
    }
  }

  static inline int64_t
  reduce (
    js_env_t *env,
    js_receiver_t,
    js_typedarray_t<W> buffer
  ) {
    simdle_v128_t *buf;
    size_t buf_len;

    int err = js_get_typedarray_info(env, buffer, reinterpret_cast<W *&>(buf), buf_len);
    assert(err == 0);

    uint64_t result = 0;

    for (size_t i = 0, n = buf_len  * sizeof(W) / 16; i < n; i++) {
      result += fn(buf[i]);
    }

    return result;
  }
};

static inline uint32_t
simdle_napi_allo_v128 (js_env_t *env, js_receiver_t, js_typedarray_t<simdle_v128_t> buffer) {
  simdle_v128_t *buf;
  size_t buf_len;

  int err = js_get_typedarray_info(env, buffer, buf, buf_len);
  assert(err == 0);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    if (!simdle_allo_v128(buf[i])) return 0;
  }

  return 1;
}

static inline uint32_t
simdle_napi_allz_v128 (js_env_t *env, js_receiver_t, js_typedarray_t<simdle_v128_t> buffer) {
  simdle_v128_t *buf;
  size_t buf_len;

  int err = js_get_typedarray_info(env, buffer, buf, buf_len);
  assert(err == 0);

  for (size_t i = 0, n = buf_len / 16; i < n; i++) {
    if (!simdle_allz_v128(buf[i])) return 0;
  }

  return 1;
}

constexpr inline auto simdle_napi_cnt_v128_u8  = simdle_op<simdle_cnt_v128_u8,  uint8_t>::unary;
constexpr inline auto simdle_napi_cnt_v128_u16 = simdle_op<simdle_cnt_v128_u16, uint16_t>::unary;
constexpr inline auto simdle_napi_cnt_v128_u32 = simdle_op<simdle_cnt_v128_u32, uint32_t>::unary;

constexpr inline auto simdle_napi_clo_v128_u8  = simdle_op<simdle_clo_v128_u8,  uint8_t>::unary;
constexpr inline auto simdle_napi_clo_v128_u16 = simdle_op<simdle_clo_v128_u16, uint16_t>::unary;
constexpr inline auto simdle_napi_clo_v128_u32 = simdle_op<simdle_clo_v128_u32, uint32_t>::unary;

constexpr inline auto simdle_napi_clz_v128_u8  = simdle_op<simdle_clz_v128_u8,  uint8_t>::unary;
constexpr inline auto simdle_napi_clz_v128_u16 = simdle_op<simdle_clz_v128_u16, uint16_t>::unary;
constexpr inline auto simdle_napi_clz_v128_u32 = simdle_op<simdle_clz_v128_u32, uint32_t>::unary;

constexpr inline auto simdle_napi_cto_v128_u8  = simdle_op<simdle_cto_v128_u8,  uint8_t>::unary;
constexpr inline auto simdle_napi_cto_v128_u16 = simdle_op<simdle_cto_v128_u16, uint16_t>::unary;
constexpr inline auto simdle_napi_cto_v128_u32 = simdle_op<simdle_cto_v128_u32, uint32_t>::unary;

constexpr inline auto simdle_napi_ctz_v128_u8  = simdle_op<simdle_ctz_v128_u8,  uint8_t>::unary;
constexpr inline auto simdle_napi_ctz_v128_u16 = simdle_op<simdle_ctz_v128_u16, uint16_t>::unary;
constexpr inline auto simdle_napi_ctz_v128_u32 = simdle_op<simdle_ctz_v128_u32, uint32_t>::unary;

constexpr inline auto simdle_napi_not_v128_u8  = simdle_op<simdle_not_v128_u8,  uint8_t>::unary;
constexpr inline auto simdle_napi_not_v128_u16 = simdle_op<simdle_not_v128_u16, uint16_t>::unary;
constexpr inline auto simdle_napi_not_v128_u32 = simdle_op<simdle_not_v128_u32, uint32_t>::unary;

constexpr inline auto simdle_napi_and_v128_u8   = simdle_op<simdle_and_v128_u8,   uint8_t>::binary;
constexpr inline auto simdle_napi_and_v128_u16  = simdle_op<simdle_and_v128_u16,  uint16_t>::binary;
constexpr inline auto simdle_napi_and_v128_u32  = simdle_op<simdle_and_v128_u32,  uint32_t>::binary;

constexpr inline auto simdle_napi_clear_v128_u8  = simdle_op<simdle_clear_v128_u8,  uint8_t>::binary;
constexpr inline auto simdle_napi_clear_v128_u16 = simdle_op<simdle_clear_v128_u16, uint16_t>::binary;
constexpr inline auto simdle_napi_clear_v128_u32 = simdle_op<simdle_clear_v128_u32, uint32_t>::binary;

constexpr inline auto simdle_napi_or_v128_u8   = simdle_op<simdle_or_v128_u8,   uint8_t>::binary;
constexpr inline auto simdle_napi_or_v128_u16  = simdle_op<simdle_or_v128_u16,  uint16_t>::binary;
constexpr inline auto simdle_napi_or_v128_u32  = simdle_op<simdle_or_v128_u32,  uint32_t>::binary;

constexpr inline auto simdle_napi_xor_v128_u8   = simdle_op<simdle_xor_v128_u8,   uint8_t>::binary;
constexpr inline auto simdle_napi_xor_v128_u16  = simdle_op<simdle_xor_v128_u16,  uint16_t>::binary;
constexpr inline auto simdle_napi_xor_v128_u32  = simdle_op<simdle_xor_v128_u32,  uint32_t>::binary;

constexpr inline auto simdle_napi_sum_v128_u8   = simdle_op<simdle_sum_v128_u8,   uint8_t>::reduce;
constexpr inline auto simdle_napi_sum_v128_u16  = simdle_op<simdle_sum_v128_u16,  uint16_t>::reduce;
constexpr inline auto simdle_napi_sum_v128_u32  = simdle_op<simdle_sum_v128_u32,  uint32_t>::reduce;

static js_value_t *
bare_addon_exports(js_env_t *env, js_value_t *exports) {
  int err;

#define EXPORT_FUNCTION(fn) \
  err = js_set_property<fn>(env, exports, #fn); \
  assert(err == 0);

  EXPORT_FUNCTION(simdle_napi_allo_v128);
  EXPORT_FUNCTION(simdle_napi_allz_v128);

  EXPORT_FUNCTION(simdle_napi_cnt_v128_u8);
  EXPORT_FUNCTION(simdle_napi_cnt_v128_u16);
  EXPORT_FUNCTION(simdle_napi_cnt_v128_u32);

  EXPORT_FUNCTION(simdle_napi_clz_v128_u8);
  EXPORT_FUNCTION(simdle_napi_clz_v128_u16);
  EXPORT_FUNCTION(simdle_napi_clz_v128_u32);

  EXPORT_FUNCTION(simdle_napi_and_v128_u8);
  EXPORT_FUNCTION(simdle_napi_and_v128_u16);
  EXPORT_FUNCTION(simdle_napi_and_v128_u32);

  EXPORT_FUNCTION(simdle_napi_clear_v128_u8);
  EXPORT_FUNCTION(simdle_napi_clear_v128_u16);
  EXPORT_FUNCTION(simdle_napi_clear_v128_u32);

  EXPORT_FUNCTION(simdle_napi_clo_v128_u8);
  EXPORT_FUNCTION(simdle_napi_clo_v128_u16);
  EXPORT_FUNCTION(simdle_napi_clo_v128_u32);

  EXPORT_FUNCTION(simdle_napi_cto_v128_u8);
  EXPORT_FUNCTION(simdle_napi_cto_v128_u16);
  EXPORT_FUNCTION(simdle_napi_cto_v128_u32);

  EXPORT_FUNCTION(simdle_napi_ctz_v128_u8);
  EXPORT_FUNCTION(simdle_napi_ctz_v128_u16);
  EXPORT_FUNCTION(simdle_napi_ctz_v128_u32);

  EXPORT_FUNCTION(simdle_napi_not_v128_u8);
  EXPORT_FUNCTION(simdle_napi_not_v128_u16);
  EXPORT_FUNCTION(simdle_napi_not_v128_u32);

  EXPORT_FUNCTION(simdle_napi_or_v128_u8);
  EXPORT_FUNCTION(simdle_napi_or_v128_u16);
  EXPORT_FUNCTION(simdle_napi_or_v128_u32);

  EXPORT_FUNCTION(simdle_napi_sum_v128_u8);
  EXPORT_FUNCTION(simdle_napi_sum_v128_u16);
  EXPORT_FUNCTION(simdle_napi_sum_v128_u32);

  EXPORT_FUNCTION(simdle_napi_xor_v128_u8);
  EXPORT_FUNCTION(simdle_napi_xor_v128_u16);
  EXPORT_FUNCTION(simdle_napi_xor_v128_u32);
#undef EXPORT_FUNCTION

  return exports;
}

BARE_MODULE(bare_addon, bare_addon_exports)
