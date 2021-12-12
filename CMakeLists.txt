cmake_minimum_required(VERSION 3.1)
project( Memorama )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( memorama main.cpp )

target_link_libraries( memorama ${OpenCV_LIBS})


