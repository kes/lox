#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include "scanner/Scanner.h"

void runFile(char** argv);
void runPrompt();
void run(std::string source);
std::string readStringFromFile(const std::string &file_path);

int main (int argc, char* argv[]){
    std::string help = "Usage: lox [script]";
    if (argc > 2){
        std::cerr << help << "\n";
        exit;
    }
    if (argc == 2 ){
        runFile(argv);
        return 0;
    }else{
        runPrompt();
        return 0;
    }
}

void runFile(char **argv){
    std::string f = argv[1];
    run(readStringFromFile(f));

}

std::string readStringFromFile(const std::string &file) {

    const std::ifstream inputStream(file, std::ios_base::binary);
    if (inputStream.fail()) {
        throw std::runtime_error("Error:Failed to open: " + file);
    }

    std::stringstream buffer;
    buffer << inputStream.rdbuf();
    return buffer.str();
}
void run (std::string source){
    Scanner scanner(source);
    std::list<Token> tokens = scanner.scanTokens();
    for (auto tok : tokens){
        std::cout << tok <<  "\n"; 
    }
}
void runPrompt(){
    for (;;){
        std::string input;
        std::cout << "\n> ";
        std::getline(std::cin, input);
        if (input.length() == 0) break;
        (run(input));
    }
}