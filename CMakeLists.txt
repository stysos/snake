cmake_minimum_required(VERSION 3.0.0)
project(snake VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(SFML)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_executable(snake main.cpp
                    snake.cpp
                    gameWindow.cpp)

target_link_libraries(snake sfml-graphics sfml-audio)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
