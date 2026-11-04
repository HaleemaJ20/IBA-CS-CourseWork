#include <iostream>
#include <vector>

bool vector_eq(std:: vector<int> v1, std:: vector<int> v2)
{
    if (v1.size() != v2.size())
        return false;

    for (int i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
            return false;

    return true;
}

int main() 
{
    std:: vector<int> a{1, 2, 3};
    std:: vector<int> b{1, 2, 3};

    std:: cout << std:: boolalpha;

    std:: cout << vector_eq(a, b); 
    return 0;
}
