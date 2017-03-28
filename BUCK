include_defs('//BUCKAROO_DEPS')

prebuilt_cxx_library(
  name = 'spirit', 
  header_only = True,
  header_namespace = 'boost', 
  exported_headers = subdir_glob([
    ('include/boost', '**/*.hpp'),
    ('include/boost', '**/*.ipp'),
  ]),
  visibility = [
    'PUBLIC',
  ],
  deps = BUCKAROO_DEPS,
)
