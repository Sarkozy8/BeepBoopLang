#pragma once

#include "Lexer.h"
#include <string>
#include <unordered_map>
#include <vector>

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
    Add,   // Arrays thingies
    Size,  // Arrays thingies
    Erase, // Arrays thingies
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
    std::string functionTranslation;
    size_t functionEndIndex = 0;
    std::vector<Token> tokens;
    size_t current = 0;
    static const std::unordered_map<std::string, Keyword> dictionary;
};
