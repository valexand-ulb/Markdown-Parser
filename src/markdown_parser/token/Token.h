//
// Created by Vinovrski Alexandre on 09/02/2024.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

#include "TokenType.h"

struct Token {
    std::string value;
    TokenType type;
};


#endif //TOKEN_H
