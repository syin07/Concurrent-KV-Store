add_executable(kvstore_tests
    smoke_test.cpp
)
target_link_libraries(kvstore_tests PRIVATE kvstore kv_warnings GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(kvstore_tests)
