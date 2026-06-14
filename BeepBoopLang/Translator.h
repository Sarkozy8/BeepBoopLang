#pragma once

#include "Lexer.h"
#include <string>
#include <unordered_map>
#include <vector>

// This is a two-pass translator. One for adding things to the
// symbol table for reference and second for actually translating.

enum class Keyword
{
    Print,
    TypeDeclarationVar,
    TypeDeclarationFun,
    If,
    Else,
    Elseif,
    While,
    For,
    Break,
    Return,
    Unknown
};

class Translator
{
  public:
    Translator(const std::vector<Token> &tokens);
    std::string Translate(); // Translate tokens to C++

  private:
    void SemanticAnalysis(); // For validating variables
    std::string TranslateToken(const Token &token);
    std::string TranslateBeepBoop(const std::string BeepBoop);

  private:
    const std::vector<Token> tokens;
    size_t current = 0;
    static const std::unordered_map<std::string, Keyword> dictionary;
};
