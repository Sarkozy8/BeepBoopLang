#include "HelpCenter.h"
#include "Lexer.h"
#include "Translator.h"
#include <iostream>

int main()
{
    // All of this should be inside of a transpiler class later on
    // All class own a copy of their food, may change this later

    std::string source = ReadFile("Sample.BeepBoop"); // Got to add a thing to automaticly find all beepboop files

    std::cout << "Original: " << std::endl;
    std::cout << source << std::endl;

    Lexer lexer(source);

    std::vector<Token> tokens = lexer.Tokenize();

    // Quick debug for tokens
    /* for (const auto &token : tokens)
    {
        std::cout << token.value << '\n';
    }

    std::cout << "token.value" << '\n';*/

    Translator translator(tokens);

    std::string translation = translator.Translate();

    std::cout << "Translation: " << std::endl;
    std::cout << translation << std::endl;

    return 0;
}
