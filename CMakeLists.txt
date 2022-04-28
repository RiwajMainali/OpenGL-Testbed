cmake_minimum_required(VERSION 3.12)
project(raytracing)

set (CMAKE_CXX_STANDARD 11) #cpp versions
set (CMAKE_C_STANDARD 11)   #c versions

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)  #for lsp and clangd

#SO THAT GLFW DOESNT COMPILE UNNECESSARY STUFF
set (GLFW_BUILD_DOCS FALSE)
set (GLFW_BUILD_TESTS FALSE)
set (GLFW_BUILD_EXAMPLES FALSE) 
add_executable(run src/main.cpp)


add_subdirectory(glfw)
add_subdirectory(glad)

target_link_libraries(run glfw glad)


