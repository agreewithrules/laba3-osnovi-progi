#include <iostream>
#include <string.h>

bool my_find(const char text[], char chr)
{
    int i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == chr)
            return true;
        i++;
    }

    return false;
}

int main(void)
{
    char text[1024];
    const char cons[22] = "bcdfghjklmnpqrstvwxz";
    const char vows[7] = "aeiouy";
    int vow, con = 0;
    fgets(text, 1024, stdin);

    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (my_find(cons, text[i]))
            con += 1;
        if (my_find(vows, text[i]))
            vow += 1;
    }

    std::cout << "vow: " << vow << std::endl;
    std::cout << "con: " << con << std::endl;
    return 0;
}