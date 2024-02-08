//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#ifndef REGEX_RULES_H
#define REGEX_RULES_H

struct RegexRules {
    //  headers rules :
    std::pair<const char *, const char *> h1 = {"# (.*)", "<h1>$1</h1>"};
    std::pair<const char *, const char *> h2 = {"## (.*)", "<h2>$1</h2>"};
    std::pair<const char *, const char *> h3 = {"### (.*)", "<h3>$1</h3>"};
    std::pair<const char *, const char *> h4 = {"#### (.*)", "<h4>$1</h4>"};
    std::pair<const char *, const char *> h5 = {"##### (.*)", "<h5>$1</h5>"};
    std::pair<const char *, const char *> h6 = {"###### (.*)", "<h6>$1</h6>"};

    // bold, italic, strikethrough and paragraph rules :
    std::pair<const char *, const char *> bold = {"/\\*\\*\\s?([^\n]+)\\*\\*/g", "<strong>$1</strong>"};
    std::pair<const char *, const char *> italic = {"\\*(.*?)\\*", "<em>$1</em>"};
    std::pair<const char *, const char *> strikethrough = {"~~(.*?)~~", "<del>$1</del>"};
    std::pair<const char *, const char *> paragraph = {"(?:\n\n|^)(.*)", "<p>$1</p>\n"};

    // links and images rules :
    std::pair<const char *, const char *> links = {R"(\[([^\[]+)\]\(([^\)]+)\))", "<a href=\"$2\">$1</a>"};
    std::pair<const char *, const char *> images = {R"(!\[(.*?)\]\((.*?)\))", R"(<img src="$2" alt="$1">)"};

    // lists rules :
    std::pair<const char *, const char *> unorderedList = {R"(\s*\*\s+(.*)\n)", "\n<li>$1</li>"};
    std::pair<const char *, const char *> orderedList = {R"(\s*\d+\.\s+(.*)\n)", "\n<li>$1</li>"};
    std::pair<const char *, const char *> checkListUnchecked = {R"(\s*\-\s+\[ \]\s+(.*)\n)", "\n<li><input type=\"checkbox\">$1</li>"};
    std::pair<const char *, const char *> checkListChecked = {R"(\s*\-\s+\[x\]\s+(.*)\n)", "\n<li><input type=\"checkbox\" checked>$1</li>"};
    // blockquotes and code blocks rules :

    // horizontal rules and escape characters rules :

    // inline code rules :

    // extended markdown parsing rules :
    // tables, footnotes and highlight rules :
    std::pair<const char *, const char *> table = {"|(?:([^\r\n|]*)\\|)+\r?\n\\|(?:(:?-+:?)\\|)+\r?\n(\\|(?:([^\r\n|]*)\\|)+\r?\n)+", "<table><tr><th>$1</th></tr><tr><td>$3</td></tr></table>"};
};

#endif //REGEX_RULES_H
