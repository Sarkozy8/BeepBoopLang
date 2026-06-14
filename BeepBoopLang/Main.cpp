#include "Transpiler.h"

int main(int argc, char *argv[])
{
    try
    {
        Transpiler transpiler("Sample.BeepBoop");
        transpiler.Run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
