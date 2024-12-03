cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0)

# Включение директории include/
include_directories(include)

# Добавление поддиректорий для static и dynamic
add_subdirectory(static)
add_subdirectory(dynamic)

# Линковка исполняемого файла из src/main.c с библиотеками из поддиректорий
add_executable(MyExecutable src/main.c)
target_link_libraries(MyExecutable MyStaticLibrary MyDynamicLibrary)
