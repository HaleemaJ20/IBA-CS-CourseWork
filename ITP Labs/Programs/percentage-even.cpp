#include <iostream>
#include <vector>

double percent_even(std:: vector<int> v)
{
    int even_count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
            even_count++;
    }

    if (v.size() == 0)
        return 0.0;

    return (even_count * 100.0) / v.size();
}

int main()
{
    std:: vector<int> v1{6, 2, 9, 11, 3};
    std:: cout << percent_even(v1) << std:: endl; 

    std:: vector<int> v2{6, 2, 9, 11, 4};
    std:: cout << percent_even(v2) << std:: endl; 

    std:: vector<int> v3{1, 3, 5, 7, 9};
    std:: cout << percent_even(v3) << std:: endl; 

    return 0;
}
