#include <iostream>

#include "markdown_parser/md_parser.h"

int main()
{
    std::string markdown = R"(# Heading 1

## Heading 2

This is a paragraph with some **bold** and *italic* text.

There is also some ~~strikethrough~~ text.

And also ***bold italic*** text.

* Unordered List Item 1
* Unordered List Item 2

1. Ordered List Item 1
2. Ordered List Item 2

![Alt text](image.jpg)

[Link Text](https://www.example.com)
)";
    MarkdownParser md_parser;
    std::cout << md_parser.parse(markdown) << std::endl;
    return 0;
}
