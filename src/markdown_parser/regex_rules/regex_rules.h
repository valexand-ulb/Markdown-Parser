//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#ifndef REGEX_RULES_H
#define REGEX_RULES_H
#include "../token/TokenType.h"

struct RegexRules {
    //  headers rules :
    std::pair<const char *, const char *> h1 = {"# (.*)", "<h1>$1</h1>"};
    std::pair<const char *, const char *> h2 = {"## (.*)", "<h2>$1</h2>"};
    std::pair<const char *, const char *> h3 = {"### (.*)", "<h3>$1</h3>"};
    std::pair<const char *, const char *> h4 = {"#### (.*)", "<h4>$1</h4>"};
    std::pair<const char *, const char *> h5 = {"##### (.*)", "<h5>$1</h5>"};
    std::pair<const char *, const char *> h6 = {"###### (.*)", "<h6>$1</h6>"};

    // bold, italic, strikethrough and paragraph rules :
    std::pair<const char *, const char *> bold = {R"(\*\*\s?([^\n]+)\*\*)", "<strong>$1</strong>"};
    std::pair<const char *, const char *> italic = {R"(\*(.*?)\*)", "<em>$1</em>"};
    std::pair<const char *, const char *> strikethrough = {"~~(.*?)~~", "<del>$1</del>"};
    std::pair<const char *, const char *> paragraph = {"(?:\n\n|^)(.*)", "<p>$1</p>"};

    // links and images rules :
    std::pair<const char *, const char *> links = {R"(\[([^\[]+)\]\(([^\)]+)\))", "<a href=\"$2\">$1</a>"};
    std::pair<const char *, const char *> images = {R"(!\[(.*?)\]\((.*?)\))", "<img src=\"$2\" alt=\"$1\">"};
};

#endif //REGEX_RULES_H
