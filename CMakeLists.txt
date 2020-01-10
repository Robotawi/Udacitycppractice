cmake_minimum_required(VERSION 3.15)
project(Udacitycppractice)

set(CMAKE_CXX_STANDARD 17)

add_executable(incrementsum course1-multiple-files-project/main.cpp course1-multiple-files-project/addone.cpp course1-multiple-files-project/incrementandsum.cpp)
add_executable(unorderedmap course1-unordere-map/unordere-map-try.cpp)
#add_executable(carclass ./course1-make-classes-files/onefile.cpp)
add_executable(carmultfiles course1-make-classes-files/car.cpp course1-make-classes-files/carmain.cpp)