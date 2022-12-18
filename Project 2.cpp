#include <iostream>
#include <iomanip>
#include "Account.h"
#include "InvestmentAccount.h"
#include "AccountNumber.h"

using namespace std;

const double TOLERANCE = 0.01;

void displayOutput(Account* account, int numberOfYears);
template<typename T> void printElement(T t, int width);


template<typename T> void printElement(T t, int width) {
    cout << left << setw(width) << setfill(' ') << t;
}

// following method display the table of balances and interest each year
// @param account - pointer to the account that will be used
// @param numberOfYears - the amount of years the user will accumulaste interest on the account
void displayOutput(Account* account, int numberOfYears) {
    string totalBalance;
    string totalInterest;
    int width = 20;

    // print the details of the account
    cout << "\nACCOUNT DETAILS" << endl;
    cout << "Account Type: " << account->getAccountType() << endl;
    cout << account->getAccountDetails() << endl;
    cout << "Year\t\t";
    printElement("End Balance", width);
    printElement("Interest Earned", width);
    cout << endl;
    // loop to print the balances and interests per year
    for (int i = 1; i <= numberOfYears; ++i) {
        cout << i << "\t\t";
        
        totalBalance = account->getEndingBalanceFormatted(i);
        printElement(totalBalance, width);
        
        totalInterest = account->getInterestEarnedFormatted(i);
        printElement(totalInterest, width);

        cout << endl;
    }
}



int main()
{
    double initialAmount;
    double monthlyDeposit;
    double annualInterestRate;
    int numYears;

    // get the input for the monthly deposit and validate that it is a non-negative
    cout << "Enter initial amount you would like to deposit into your new account:" << endl;
    cin >> initialAmount;

    while (true) {
        if (initialAmount < 0) {
            cout << "Please input a value that is not negative:" << endl;
            cout << "Enter Monthly Deposit:" << endl;
            cin >> initialAmount;
        }
        else {
            break;
        }
    }

    // get the input for the monthly deposit and validate that it is a non-negative
    cout << "Enter Monthly Deposit:" << endl;
    cin >> monthlyDeposit;

    while (true) {
        if (monthlyDeposit < 0) {
            cout << "Please input a value that is not negative:" << endl;
            cout << "Enter Monthly Deposit:" << endl;
            cin >> monthlyDeposit;
        }
        else {
            break;
        }
    }

    // get the input for the interest rate and validate that it is a non-negative
    cout << "Enter Annual Interest Rate:" << endl;
    cin >> annualInterestRate;

    while (true) {
        if (annualInterestRate < 0) {
            cout << "Please input a value that is not negative:" << endl;
            cout << "Enter Annual Interest Rate:" << endl;
            cin >> annualInterestRate;
        }
        else {
            break;
        }
    }

    // get the input for the number of years for the account and validate that it is a non-negative
    cout << "Enter Number of Years:" << endl;
    cin >> numYears;

    while (true) {
        if (numYears < 0) {
            cout << "Please input a value that is not negative:" << endl;
            cout << "Enter Number of Years:" << endl;
            cin >> numYears;
        }
        else {
            break;
        }
    }
    

    //Create two InvestmentAccount pointer variables...one with monthly deposit and one without monthly deposit
    AccountNumber* accountWithoutMonthlyDeposit = new AccountNumber();
    InvestmentAccount investmentWithoutMonthlyDeposit(accountWithoutMonthlyDeposit, initialAmount, annualInterestRate);

    AccountNumber* accountWithMonthlyDeposit = new AccountNumber();
    InvestmentAccount investmentWithMonthlyDeposit(accountWithMonthlyDeposit, initialAmount, annualInterestRate, monthlyDeposit);

    //Display the output for each investment account
    InvestmentAccount* noDeposit_pointer = &investmentWithoutMonthlyDeposit; // get a pointer for investment account
    displayOutput(noDeposit_pointer, numYears);

    Account* withDeposit_pointer = &investmentWithMonthlyDeposit;
    displayOutput(withDeposit_pointer, numYears);
}

