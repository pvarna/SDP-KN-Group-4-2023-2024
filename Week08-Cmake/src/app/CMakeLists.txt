add_executable(
    app
)

target_link_libraries(
    app
    PUBLIC
    math
    person
)

target_sources(
    app
    PUBLIC
    main.cpp
)