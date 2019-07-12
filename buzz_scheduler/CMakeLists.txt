#
# Set minimum required version
#
cmake_minimum_required(VERSION 2.8.12)

#
# Find pkg-config
#
find_package(PkgConfig REQUIRED)

find_package(Buzz REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/src ${BUZZ_C_INCLUDE_DIR})
add_executable(scheduler
  src/buzz_utils.cpp 
  src/buzz_utils.h
  src/scheduler.cpp)
target_link_libraries(scheduler 
  buzz
  buzzdbg
  -lpthread
  )
install(TARGETS scheduler RUNTIME DESTINATION bin)