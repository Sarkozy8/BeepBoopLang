#include "Transpiler.h"
#include "HelpCenter.h"
#include "Lexer.h"
#include "Translator.h"
#include <iostream>

Transpiler::Transpiler(const std::string &filePath) : filePath(filePath)
{
}

void Transpiler::Run()
{
    GetBeepBoops();
    Tokenize();
    Translate();
}

void Transpiler::GetBeepBoops()
{
    source = ReadFile(filePath);
    std::cout << "Original: " << std::endl;
    std::cout << source << std::endl;
}

void Transpiler::Tokenize()
{
    Lexer lexer(source);
    tokens = lexer.Tokenize();
}

void Transpiler::Translate()
{
    Translator translator(tokens);
    translation = translator.Translate();
    std::cout << "Translation: " << std::endl;
    std::cout << translation << std::endl;
}
