project(avhacker)
cmake_minimum_required(version 2.6) 
aux_source_directory(./src/avhacker DIR_SRCS)
add_executable(hello ${DIR_SRCS})