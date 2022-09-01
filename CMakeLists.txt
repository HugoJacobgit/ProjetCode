cmake_minimum_required(VERSION 3.16.3)

project(ProjetCode VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_ORIGINAL_LIB "Use original libraries to compute fights" ON)


configure_file(ProjetConfig.h.in ProjetConfig.h)
#####################################

if(USE_ORIGINAL_LIB)
    add_subdirectory(lib)
    list(APPEND EXTRA_LIBS lib)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib")
endif()

add_executable(${PROJECT_NAME} ProjetMain.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

target_include_directories(ProjetCode PUBLIC "${PROJECT_BINARY_DIR}" ${EXTRA_INCLUDES})

