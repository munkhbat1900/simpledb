#include "page.hpp"
#include <__memory/unique_ptr.h>
#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>
#include <vector>

/*
What the hell is this double cast.
It is because I want to treat a char as unsigned char and then cast it to int.
Why do I do this?

In a signed 8-bit representation, the binary representation of 205 is 11001101. When interpreted as a signed 8-bit integer, 
this binary representation is treated as a negative number because the most significant bit is 1, indicating a negative value.

Therefore, in a signed representation, 205 would be interpreted as -51.
*/

TEST(PageTest, WriteInt1) {
    std::unique_ptr<Page> page = std::make_unique<Page>(9);
    page->setInt(3, 345);
    EXPECT_EQ(static_cast<int>(static_cast<unsigned char>(page->contents()->at(3))), 89);
    EXPECT_EQ(static_cast<int>(static_cast<unsigned char>(page->contents()->at(4))), 1);
    EXPECT_EQ(static_cast<int>(static_cast<unsigned char>(page->contents()->at(5))), 0);
    EXPECT_EQ(static_cast<int>(static_cast<unsigned char>(page->contents()->at(6))), 0);
    EXPECT_EQ(page->getInt(3), 345);
}

TEST(PageTest, WriteInt2) {
    std::unique_ptr<Page> page = std::make_unique<Page>(9);
    page->setInt(3, 123456789);
    EXPECT_EQ(static_cast<int>(static_cast<unsigned char>(page->contents()->at(3))), 21);
    EXPECT_EQ(static_cast<int>(static_cast<unsigned char>(page->contents()->at(4))), 205);
    EXPECT_EQ(static_cast<int>(static_cast<unsigned char>(page->contents()->at(5))), 91);
    EXPECT_EQ(static_cast<int>(static_cast<unsigned char>(page->contents()->at(6))), 7);

    EXPECT_EQ(page->getInt(3), 123456789);
}

TEST(PageTest, GetIntException) {
    std::unique_ptr<Page> page = std::make_unique<Page>(9);
    EXPECT_THROW(page->setInt(7, 123456789), std::out_of_range);
}

TEST(PageTest, WriteString) {
    std::unique_ptr<Page> page = std::make_unique<Page>(9);
    page->setString(1, "munk");

    EXPECT_EQ(page->getInt(1), 4);

    EXPECT_EQ(page->contents()->at(5), 'm');
    EXPECT_EQ((*page->contents())[6], 'u');
    EXPECT_EQ((*page->contents())[7], 'n');
    EXPECT_EQ((*page->contents())[8], 'k');

    EXPECT_EQ(page->getString(1), "munk");
}