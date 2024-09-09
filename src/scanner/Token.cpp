#include <iostream>
#include "Token.h"
    std::ostream& operator<< (std::ostream &strm, const Token &t) {
    std::string output;
    switch (t.type){
        case (TokenType::OPENPAREN):        output = "OPENPAREN";               break;
        case( TokenType::CLOSEPAREN):       output = "CLOSEPAREN";              break;
        case( TokenType::OPENBRACE):        output = "OPENBRACE";               break;
        case( TokenType::CLOSEBRACE):       output = "CLOSEBRACE";              break;
        case( TokenType::COMMA):            output = "COMMA";                   break;
        case( TokenType::DOT):              output = "DOT";                     break;
        case( TokenType::MINUS):            output = "MINUS";                   break;
        case( TokenType::PLUS):             output = "PLUS";                    break;
        case( TokenType::SEMICOLON):        output = "SEMICOLON";               break;
        case( TokenType::SLASH):            output = "SLASH";                   break;
        case( TokenType::STAR):             output = "STAR";                    break;
        case( TokenType::BANG):             output = "BANG";                    break;
        case( TokenType::BANG_EQUAL):       output = "BANG_EQUAL";              break;
        case( TokenType::EQUAL):            output = "EQUAL";                   break;
        case( TokenType::EQUAL_EQUAL):      output = "EQUAL_EQUAL";             break;
        case( TokenType::GREATER):          output = "GREATER";                 break;
        case( TokenType::GREATER_EQUAL):    output = "GREATER_EQUAL";           break;
        case( TokenType::LESS):             output = "LESS";                    break;
        case( TokenType::LESS_EQUAL):       output = "LESS_EQUAL";              break;
        case( TokenType::IDENTIFIER):       output = "IDENTIFIER:" + t.lexeme;  break;
        case( TokenType::STRING):           output = "STRING:" + t.lexeme;      break;
        case( TokenType::DOUBLE):           output = "DOUBLE:" + std::to_string(t.literal.doublevalue);break;
        case( TokenType::LONG):             output = "LONG:" + std::to_string(t.literal.longvalue); break;
        case( TokenType::AND):              output = "AND";                     break;
        case( TokenType::CLASS):            output = "CLASS";                   break;
        case( TokenType::ELSE):             output = "ELSE";                    break;
        case( TokenType::FALSE):            output = "FALSE";                   break;
        case( TokenType::FUN):              output = "FUN";                     break;
        case( TokenType::FOR):              output = "FOR";                     break;
        case( TokenType::IF):               output = "IF";                      break;
        case( TokenType::NIL):              output = "NIL";                     break;
        case( TokenType::OR):               output = "OR";                      break;
        case( TokenType::PRINT):            output = "PRINT";                   break;
        case( TokenType::RETURN):           output = "RETURN";                  break;
        case( TokenType::SUPER):            output = "SUPER";                   break;
        case( TokenType::THIS):             output = "THIS";                    break;
        case( TokenType::VAR):              output = "VAR";                     break;
        case( TokenType::WHILE):            output = "WHILE";                   break;
        case( TokenType::TRUE):             output = "TRUE";                    break;
        case( TokenType::EOS):              output = "EOS";                     break;
    }
    return strm << output ; 
}