project('blurhash-server', 'c')

math = meson.get_compiler('c').find_library('m', static: true)

inc = include_directories('include')
src = files(
  'src/main.c',
  'src/blurhash/encode.c',
  'src/server/http_server.c',
)

subdir('lib')

executable(
  'blurhash-server-bin',
  src,
  c_args: [
    '-DSTB_IMAGE_IMPLEMENTATION',
  ],
  link_args: [
    '-static',
  ],
  include_directories: inc,
  dependencies: [ math, facilio_dep ],
)
