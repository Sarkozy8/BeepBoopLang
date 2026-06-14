#include "Translator.h"

Translator::Translator(const std::vector<Token> &tokens) : tokens(tokens)
{
}

std::string Translator::Translate()
{
    SemanticAnalysis();

    std::string translation;

    for (const auto &token : tokens)
    {
        translation.append(TranslateToken(token));
    }

    if (translation.empty())
        throw std::runtime_error("Translator: You got no translation my brother/sister christ.");

    return translation;
}

void Translator::SemanticAnalysis()
{
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
        return token.value + "\n";
    case TokenType::Operator:
        return token.value;
    case TokenType::Delimiters:
        if (token.value == "}" || token.value == ")" || token.value == "{")
            return token.value + "\n";
        return token.value;
    case TokenType::Comment:
        return token.value;
    case TokenType::EndOfFile:
        return token.value;
    default:
        throw std::runtime_error("Transalator: You really fucked up, ah?");
        break;
    }
}

std::string Translator::TranslateBeepBoop(const std::string BeepBoop)
{
    std::string BeepBoopTranslation;

    auto definition = dictionary.find(BeepBoop);

    if (definition == dictionary.end())
        return BeepBoop;

    switch (definition->second)
    {
    case Keyword::Print:
        BeepBoopTranslation = "std::cout << ";
        break;
    case Keyword::TypeDeclarationVar:
        BeepBoopTranslation = "auto ";
        break;
    case Keyword::TypeDeclarationFun:
        BeepBoopTranslation = "auto ";
        break;
    case Keyword::If:
        BeepBoopTranslation = "if ";
        break;
    case Keyword::Else:
        BeepBoopTranslation = "else ";
        break;
    case Keyword::Elseif:
        BeepBoopTranslation = "else if ";
        break;
    case Keyword::While:
        BeepBoopTranslation = "while ";
        break;
    case Keyword::For:
        BeepBoopTranslation = "for ";
        break;
    case Keyword::Break:
        BeepBoopTranslation = "break";
        break;
    case Keyword::Return:
        BeepBoopTranslation = "return ";
        break;
    default:
        throw std::runtime_error("Translator: You really fucked up, ah?");
        break;
    }

    return BeepBoopTranslation;
}

// Define all you stuff here man
const std::unordered_map<std::string, Keyword> Translator::dictionary = {{"BeepBoop", Keyword::Print},
                                                                         {"Boop", Keyword::TypeDeclarationVar},
                                                                         {"BoopBop", Keyword::TypeDeclarationFun},
                                                                         {"Beep", Keyword::If},
                                                                         {"Bop", Keyword::Else},
                                                                         {"BopBeep", Keyword::Elseif},
                                                                         {"BoopBoop", Keyword::While},
                                                                         {"BopBop", Keyword::For},
                                                                         {"BopBoop", Keyword::Break},
                                                                         {"BeepBeep", Keyword::Return}};
