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

    std::string parseLinks(const std::string& md_text);

    std::string parseImages(const std::string& md_text);

    // generic parsing

    std::string parseItem(const std::string& md_text, const std::regex& reg, const std::string& replacement);

    std::string md_to_hmtl_simple_remplacement(const std::string&md_text);

};





#endif //MD_INTERPRETER_H
