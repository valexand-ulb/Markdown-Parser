#include <fstream>
#include <iostream>
#include <string>

#include "markdown_parser/md_parser.h"



int main()
{
    std::ifstream inputFile("../test/test.md");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    std::stringstream buffer;

    buffer << inputFile.rdbuf();

    std::string markdownContent = buffer.str();

    // Close the input file
    inputFile.close();

    MarkdownParser md_parser;

    md_parser.parse(markdownContent);
    md_parser.printTokens();
    return 0;
}
