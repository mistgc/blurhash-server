facilio_src = files(
  'src/fiobj_ary.c',
  'src/fiobj_data.c',
  'src/fiobject.c',
  'src/fiobj_hash.c',
  'src/fiobj_json.c',
  'src/fiobj_mustache.c',
  'src/fiobj_numbers.c',
  'src/fiobj_str.c',
  'src/fio.c',
  'src/fio_cli.c',
  'src/fio_siphash.c',
  'src/fio_tls_missing.c',
  'src/fio_tls_openssl.c',
  'src/http1.c',
  'src/http.c',
  'src/http_internal.c',
  'src/redis_engine.c',
  'src/websockets.c',
)
facilio_inc = include_directories('include')

facilio = static_library(
  'facilio',
  facilio_src,
  link_args: [
    '-static'
  ],
  include_directories: facilio_inc,
)

facilio_dep = declare_dependency(
  include_directories: facilio_inc,
  link_with: facilio,
)
