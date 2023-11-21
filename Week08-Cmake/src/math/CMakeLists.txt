add_library(mathlib)

target_include_directories(
    mathlib
    PUBLIC
    include/
)

target_sources(
    mathlib
    PUBLIC
    fact.cpp
)