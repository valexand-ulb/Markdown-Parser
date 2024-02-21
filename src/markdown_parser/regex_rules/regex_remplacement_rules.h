//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#ifndef REGEX_RULES_H
#define REGEX_RULES_H

struct RegexRemplacementRules {
    // bold, italic, strikethrough and paragraph rules :
    std::pair<const char *, const char *> bold = {R"(\*\*\s?([^\n]+)\*\*)", "<strong>$1</strong>"};
    std::pair<const char *, const char *> italic = {R"(\*(.*?)\*)", "<em>$1</em>"};
    std::pair<const char *, const char *> strikethrough = {"~~(.*?)~~", "<del>$1</del>"};

    // links and images rules :
    std::pair<const char *, const char *> links = {R"(\[([^\[\]]+)\]\(([^()]+)\))", "<a href=\"$2\">$1</a>"};
    std::pair<const char *, const char *> images = {R"(!\[(.*?)\]\((.*?)\))", "<img src=\"$2\" alt=\"$1\">"};

    // blockquotes rules, inline code and horizontal rule rules :
    std::pair<const char *, const char *> inline_code = {"`([^`\n]+)`", "<code>$1</code>"};
};

#endif //REGEX_RULES_H
