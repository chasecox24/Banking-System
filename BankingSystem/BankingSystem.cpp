// BankingSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Chase Cox ( A00632215)
// ITSE - 1302
/*
This program allows its user to make a check if the balance is greater than or equal to it and then shows current balance,
Allows users to deposit money into thier account and displays the total balance.
Allows users to deduct a debit charge to thier account and displays the total balance.
*/
#include <iostream>
using namespace std;

// system ("cls") clear screen

int main()
{
	//declaration
	double balance = 0.0;
	int option = 0;
	int checkAmount = 0;
	int nfcCharge = 35;
	int deposit = 0;
	int debitCharge = 0;

	//Counters
	int numberOfChecks = 0;
	int numberOfCharges = 0;
	int numberOfDeposits = 0;

	//Accumlators
	int totalChecks = 0;
	int totalCharges = 0;
	int totalDeposites = 0;

	//BALANCE START
	cout << "What is your balance" << endl;
	cin >> balance;

	//DO LOOP START (BANKING)
	do
	{
		system("cls");
		cout << "1 for CHECK!" << endl;
		cout << "2 for DEPOSIT!" << endl;
		cout << "3 for CHARGE!" << endl;
		cout << "4 for EXIT!" << endl;
		cout << "Enter a number that corresponds with the transaction" << endl;
		cin >> option;

		switch (option)
		{
		case 1: // CHECK
			cout << "How much is the check: " << endl;
			cin >> checkAmount;
			if (checkAmount <= balance)
			{
				balance = balance - checkAmount;
				totalChecks += checkAmount;
				numberOfChecks++;
			}
			else
			{
				balance = balance - nfcCharge;
				totalCharges += nfcCharge;
				numberOfCharges++;
			}
			break;

		case 2: // DEPOSIT
			cout << "How much is the deposit" << endl;
			cin >> deposit;
			balance += deposit;
			totalDeposites += deposit;
			numberOfDeposits++;
			break;

		case 3: // CHARGE
			cout << "What is the charge amount: " << endl;
			cin >> debitCharge;

			if (debitCharge <= balance)
			{
				balance -= debitCharge;
				totalCharges += debitCharge;
				numberOfCharges++;
			}
			else
			{
				cout << "Not enough money!" << endl;
			}
			break;

		case 4: // EXIT
			system("cls");

			//PRINT EVERYTHING 
			cout << "Balance is: " << balance << endl;
			cout << "Number of checks: " << numberOfChecks << endl;
			cout << "Number of deposits: " << numberOfDeposits << endl;
			cout << "Number of charges: " << numberOfCharges << endl;
			cout << "Total checks: " << totalChecks << endl;
			cout << "Total deposits: " << totalDeposites << endl;
			cout << "Total charges: " << totalCharges << endl;
			break;

		default:
			cout << "Invalid Input!!!" << endl;
		} // END SWITCH

	} while (option != 4);    // LEAVES IF 4

	system("pause");
	return 0;
}