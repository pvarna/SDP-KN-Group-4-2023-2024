add_library(math)

target_include_directories(
    math
    PUBLIC
    include/
)

target_sources(
    math
    PUBLIC
    fact.cpp
)