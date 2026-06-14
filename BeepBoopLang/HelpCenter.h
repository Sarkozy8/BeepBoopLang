#pragma once
#include <fstream>
#include <sstream>
#include <string>

std::string ReadFile(const std::filesystem::path &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename.string());

    std::stringstream buffer;
    buffer << file.rdbuf();

    if (buffer.str().empty())
        throw std::runtime_error("Couldn't read source file or it is empty.");

    return buffer.str();
}

void SaveFile(const std::string &translation, const std::string &fileName)
{
    std::ofstream file(fileName);

    if (!file)
        throw std::runtime_error("Couldn't create C++ file: " + fileName);

    file << translation;
}
