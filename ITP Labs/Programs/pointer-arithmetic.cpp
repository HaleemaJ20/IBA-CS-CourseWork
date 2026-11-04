#include <cstddef>
#include <iostream>

int find_max(int* arr, std::size_t size)
{
    int* ptr = arr;          
    int max = *ptr;          

    for (std::size_t i = 1; i < size; ++i)
    {
        ptr++;               
        if (*ptr > max)      
        {
            max = *ptr;
        }
    }

    return max;
}

int main()
{
    int numbers[]{12, 45, 7, 89, 33, 21};
    std::size_t size{sizeof(numbers) / sizeof(numbers[0])};

    int max{find_max(numbers, size)};
    std::cout << "Maximum value is: " << max << std::endl;

    return 0;
}
