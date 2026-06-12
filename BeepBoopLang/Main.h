#pragma once

#include "Lexer.h"
#include "Translator.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string ReadFile(const std::string &filename);

void RunLexer(Lexer &lexer);

void TranslateCommand(const Token &token);
