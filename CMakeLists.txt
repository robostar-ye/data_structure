cmake_minimum_required(VERSION 3.17)
project(test_2)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(homework_3 homework/homework_3.cpp include/lists.hpp)
add_executable(from_zhanghuimin from_zhanghuimin.cpp include/lists.hpp)
add_executable(exp1_1 exp1/exp1_1.cpp include/lists.hpp exp2/exp2_1.cpp)
add_executable(exp1_2 include/lists.hpp exp1/exp1_2.cpp)
add_executable(exp1_3 exp1/exp1_3.cpp include/lists.hpp)
add_executable(exp2_1 exp2/exp2_1.cpp include/stacks.hpp)
add_executable(exp2_2 exp2/exp2_2.cpp include/stacks.hpp)
add_executable(exp2_3 exp2/exp2_3.cpp include/stacks.hpp include/queues.hpp)
add_executable(exp2_4 exp2/exp2_4.cpp include/stacks.hpp)
add_executable(exp3_1 exp3/exp3_1.cpp)
add_executable(exp3_1_ exp3/exp3_1_.cpp)
add_executable(exp3_2 exp3/exp3_2.cpp)
add_executable(exp3_3 exp3/exp3_3.cpp)
add_executable(exp3_4 exp3/exp3_4.cpp)
add_executable(exp4_6 include/graph.hpp exp4/exp4_6.cpp)
add_executable(exp4_8 include/graph.hpp exp4/exp4_8.cpp)
add_executable(exp5_1 exp5/exp5_1.cpp)
add_executable(exp5_2 exp5/exp5_2.cpp)
add_executable(homework_4 homework/homework_4.cpp include/trees.hpp)
add_executable(homework_5 homework/homework_5.cpp)