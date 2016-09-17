include_directories(${PROJECT_SOURCE_DIR}/src/avhacker/include)
set(EXAMPLE1_SRC example1.c)
add_executable(example1 ${EXAMPLE1_SRC})
target_link_libraries(example1 avhacker)
