cmake_minimum_required(VERSION 3.25)

project(simdle_native C)

include(bare)
include(napi)

if(NOT TARGET simdle)
  add_subdirectory(vendor/libsimdle EXCLUDE_FROM_ALL)
endif()

add_bare_module(simdle_native_bare)

target_sources(
  ${simdle_native_bare}
  PRIVATE
    binding.c
  PUBLIC
    $<TARGET_OBJECTS:simdle>
)

target_link_libraries(
  ${simdle_native_bare}
  PUBLIC
    simdle
)

add_napi_module(simdle_native_node)

target_sources(
  ${simdle_native_node}
  PRIVATE
    binding.c
  PUBLIC
    $<TARGET_OBJECTS:simdle>
)

target_link_libraries(
  ${simdle_native_node}
  PUBLIC
    simdle
)
