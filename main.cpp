#include <iostream>
#include <string>
#include <stdlib.h>
#include "Client.h"

using namespace std;

void createNew();
void searchFor();
void addNew();
void deleteClient();

int main()
{
	int choice;
	cout << "Welcome to the Public Property Manager." << endl;
	cout << "=======================================" << endl;
	cout << "Please select an option: " << endl << endl;
	cout << "(1) Add/Delete a client. " << endl;
	cout << "(2) Search for existing client." << endl;
	cin >> choice;

	if(choice == 1)
	{
		system("cls");
		createNew();
	}
	else if(choice == 2)
		searchFor();
	else
		cout << "Exiting..." << endl;
	system("PAUSE");
	return 0;
}


void createNew()
{
	int choice;
	cout << "Select an option: " << endl;
	cout << "(1) Add new client " << endl;
	cout << "(2) Delete existing client " << endl;
	cin >> choice;

	if(choice == 1)
		addNew();
	else
		deleteClient();
	return;
}

void searchFor()
{
	cout << "Enter client name: " << endl;
}

	
