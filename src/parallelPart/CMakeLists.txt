#################
# Required CMakeVersion
#################

cmake_minimum_required(VERSION 2.8.12)

#################
# Project
#################

project(parallelParts)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")


##########
#Find OpenMP
#########
find_package(OpenMP)

##########
#Find OpenMPI
##########
find_package(MPI)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}  ${MPI_COMPILE_FLAGS})
include_directories(MPI_INCLUDE_PATH)



#################
# Build & Links
#################

file(GLOB_RECURSE SRC_FILES "*.cpp")

add_executable(parallelparts ${SRC_FILES})

target_link_libraries(parallelparts ${OpenMP_CXX_FLAGS} ${MPI_LIBRARIES} )

if(UNIX)
	target_link_libraries(parallelparts m)
endif()
