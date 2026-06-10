#include "Lexer.h"

Lexer::Lexer(const std::string &source) : source(source), current(0)
{
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
        return ReadIdentifier();

    if (std::isdigit(c))
        return ReadNumber();

    if (c == '"')
        return ReadString();

    if (c == ';')
    {
        Advance();
        return {TokenType::Semicolon, ";"};
    }

    Advance();
    return {TokenType::Unknown, std::string(1, c)};
}

Token Lexer::ReadIdentifier()
{
    std::string value;

    while (!IsAtEnd() && (std::isalpha(Peek())))
    {
        value += Advance();
    }

    return {TokenType::Identifier, value};
}

Token Lexer::ReadNumber()
{
    std::string value;
    while (!IsAtEnd() && std::isdigit(Peek()))
    {
        value += Advance();
    }
    return {TokenType::Number, value};
}

Token Lexer::ReadString()
{
    std::string value;
    Advance(); // Skip the opening quote
    while (!IsAtEnd() && Peek() != '"')
    {
        value += Advance();
    }
    if (IsAtEnd())
    {
        return {TokenType::Unknown, value}; // Unterminated string, Add error handling here
    }
    Advance(); // Skip the closing quote
    return {TokenType::String, value};
}
