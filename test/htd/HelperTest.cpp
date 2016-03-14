/*
 * File:   HelperTest.cpp
 *
 * Author: ABSEHER Michael (abseher@dbai.tuwien.ac.at)
 *
 * Copyright 2015, Michael Abseher
 *    E-Mail: <abseher@dbai.tuwien.ac.at>
 *
 * This file is part of htd.
 *
 * htd is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * htd is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.

 * You should have received a copy of the GNU General Public License
 * along with htd.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>

#include <htd/main.hpp>

#include <vector>

class HelperTest : public ::testing::Test
{
    public:
        HelperTest(void)
        {

        }

        ~HelperTest()
        {

        }

        void SetUp()
        {

        }

        void TearDown()
        {

        }
};

TEST(HelperTest, CheckPrintBoolToStdout1)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    htd::print(true);

    ASSERT_EQ("true", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintBoolToStdout2)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    htd::print(false);

    ASSERT_EQ("false", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintStringToStdout)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    htd::print(std::string("abc123!!!"));

    ASSERT_EQ("\"abc123!!!\"", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintVectorToStdout1)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::vector<int> inputSet { 1, 5, 3 };

    htd::print(inputSet);

    ASSERT_EQ("[ 1, 5, 3 ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintVectorToStdout2)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::vector<int> inputSet { 1, 5, 3 };

    htd::print(inputSet, false);

    ASSERT_EQ("[ 1, 5, 3 ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintVectorToStdout3)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::vector<std::string> inputSet { "a", "e", "c" };

    htd::print(inputSet);

    ASSERT_EQ("[ \"a\", \"e\", \"c\" ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintVectorToStdout4)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::vector<std::string> inputSet { "a", "e", "c" };

    htd::print(inputSet, false);

    ASSERT_EQ("[ \"a\", \"e\", \"c\" ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintVectorToStdoutSorted1)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::vector<int> inputSet { 1, 5, 3 };

    htd::print(inputSet, true);

    ASSERT_EQ("[ 1, 3, 5 ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintVectorToStdoutSorted2)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::vector<std::string> inputSet { "a", "e", "c" };

    htd::print(inputSet, true);

    ASSERT_EQ("[ \"a\", \"c\", \"e\" ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintSetToStdout1)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::set<int> inputSet { 1, 3, 5 };

    htd::print(inputSet);

    ASSERT_EQ("[ 1, 3, 5 ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintSetToStdout2)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::set<std::string> inputSet { "a", "c", "e" };

    htd::print(inputSet);

    ASSERT_EQ("[ \"a\", \"c\", \"e\" ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintUnorderedSetToStdout1)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::unordered_set<int> inputSet { 1, 5, 3 };

    htd::print(inputSet);

    std::string output = testing::internal::GetCapturedStdout();

    if (output != "[ 1, 3, 5 ]" && output != "[ 1, 5, 3 ]" &&
        output != "[ 3, 1, 5 ]" && output != "[ 3, 5, 1 ]" &&
        output != "[ 5, 1, 3 ]" && output != "[ 5, 3, 1 ]")
    {
        std::cout << "UNEXPECTED RESULT: \"" << output << "\"" << std::endl;

        FAIL();
    }

    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintUnorderedSetToStdout2)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::unordered_set<std::string> inputSet { "a", "e", "c" };

    htd::print(inputSet);

    std::string output = testing::internal::GetCapturedStdout();

    if (output != "[ \"a\", \"c\", \"e\" ]" && output != "[ \"a\", \"e\", \"c\" ]" &&
        output != "[ \"c\", \"a\", \"e\" ]" && output != "[ \"c\", \"e\", \"a\" ]" &&
        output != "[ \"e\", \"a\", \"c\" ]" && output != "[ \"e\", \"c\", \"a\" ]")
    {
        std::cout << "UNEXPECTED RESULT: \"" << output << "\"" << std::endl;

        FAIL();
    }

    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintUnorderedSetToStdoutSorted1)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::unordered_set<int> inputSet { 1, 5, 3 };

    htd::print(inputSet, true);

    ASSERT_EQ("[ 1, 3, 5 ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintUnorderedSetToStdoutSorted2)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    std::unordered_set<std::string> inputSet { "a", "e", "c" };

    htd::print(inputSet, true);

    ASSERT_EQ("[ \"a\", \"c\", \"e\" ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintHyperedgeToStdout1)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    htd::print(htd::Hyperedge(1, { 1, 5, 3, 5, 3 }));

    ASSERT_EQ("Hyperedge 1: [ 1, 5, 3, 5, 3 ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckPrintHyperedgeToStdout2)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    htd::print(htd::Hyperedge(3, { 1, 5, 3, 5, 3 }));

    ASSERT_EQ("Hyperedge 3: [ 1, 5, 3, 5, 3 ]", testing::internal::GetCapturedStdout());
    ASSERT_EQ("", testing::internal::GetCapturedStderr());
}

TEST(HelperTest, CheckSetUnion1)
{
    std::vector<int> input1 { 1, 3, 5 };
    std::vector<int> input2 { 0, 2, 4, 6 };

    std::vector<int> actualResult;

    std::vector<int> expectedResult { 0, 1, 2, 3, 4, 5, 6 };

    htd::set_union(input1, input2, actualResult);

    ASSERT_TRUE(actualResult == expectedResult);
}

TEST(HelperTest, CheckSetUnion2)
{
    std::vector<int> input1 { 0, 2, 4, 6 };
    std::vector<int> input2 { 1, 3, 5 };

    std::vector<int> actualResult;

    std::vector<int> expectedResult { 0, 1, 2, 3, 4, 5, 6 };

    htd::set_union(input1, input2, actualResult);

    ASSERT_TRUE(actualResult == expectedResult);
}

TEST(HelperTest, CheckSetUnion3)
{
    std::vector<int> input1 { 1, 3, 5 };
    std::vector<int> input2 { 0, 2, 4, 6 };

    std::vector<int> actualResult;

    std::vector<int> expectedResult { 1, 3, 5 };

    htd::set_union<int>(input1, input2, [](int value) { return (value % 2) == 1; }, actualResult);

    ASSERT_TRUE(actualResult == expectedResult);
}


TEST(HelperTest, CheckSetUnion4)
{
    std::vector<htd::vertex_t> input1 { 1, 3, 5 };
    std::vector<htd::vertex_t> input2 { 1, 2, 4, 6 };

    std::vector<htd::vertex_t> actualResult;

    std::vector<htd::vertex_t> expectedResult { 1, 2, 4, 5, 6 };

    htd::set_union(input1, input2, 3, actualResult);

    ASSERT_TRUE(actualResult == expectedResult);
}

TEST(HelperTest, CheckSetUnion5)
{
    std::vector<htd::vertex_t> input1 { 1, 3, 5 };
    std::vector<htd::vertex_t> input2 { 1, 2, 4, 6 };

    std::vector<htd::vertex_t> actualResult;

    std::vector<htd::vertex_t> expectedResult { 1, 2, 3, 4, 5, 6 };

    htd::set_union(input1, input2, 0, actualResult);

    ASSERT_TRUE(actualResult == expectedResult);
}

TEST(HelperTest, CheckSetUnion6)
{
    std::vector<htd::vertex_t> input1 { 1, 3, 5 };
    std::vector<htd::vertex_t> input2 { 1, 2, 4, 5, 6 };

    std::vector<htd::vertex_t> actualResult;

    std::vector<htd::vertex_t> expectedResult { 1, 2, 3, 4, 5, 6 };

    htd::set_union(input1, input2, 7, actualResult);

    ASSERT_TRUE(actualResult == expectedResult);
}

TEST(HelperTest, CheckSetUnion7)
{
    std::vector<htd::vertex_t> input1 { 1, 3, 5 };
    std::vector<htd::vertex_t> input2 { };

    std::vector<htd::vertex_t> actualResult;

    std::vector<htd::vertex_t> expectedResult { 1, 5 };

    htd::set_union(input1, input2, 3, actualResult);

    ASSERT_TRUE(actualResult == expectedResult);
}

TEST(HelperTest, CheckSetUnion8)
{
    std::vector<htd::vertex_t> input1 { 1, 3, 5 };
    std::vector<htd::vertex_t> input2 { 3 };

    std::vector<htd::vertex_t> actualResult;

    std::vector<htd::vertex_t> expectedResult { 1, 3, 5 };

    htd::set_union(input1, input2, 0, actualResult);

    ASSERT_TRUE(actualResult == expectedResult);
}

int main(int argc, char **argv)
{
    // coverity[GoogleTest may throw. This results in a non-zero exit code and is intended.]
    ::testing::InitGoogleTest(&argc, argv);

    // coverity[GoogleTest may throw. This results in a non-zero exit code and is intended.]
    return RUN_ALL_TESTS();
}
