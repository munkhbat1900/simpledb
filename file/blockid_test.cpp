#include <gtest/gtest.h>
#include "blockid.hpp"

namespace simpledb {
    TEST(BlockIDTest, EqualsOperatorOverloadTest) {
        BlockID blockID1 = BlockID("test", 21);
        BlockID blockID2 = BlockID("test", 21);
        EXPECT_TRUE(blockID1 == blockID1);
    }
}