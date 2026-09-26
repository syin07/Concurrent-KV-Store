#include "kvstore/version.h"

#include <gtest/gtest.h>

// Proves the toolchain works end to end: library builds, test links, GoogleTest runs.
TEST(Smoke, VersionIsNotEmpty) {
    EXPECT_FALSE(kvstore::version().empty());
}
