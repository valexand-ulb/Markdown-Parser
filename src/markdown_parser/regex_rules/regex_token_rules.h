//
// Created by Vinovrski Alexandre on 10/02/2024.
//

#ifndef REGEX_TOKEN_RULES_H
#define REGEX_TOKEN_RULES_H

#include <utility>

#include "../token/TokenType.h"

struct RegexTokenRules{
    std::pair<const char *, TokenType> headers = {"^#{1,6}", TokenType::HEADERS};
    std::pair<const char *, TokenType> unordered_list= {R"((^\s*\*\s+.+\n?)+)", TokenType::UNORDERED_LIST};
    std::pair<const char *, TokenType> ordered_list= {R"((^\s*\d+\.\s+.+\n?)+)", TokenType::ORDERED_LIST};
    std::pair<const char *, TokenType> checklist= {R"((^\s*-\s+\[[ x]\]\s+.+$\s*)+)", TokenType::CHECKLIST};
    std::pair<const char *, TokenType> table = {R"(\|(.+?)\|(.+?)\|\n((\|.+?\|\n)+))", TokenType::TABLE};
};

#endif //REGEX_TOKEN_RULES_H
