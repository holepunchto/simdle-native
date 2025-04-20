#include <bare.h>
#include <js.h>
#include <jstl.h>
#include <stdint.h>
#include <simdle.h>

template<auto fn>
struct simdle_op {
  static inline void
  unary (js_env_t *env, js_receiver_t, js_typedarray_t<simdle_v128_t> operand, js_typedarray_t<uint8_t> result_buf) {
    int err;

    simdle_v128_t *buf;
    size_t buf_len = 0;

    err = js_get_typedarray_info(env, operand, buf, buf_len);
    assert(err == 0);

    simdle_v128_t *result;
    err = js_get_typedarray_info(env, result_buf, result);
    assert(err == 0);

    for (size_t i = 0, n = buf_len / 16; i < n; i++) {
      result[i] = fn(buf[i]);
    }
    // __builtin_debugtrap();
  }

  static inline void
  binary (
    js_env_t *env,
    js_receiver_t,
    js_typedarray_t<uint8_t> a_buf,
    js_typedarray_t<uint8_t> b_buf,
    js_typedarray_t<simdle_v128_t> result_buf
  ) {
    int err;
    simdle_v128_t *a, *b, *result;

    err = js_get_typedarray_info(env, a_buf, a);
    assert(err == 0);

    err = js_get_typedarray_info(env, b_buf, b);
    assert(err == 0);

    size_t len = 0;
    err = js_get_typedarray_info(env, result_buf, result, len);
    assert(err == 0);

    for (size_t i = 0, n = len / 16; i < n; i++) {
      result[i] = fn(a[i], b[i]);
    }
  }

  static inline int64_t
  reduce (js_env_t *env, js_receiver_t, js_typedarray_t<simdle_v128_t> buffer) {
    simdle_v128_t *buf;
    size_t buf_len;

    int err = js_get_typedarray_info(env, buffer, buf, buf_len);
    assert(err == 0);

    uint64_t result = 0;

    for (size_t i = 0, n = buf_len / 16; i < n; i++) {
      result += fn(buf[i]);
    }

    return result;
  }
};

inline uint32_t // TODO: check if inline has any effect
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

inline uint32_t
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

#define SIMDLE_NAPI_BINARY(name, fn) \
  constexpr inline auto name = simdle_op<fn>::binary;

#define SIMDLE_NAPI_UNARY(name, fn) \
  constexpr inline auto name = simdle_op<fn>::unary;

#define SIMDLE_NAPI_REDUCE(name, fn) \
  constexpr inline auto name = simdle_op<fn>::reduce;

SIMDLE_NAPI_BINARY(simdle_napi_and_v128_u8, simdle_and_v128_u8)
SIMDLE_NAPI_BINARY(simdle_napi_and_v128_u16, simdle_and_v128_u16)
SIMDLE_NAPI_BINARY(simdle_napi_and_v128_u32, simdle_and_v128_u32)

SIMDLE_NAPI_BINARY(simdle_napi_clear_v128_u8, simdle_clear_v128_u8)
SIMDLE_NAPI_BINARY(simdle_napi_clear_v128_u16, simdle_clear_v128_u16)
SIMDLE_NAPI_BINARY(simdle_napi_clear_v128_u32, simdle_clear_v128_u32)

SIMDLE_NAPI_UNARY(simdle_napi_clo_v128_u8, simdle_clo_v128_u8)

SIMDLE_NAPI_UNARY(simdle_napi_clo_v128_u16, simdle_clo_v128_u16)
SIMDLE_NAPI_UNARY(simdle_napi_clo_v128_u32, simdle_clo_v128_u32)

SIMDLE_NAPI_UNARY(simdle_napi_clz_v128_u8, simdle_clz_v128_u8)
SIMDLE_NAPI_UNARY(simdle_napi_clz_v128_u16, simdle_clz_v128_u16)
SIMDLE_NAPI_UNARY(simdle_napi_clz_v128_u32, simdle_clz_v128_u32)

