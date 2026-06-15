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
    Execute();
}

void Transpiler::GetBeepBoops()
{
    source = ReadFile(filePath);
    newFileName = filePath.stem().string();
    std::cout << "\nOriginal: \n" << std::endl;
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
    std::cout << "\nTranslation: \n" << std::endl;
    std::cout << translation << std::endl;
}

void Transpiler::SaveTranslation()
{
    SaveFile(translation, newFileName + ".cpp");
    std::cout << "Translation saved properly. \n" << std::endl;
}

void Transpiler::Compile()
{
    std::string command = "compiler\\bin\\g++.exe " + newFileName + ".cpp -o" + newFileName + ".exe -std=c++20";

    int result = std::system(command.c_str());

    if (result != 0)
        throw std::runtime_error("Transpiler: I was not able to compile the code.");

    std::cout << "Translation compiled properly. \n" << std::endl;
}

void Transpiler::Execute()
{
    std::string command = ".\\" + newFileName + ".exe";

    std::cout << "Executing... \n" << std::endl;

    int result = std::system(command.c_str());

    if (result != 0)
        throw std::runtime_error("Execution failed.");

    std::cout << "\n\nTranslation executed properly. " << std::endl;
}
