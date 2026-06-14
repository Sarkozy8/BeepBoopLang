#include "Transpiler.h"
#include "HelpCenter.h"
#include "Lexer.h"
#include "Translator.h"
#include <iostream>

Transpiler::Transpiler(const std::filesystem::path &filePath) : filePath(filePath)
{
}

void Transpiler::Run()
{
    GetBeepBoops();
    Tokenize();
    Translate();
    SaveTranslation();
    Compile();
}

void Transpiler::GetBeepBoops()
{
    source = ReadFile(filePath);
    newFileName = filePath.stem().string() + ".cpp";
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

void Transpiler::SaveTranslation()
{
    SaveFile(translation, newFileName);
}

void Transpiler::Compile()
{
    std::string command = "compiler\\bin\\g++.exe " + newFileName + " -o Generated.exe";

    int result = std::system(command.c_str());

    if (result != 0)
        throw std::runtime_error("Transpiler: I was not able to compile the code.");
}

void Transpiler::Execute()
{
}
