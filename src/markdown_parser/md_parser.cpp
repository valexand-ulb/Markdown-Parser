//
// Created by Vinovrski Alexandre on 08/02/2024.
//

#include "md_parser.h"

std::string MarkdownParser::parse(const std::string &md_text) {
    std::string parsed_text;

    parsed_text = line_by_line_parsing(md_text);

    return parsed_text;
}

std::string MarkdownParser::line_by_line_parsing(const std::string& md_text) {

    std::istringstream md_text_stream(md_text);
    std::stringstream output_stream;
    std::string line;
    while (std::getline(md_text_stream, line)) {
        if (std::regex_search(line, std::regex(rules.HEADERS))) { // header mode
            parseHeaders(md_text_stream, output_stream, line);
        }
        else if (std::regex_search(line, std::regex(rules.HORIZONTAL_RULE))) { // horizontal rule mode
            std::cout << "Parsing horizontal rule..." << std::endl;
            output_stream << "<hr>" << std::endl;
        }
        else if (std::regex_search(line, std::regex(rules.BLOCKQUOTES))) {   // blockquote mode
            parseBlockQuotes(md_text_stream, output_stream, line);
        }
        else if (std::regex_search(line, std::regex(rules.CHECKLIST))) { // checklist mode
            parseCheckList(md_text_stream, output_stream, line);
        }
        else if (std::regex_search(line, std::regex(rules.ORDERED_LIST))) { // ordered list mode
            parseOrderedList(md_text_stream, output_stream, line);
        }
        else if (std::regex_search(line, std::regex(rules.UNORDERED_LIST))) { // unordered list mode
            parseUnorderedList(md_text_stream, output_stream, line);
        }
        else if (std::regex_search(line, std::regex(rules.TABLE))) { // table mode
            parseTable(md_text_stream, output_stream, line);
        }
        else if (std::regex_search(line, std::regex(rules.CODEBLOCK))) { // codeblock mode
            parseCodeBlock(md_text_stream, output_stream, line);
        }
        else if (std::regex_search(line, std::regex(rules.TEXT))){ // paragraph mode
            parseParagraph(md_text_stream, output_stream, line);
        }

    }
    return output_stream.str();
}

std::string MarkdownParser::parseTextElements(std::string& md_text_line) {
    // text modification
    md_text_line = std::regex_replace(md_text_line, std::regex(regex_rules.bold.first), regex_rules.bold.second);
    md_text_line = std::regex_replace(md_text_line, std::regex(regex_rules.italic.first), regex_rules.italic.second);
    md_text_line = std::regex_replace(md_text_line, std::regex(regex_rules.strikethrough.first), regex_rules.strikethrough.second);

    // links and images
    md_text_line = std::regex_replace(md_text_line, std::regex(regex_rules.images.first), regex_rules.images.second);
    md_text_line = std::regex_replace(md_text_line, std::regex(regex_rules.links.first), regex_rules.links.second);

    // inline code
    md_text_line = std::regex_replace(md_text_line, std::regex(regex_rules.inline_code.first), regex_rules.inline_code.second);

    // escaping characters
    md_text_line = std::regex_replace(md_text_line, std::regex(regex_rules.esape_characters.first), regex_rules.esape_characters.second);

    // line break
    //md_text_line = std::regex_replace(md_text_line, std::regex(regex_rules.line_break.first), regex_rules.line_break.second);

    return md_text_line;
}

void MarkdownParser::parseHeaders(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line) {
    std::cout << "Parsing headers..." << std::endl;

    unsigned short int header_level = 0;
    while (line[header_level] != ' ' && line[header_level] == '#') {
        header_level++;
    }
    std::string header_tag = "<h" + std::to_string(header_level) + ">";
    std::string header_text = line.substr(header_level+1);
    output_stream << header_tag + parseTextElements(header_text) + "</h" + std::to_string(header_level) + ">" << std::endl;
}

void MarkdownParser::parseBlockQuotes(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line) {
    std::cout << "Parsing blockquotes..." << std::endl;
    std::string terminaison_line = line;
    std::string blockquote_text = "<blockquote>\n";
    do {
        terminaison_line = terminaison_line.substr(2);
        blockquote_text += parseTextElements(terminaison_line) + "\n";
    } while(std::getline(md_text_stream,terminaison_line) && terminaison_line[0] == '>');
    blockquote_text += "</blockquote>\n";
    output_stream << blockquote_text << std::endl;
}

