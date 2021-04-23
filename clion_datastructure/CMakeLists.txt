cmake_minimum_required(VERSION 3.17)
project(clion_datastructure C)

set(CMAKE_C_STANDARD 99)

add_executable(clion_datastructure main.c _3_stack_and_queue/stack/SqStack.h _3_stack_and_queue/stack/SqStackImpl.h _3_stack_and_queue/stack/SqStackMain.h _3_stack_and_queue/stack/LinkStack.h _3_stack_and_queue/stack/stack_common.h _3_stack_and_queue/stack/LinkStackImpl.h _3_stack_and_queue/stack/LinkStackMain.c)
add_executable(ch3_s1_3 ../clion_datastructure/_3_stack_and_queue/stack/_ch3_se1_3.c _3_stack_and_queue/queue/LinkQueue.h _3_stack_and_queue/queue/LinkQueueImpl.h _3_stack_and_queue/queue/LinkQueueMain.c _3_stack_and_queue/queue/_ch3_se2_1.c _3_stack_and_queue/queue/_ch3_se2_2.c)
add_executable(ch3_s1_4 ../clion_datastructure/_3_stack_and_queue/stack/_ch3_se1_4.c)
add_executable(link_stack_main ../clion_datastructure/_3_stack_and_queue/stack/LinkStackMain.c _3_stack_and_queue/stack/LinkStack.h _3_stack_and_queue/stack/LinkStackImpl.h)
add_executable(sq_queue_main _3_stack_and_queue/queue/SqQueueMain.c)
add_executable(ch3_s2_1 _3_stack_and_queue/queue/_ch3_se2_1.c)
add_executable(ch3_s2_2 _3_stack_and_queue/queue/_ch3_se2_2.c)

