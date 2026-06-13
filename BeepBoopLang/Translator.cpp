#include "Translator.h"

Translator::Translator(const std::vector<Token> &tokens) : tokens(tokens)
{
}
std::string Translator::Translate()
{
    std::string translation;

    for (const auto &token : tokens)
    {
        translation.append(TranslateToken(token));
    }

    return translation;
}

std::string Translator::TranslateToken(const Token &token)
{
    switch (token.type)
    {
    case TokenType::BeepBoops:
        return TranslateBeepBoop(token.value);

    case TokenType::Number:
        return token.value;

    case TokenType::String:
        return token.value;
    case TokenType::Semicolon:
        return token.value;
    case TokenType::EndOfFile:
        return token.value;
    case TokenType::Unknown:
        return "";
    default:
        std::cout << "You really fucked up, ah?" << std::endl;
        break;
    }
}

std::string Translator::TranslateBeepBoop(const std::string BeepBoop)
{
    std::string BeepBoopTranslation;

    auto definition = dictionary.find(BeepBoop);

    switch (definition->second)
    {
    case Keyword::Print:
        BeepBoopTranslation = "std::cout << ";
        break;

    case Keyword::Variable:
        std::cout << "Variable command found" << std::endl;
        break;

    case Keyword::If:
        std::cout << "If command found" << std::endl;
        break;

    default:
        break;
    }

    return BeepBoopTranslation;
}

// Define all you stuff here man
const std::unordered_map<std::string, Keyword> Translator::dictionary = {{"BeepBoop", Keyword::Print},
                                                                         {"Bop", Keyword::Variable},
                                                                         {"Beep", Keyword::If}};
