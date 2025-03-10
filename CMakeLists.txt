# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Имя проекта
project(pr2sem2 C)

# Установка стандарта C (например, C11, потому что на нем лучше работа с многопоточными средами, чем с С99)
set(CMAKE_C_STANDARD 11)

#Включение папки с файлами заголовков (*.h)
include_directories(hfiles)

# Добавление исполняемого файла
add_executable(pr2sem2
  src/main.c
  src/users.c
  src/processes.c
  src/logger.c
  src/errors.c)
