{
  'targets': [{
    'target_name': 'simd',
    'type': 'static_library',
    'sources': [
      './libsimd/src/clo.c',
      './libsimd/src/clz.c',
      './libsimd/src/cnt.c',
      './libsimd/src/cto.c',
      './libsimd/src/ctz.c',
    ],
    'configurations': {
      'Debug': {
        'defines': ['DEBUG'],
      },
      'Release': {
        'defines': ['NDEBUG'],
      },
    },
    'xcode_settings': {
      'OTHER_CFLAGS': [
        '-O3',
      ]
    },
    'cflags': [
      '-O3',
    ],
  }]
}
