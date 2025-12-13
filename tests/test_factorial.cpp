#include <gtest/gtest.h>
#include "factorial.hpp"

TEST(FactorialTest, HandlesZero) {
    EXPECT_EQ(factorial(0), 1);
}

TEST(FactorialTest, HandlesOne) {
    EXPECT_EQ(factorial(1), 1);
}

TEST(FactorialTest, HandlesPositiveNumbers) {
    EXPECT_EQ(factorial(2), 2);
    EXPECT_EQ(factorial(3), 6);
    EXPECT_EQ(factorial(4), 24);
    EXPECT_EQ(factorial(5), 120);
}

TEST(FactorialTest, HandlesNegativeNumbers) {
    // By design: val <= 1 returns 1
    EXPECT_EQ(factorial(-1), 1);
    EXPECT_EQ(factorial(-10), 1);
}
