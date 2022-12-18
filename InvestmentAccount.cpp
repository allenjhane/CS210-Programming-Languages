#include "InvestmentAccount.h"
#include <vector>

#include <iostream>
#include <iomanip>

using namespace std;

// following method is the constructor method without a monthly deposit
// @param accountNumber - pointer to the account being made
// @param initialAmount - the amount the user initial puts into the account
// @param annualInterestRate - the annual rate the account will be on
InvestmentAccount::InvestmentAccount(AccountNumber* accountNumber, double initialAmount, double annualInterestRate) : Account(accountNumber, "Investment-Compound Monthly, Without Monthly Deposit") {
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
	this->monthlyDeposit = 0;
}

//following method is the constructor method with a monthly deposit
// @param accountNumber - pointer to the account being made
// @param initialAmount - the amount the user initial puts into the account
// @param annualInterestRate - the annual rate the account will be on
// @param monthlyDeposit - the amount the user deposits monthly into the account
InvestmentAccount::InvestmentAccount(AccountNumber* accountNumber, double initialAmount, double annualInterestRate, double monthlyDeposit) : Account(accountNumber, "Investment-Compound Monthly, With Monthly Deposit") {
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
	this->monthlyDeposit = monthlyDeposit;
}

// following method gets the end balance for the account
// @param numberOfYears - the amount of years for the account
// @return totalEndingBalance - the total balance for the account at the end
double InvestmentAccount::getEndingBalance(int numberOfYears) {
	double totalEndingBalance = initialAmount;
	double monthlyInterestEarned;
	
	// for-loop based on numberOfYears
	for (int i = 0; i < numberOfYears; ++i) {
		// for loop to calculate the monthly compounded interest/balance
		for (int j = 0; j <12; ++j) {
			totalEndingBalance += monthlyDeposit;
			monthlyInterestEarned = totalEndingBalance * ((annualInterestRate / 100) / 12);
			totalEndingBalance += monthlyInterestEarned;
		}
	}
	return totalEndingBalance;
}

// following method gets the interest earned for the account
// @param numberOfYears - the amount of years for the account
// @return totalInterestEarned - the total earned interest for the account at the end
double InvestmentAccount::getInterestEarned(int numberOfYears) {
	double totalEndingBalance = initialAmount;
	double monthlyInterestEarned;
	double totalInterestEarned = 0;

	double totalEndingBalance2 = initialAmount;
	double monthlyInterestEarned2;
	double totalInterestEarned2 = 0;

	// for-loop based on numberOfYears
	for (int i = 0; i < numberOfYears; ++i) {
		// for loop to calculate the monthly compounded interest/balance
		for (int j = 0; j <12; ++j) {
			totalEndingBalance += monthlyDeposit;
			monthlyInterestEarned = totalEndingBalance * ((annualInterestRate / 100) / 12);
			totalEndingBalance += monthlyInterestEarned;
			totalInterestEarned += monthlyInterestEarned;
		}
	}
	// for-loop based on numberOfYears, used to subtract so it only gets the interest of that year
	for (int i = 0; i < numberOfYears - 1; ++i) {
		// for loop to calculate the monthly compounded interest/balance
		for (int j = 0; j < 12; ++j) {
			totalEndingBalance2 += monthlyDeposit;
			monthlyInterestEarned2 = totalEndingBalance2 * ((annualInterestRate / 100) / 12);
			totalEndingBalance2 += monthlyInterestEarned2;
			totalInterestEarned2 += monthlyInterestEarned2;
		}
	}
	return totalInterestEarned - totalInterestEarned2;
}

// following method formats the ending balance for readability
// @param numberOfYears - amount of years needed for calculation
// @return roundedBalance - a string form of the rounded balance
string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears) {
	string roundedBalance;

	roundedBalance = "$" + format(getEndingBalance(numberOfYears)); // calculate the end balance and convert it into a string

	return roundedBalance;
}

// following method formats the total interest earned for readability
// @param numberOfYears - amount of years needed for calculation
// @return roundedInterest - a string form of the rounded balance
string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears) {
	string roundedInterestEarned;

	roundedInterestEarned = "$" + format(getInterestEarned(numberOfYears)); // calculate the interest earned and convert it into a string

	return roundedInterestEarned;
}

// following method gets the details of the account
// @returns fullAccountDetails - the details of the created account
string InvestmentAccount::getAccountDetails(){
	string string_initialAmount = "Initial Amount: $" + format(initialAmount) + "\n";
	string string_monthlyDeposit = "Monthly Deposit Amount: $" + format(monthlyDeposit) + "\n";
	string string_annualInterestRate = "Annual Interest Rate: " + format(annualInterestRate) + "%\n";

	string fullAccountDetails = string_initialAmount + string_monthlyDeposit + string_annualInterestRate;

	return fullAccountDetails;
}

// following method gets the initial amount of the account
// @return initialAmount - the initial amount when account was created
double InvestmentAccount::getInitialAmount() {
	return initialAmount;
}

// following method gets the monthly deposit of the account
// @return monthlyDeposit - the account's monthly deposit
double InvestmentAccount::getMonthlyDeposit() {
	return monthlyDeposit;
}

// following method gets the annunal interest rate of the account
// @return annualInterestRate - the account's annual interest rate
double InvestmentAccount::getAnnualInterestRate() {
	return annualInterestRate;
}