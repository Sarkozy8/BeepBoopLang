#pragma once
#include <string>

enum class TokenType
{
    BeepBoops,
    Number,
    String,
    Semicolon,
    EndOfFile,
    Unknown
};

struct Token
{
    TokenType type;
    std::string value;
};

class Lexer
{
  public:
    // Initialize the lexer with the source code and starts at the beggining
    // Note: I am not sure using string is the best idea but we roll
    Lexer(const std::string &source);
    char Peek() const;
    char Advance();
    void SkipWhitespace();
    bool IsAtEnd() const;

    Token NextToken();

  private:
    Token ReadBeepBoops();
    Token ReadNumber();
    Token ReadString();
    std::string source;
    size_t current;
};
