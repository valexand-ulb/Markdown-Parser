//
// Created by alex on 12/02/24.
//

#ifndef HTMLCONSTANTS_H
#define HTMLCONSTANTS_H
#include <string>

const std::string HTML_HEAD = "<!DOCTYPE html>\n"
                        "<html>\n"
                        "<head>\n"
                        "\t<link rel=\"stylesheet\" href=\"../../styles/retro.css\">"
                        "\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">"
                        "\t<title>Markdown Parser Benchmark</title>\n"
                        "</head>\n"
                        "<body>\n";

const std::string HTML_TAIL = "\n</body>\n</html>\n";

#endif //HTMLCONSTANTS_H
