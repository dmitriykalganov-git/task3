cmake_minimum_required(VERSION 3.5)

project(allocator VERSION 0.0.1)



add_executable(task_allocator task_allocator.cpp pool_allocator.h UList.h)
set_target_properties(task_allocator PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

#install(TARGETS allocator RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT kalganov_dmitriy@mail.ru)

include(CPack)