void MarkdownParser::parseCheckList(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line) {
    std::cout << "Parsing checklist..." << std::endl;
    std::string terminaison_line = line;
    std::string checklist_text = "<ul>\n";
    do {
        terminaison_line = terminaison_line.substr(2);
        if (terminaison_line[1] == 'x' || terminaison_line[1] == 'X') {
            terminaison_line = terminaison_line.substr(3);
            checklist_text += "<li><input type=\"checkbox\" checked>" + parseTextElements(terminaison_line) + "</li>\n";
        }
        else {
            terminaison_line = terminaison_line.substr(3);
            checklist_text += "<li><input type=\"checkbox\">" + parseTextElements(terminaison_line) + "</li>\n";
        }
    } while(std::getline(md_text_stream,terminaison_line) && terminaison_line[0] == '-');
    checklist_text += "</ul>\n";
    output_stream << checklist_text << std::endl;
}

void MarkdownParser::parseOrderedList(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line) {
    std::cout << "Parsing ordered list..." << std::endl;
    std::string terminaison_line = line;
    std::string ordered_list_text = "<ol>\n";
    do {
        terminaison_line = terminaison_line.substr(3); // remove the number, the dot and the space
        ordered_list_text += "<li>" + parseTextElements(terminaison_line) + "</li>\n";
    } while(std::getline(md_text_stream,terminaison_line) && !terminaison_line.empty());
    ordered_list_text += "</ol>\n";
    output_stream << ordered_list_text << std::endl;
}

void MarkdownParser::parseUnorderedList(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line) {
    std::cout << "Parsing unordered list..." << std::endl;
    std::string terminaison_line = line;
    std::string unordered_list_text = "<ul>\n";
    do {
        terminaison_line = terminaison_line.substr(2);
        unordered_list_text += "<li>" + parseTextElements(terminaison_line) + "</li>\n";
    } while(std::getline(md_text_stream,terminaison_line) && terminaison_line[0] == '-');
    unordered_list_text += "</ul>\n";
    output_stream << unordered_list_text << std::endl;
}

void MarkdownParser::parseTable(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line) {
    std::cout << "Parsing table..." << std::endl;
    std::string terminaison_line = line;
    std::string table_text = "<table>\n";
    unsigned short count_line = 0;
    do {
        if (count_line == 0) {
            table_text += "\t<tr>\n";
            std::string cell;
            std::istringstream line_stream(terminaison_line);
            while(std::getline(line_stream,cell,'|')){
                table_text += "\t\t<th>" + parseTextElements(cell) + "</th>\n";
            }
            table_text += "\t</tr>\n";
        }
        else if (count_line > 1) {
            table_text += "\t<tr>\n";
            std::string cell;
            std::istringstream line_stream(terminaison_line);
            while(std::getline(line_stream,cell,'|')){
                table_text += "\t\t<td>" + parseTextElements(cell) + "</td>\n";
            }
            table_text += "\t\t</tr>\n";
        }
        count_line++;

    } while(std::getline(md_text_stream,terminaison_line) && terminaison_line[0] == '|');
    table_text += "</table>\n";
    output_stream << table_text << std::endl;
}

void MarkdownParser::parseCodeBlock(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line) {
    std::cout << "Parsing code block..." << std::endl;
    std::string terminaison_line = line.substr(3);
    std::string codeblock_text;
    if (terminaison_line[0] == ' ') {
        codeblock_text = "<pre><code>\n";
    }
    else {
        codeblock_text = "<pre><code>" + terminaison_line + "\n";
    }
    while(std::getline(md_text_stream,terminaison_line) && terminaison_line != "```"){
        codeblock_text += terminaison_line + "\n";
    }
    codeblock_text += "</code></pre>\n";
    output_stream << codeblock_text << std::endl;
}

void MarkdownParser::parseParagraph(std::istringstream& md_text_stream, std::stringstream& output_stream, std::string& line) {
    std::cout << "Parsing paragraph..." << std::endl;
    std::string terminaison_line = line;
    std::string paragraph_text = "<p>\n";
    do {
        paragraph_text += parseTextElements(terminaison_line) + '\n';
    } while(std::getline(md_text_stream,terminaison_line) && !terminaison_line.empty());
    paragraph_text += "</p>\n";

    output_stream << paragraph_text << std::endl;
}