#include <iostream>
#include <algorithm>

int main()
{
	int num1, num2, num3;
	std:: cout << "Num1: ";
	std:: cin >> num1;

	std:: cout << "Num2: ";
	std:: cin >> num2;

	std:: cout << "Num3: ";
	std:: cin >> num3;

	int Smallest, Largest, Middle;

	Smallest = std:: min(num1, num2);
	Smallest = std:: min(Smallest, num3);

	Largest = std:: max(num1, num2);
	Largest = std:: max(Largest, num3);

	Middle = (num1 + num2 + num3) - Smallest - Largest;

	std:: cout << "In ascending order: " << Smallest << " " << Middle << " " << Largest;
	
	return 0;
}