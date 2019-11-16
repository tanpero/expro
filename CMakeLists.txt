cmake_minimum_required (VERSION 3.8)

project ("expro")

add_library (expro
  deps/tinyexpr.h
  deps/tinyexpr.c
  src/expro.h
  src/expro.cc
)

set_property(TARGET expro PROPERTY CXX_STANDARD 17)

target_include_directories (expro PUBLIC deps)

add_executable(expro-test test/main.cc)
target_include_directories (expro-test PUBLIC src)
target_link_libraries(expro-test expro)
