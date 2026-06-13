#pragma once
#include "Lexer.h"
#include <string>
#include <vector>

class Transpiler
{
  public:
    Transpiler(const std::string &filePath);
    void Run(); // Translate the given beepboops into C++

  private:
    void GetBeepBoops(); // Get source code from filepath
    void Tokenize();     // Use Lexer to tokenize source
    void Translate();    // Use Translator to translate tokens

  private:
    std::string filePath;
    std::string source;
    std::vector<Token> tokens;
    std::string translation;
};