SIMDLE_NAPI_UNARY(simdle_napi_cnt_v128_u8, simdle_cnt_v128_u8)
SIMDLE_NAPI_UNARY(simdle_napi_cnt_v128_u16, simdle_cnt_v128_u16)
SIMDLE_NAPI_UNARY(simdle_napi_cnt_v128_u32, simdle_cnt_v128_u32)

SIMDLE_NAPI_UNARY(simdle_napi_cto_v128_u8, simdle_cto_v128_u8)
SIMDLE_NAPI_UNARY(simdle_napi_cto_v128_u16, simdle_cto_v128_u16)
SIMDLE_NAPI_UNARY(simdle_napi_cto_v128_u32, simdle_cto_v128_u32)

SIMDLE_NAPI_UNARY(simdle_napi_ctz_v128_u8, simdle_ctz_v128_u8)
SIMDLE_NAPI_UNARY(simdle_napi_ctz_v128_u16, simdle_ctz_v128_u16)
SIMDLE_NAPI_UNARY(simdle_napi_ctz_v128_u32, simdle_ctz_v128_u32)

SIMDLE_NAPI_UNARY(simdle_napi_not_v128_u8, simdle_not_v128_u8)
SIMDLE_NAPI_UNARY(simdle_napi_not_v128_u16, simdle_not_v128_u16)
SIMDLE_NAPI_UNARY(simdle_napi_not_v128_u32, simdle_not_v128_u32)

SIMDLE_NAPI_BINARY(simdle_napi_or_v128_u8, simdle_or_v128_u8)
SIMDLE_NAPI_BINARY(simdle_napi_or_v128_u16, simdle_or_v128_u16)
SIMDLE_NAPI_BINARY(simdle_napi_or_v128_u32, simdle_or_v128_u32)

SIMDLE_NAPI_REDUCE(simdle_napi_sum_v128_u8, simdle_sum_v128_u8)
SIMDLE_NAPI_REDUCE(simdle_napi_sum_v128_u16, simdle_sum_v128_u16)
SIMDLE_NAPI_REDUCE(simdle_napi_sum_v128_u32, simdle_sum_v128_u32)

SIMDLE_NAPI_BINARY(simdle_napi_xor_v128_u8, simdle_xor_v128_u8)
SIMDLE_NAPI_BINARY(simdle_napi_xor_v128_u16, simdle_xor_v128_u16)
SIMDLE_NAPI_BINARY(simdle_napi_xor_v128_u32, simdle_xor_v128_u32)

#undef SIMDLE_NAPI_BINARY
#undef SIMDLE_NAPI_UNARY
#undef SIMDLE_NAPI_REDUCE

static js_value_t *
bare_addon_exports(js_env_t *env, js_value_t *exports) {
  int err;

#define EXPORT_FUNCTION(fn) \
  err = js_set_property<fn>(env, exports, #fn); \
  assert(err == 0);

  EXPORT_FUNCTION(simdle_napi_allo_v128);
  EXPORT_FUNCTION(simdle_napi_allz_v128);

  EXPORT_FUNCTION(simdle_napi_and_v128_u8);
  EXPORT_FUNCTION(simdle_napi_and_v128_u16);
  EXPORT_FUNCTION(simdle_napi_and_v128_u32);

  EXPORT_FUNCTION(simdle_napi_clear_v128_u8);
  EXPORT_FUNCTION(simdle_napi_clear_v128_u16);
  EXPORT_FUNCTION(simdle_napi_clear_v128_u32);

  EXPORT_FUNCTION(simdle_napi_clo_v128_u8);
  EXPORT_FUNCTION(simdle_napi_clo_v128_u16);
  EXPORT_FUNCTION(simdle_napi_clo_v128_u32);

  EXPORT_FUNCTION(simdle_napi_clz_v128_u8);
  EXPORT_FUNCTION(simdle_napi_clz_v128_u16);
  EXPORT_FUNCTION(simdle_napi_clz_v128_u32);

  EXPORT_FUNCTION(simdle_napi_cnt_v128_u8);
  EXPORT_FUNCTION(simdle_napi_cnt_v128_u16);
  EXPORT_FUNCTION(simdle_napi_cnt_v128_u32);

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
