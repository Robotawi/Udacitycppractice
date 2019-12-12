cmake_minimum_required(VERSION 3.15)
project(Udacitycppractice)

set(CMAKE_CXX_STANDARD 17)

add_executable(incrementsum ./multiple-files-project/main.cpp ./multiple-files-project/addone.cpp ./multiple-files-project/incrementandsum.cpp)
add_executable(unorderedmap ./unordere-map/unordere-map-try.cpp)
#add_executable(carclass ./make-classes-files/onefile.cpp)
add_executable(carmultfiles ./make-classes-files/car.cpp ./make-classes-files/carmain.cpp)