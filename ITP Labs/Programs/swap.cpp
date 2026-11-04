#include <iostream>

void swap_ptr(int* a, int* b)
{
    int temp = *a;  
    *a = *b;         
    *b = temp;      
}

void swap_ref(int& a, int& b)
{
    int temp = a;    
    a = b;          
    b = temp;        
}

int main()
{
    int x{10};
    int y{20};

    std::cout << "Original: x=" << x << ", y=" << y << std::endl;

    swap_ptr(&x, &y);
    std::cout << "After swap_ptr: x=" << x << ", y=" << y << std::endl;

    swap_ref(x, y);
    std::cout << "After swap_ref: x=" << x << ", y=" << y << std::endl;

    return 0;
}
