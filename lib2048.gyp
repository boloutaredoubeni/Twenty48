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
        '<!@(python scripts/glob.py third_party/djinni/support-lib/objc/ *.h *.mm)'
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
        'target_name': 'lib2048_jni',
        'type': 'shared_library',
        'dependencies': [
            'third_party/djinni/support-lib/support_lib.gyp:djinni_jni',
            'lib2048'
        ],
        'ldflags': [
            '-llog',
            '-Wl,--build-id,--gc-sections,--exclude-libs,ALL'
        ],
        'sources': [
          '<!@(python scripts/glob.py third_party/djinni/support-lib/jni/ *.hpp *.cpp)',
          '<!@(python scripts/glob.py generated-src/jni/ *.hpp *.cpp)'
        ],
        'include_dirs': [
          'generated-src/jni'
        ],
        'all_dependent_settings': {
          'include_dirs': [
            'generated-src/jni'
          ]
        }
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
