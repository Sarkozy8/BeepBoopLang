#include "Transpiler.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage:\n";
        std::cout << "BeepBoopLang.exe run <file.BeepBoop>\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "run")
    {
        if (argc < 3)
        {
            std::cout << "Error: No file provided.\n";
            return 1;
        }

        try
        {
            std::string filePath = argv[2];

            Transpiler transpiler(filePath);
            transpiler.Run();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            return 1;
        }
    }
    else

    {
        std::cout << "Unknown command: " << command << "\n";
        return 1;
    }

    return 0;
}
