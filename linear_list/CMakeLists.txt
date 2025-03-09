cmake_minimum_required(VERSION 3.10.0)
project(linear_list)
add_library(linear_list sequenceList.c link_list.c linear_list_test.c circular_link_list.c circular_queue.c queue.c stack.c double_link_list.c static_link_list.c)