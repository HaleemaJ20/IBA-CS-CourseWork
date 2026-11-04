#include <iostream>

int* create_int(int value)
{
    int* ptr{new int};
    *ptr = value;
    return ptr;
}

int main()
{
    int* my_int{create_int(42)};

    if (my_int != nullptr)
    {
        std::cout << "Value on heap: " << *my_int << std::endl;
        delete my_int;
        my_int = nullptr;
        std::cout << "Memory freed." << std::endl;
    }

    return 0;
}
