//
// Created by alex on 16/02/24.
//

#ifndef HTMLTOPDF_H
#define HTMLTOPDF_H

#include <iostream>
#include <fstream>
#include <string>
#include <wkhtmltox/pdf.h>

class HtmlToPdf {
public:
    static int convert_html_to_pdf(const std::string& input_file, const std::string& output_file);
};



#endif //HTMLTOPDF_H
