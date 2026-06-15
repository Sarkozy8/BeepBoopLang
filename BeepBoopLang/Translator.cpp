#include "Translator.h"

Translator::Translator(const std::vector<Token> &tokens) : tokens(tokens)
{
}

std::string Translator::Translate()
{
    SemanticAnalysis();

    std::string translation;

    translation += "#include <string>\n";
    translation += "#include <iostream>\n";
    translation += "#include <vector>\n";
    translation += "#include <unordered_map>\n\n";

    translation += functionTranslation;

    translation += "\nint main()\n";
    translation += "{\n";

    for (size_t i = functionEndIndex; i < tokens.size(); i++)
    {
        translation.append(TranslateToken(tokens[i]));
    }

    if (translation.empty())
        throw std::runtime_error("Translator: You got no translation my brother/sister christ.");

    translation += "return 0;\n";
    translation += "}\n";

    return translation;
}

void Translator::SemanticAnalysis()
{
    // Separate functions from main
    size_t i = 0;

    if (tokens[i].value == "BeepBeepBeep")
    {
        tokens[i].type = TokenType::FunctionSection;
        i++;

        while (i < tokens.size())
        {
            if (tokens[i].value == "BeepBeepBeep")
            {
                tokens[i].type = TokenType::FunctionSection;
                break;
            }
            functionTranslation += TranslateToken(tokens[i]);
            i++;
        }
        if (tokens[i].value != "BeepBeepBeep")
            throw std::runtime_error("Semantic Analizer: No closing function section. (BeepBeepBeep)");

        functionEndIndex = i + 1;
    }
    else
        throw std::runtime_error("Semantic Analizer: Function section is not defined. (BeepBeepBeep)");

    // A parser would have been a good option to simplify this step BUT it would be overkill for the purpose.
    // One day later, I hate myself for not doing it...
    for (size_t i = 0; i < tokens.size(); i++)
    {
        // Check declarations to properly transform tokens (string,arrays,dictionaries)
        if (tokens[i].value == "Boop")
        {
            bool err = true;
            for (size_t j = i + 1; j < tokens.size(); j++)
            {
                // Check for strings and vectors
                if (tokens[j].value == "=")
                {
                    if (j + 1 < tokens.size()) // Checker to avoid overflow
                    {
                        if (tokens[j + 1].type == TokenType::String)
                        {
                            tokens[i] = {TokenType::StringDeclaration, "std::string "};
                            err = false;
                            break;
                        }
                        else if (tokens[j + 1].value == "{")
                        {
                            tokens[j + 1] = {TokenType::VectorDeclaration, "std::vector{"};
                            err = false;
                            break;
                        }
                        else
                        {
                            err = false;
                            break;
                        }
                    }
                }
            }
            if (err == true && i + 1 < tokens.size() && i + 2 < tokens.size())
                if (tokens[i + 2].value != ")")
                    throw std::runtime_error("Semantic Analizer: Variable was not initilized: " + tokens[i + 1].value);
        }

        // Erase special case
        if (tokens[i].value == "Bup")
        {
            // Check for strings and vectors
            if (i + 1 < tokens.size())
                if (tokens[i + 1].value == "(")
                {
                    tokens[i].value = ".erase";
                    tokens[i + 1].value = "(" + tokens[i - 1].value + ".begin() + ";
                }
                else
                {
                    std::cout << i << std::endl;
                    throw std::runtime_error("Semantic Analizer: Bup needs the index. Example - BupBeep Bup(2).");
                }
        }
    }
}

std::string Translator::TranslateToken(const Token &token)
{
    switch (token.type)
    {
    case TokenType::BeepBoops:
        return TranslateBeepBoop(token.value);
    case TokenType::StringDeclaration:
        return token.value;
    case TokenType::VectorDeclaration:
        return token.value;
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
    case TokenType::FunctionSection:
        return "";
    case TokenType::EndOfFile:
        return token.value;
    default:
        throw std::runtime_error("Translator: You really fucked up, ah?");
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
    case Keyword::Add:
        BeepBoopTranslation = ".push_back";
        break;
    case Keyword::Size:
        BeepBoopTranslation = ".size()";
        break;
    case Keyword::Erase:
        BeepBoopTranslation = ".erase";
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
                                                                         {"BeepBeep", Keyword::Return},
                                                                         {"Bap", Keyword::Add},
                                                                         {"Bip", Keyword::Size},
                                                                         {"Bup", Keyword::Erase}};
