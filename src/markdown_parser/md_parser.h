//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#ifndef MD_INTERPRETER_H
#define MD_INTERPRETER_H

#include <regex>
#include <vector>
#include <iostream>
#include <iomanip>

#include "RegexRules.h"
#include "token/Token.h"
#include "regex_rules/regex_remplacement_rules.h"
#include "regex_rules/regex_token_rules.h"


class MarkdownParser {

public:

    std::string parse(const std::string &md_text);

    std::string line_by_line_parsing(const std::string &md_text);

private:
    RegexRules rules;
    RegexRemplacementRules regex_rules;
    RegexTokenRules token_rules;
    std::vector<Token> tokens;

    std::string parseHeaders(const std::string& md_line_text);

    void parseHeaders(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line);

    void parseBlockQuotes(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line);

    void parseCheckList(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line);

    void parseOrderedList(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line);

    void parseUnorderedList(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line);

    void parseTable(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line);

    void parseCodeBlock(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line);

    void parseParagraph(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line);

    std::string parseTextElements(std::string& md_text_line);

};





#endif //MD_INTERPRETER_H
