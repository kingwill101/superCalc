project(kingwill)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(kingwill_SRCS operations.cpp button.cpp calculate.h calculate.cpp main.cpp)
qt4_automoc(${kingwill_SRCS})
add_executable(kingwill ${kingwill_SRCS})
target_link_libraries(kingwill ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS kingwill RUNTIME DESTINATION bin)
