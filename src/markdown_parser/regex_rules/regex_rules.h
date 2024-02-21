//
// Created by alex on 20/02/24.
//

#ifndef REGEXRULES_H
#define REGEXRULES_H

struct RegexRules {
    const std::string HEADERS = "^#{1,6}";
    const std::string BLOCKQUOTES = R"(^(>))";
    const std::string CHECKLIST = R"(^\s*-\s+\[[ |x]\]\s)";
    const std::string ORDERED_LIST = R"(^\d+\.\s)";
    const std::string UNORDERED_LIST = R"(^[-\*\+]\s)";
    const std::string TABLE = R"(\|)";
    const std::string HORIZONTAL_RULE = R"(^(-{3,}|\*{3,}|_{3,}))";
    const std::string CODEBLOCK = "^```[a-zA-Z0-9]*.*";
    const std::string TEXT = "^.*\\S.*$";
};

#endif //REGEXRULES_H
