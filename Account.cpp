#include "Account.h"

//following method is the constructor method
Account::Account(AccountNumber* accountNumber, string accountType) {
	this->accountNumber = accountNumber;
	this->accountType = accountType;
}

// following method gets the account number
// @returns accountNumber - the number of the account
AccountNumber* Account::getAccountNumber() {
	return accountNumber;
}

// following method gets the account type
// @returns accountType - the type of account
string Account::getAccountType() {
	return accountType;
}

//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param value - the value to round
//@param places - the number of places to round
//@returns - the rounded number
double Account::round(double value, int places) {
	const int multiplier = pow(10, places);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param value - the value to format
//@returns - the formatted value.
string Account::format(double value) {
	string valueAsString = to_string(value);
	string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		} else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(string(1, currentChar));
	}

	return formatted;
}