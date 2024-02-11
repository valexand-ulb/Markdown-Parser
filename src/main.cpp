#include <fstream>
#include <iostream>
#include <string>

#include "markdown_parser/md_parser.h"

#include <chrono>


int main()
{
    std::ifstream inputFile("../test/test.md");
    std::ofstream outputFile("../test/test.html");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file.\n";
        return 1;
    }

    std::stringstream buffer;

    buffer << inputFile.rdbuf();

    std::string markdownContent = buffer.str();

    // Close the input file
    inputFile.close();

    MarkdownParser md_parser;
    std::string content = md_parser.parse(markdownContent);
    outputFile << content;

    return 0;
}
