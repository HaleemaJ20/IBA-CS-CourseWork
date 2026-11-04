#include <cstddef>
#include <iostream>

int* resize_array(int* old_array, std::size_t old_size, std::size_t new_size)
{
    int* new_array{new int[new_size]};

    std::size_t limit = (old_size < new_size) ? old_size : new_size;
    for (std::size_t i = 0; i < limit; i++)
    {
        new_array[i] = old_array[i];
    }

    for (std::size_t i = limit; i < new_size; i++)
    {
        new_array[i] = 0;
    }

    delete[] old_array;
    return new_array;
}

int main()
{
    std::size_t size{5};
    int* arr{new int[size]};

    for (std::size_t i{0}; i < size; i++)
    {
        arr[i] = i * 10;
    }

    std::cout << "Original array: ";
    for (std::size_t i{0}; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr = resize_array(arr, size, 8);
    size = 8;

    std::cout << "Resized array:  ";
    for (std::size_t i{0}; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
