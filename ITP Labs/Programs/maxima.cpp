#include <iostream>
#include <vector>

int maxElement(std::vector<int> a, int n)
{
    if (n == 1)
        return a[0];

    int m = maxElement(a, n - 1);

    if (m > a[n - 1])
        return m;
    else
        return a[n - 1];
}

int main()
{
    std::vector<int> arr = {5, 12, 3, 9, 21, 7};

    std::cout << "Array elements: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int result = maxElement(arr, arr.size());
    std::cout << "Maximum element in the array: " << result << std::endl;

    return 0;
}
