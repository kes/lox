#ifndef TOKEN
#define TOKEN
#include <iostream>
enum TokenType  {
    // single character
    OPENPAREN,
    CLOSEPAREN,
    OPENBRACE,
    CLOSEBRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,
    // one or two character    
    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,
    // literals
    IDENTIFIER,
    STRING,
    LONG, 
    DOUBLE,

    // keywords
    AND,
    CLASS,
    ELSE,
    FALSE,
    FUN,
    FOR,
    IF,
    NIL,
    OR,
    PRINT,
    RETURN,
    SUPER,
    THIS,
    VAR,
    WHILE,
    TRUE,
    EOS, // End of Source
};
struct Token{
    Token(TokenType t, std::string l, double d, int ln) : type(t), lexeme(l), literal(d), line(ln) {};
    Token(TokenType t, std::string l, long lt, int ln) : type(t), lexeme(l), literal(lt), line(ln) {};
    const TokenType type;
    const std::string lexeme;
    const union number {
        number(long l) : longvalue(l) {};
        number(double d) : doublevalue(d) {};
        long longvalue; 
        double doublevalue; 
    } literal;
    const int line;

    
};
std::ostream& operator<< (std::ostream &strm, const Token &t) ;

#endif