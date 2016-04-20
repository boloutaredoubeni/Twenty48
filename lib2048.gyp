{
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
        'generated-src/cpp/'
      ],
      'all_dependent_settings': {
        'include_dirs': [
          'include',
          'generated-src/cpp/'
        ]
      },
    },
    {
      'target_name': 'lib2048_ios',
      'type': 'static_library',
      'dependencies': [
        './third_party/djinni/support-lib/support_lib.gyp:djinni_objc',
        'lib2048'
      ],
      'sources': [
        # XXX(boloutaredoubeni): djinni support files need to be included twice?
        '<!@(python scripts/glob.py third_party/djinni/support-lib/objc/ *.mm)'
        '<!@(python scripts/glob.py generated-src/objc/ *.h *.m)',
        '<!@(python scripts/glob.py generated-src/objcpp/ *.h *.mm)',
      ],
      'include_dirs': [
        'generated-src/objc',
        'generated-src/objcpp',
      ],
      'all_dependent_settings': {
        'include_dirs': [
          'generated-src/objc',
          'generated-src/objcpp',
        ],
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
