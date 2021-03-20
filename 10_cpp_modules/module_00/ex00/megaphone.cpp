//megaphone.cpp
#include <iostream>

void    f_to_upper(char* str)
{
    for (int i = 0; str[i]; i += 1)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

int     main(int argc, char* argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i += 1)
        {
            f_to_upper(argv[i]);
            std::cout << argv[i];
        }
        std::cout << std::endl;
    }
    return 0;
}
