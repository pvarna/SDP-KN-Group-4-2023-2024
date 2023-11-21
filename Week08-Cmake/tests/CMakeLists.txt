# Downloading catch2
message(STATUS "Fetching catch2")

Include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.1.1
)
FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_executable(unit-tests)

target_sources(
    unit-tests
    PUBLIC
    fact_test.cpp
)

target_link_libraries(
    unit-tests
    PRIVATE
    Catch2::Catch2WithMain
    mathlib
)

# Automatically register all tests
catch_discover_tests(unit-tests)