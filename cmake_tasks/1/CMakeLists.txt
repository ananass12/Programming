cmake_minimum_required(VERSION 3.10)

# Название проекта
project(ThreadProject C)

# Установка стандарта C
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Установка флагов компилятора
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pthread")

# Добавление исходных файлов
set(SOURCES
    threads.c
    threadFunctions.c
)

# Создание исполняемого файла
add_executable(ThreadProject ${SOURCES})

# Линковка с библиотекой pthread
target_link_libraries(ThreadProject pthread)
