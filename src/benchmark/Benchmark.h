//
// Created by alex on 12/02/24.
//

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "../markdown_parser/md_parser.h"
#include "../html_utlis/HtmlUtils.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <sstream>

class Benchmark {
    const std::string file_name = "benchmark.md";

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;

    std::string get_html_head();

    void start();
    void end();
    void print_elapsed_time();
public:

    std::string execute_parsing_function(MarkdownParser parser);
};



#endif //BENCHMARK_H
