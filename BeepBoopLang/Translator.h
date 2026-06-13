#pragma once

#include "Lexer.h"
#include <string>
#include <unordered_map>
#include <vector>

enum class Keyword
{
    Print,
    Variable,
    If,
    Unknown
};

class Translator
{
  public:
    Translator(const std::vector<Token> &tokens);
    std::string Translate();

  private:
    std::string TranslateToken(const Token &token);
    std::string TranslateBeepBoop(const std::string BeepBoop);

  private:
    const std::vector<Token> tokens;
    size_t current = 0;
    static const std::unordered_map<std::string, Keyword> dictionary;
};
