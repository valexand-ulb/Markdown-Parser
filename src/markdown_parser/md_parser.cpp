//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#include "md_parser.h"

#include <iostream>
#include <iomanip>

#include "token/Token.h"
#include "regex_rules/regex_remplacement_rules.h"


std::string MarkdownParser::parse(const std::string &md_text) {
    std::string parsed_text;

    // first we parse the simple rules
    parsed_text = md_to_hmtl_simple_remplacement(md_text);

    // then we tokenize and parse for complex rules
    parsed_text = parseLists(parsed_text);

    parsed_text = parseAllTable(parsed_text);

    return parsed_text;
}

/**
 * @brief Parse the markdown text and replace it in the go with the html equivalent for the simple rules
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent
 */
std::string MarkdownParser::md_to_hmtl_simple_remplacement(const std::string& md_text) {
    std::string parsed_text;
    parsed_text = parseHeaders(md_text);

    parsed_text = parseHorizontalRule(parsed_text);

    parsed_text = parseBold(parsed_text);
    parsed_text = parseItalic(parsed_text);
    parsed_text = parseStrikethrough(parsed_text);

    parsed_text = parseImages(parsed_text);
    parsed_text = parseLinks(parsed_text);

    parsed_text = parseBlockquotes(parsed_text);
    parsed_text = parseCodeBlock(parsed_text);
    parsed_text = parseInlineCode(parsed_text);

    return parsed_text;
}

/**
 * @brief Parse the headers of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the headers
 */
std::string MarkdownParser::parseHeaders(const std::string &md_text) {
    std::cout << "Parsing headers..." << std::endl;
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
    std::cout << "Parsing bold..." << std::endl;
    const std::regex reg(regex_rules.bold.first);
    return parseItem(md_text, reg, regex_rules.bold.second);
}

/**
 * @brief Parse the italic of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the italic
 */
std::string MarkdownParser::parseItalic(const std::string &md_text) {
    std::cout << "Parsing italic..." << std::endl;
    const std::regex reg(regex_rules.italic.first);
    return parseItem(md_text, reg, regex_rules.italic.second);
}

/**
 * @brief Parse the strikethrough of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the strikethrough
 */
std::string MarkdownParser::parseStrikethrough(const std::string &md_text) {
    std::cout << "Parsing strikethrough..." << std::endl;
    const std::regex reg(regex_rules.strikethrough.first);
    return parseItem(md_text, reg, regex_rules.strikethrough.second);
}

/**
 * @brief Parse the links of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the links
 */
std::string MarkdownParser::parseLinks(const std::string &md_text) {
    std::cout << "Parsing links..." << std::endl;
    const std::regex reg(regex_rules.links.first);
    return parseItem(md_text, reg, regex_rules.links.second);
}

/**
 * @brief Parse the images of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the images
 */
std::string MarkdownParser::parseImages(const std::string &md_text) {
    std::cout << "Parsing images..." << std::endl;
    const std::regex reg(regex_rules.images.first);
    return parseItem(md_text, reg, regex_rules.images.second);
}

/**
 * @brief Parse the blockquotes of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the blockquotes
 */
std::string MarkdownParser::parseBlockquotes(const std::string &md_text) {
    std::cout << "Parsing blockquotes..." << std::endl;
    const std::regex reg(regex_rules.blockquotes.first, std::regex_constants::multiline);
    return parseItem(md_text, reg, regex_rules.blockquotes.second);
}

/**
 * @brief Parse the code block of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the code block
 */
std::string MarkdownParser::parseCodeBlock(const std::string&md_text) {
    std::cout << "Parsing code block..." << std::endl;
    const std::regex reg(regex_rules.code_block.first, std::regex_constants::multiline);
    return parseItem(md_text, reg, regex_rules.code_block.second);
}

/**
 * @brief Parse the inline code of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the inline code
 */
std::string MarkdownParser::parseInlineCode(const std::string &md_text) {
    std::cout << "Parsing inline code..." << std::endl;
    const std::regex reg(regex_rules.inline_code.first);
    return parseItem(md_text, reg, regex_rules.inline_code.second);
}

/**
 * @brief Parse the horizontal rule of the markdown text
 *
 * @param md_text : The markdown text to parse
 * @return std::string : The parsed text with the html equivalent for the horizontal rule
 */
