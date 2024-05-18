#include "blockid.hpp"
#include <gtest/gtest.h>

TEST(BlockIDTest, EqualsOperatorOverloadTestTrue) {
  auto const blockID1 = BlockID("test", 21);
  auto const blockID2 = BlockID("test", 21);
  EXPECT_TRUE(blockID1 == blockID2);
}

TEST(BlockIDTest, EqualsOperatorOverloadTestFalse) {
  auto const blockID1 = BlockID("test", 21);
  auto const blockID2 = BlockID("test1", 211);
  EXPECT_FALSE(blockID1 == blockID2);
}