//
// Created by alex on 20/02/24.
//

#ifndef REGEXRULES_H
#define REGEXRULES_H
#include <utility>

#include "TokenType.h"

struct RegexRules {
    const std::pair<const char *, TokenType> HEADERS = {"^#{1,6}", TokenType::HEADERS};
    const std::pair<const char *, TokenType> BLOCKQUOTES = {R"(^(>))", TokenType::BLOCKQUOTE};
    const std::pair<const char*, TokenType> CHECKLIST = {R"(^\s*-\s+\[[ |x]\]\s)", TokenType::CHECKLIST};
    const std::pair<const char *, TokenType> ORDERED_LIST = {R"(^\d+\.\s)", TokenType::ORDERED_LIST};
    const std::pair<const char *, TokenType> UNORDERED_LIST = {R"(^[-\*\+]\s)", TokenType::UNORDERED_LIST};
    const std::pair<const char *, TokenType> TABLE = {R"(\|)", TokenType::TABLE};
    const std::pair<const char *, TokenType> HORIZONTAL_RULE = {R"(^(-{3,}|\*{3,}|_{3,}))", TokenType::HORIZONTAL_RULE};
    const std::pair<const char *, TokenType> CODEBLOCK = {R"(^(```.*$|^```.+\n))", TokenType::INLINE_CODE};
};

#endif //REGEXRULES_H
