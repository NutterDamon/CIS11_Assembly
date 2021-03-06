/*
Write a function that receives an integer. The function must return a string containing the
binary representation of the integer.
	MAX INT SIZE = 2^29
*/
#include <iostream>
#include <string>
using namespace std;
const int BASE = 2;
string toBinary(unsigned long long int input);
int main() {
	unsigned long long int input;
	string converted;
	cout << "Enter an integer up to a max of 10^16 and I will convert it into a binary string:";
	cin >> input;
	converted = toBinary(input);
	cout << converted << endl;
	system("pause");
	return 0;
}
string toBinary(unsigned long long int input) {
	string converted = "";
	bool noTrail= false;
	int spaceCounter = 0;
	for (int SIZE = 54; SIZE >= 0; SIZE--) {
		unsigned long long int divisor = pow(BASE, SIZE);
		if (input >= divisor) {
			unsigned long long int quotient = floor(input / divisor);
			converted += to_string(quotient);
			unsigned long long int remainder = input % divisor;
			input = remainder;
			noTrail = true;
			spaceCounter++;
		}
		else if (noTrail && input < divisor) {
			converted += to_string(0);
			spaceCounter++;
		}
		if (input == divisor) {
			converted += to_string(0);
			spaceCounter++;
		}
		if (spaceCounter == 4) {
			converted += " ";
			spaceCounter = 0;
		}
	}
	return converted;
}
