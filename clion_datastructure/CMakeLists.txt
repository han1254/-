cmake_minimum_required(VERSION 3.17)
project(clion_datastructure C)

set(CMAKE_C_STANDARD 99)

add_executable(clion_datastructure main.c _3_stack_and_queue/stack/SqStack.h _3_stack_and_queue/stack/SqStackImpl.h _3_stack_and_queue/stack/SqStackMain.h _3_stack_and_queue/stack/LinkStack.h _3_stack_and_queue/stack/stack_common.h _3_stack_and_queue/stack/LinkStackImpl.h _3_stack_and_queue/stack/LinkStackMain.c)
add_executable(ch3_s1_3 ../clion_datastructure/_3_stack_and_queue/stack/_ch3_se1_3.c)
