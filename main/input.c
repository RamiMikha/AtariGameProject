#include "input.h"

char get_input()
{
    char input;
    if (Cconis())
    {
        input = (char)Cnecin();
    }
    return input;
}