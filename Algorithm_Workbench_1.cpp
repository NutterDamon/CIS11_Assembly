/*
Write a function that receives an integer. The function must return a string containing the
binary representation of the integer.
	MAX INT SIZE = 2^29
*/
#include <iostream>
#include <string>
using namespace std;
const int BASE = 2;
string toBinary(int input);
int main() {
	int input;
	string converted;
	cout << "Enter an integer up to a max of 536,870,912 and I will convert it into a binary string:";
	cin >> input;
	converted = toBinary(input);
	cout << converted << endl;
	system("pause");
	return 0;
}
string toBinary(int input) {
	string converted = ""; 		// setting up the string
	bool noTrail= false;		// Not allowing trailing zeros
	int spaceCounter = 0;		// counter for the 4 character spacing
	for (int SIZE = 30; SIZE >= 0; SIZE--) {	// Loop through max possible size
		int divisor = pow(BASE, SIZE);		// Set up the divisor 
		if (input >= divisor) {			
			int quotient = floor(input / divisor); //Round down quotient
			converted += to_string(quotient);	// insert the quotient to string
			int remainder = input % divisor;	// set up remainder
			input = remainder;			// set remainder to remaining input
			noTrail = true;				// Allowing trailing 0's
			spaceCounter++;	
		}
		else if (noTrail && input < divisor) {		// Checking if 0 needs to be inserted
			converted += to_string(0);
			spaceCounter++;
		}
		if (input == divisor) {				// Checking if 0 needs to be inserted
			converted += to_string(0);
			spaceCounter++;
		}
		if (spaceCounter == 4) {			//Adding left aligned 4 character spacing
			converted += " ";
			spaceCounter = 0;
		}
	}
	return converted;
}
