//
// Created by alex on 16/02/24.
//

#include "HtmlToPdf.h"




int HtmlToPdf::convert_html_to_pdf(const std::string& html_content, const std::string& pdf_file) {

    // Write the HTML content to a temporary file
    std::string tempHtmlFile = "temp.html";
    std::ofstream outFile(tempHtmlFile);
    if (!outFile.is_open()) {
        std::cerr << "Failed to create temporary HTML file\n";
        return 1;
    }
    outFile << html_content;
    outFile.close();

    // Initialize the library
    if (!wkhtmltopdf_init(0)) {
        std::cerr << "Failed to initialize the library\n";
        return 1;
    }

    // Create a PDF object
    wkhtmltopdf_global_settings *globalSettings = wkhtmltopdf_create_global_settings();
    wkhtmltopdf_object_settings *objectSettings = wkhtmltopdf_create_object_settings();

    // Set up input and output
    wkhtmltopdf_set_global_setting(globalSettings, "out", pdf_file.c_str());
    wkhtmltopdf_set_object_setting(objectSettings, "page", tempHtmlFile.c_str());

    wkhtmltopdf_converter *converter = wkhtmltopdf_create_converter(globalSettings);

    // Add the HTML file to convert
    wkhtmltopdf_add_object(converter, objectSettings, NULL);

    // Convert the HTML file to PDF
    if (!wkhtmltopdf_convert(converter)) {
        std::cerr << "Conversion failed!\n";
        return 1;
    }

    // Cleanup
    wkhtmltopdf_destroy_converter(converter);
    wkhtmltopdf_deinit();

    // Remove temporary HTML file
    std::remove(tempHtmlFile.c_str());

    std::cout << "Conversion successful!\n";

    return 0;

    return 0;
}