std::string MarkdownParser::parseHorizontalRule(const std::string& md_text) {
    std::cout << "Parsing horizontal rule..." << std::endl;
    const std::regex reg(regex_rules.horizontal_rule.first, std::regex_constants::multiline);
    return parseItem(md_text, reg, regex_rules.horizontal_rule.second);
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
    switch (token_rule.second) {
        case TokenType::UNORDERED_LIST:
            std::cout << "Parsing unordered list..." << std::endl;
            break;
        case TokenType::ORDERED_LIST:
            std::cout << "Parsing ordered list..." << std::endl;
            break;
        case TokenType::CHECKLIST:
            std::cout << "Parsing checklist..." << std::endl;
            break;
        default:
            break;
    }
    std::regex reg(token_rule.first, std::regex_constants::multiline);

    std::sregex_iterator next(md_text.begin(),md_text.end(), reg);
    std::sregex_iterator end;

    int last_index = 0;
    for (; next != end; ++next) {
        std::smatch match = *next;

        // non matched text
        if (match.position() > last_index) {
            std::string nonMatchedText = md_text.substr(last_index, match.position() - last_index);
            tokens.push_back(Token{nonMatchedText, TokenType::TEXT});
        }
        tokens.push_back({match.str(), token_rule.second});
        last_index = match.position() + match.length();
    }
    if (last_index < md_text.length()) {
        std::string nonMatchedText = md_text.substr(last_index, md_text.length() - last_index);
        tokens.push_back(Token{nonMatchedText, TokenType::TEXT});
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
        final_string += "\t<li>" + match[1].str() + "</li>\n";
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
        final_string += "\t<li>" + match[1].str() + "</li>\n";
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
        final_string += "\t<li><input type=\"checkbox\" " + checked + ">" + text + "</li>\n";
        remainingText = match.suffix().str();
    }
    final_string += "</ul>\n";
    return final_string;
}

std::string MarkdownParser::parseAllTable(const std::string& md_text) {
    std::cout << "Parsing table..." << std::endl;
    parseTable(md_text);
    std::string parsed_text;

    for (Token token: tokens) {
        if (token.type == TokenType::TABLE) {
            parsed_text += md_table_to_html(token.value);
        }
        else {
            parsed_text += token.value;
        }
    }
    tokens.clear();
    return parsed_text;
}

void MarkdownParser::parseTable(const std::string&md_text) {
    const std::regex reg(token_rules.table.first, std::regex_constants::multiline);

    std::sregex_iterator next(md_text.begin(),md_text.end(), reg);
    std::sregex_iterator end;

    int last_index = 0;
    for (; next != end; ++next) {
        std::smatch match = *next;

        // non matched text
        if (match.position() > last_index) {
            const std::string nonMatchedText = md_text.substr(last_index, match.position() - last_index);
            tokens.push_back(Token{nonMatchedText, TokenType::TEXT});
        }
        tokens.push_back({match.str(), TokenType::TABLE});
        last_index = match.position() + match.length();
    }
    if (last_index < md_text.length()) {
        const std::string nonMatchedText = md_text.substr(last_index, md_text.length() - last_index);
        tokens.push_back(Token{nonMatchedText, TokenType::TEXT});
    }
}

std::string MarkdownParser::md_table_to_html(const std::string& md_text) {
    std::string final_string = "<table>\n";
    std::vector<std::vector<std::string>> rows;

    // Define regex patterns
    std::regex rowRegex("\\|(.+?)\\|");
    std::regex cellRegex("\\s*([^|]+)\\s*");

    std::istringstream markdownStream(md_text);
    std::string line;

    while (std::getline(markdownStream, line)) {
        std::vector<std::string> cells;
        auto cellBegin = std::sregex_iterator(line.begin(), line.end(), cellRegex);
        auto cellEnd = std::sregex_iterator();

        for (auto it = cellBegin; it != cellEnd; ++it) {
            cells.push_back((*it)[1]);
        }

        if (!cells.empty()) {
            rows.push_back(cells);
        }
    }

    for (const auto& row : rows) {
        final_string += "\t<tr>\n";
        for (const auto& cell : row) {
            final_string += "\t\t<td>" + cell + "</td>\n";
        }
        final_string += "\t</tr>\n";
    }
    final_string += "</table>\n";
    return final_string;
}

