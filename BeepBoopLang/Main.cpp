#include "Main.h"

int main()
{
    std::string source = ReadFile("Sample.BeepBoop"); // Got to add a thing to automaticly find all beepboop files

    Lexer lexer(source);

    RunLexer(lexer);

    return 0;
}

std::string ReadFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void RunLexer(Lexer &lexer)
{
    while (true)
    {
        // Get the next token from the lexer
        Token token = lexer.NextToken();

        auto it = dictionary.find(token.value);

        // Print the token value to the console
        if (token.type == TokenType::BeepBoops)
        {
            std::cout << "BeepBoops: " << token.value << std::endl;
            TranslateCommand(token);
        }
        else if (token.type == TokenType::Number)
        {
            std::cout << "Number: " << token.value << std::endl;
        }
        else if (token.type == TokenType::String)
        {
            std::cout << "String: " << token.value << std::endl;
        }

        else if (token.type == TokenType::Semicolon)
        {
            std::cout << "Semicolon" << std::endl;
        }
        else if (token.type == TokenType::Unknown)
            std::cout << "Unknown token: " << token.value << std::endl;

        // End loop
        if (token.type == TokenType::EndOfFile)
            break;
    }
}

void TranslateCommand(const Token &token)
{
    if (token.type == TokenType::BeepBoops)
    {
        auto it = dictionary.find(token.value);

        if (it != dictionary.end())
        {
            switch (it->second)
            {
            case Command::Print:

                std::cout << "Print command found" << std::endl;
                break;

            case Command::Variable:
                std::cout << "Variable command found" << std::endl;
                break;

            case Command::If:
                std::cout << "If command found" << std::endl;
                break;

            default:
                break;
            }
        }
    }
}
