cmake_minimum_required(VERSION 3.10.0)
project(linear_list)
add_library(linear_list sequenceList.c linkList.c linear_list_test.c)