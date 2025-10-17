cmake_minimum_required(VERSION 3.28)
project(RVV_CAS CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add vreg library
add_library(vreg INTERFACE)
add_library(vcsr_vtype INTERFACE)

# Include directories
target_include_directories(vreg INTERFACE include)
target_include_directories(vcsr_vtype INTERFACE include)


add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE vreg vcsr_vtype)