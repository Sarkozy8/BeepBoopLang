#pragma once

// This file holds the dictionary for BeepBoopLang.
// It is used to map the BeepBoop to a "command"

#include <string>
#include <unordered_map>

enum class Command
{
    Print,
    Variable,
    If,
    Unknown
};

std::unordered_map<std::string, Command> dictionary = {{"BeepBoop", Command::Print},
                                                       {"Bop", Command::Variable},
                                                       {"Beep", Command::If}};
