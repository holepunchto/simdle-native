{
  'targets': [{
    'target_name': 'simd',
    'include_dirs': [
      '<!(node -e "require(\'napi-macros\')")',
      './vendor/libsimd/include',
    ],
    'dependencies': [
      './vendor/libsimd.gyp:simd',
    ],
    'sources': [
      './binding.c',
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
