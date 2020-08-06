#include <iostream>
#include <Windows.h>

#include "Base360.h"

int main()
{
    SetConsoleOutputCP(65001);
    base360_init();
    std::cout << base360_encode(1234) << std::endl;
    return 0;
}