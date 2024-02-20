//
// Created by alex on 17/02/24.
//

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>

#include "Token.h"


class Tokenizer {
public:
    void tokenize(const std::string& md_text);
    std::vector<Token> get_tokens() {return tokens_;}
private:
    std::vector<Token> tokens_;

};



#endif //TOKENIZER_H
