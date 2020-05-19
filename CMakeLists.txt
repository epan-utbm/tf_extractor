cmake_minimum_required(VERSION 2.8.3)
project(tf_extractor)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  )

include_directories(include ${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(tf_extractor src/tf_extractor.cpp)
target_link_libraries(tf_extractor ${catkin_LIBRARIES})
if(catkin_EXPORTED_TARGETS)
  add_dependencies(tf_extractor ${catkin_EXPORTED_TARGETS})
endif()
