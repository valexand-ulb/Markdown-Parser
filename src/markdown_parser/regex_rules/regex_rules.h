//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#ifndef REGEX_RULES_H
#define REGEX_RULES_H
#include "../token/TokenType.h"

struct RegexRules {
    //  headers rules :
    std::pair<const char *, TokenType> h1 = {"# (.*)", TokenType::HEADER1};
    std::pair<const char *, TokenType> h2 = {"## (.*)", TokenType::HEADER2};
    std::pair<const char *, TokenType> h3 = {"### (.*)", TokenType::HEADER3};
    std::pair<const char *, TokenType> h4 = {"#### (.*)", TokenType::HEADER4};
    std::pair<const char *, TokenType> h5 = {"##### (.*)", TokenType::HEADER5};
    std::pair<const char *, TokenType> h6 = {"###### (.*)", TokenType::HEADER6};

    // bold, italic, strikethrough and paragraph rules :
    std::pair<const char *, TokenType> bold = {"/\\*\\*\\s?([^\n]+)\\*\\*/g", TokenType::BOLD};
    std::pair<const char *, TokenType> italic = {"\\*(.*?)\\*", TokenType::ITALIC};
    std::pair<const char *, TokenType> strikethrough = {"~~(.*?)~~", TokenType::STRIKETHROUGH};
    std::pair<const char *, TokenType> paragraph = {"(?:\n\n|^)(.*)", TokenType::PARAGRAPH};

    // links and images rules :
    std::pair<const char *, TokenType> links = {R"(\[([^\[]+)\]\(([^\)]+)\))", TokenType::LINKS};
    std::pair<const char *, TokenType> images = {R"(!\[(.*?)\]\((.*?)\))", TokenType::IMAGES};

    // lists rules :
    std::pair<const char *, TokenType> unorderedList = {R"(\s*\*\s+(.*)\n)", TokenType::UNORDERED_LIST};
    std::pair<const char *, TokenType> orderedList = {R"(\s*\d+\.\s+(.*)\n)", TokenType::ORDERED_LIST};
    std::pair<const char *, TokenType> checkListUnchecked = {R"(\s*\-\s+\[ \]\s+(.*)\n)", TokenType::CHECKLISTUNCHECKED};
    std::pair<const char *, TokenType> checkListChecked = {R"(\s*\-\s+\[x\]\s+(.*)\n)", TokenType::CHECKLISTCHECKED};
    // blockquotes and code blocks rules :

    // horizontal rules and escape characters rules :

    // inline code rules :

    // extended markdown parsing rules :
    // tables, footnotes and highlight rules :
    std::pair<const char *, TokenType> table = {"|(?:([^\r\n|]*)\\|)+\r?\n\\|(?:(:?-+:?)\\|)+\r?\n(\\|(?:([^\r\n|]*)\\|)+\r?\n)+", TokenType::TABLE};
};

#endif //REGEX_RULES_H
