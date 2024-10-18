#include <iostream>

int main(void)
{
    int arr[2][3] = {};
    int l_pos, f_neg = 0;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            std::cin >> arr[i][j];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
    {
        if (f_neg == 0 && arr[i][j] < 0)
            f_neg = arr[i][j];
        if (arr[i][j] > 0)
            l_pos = arr[i][j];
    }
            
    std::cout << "First_negative: " << f_neg << std::endl;
    std::cout << "Last positive: " << l_pos << std::endl;

    return 0;
}