#include <fstream>
#include <iostream>
#include <string>

#include "markdown_parser/md_parser.h"
#include "pdf_conversion/HtmlToPdf.h"
#include "benchmark/Benchmark.h"
#include "html_utlis/HtmlUtils.h"


int main()
{
    Benchmark benchmark;
    std::ifstream inputFile("test/test.md");
    std::ofstream outputFile("test/test.html");

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
    //std::string content = md_parser.parse(markdownContent);
    std::string content = benchmark.execute_parsing_function(md_parser);
    outputFile << HtmlUtils::get_html_head();
    outputFile << content;
    outputFile << HtmlUtils::get_html_tail();

    HtmlToPdf::convert_html_to_pdf(content, "test/test.pdf");
    outputFile.close();

    return 0;
}
