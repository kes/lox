#include "Scanner.h"

std::list<Token> Scanner::scanTokens(){
    while (!isAtEnd()){
        start = current;

        scanToken();

    }
    addToken(TokenType::EOS, "", 0, line);
    return tokens;
}
void Scanner::scanToken(){
    char c = advance();
    switch(c){
        case('('):
            addToken(TokenType::OPENPAREN);
            break;
        case (')'):
            addToken(TokenType::CLOSEPAREN);
            break;
        case ('{'):
            addToken(TokenType::OPENBRACE);
            break;
        case ('}'):
            addToken(TokenType::CLOSEBRACE);
            break;
        case (';'):
            addToken(TokenType::SEMICOLON);
            break;
        case ('/'):
            if (match('/')){
                // this handles slashslash comments
                while(peek() != '\n' && !isAtEnd()) advance();
            }else{
                if (match('*')){
                    commentMode = true;
                    // handles slash star comments
                    // we need to see */ to get out of it
                    // if the coder tries to put comments in comments?? 
                    // too bad, we're out on the first */
                    do{
                        if (match('*')){
                            // perhaps the end of the comment
                            if (match('/')){
                                // yup the end of the comment
                                commentMode = false;
                            }else{
                                // nope not at end of a comment
                                // throw away this character
                                advance();
                            }
                        }else{
                            // not even close to the end of the comment
                           if (match('\n')){
                                ++line;
                            }else{
                                if (isAtEnd()) {
                                    // this should not happen -- we at the end of 
                                    // the source in a comment..? maybe it could happen
                                    commentMode = false;
                                }
                                else
                                    // throw away this character
                                    advance();
                            }
                        }
                    }while(commentMode);    
                }else{
                    addToken(TokenType::SLASH);
                }
                
            }
            break;
        case(' '):
        case('\t'):
        case('\r'):
            break;
        case('\n'):
            ++line;
            break;
        default:
            if (std::isdigit(c)){
                number();
            }else if (std::isalpha(c)){
                identifier();

            }else
                std::cout << "Scanner Error: Line:" << line << "\n";
    }
}
void Scanner::addToken(TokenType ttype){
    addToken(ttype, (long) 0);
}
void Scanner::addToken(TokenType ttype, long l){
    std::string text = source.substr(start, current-start);
    Token newToken(ttype, text, l, line);
    tokens.push_back(newToken);
}
void Scanner::addToken(TokenType ttype, double d){
    std::string text = source.substr(start, current-start);
    Token newToken(ttype, text, d, line);
    tokens.push_back(newToken);
}
void Scanner::addToken(TokenType ttype, std::string s, long l, int line){
    Token newToken(ttype, s, l, line);
    tokens.push_back(newToken);
}
char Scanner::advance(){
    return source[current++];

}
void Scanner::identifier(){
    while (isalnum(peek() )) {
        advance() ;
    }
    std::string text = source.substr(start, current-start);
    TokenType ttype = keywords[text];
    if (!ttype) ttype = TokenType::IDENTIFIER;
    addToken(ttype);
}
bool Scanner::isAtEnd(){
    return current >= source.length();
}
bool Scanner::match(char expected){
    if (isAtEnd()) return false;
    if (source[current] != expected) return false;
    ++current;
    return true;
}
void Scanner::number(){
    while(std::isdigit(peek())) advance();

    if ((peek() == '.') && (std::isdigit(peekNext()))) {
        advance();
        while(std::isdigit(peek())) advance() ;
        double d; std::stod(source.substr(start, current-start));
        addToken(TokenType::DOUBLE, d);
    }else{
        long l = std::stoi(source.substr(start, current-start));
        addToken(TokenType::LONG, l);
    }
}
char Scanner::peek(){
    if (isAtEnd()) return '\0';
    return source[current]; //noitce we do not advance. 
}
char Scanner::peekNext(){
    if (current + 1 >= source.length()) return '\0';
    return source[current + 1]; // and notice we do not advance
}

