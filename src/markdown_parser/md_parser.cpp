//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#include <stack>
#include <iostream>
#include "md_parser.h"
#include "regex_rules/regex_remplacement_rules.h"

std::string MarkdownParser::parse(const std::string &md_text) {
    std::string parsed_text;

    // first we parse the simple rules
    parsed_text = md_to_hmtl_simple_remplacement(md_text);

    // then we tokenize and parse for complex rules
    parsed_text = parseLists(parsed_text);


    return parsed_text;
}

/**
 * @brief Parse the markdown text and replace it in the go with the html equivalent for the simple rules
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent
 */
std::string MarkdownParser::md_to_hmtl_simple_remplacement(const std::string& md_text) {
    std::string parsed_text = md_text;

    parsed_text = parseHeaders(parsed_text);

    parsed_text = parseBold(parsed_text);
    parsed_text = parseItalic(parsed_text);
    parsed_text = parseStrikethrough(parsed_text);

    parsed_text = parseImages(parsed_text);
    parsed_text = parseLinks(parsed_text);

    return parsed_text;
}

/**
 * @brief Parse the headers of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the headers
 */
std::string MarkdownParser::parseHeaders(const std::string &md_text) {
    std::regex reg(regex_rules.h6.first);
    std::string parsed_text = parseItem(md_text, reg, regex_rules.h6.second);
    reg = std::regex(regex_rules.h5.first);
    parsed_text = parseItem(parsed_text, reg, regex_rules.h5.second);
    reg = std::regex(regex_rules.h4.first);
    parsed_text = parseItem(parsed_text, reg, regex_rules.h4.second);
    reg = std::regex(regex_rules.h3.first);
    parsed_text = parseItem(parsed_text, reg, regex_rules.h3.second);
    reg = std::regex(regex_rules.h2.first);
    parsed_text = parseItem(parsed_text, reg, regex_rules.h2.second);
    reg = std::regex(regex_rules.h1.first);
    parsed_text = parseItem(parsed_text, reg, regex_rules.h1.second);
    return parsed_text;
}

/**
 * @brief Parse the bold of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the bold
 */
std::string MarkdownParser::parseBold(const std::string &md_text) {
    std::regex reg(regex_rules.bold.first);
    return parseItem(md_text, reg, regex_rules.bold.second);
}

/**
 * @brief Parse the italic of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the italic
 */
std::string MarkdownParser::parseItalic(const std::string &md_text) {
    std::regex reg(regex_rules.italic.first);
    return parseItem(md_text, reg, regex_rules.italic.second);
}

/**
 * @brief Parse the strikethrough of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the strikethrough
 */
std::string MarkdownParser::parseStrikethrough(const std::string &md_text) {
    std::regex reg(regex_rules.strikethrough.first);
    return parseItem(md_text, reg, regex_rules.strikethrough.second);
}

/**
 * @brief Parse the links of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the links
 */
std::string MarkdownParser::parseLinks(const std::string &md_text) {
    std::regex reg(regex_rules.links.first);
    return parseItem(md_text, reg, regex_rules.links.second);
}

/**
 * @brief Parse the images of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the images
 */
std::string MarkdownParser::parseImages(const std::string &md_text) {
    std::regex reg(regex_rules.images.first);
    return parseItem(md_text, reg, regex_rules.images.second);
}


/**
 * @brief Parse the markdown text with the regex and replace it with the replacement
 *
 * @param md_text : The markdown text to parse
 * @param reg : The regex to use for the parsing
 * @param replacement : The replacement to use for the parsing
 * @return std::string : The parsed text
 */
std::string MarkdownParser::parseItem(const std::string&md_text, const std::regex& reg, const std::string& replacement) {
    return std::regex_replace(md_text, reg, replacement);
}


std::string MarkdownParser::parseLists(const std::string&md_text) {
    std::string parsed_text = md_text;

    parseTypedLists(md_text, token_rules.unordered_list);
    parsed_text = ListTokenToHtml();
    tokens.clear();

    parseTypedLists(parsed_text, token_rules.ordered_list);
    parsed_text = ListTokenToHtml();
    tokens.clear();

    parseTypedLists(parsed_text, token_rules.checklist);
    parsed_text = ListTokenToHtml();
    tokens.clear();
    return parsed_text;
}

void MarkdownParser::parseTypedLists(const std::string& md_text, const std::pair<const char *, TokenType>& token_rule) {
    std::regex reg(token_rule.first, std::regex_constants::multiline);

    std::sregex_iterator next(md_text.begin(),md_text.end(), reg);
    std::sregex_iterator end;

    int last_index = 0;
    for (; next != end; next++) {
        std::smatch match = *next;

        // non matched text
        if (match.position() > last_index) {
            std::string nonMatchedText = md_text.substr(last_index, match.position() - last_index);
            tokens.push_back(Token(nonMatchedText, TokenType::TEXT));
        }
        tokens.push_back({match.str(), token_rule.second});
        last_index = match.position() + match.length();
    }
    if (last_index < md_text.length()) {
        std::string nonMatchedText = md_text.substr(last_index, md_text.length() - last_index);
        tokens.push_back(Token(nonMatchedText, TokenType::TEXT));
    }

}

std::string MarkdownParser::ListTokenToHtml() {
    std::string final_string;
    for (auto &token : tokens) {
       switch (token.type) {
           case TokenType::UNORDERED_LIST:
               final_string += md_unordered_list_to_html(token.value);
               break;
           case TokenType::ORDERED_LIST:
                final_string += md_ordered_list_to_html(token.value);
                break;
           case TokenType::CHECKLIST:
               final_string += md_checklist_to_html(token.value);
               break;
           case TokenType::TEXT:
                final_string += token.value;
                break;
       }
    }
    return final_string;
}

std::string MarkdownParser::md_unordered_list_to_html(const std::string&md_text) {
    std::string final_string = "<ul>\n";
    std::smatch match;
    std::regex reg(R"(^[-\*\+]\s+(.+)$)", std::regex_constants::multiline);

    std::string::const_iterator searchStart( md_text.cbegin() );
    while (std::regex_search(searchStart, md_text.cend(), match, reg)) {
        final_string += "<li>" + match[1].str() + "</li>\n";
        searchStart = match.suffix().first;
    }

    final_string += "</ul>\n";
    return final_string;
}

std::string MarkdownParser::md_ordered_list_to_html(const std::string&md_text) {
    std::string final_string = "<ol>\n";
    std::smatch match;
    std::regex reg(R"(^\d+\.\s+(.+)$)", std::regex_constants::multiline);

    std::string::const_iterator searchStart( md_text.cbegin() );
    while (std::regex_search(searchStart, md_text.cend(), match, reg)) {
        final_string += "<li>" + match[1].str() + "</li>\n";
        searchStart = match.suffix().first;
    }
    final_string += "</ol>\n";
    return final_string;
}

std::string MarkdownParser::md_checklist_to_html(const std::string&md_text) {
    std::string final_string = "<ul>\n";
    std::smatch match;
    std::regex checkboxPattern("- \\[( |x|X)\\] (.*)");

    std::string remainingText = md_text;
    while (std::regex_search(remainingText, match, checkboxPattern)) {
        std::string checkbox = match[1].str();
        std::string text = match[2].str();
        std::string checked = checkbox == " " ? "" : "checked";
        final_string += "<li><input type=\"checkbox\" " + checked + ">" + text + "</li>\n";
        remainingText = match.suffix().str();
    }
    final_string += "</ul>\n";
    return final_string;
}
