file(GLOB SOURCE_C . *.cpp)
file(GLOB SOURCE_H . *.h)
add_library(lib ${SOURCE_C} ${SOURCE_H})