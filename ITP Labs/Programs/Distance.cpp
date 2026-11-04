#include <iostream>
#include <cmath>

int main()
{
	double x1, x2, y1, y2;
	std:: cout << "Enter the values of \n";
 	std:: cout << "x1: ";
	std:: cin >> x1; 
	
	std:: cout << "y1: ";
	std:: cin >> y1;

	std:: cout << "x2: ";
	std:: cin >> x2;

	std:: cout << "y2: ";
	std:: cin >> y2;

	double distance;
	distance = std:: sqrt(std:: pow(x2 - x1, 2) + std:: pow(y2 - y1, 2));

	std:: cout << "Euclidean distance= " << distance;

	return 0;
}