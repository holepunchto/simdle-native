{
  'targets': [{
    'target_name': 'simdle',
    'include_dirs': [
      '<!(node -e "require(\'napi-macros\')")',
      './vendor/libsimdle/include',
    ],
    'dependencies': [
      './vendor/libsimdle.gyp:libsimdle',
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
