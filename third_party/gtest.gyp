{
  'targets': [
    {
      'target_name': 'gtest',
      'type': 'static_library',
      'sources': [
        'googletest/googletest/src/gtest-all.cc',
        'googletest/googlemock/src/gmock-all.cc',
        # 'googletest/googlemock/src/gmock-main.cc',
        # 'googletest/googletest/src/gtest-main.cc',
      ],
      'cflags_cc!': ['-Werror'],
      'xcode_settings': {
        'OTHER_CPLUSPLUSFLAGS!': ['-Werror'],
      },
      "include_dirs": [
        'googletest/googletest/',
        'googletest/googlemock/',
        'googletest/googletest/include',
        'googletest/googlemock/include/'
      ],
      'direct_dependent_settings': {
        'include_dirs': [
          'googletest/googletest/include',
          'googletest/googlemock/include',
        ],
      },
    }
  ],
}
