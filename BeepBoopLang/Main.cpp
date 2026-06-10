#include "Lexer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string ReadFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main()
{
    std::string source = ReadFile("Sample.BeepBoop"); // Got to add a thing to automaticly find all beepboop files

    Lexer lexer(source);

    while (true)
    {
        // Get the next token from the lexer
        Token token = lexer.NextToken();

        // Print the token value to the console
        if (token.type == TokenType::Identifier)
            std::cout << "Identifier: " << token.value << std::endl;
        else if (token.type == TokenType::Number)
            std::cout << "Number: " << token.value << std::endl;
        else if (token.type == TokenType::String)
            std::cout << "String: " << token.value << std::endl;
        else if (token.type == TokenType::Semicolon)
            std::cout << "Semicolon" << std::endl;
        else if (token.type == TokenType::Unknown)
            std::cout << "Unknown token: " << token.value << std::endl;

        // End loop
        if (token.type == TokenType::EndOfFile)
            break;
    }

    return 0;
}
