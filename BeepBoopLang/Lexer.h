#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class TokenType
{
    BeepBoops,
    Number,
    String,
    Semicolon,
    Operator,
    Delimiters,
    Comment,
    StringDeclaration, // For SemanticAnalysis()
    VectorDeclaration, // For SemanticAnalysis()
    FunctionSection,   // For declaring function section
    EndOfFile
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

    std::vector<Token> Tokenize();

  private:
    char Peek() const;
    char Advance();
    void SkipWhitespace();
    bool IsAtEnd() const;
    Token NextToken();
    Token ExtractBeepBoops();
    Token ExtractNumber();
    Token ExtractString();
    std::string source;
    size_t current;
};
