project(itkZeroCrossingImageFilter)

cmake_minimum_required(VERSION 2.8)

find_package(ITK REQUIRED)

include(${ITK_USE_FILE})

add_executable(itkZeroCrossingImageFilter
  main.cxx
)

target_link_libraries(itkZeroCrossingImageFilter
  ${ITK_LIBRARIES}
)