#include <iostream>
#include <vector>

void fill_matrix(std::vector<std::vector<int>>& a, int x, int index)
{
    if (index < 0) // base case
        return;

    int row = index / 3;
    int col = index % 3;

    a[row][col] = x % 2; 

    // Recursive call for remaining bits
    fill_matrix(a, x / 2, index - 1);
}

//Convert an integer between 0 and 511 to a 3×3 binary matrix

std::vector<std::vector<int>> to_matrix(int x)
{
    std::vector<std::vector<int>> a(3, std::vector<int>(3, 0));
    fill_matrix(a, x, 8); 
    return a;
}

//Print a coin matrix with H for heads (0) and T for tails (1)

void print_coins_matrix(std::vector<std::vector<int>> a, int i = 0, int j = 0)
{
    if (i == 3) // base case
        return;

    std::cout << (a[i][j] == 0 ? 'H' : 'T') << " ";

    if (j == 2) {
        std::cout << std::endl;
        print_coins_matrix(a, i + 1, 0);
    } else {
        print_coins_matrix(a, i, j + 1);
    }
}

int main()
{
    int num;
    std::cout << "Enter a number between 0 and 511: ";
    std::cin >> num;

    if (num < 0 || num > 511) {
        std::cout << "Invalid number! Please enter between 0 and 511.\n";
        return 0;
    }

    std::cout << "Binary: ";
    for (int i = 8; i >= 0; i--)
        std::cout << ((num >> i) & 1);
    std::cout << std::endl << std::endl;

    std::vector<std::vector<int>> coins = to_matrix(num);
    print_coins_matrix(coins);

    return 0;
}
