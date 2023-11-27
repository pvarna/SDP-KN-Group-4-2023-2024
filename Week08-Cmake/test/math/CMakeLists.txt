add_executable(mathTests)

target_sources(
    mathTests
    PUBLIC
    factTests.cpp
)

target_link_libraries(
    mathTests
    PUBLIC
    Catch2::Catch2WithMain
    math
)

add_test(NAME MathTests COMMAND mathTests)