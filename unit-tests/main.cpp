#include "gtest/gtest.h"

TEST(Example, Test1) {
    ASSERT_EQ(10, 12);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}