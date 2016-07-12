{
  "variables": {},
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "lib/addon.cc", "lib/test.cc" ],
      "include_dirs": [],
      "link_settings": {},
      "cflags": [
        "-std=c++11"
      ],
      "cflags_cc!": [
        "-fno-rtti",
        "-fno-exceptions"
      ]
    }
  ]
}