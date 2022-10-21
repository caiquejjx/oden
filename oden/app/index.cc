#include "v8.h"

#include "./src/oden.hpp"

int main(int argc, char *argv[])
{
    char *filename = argv[1];
    auto oden = new Oden();
    std::unique_ptr<v8::Platform> platform =
        oden->initializeV8(argc, argv);

    oden->initializeVM();
    oden->InitializeProgram(filename);
    oden->Shutdown();

    return 0;
}