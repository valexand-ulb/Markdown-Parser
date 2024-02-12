//
// Created by alex on 12/02/24.
//

#include "Benchmark.h"

#include "md_parser.h"


void Benchmark::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

void Benchmark::end() {
    end_time = std::chrono::high_resolution_clock::now();
}

void Benchmark::print_elapsed_time() {
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time).count() << "ms\n";
}

std::string Benchmark::get_html_head() {
    std::string head = "<!DOCTYPE html>\n";
    head += "<html>\n";
    head += "<head>\n";
    head += "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">";

    head += "<title>Markdown Parser Benchmark</title>\n";
    head += "</head>\n";
    head += "<body>\n";
    return head;
}

std::string Benchmark::execute_parsing_function(MarkdownParser parser) {
    std::ifstream inputFile("test/" + file_name);
    std::ofstream outputFile("test/benchmark.html");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file.\n";
        return "Error: Unable to open input file.\n";
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file.\n";
        return "Error: Unable to open output file.\n";
    }

    std::stringstream buffer;

    buffer << inputFile.rdbuf();

    std::string markdownContent = buffer.str();

    // Close the input file
    inputFile.close();

    start();
    std::string content = parser.parse(markdownContent);
    end();

    outputFile << HtmlUtils::get_html_head();
    outputFile << content;
    outputFile << HtmlUtils::get_html_tail();
    outputFile.close();

    print_elapsed_time();
    return content;
}
