#pragma once
#include "Account.h"

class InvestmentAccount : public Account
{

public:
	InvestmentAccount(AccountNumber* accountNumber, double initialAmount, double annualInterestRate);
	InvestmentAccount(AccountNumber* accountNumber, double initialAmount, double annualInterestRate, double monthlyDeposit);

	//inherited methods from Account
	virtual double getEndingBalance(int numberOfYears);
	virtual double getInterestEarned(int numberOfYears);
	virtual string getEndingBalanceFormatted(int numberOfYears);
	virtual string getInterestEarnedFormatted(int numberOfYears);
	virtual string getAccountDetails();

	double getInitialAmount();
	double getMonthlyDeposit();
	double getAnnualInterestRate();


private:
	double initialAmount;
	double monthlyDeposit;
	double annualInterestRate;

};

