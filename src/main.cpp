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

    std::ofstream outputFile("../test/result.html");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file.\n";
        return 1;
    }

    outputFile << "<!DOCTYPE html>\n"
                 "<html>\n"
                 "<head>\n"
                 "<title>Markdown to HTML</title>\n"
                 "</head>\n"
                 "<body>\n";

    MarkdownParser md_parser;

    outputFile << md_parser.parse(markdownContent) << "\n";

    outputFile << "</body>\n"
                  "</html>\n";

    return 0;
}
