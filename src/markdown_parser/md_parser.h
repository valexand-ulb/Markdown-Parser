//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#ifndef MD_INTERPRETER_H
#define MD_INTERPRETER_H

#include <regex>
#include <vector>

#include "regex_rules/regex_remplacement_rules.h"
#include "regex_rules/regex_token_rules.h"
#include "token/Token.h"


class MarkdownParser {

public:
    std::string parse(const std::string &md_text);

private:
    RegexRemplacementRules regex_rules;
    RegexTokenRules token_rules;
    std::vector<Token> tokens;

    // base markdown parsing : one line elements with direct replacement

    std::string parseHeaders(const std::string& md_text);

    std::string parseBold(const std::string& md_text);

    std::string parseItalic(const std::string& md_text);

    std::string parseStrikethrough(const std::string& md_text);

    std::string parseLinks(const std::string& md_text);

    std::string parseImages(const std::string& md_text);

    // complex markdown parsing : multi line elements with no direct replacement

    std::string parseLists(const std::string& md_text);

    std::string parseTypedLists(const std::string& md_text, const std::pair<const char *, TokenType>& token_rule);




    // generic parsing

    std::string parseItem(const std::string& md_text, const std::regex& reg, const std::string& replacement);

    std::string md_to_hmtl_simple_remplacement(const std::string&md_text);

};





#endif //MD_INTERPRETER_H
