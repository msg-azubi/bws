#ifndef TST_ZEUGNIS_H
#define TST_ZEUGNIS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(ArrayExample, Zeugnis)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_ZEUGNIS_H
