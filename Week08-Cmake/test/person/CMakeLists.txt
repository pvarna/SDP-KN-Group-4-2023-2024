add_executable(personTests)

target_sources(
    personTests
    PUBLIC
    personTests.cpp
)

target_link_libraries(
    personTests
    PUBLIC
    Catch2::Catch2WithMain
    person
)

add_test(NAME PesonTests COMMAND personTests)