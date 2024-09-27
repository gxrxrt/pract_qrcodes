cmake_minimum_required(VERSION 3.29)
project(pract_qr_codes)

set(CMAKE_CXX_STANDARD 20)

set(PATH_TO_MYSQL_CONNECTOR "C:/Program Files/MySQL/mysql-connector-c++-9.0.0")

include_directories(${PATH_TO_MYSQL_CONNECTOR}/include)
link_directories(${PATH_TO_MYSQL_CONNECTOR}/lib64/vs14)

#Подключаем httplib через FetchContent
#include(FetchContent)
#FetchContent_Declare(
#httplib
#GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
#GIT_TAG        v0.10.8
#)
#FetchContent_MakeAvailable(httplib)

add_executable(pract_qr_codes main.cpp db.h
        dp.cpp
        auth.cpp
        auth.h)

target_link_libraries(pract_qr_codes mysqlcppconn)

target_compile_features(pract_qr_codes PRIVATE cxx_range_for)

message(STATUS "Path to MySQL Connector: ${PATH_TO_MYSQL_CONNECTOR}")
message(STATUS "Include directories: ${PATH_TO_MYSQL_CONNECTOR}/include")
message(STATUS "Library directories: ${PATH_TO_MYSQL_CONNECTOR}/lib64/vs14")
