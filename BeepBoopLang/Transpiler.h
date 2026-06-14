#pragma once
#include "Lexer.h"
#include <filesystem>
#include <string>
#include <vector>

class Transpiler
{
  public:
    Transpiler(const std::filesystem::path &filePath);
    void Run(); // Translate the given beepboops into C++

  private:
    void GetBeepBoops(); // Get source code from filepath
    void Tokenize();     // Use Lexer to tokenize source
    void Translate();    // Use Translator to translate tokens
    void SaveTranslation();
    void Compile(); // Compile generated C++
    void Execute(); // Execute generated C++

  private:
    std::filesystem::path filePath;
    std::string newFileName;
    std::string source;
    std::vector<Token> tokens;
    std::string translation;
};
