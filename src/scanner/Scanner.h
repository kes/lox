#ifndef SCANNER
#define SCANNER
#include <iostream>
#include <list>
#include <unordered_map>
#include "Token.h"

class Scanner {
    public:
        Scanner(std::string s) {source = s;}
        std::list<Token> scanTokens();
    private:
        bool commentMode;
        int current = 0;
        int line = 1;
        std::string source;
        int start = 0;

        std::unordered_map<std::string, TokenType> keywords = {
            {"and", TokenType::AND},
            {"class", TokenType::CLASS},
            {"else", TokenType::ELSE},
            {"false", TokenType::FALSE},
            {"for", TokenType::FOR},
            {"fun", TokenType::FUN},
            {"if", TokenType::IF},
            {"nil", TokenType::NIL},
            {"or", TokenType::OR},
            {"print", TokenType::PRINT},
            {"return", TokenType::RETURN},
            {"super", TokenType::SUPER},
            {"this", TokenType::THIS},
            {"true", TokenType::TRUE},
            {"var", TokenType::VAR},
            {"while", TokenType::WHILE}
        };

        std::list<Token> tokens;
        void addToken(TokenType tt);
        void addToken(TokenType tt, long l);
        void addToken(TokenType tt, double d);
        void addToken(TokenType ttype, std::string s, long l, int line);
        char advance();
        void identifier();
        bool isAtEnd();
        bool match (char expected);
        void number();
        char peek();
        char peekNext();
        void scanToken();
        
};
#endif