#include "AccountNumber.h"

int AccountNumber::nextAccountNumber = 1;

// following method is the constructor method
AccountNumber::AccountNumber()
{
	this->accountNumber = nextAccountNumber;
	nextAccountNumber++;
}

// following method gets the account number
// @returns accountNumber - the number of the account
int AccountNumber::getAccountNumber()
{
	return accountNumber;
}
