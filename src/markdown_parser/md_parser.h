//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#ifndef MD_INTERPRETER_H
#define MD_INTERPRETER_H

#include <regex>

#include "regex_rules/regex_rules.h"


class MarkdownParser {

public:

    std::string parse(const std::string &md_text);

private:
    RegexRules regex_rules;

    // base markdown parsing

    std::string parseHeaders(const std::string& md_text);

    std::string parseBold(const std::string& md_text);

    std::string parseItalic(const std::string& md_text);

    std::string parseStrikethrough(const std::string& md_text);

    std::string parseParagraphs(const std::string& md_text);

    std::string parseLinks(const std::string& md_text);

    std::string parseImages(const std::string& md_text);

    std::string parseLists(const std::string& md_text); // unordered and ordered lists

    std::string parseUnorderedList(const std::string& md_text);

    std::string parseOrderedList(const std::string& md_text);

    std::string parseCheckList(const std::string& md_text);

    std::string parseBlockQuotes(const std::string& md_text);

    std::string parseCodeBlocks(const std::string& md_text);

    std::string parseHorizontalRules(const std::string& md_text);

    std::string parseEscapeCharacters(const std::string& md_text);

    std::string parseInlineCode(const std::string& md_text);

    // extended markdown parsing

    std::string parseTables(const std::string& md_text);

    std::string parseFootnotes(const std::string& md_text);

    std::string parseHighlight(const std::string& md_text);

    // generic parsing

    std::string parseItem(const std::string& md_text, const std::regex& reg, const std::string& replacement);

    // Enclosure of htlm tags
    std::string enclosure(const std::string& md_text, const std::string& first_tag, const std::string& second_tag);
};



#endif //MD_INTERPRETER_H
