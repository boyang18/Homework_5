#include "gtest/gtest.h"
#include "possible_parentheses.h"

void showResult(std::list<std::string> & result) {
    for (std::list<std::string>::iterator i = result.begin(); i!=result.end(); ++i) {
        printf("%s\n", (*i).c_str());
    }
};

TEST(test_recursive, 0) {
    std::list<std::string> result;
    std::list<std::string> answer;
    possibleParenthesis(0, result);
    ASSERT_EQ(0, result.size());
    ASSERT_EQ(result,answer);
}

TEST(test_recursive, 1) {
 std::list<std::string> result;
    possibleParenthesis(1, result);
    std::list<std::string> answer;
    answer.push_back("{}");
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(result,answer);
}

TEST(test_recursive, 2) {
    std::list<std::string> result;
    possibleParenthesis(2, result);
    std::list<std::string> answer;
    answer.push_back("{}{}");
    answer.push_back("{{}}");
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(result,answer);

    // homework: add verification
}

TEST(test_recursive, 3) {
    std::list<std::string> result;
    std::list<std::string> answer;
    possibleParenthesis(3, result);
    answer.push_back("{}{}{}");
    answer.push_back("{}{{}}");
    answer.push_back("{{}}{}");
    answer.push_back("{{}{}}");
    answer.push_back("{{{}}}");
    ASSERT_EQ(5, result.size());
    ASSERT_EQ(result,answer);
    // homework: add verification
}

// and more
