cmake_minimum_required(VERSION 3.25)

project(simdle_native C)

include(bare)

if(NOT TARGET simdle)
  add_subdirectory(vendor/libsimdle EXCLUDE_FROM_ALL)
endif()

add_bare_module(simdle_native)

target_sources(
  ${simdle_native}
  PRIVATE
    binding.c
)

target_link_libraries(
  ${simdle_native}
  PUBLIC
    simdle_static
)
