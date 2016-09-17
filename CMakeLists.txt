project(avhacker)
cmake_minimum_required(VERSION 2.6) 
aux_source_directory(./src/avhacker DIR_SRCS)
add_executable(avhacker ${DIR_SRCS})