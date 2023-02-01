project('blurhash-server', 'c')

math = meson.get_compiler('c').find_library('m')
inc = include_directories('include')
src = files('src/main.c', 'src/blurhash/encode.c', )
subdir('lib')

executable(
  'blurhash-server-bin',
  src,
  include_directories: inc,
  dependencies: [ math, facilio_dep ],
)
