#pragma once

#include "Lexer.h"
#include <string>
#include <unordered_map>

enum class Command
{
    Print,
    Variable,
    If,
    Unknown
};

// Easy to access
std::unordered_map<std::string, Command> dictionary = {{"BeepBoop", Command::Print},
                                                       {"Bop", Command::Variable},
                                                       {"Beep", Command::If}};

class Translator
{
  public:
    Translator(const std::vector<Token> &tokens);

    std::string Translate();

  private:
    const std::vector<Token> &tokens;
    size_t current = 0;
    std::string TranslateToken();
};
