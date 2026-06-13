#pragma once
#include <fstream>
#include <sstream>
#include <string>

std::string ReadFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);

    std::stringstream buffer;
    buffer << file.rdbuf();

    if (buffer.str().empty())
        throw std::runtime_error("Couldn't read source file or it is empty.");

    return buffer.str();
}
