#include <iostream>
int main()
{
	int isbn;
	std:: cout << "Enter a 9-digit integer: ";
	std:: cin >> isbn;

	int d2 = isbn % 10;          
	int d3 = (isbn % 100) / 10;  
	int d4 = (isbn % 1000) / 100;
	int d5 = (isbn % 10000) / 1000;
	int d6 = (isbn % 100000) / 10000;
	int d7 = (isbn % 1000000) / 100000;
	int d8 = (isbn % 10000000) / 1000000;
	int d9 = (isbn % 100000000) / 10000000;
	int d10 = (isbn % 1000000000) / 100000000; 

	int checksum = (2*d2 + 3*d3 + 4*d4 + 5*d5 + 6*d6 + 7*d7 + 8*d8 + 9*d9 + 10*d10);
	int d1 = (11 - (checksum % 11)) % 11;

	std::string digits = "0123456789X";        // converts checksum 10 into string value "X"
	std:: cout << "The full ISBN is: " << d10 << d9 << d8 << d7 << d6 << d5 << d4 << d3 << d2 << digits[d1];

    return 0;
}