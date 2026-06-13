#include "Lexer.h"

Lexer::Lexer(const std::string &source) : source(source), current(0)
{
}

std::vector<Token> Lexer::Tokenize()
{
    std::vector<Token> tokens;

    while (!IsAtEnd())
    {
        // Get the next token from the lexer
        Token token = NextToken();
        tokens.push_back(token);
        if (token.type == TokenType::EndOfFile)
            break;
    }

    tokens.push_back({TokenType::EndOfFile, ""}); // Just for now, might delete if I dont use it

    if (tokens.empty())
        throw std::runtime_error("You got no tokens my brother/sister christ.");

    return tokens;
}

char Lexer::Peek() const
{
    if (current >= source.size())
        return '\0';

    return source[current];
}

char Lexer::Advance()
{
    return source[current++]; // Return the current character and then move to the next one, dont confuse it
}

void Lexer::SkipWhitespace()
{
    while (!IsAtEnd() && isspace(Peek()))
    {
        Advance();
    }
}

bool Lexer::IsAtEnd() const
{
    return current >= source.size();
}

Token Lexer::NextToken()
{
    SkipWhitespace();

    if (IsAtEnd())
    {
        return {TokenType::EndOfFile, ""};
    }

    char c = Peek();

    if (std::isalpha(c))
        return ExtractBeepBoops();

    if (std::isdigit(c))
        return ExtractNumber();

    if (c == '"')
        return ExtractString();

    if (c == ';')
    {
        Advance();
        return {TokenType::Semicolon, ";"};
    }

    Advance();

    throw std::runtime_error(std::string("Invalid character: ") + c);
}

Token Lexer::ExtractBeepBoops()
{
    std::string value;

    while (!IsAtEnd() && (std::isalpha(Peek())))
    {
        value += Advance();
    }

    return {TokenType::BeepBoops, value};
}

// TODO: Add check for f for floats
Token Lexer::ExtractNumber()
{
    std::string value;
    while (!IsAtEnd() && std::isdigit(Peek()))
    {
        value += Advance();
    }
    return {TokenType::Number, value};
}

Token Lexer::ExtractString()
{
    std::string value;
    value += Advance();

    while (!IsAtEnd() && Peek() != '"')
    {
        value += Advance();
    }
    if (IsAtEnd())
    {
        throw std::runtime_error("Open string in source code.");
    }

    value += Advance();

    return {TokenType::String, value};
}
