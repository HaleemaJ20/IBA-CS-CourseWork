#include <iostream>
#include <string>
int main()
{
	int m, d, y;
	std:: cout << "Enter month (1 - 12): ";
 	std:: cin >> m;

	std:: cout << "Enter date: "; 
	std:: cin >> d;

	std:: cout << "Enter year: ";
	std:: cin >> y;

	int y0, x, m0, d0;
	y0 = y - ((14 - m) / 12);
	x = y0 + (y0/4) - (y0/100) + (y0/400);
	m0 = m + 12 * ((14 - m) / 12) - 2;
	d0 = (d + x + (31*m0 / 12)) % 7;

	std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};		

	std:: cout << m << " / " << d << " / " << y << " " << "falls on a " << days[d0];

	return 0;
}