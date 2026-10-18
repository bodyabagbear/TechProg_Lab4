cmake_minimum_required(VERSION 3.20)
project(TestIntegration LANGUAGES CXX)

# Створюємо наш виконуваний файл (консольну програму)
add_executable(TestApp main.cpp)

target_include_directories(TestApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Integration_SDK/include)

# Вказуємо, де шукати її файл .lib для неявного зв'язування
target_link_directories(TestApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Integration_SDK/lib)

# Підключаємо бібліотеку напарниці
target_link_libraries(TestApp PRIVATE IntegrationLib)