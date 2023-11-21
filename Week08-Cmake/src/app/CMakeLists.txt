add_executable(
    hello
)

target_sources(
    hello
    PUBLIC
    main.cpp
)

target_link_libraries(
    hello
    PUBLIC
    mathlib
)