{
  'includes': [
    'common.gypi'
  ],
  'targets': [
    {
      'target_name': 'lib2048',
      'type': 'static_library',
      'sources': [
        'djinni/twenty_forty_eight.djinni',
        '<!@(python scripts/glob.py src/ *.hpp *.cpp)',
        '<!@(python scripts/glob.py generated-src/cpp *.hpp *.cpp)',
      ],
      'include_dirs': [
        'include',
        'generated-src'
      ],
      'all_dependent_settings': {
        'include_dirs': [
          'include',
          'generated-src/cpp/'
        ]
      },
    },
    {
      'target_name': 'test',
      'type': 'executable',
      'dependencies': [
        'lib2048',
        'third_party/gtest.gyp:gtest'
      ],
      'cflags_cc!': [
        '-Werror',
        '-Wextra'
      ],
      'xcode_settings': {
        'OTHER_CPLUSPLUSFLAGS!': [
          '-Werror',
          '-Wextra'
        ]
      },
      'include_dirs': [
        'test',
      ],
      'sources': [
        '<!@(python scripts/glob.py test/ *.cpp)'
      ],
    },
  ],
}
