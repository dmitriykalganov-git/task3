cmake_minimum_required(VERSION 3.5)

project(07.templates)

add_executable(task_allocator task_allocator.cpp ip_address.cpp ip_address.h 
ip_base.h SimpleAllocator.h
)
set_target_properties(task_allocator PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

#add_executable(sfinae sfinae.cpp)
#set_target_properties(sfinae PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

#add_executable(sfinae_sort sfinae_sort.cpp)
#set_target_properties(sfinae_sort PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)