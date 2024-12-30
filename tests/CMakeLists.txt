
set(SOURCE_FILES
    Tests.cpp
)

add_subdirectory(Catch2)

# These tests can use the Catch2-provided main
add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain src)