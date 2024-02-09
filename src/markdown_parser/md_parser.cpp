//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#include <stack>
#include <iostream>

#include "md_parser.h"
#include "regex_rules/regex_rules.h"

void MarkdownParser::parse(const std::string &md_text) {

    std::smatch match;
    std::stringstream stream(md_text);
    std::string line;

    while (std::getline(stream, line)) {
        if (std::regex_search(line, match, std::regex(regex_rules.h1.first))) {
            tokens.push({match.str(1), TokenType::HEADER1});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.h2.first))) {
            tokens.push({match.str(1), TokenType::HEADER2});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.h3.first))) {
            tokens.push({match.str(1), TokenType::HEADER3});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.h4.first))) {
            tokens.push({match.str(1), TokenType::HEADER4});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.h5.first))) {
            tokens.push({match.str(1), TokenType::HEADER5});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.h6.first))) {
            tokens.push({match.str(1), TokenType::HEADER6});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.bold.first))) {
            tokens.push({match.str(1), TokenType::BOLD});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.italic.first))) {
            tokens.push({match.str(1), TokenType::ITALIC});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.strikethrough.first))) {
            tokens.push({match.str(1), TokenType::STRIKETHROUGH});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.paragraph.first))) {
            tokens.push({match.str(1), TokenType::PARAGRAPH});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.links.first))) {
            tokens.push({match.str(1), TokenType::LINKS});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.images.first))) {
            tokens.push({match.str(1), TokenType::IMAGES});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.unorderedList.first))) {
            tokens.push({match.str(1), TokenType::UNORDERED_LIST});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.orderedList.first))) {
            tokens.push({match.str(1), TokenType::ORDERED_LIST});
        }
        else if (std::regex_search(line,match,std::regex(regex_rules.checkListUnchecked.first))) {
            tokens.push({match.str(1), TokenType::CHECKLISTUNCHECKED});
        }
    }
}

void MarkdownParser::printTokens() {
    while (!tokens.empty()) {
        std::cout << tokens.top().value << std::endl;
        tokens.pop();
    }
}

/*
std::string MarkdownParser::parseItem(const std::string&md_text, const std::regex& reg, const std::string& replacement) {
    return std::regex_replace(md_text, reg, replacement);
}


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

std::string MarkdownParser::parseBold(const std::string &md_text) {
    std::regex reg(regex_rules.bold.first);
    return parseItem(md_text, reg, regex_rules.bold.second);
}

std::string MarkdownParser::parseItalic(const std::string &md_text) {
    std::regex reg(regex_rules.italic.first);
    return parseItem(md_text, reg, regex_rules.italic.second);
}

std::string MarkdownParser::parseStrikethrough(const std::string &md_text) {
    std::regex reg(regex_rules.strikethrough.first);
    return parseItem(md_text, reg, regex_rules.strikethrough.second);
}

std::string MarkdownParser::parseParagraphs(const std::string&md_text) {
    std::regex reg(regex_rules.paragraph.first);
    return parseItem(md_text, reg, regex_rules.paragraph.second);
}

std::string MarkdownParser::parseLinks(const std::string &md_text) {
    std::regex reg(regex_rules.links.first);
    return parseItem(md_text, reg, regex_rules.links.second);
}

std::string MarkdownParser::parseImages(const std::string &md_text) {
    std::regex reg(regex_rules.images.first);
    return parseItem(md_text, reg, regex_rules.images.second);
}

std::string MarkdownParser::parseLists(const std::string &md_text) {
    std::string parsed_text = md_text;
    parsed_text = parseUnorderedList(md_text);
    parsed_text = parseOrderedList(parsed_text);
    parsed_text = parseCheckList(parsed_text);
    return parsed_text;
}

std::string MarkdownParser::parseUnorderedList(const std::string& md_text) {
    std::string parsed_text = parseItem(md_text, std::regex(regex_rules.unorderedList.first), regex_rules.unorderedList.second);

    enclosure(parsed_text, "<ul>\n", "</ul>\n");
    return parsed_text;
}

std::string MarkdownParser::parseOrderedList(const std::string &md_text) {
    std::string parsed_text = parseItem(md_text, std::regex(regex_rules.orderedList.first), regex_rules.orderedList.second);
    return parsed_text;
}

std::string MarkdownParser::parseCheckList(const std::string& md_text) {
    std::string parsed_text = parseItem(md_text, std::regex(regex_rules.checkListUnchecked.first), regex_rules.checkListUnchecked.second);
    parsed_text = parseItem(parsed_text, std::regex(regex_rules.checkListChecked.first), regex_rules.checkListChecked.second);
    return parsed_text;
}

std::string MarkdownParser::enclosure(const std::string&md_text, const std::string& first_tag, const std::string& second_tag) {
    std::regex li_regex("^<li>.*</li>$", std::regex_constants::icase | std::regex_constants::multiline);

    std::smatch match;
    std::string ul_block;

    // Find the biggest <li> block
    auto start = std::sregex_iterator(md_text.begin(), md_text.end(), li_regex);
    auto end = std::sregex_iterator();
    std::sregex_iterator biggest = start;
    for (std::sregex_iterator i = start; i != end; ++i) {
        if (i->str().size() > biggest->str().size()) {
            biggest = i;
        }
    }
    // Enclose the biggest <li> block in <ul></ul>
    ul_block += first_tag;
    ul_block += biggest->str();
    ul_block += second_tag;

    return ul_block;
}
*/