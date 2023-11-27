add_library(person)

target_include_directories(
    person
    PUBLIC
    include/
)

target_sources(
    person
    PUBLIC
    egn.cpp
    person.cpp
)