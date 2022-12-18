#pragma once

#include <string>
#include "AccountNumber.h"
#include <cmath>

using namespace std;

class Account
{
public:
	Account(AccountNumber* accountNumber, string accountType);
	virtual double getEndingBalance(int numberOfYears) = 0;
	virtual double getInterestEarned(int numberOfYears) = 0;
	virtual string getEndingBalanceFormatted(int numberOfYears) = 0;
	virtual string getInterestEarnedFormatted(int numberOfYears) = 0;
	virtual string getAccountDetails() = 0;

	AccountNumber* getAccountNumber();
	string getAccountType();

protected:
	double round(double value, int places);
	string format(double value);

private:
	AccountNumber* accountNumber;
	string accountType;
};

