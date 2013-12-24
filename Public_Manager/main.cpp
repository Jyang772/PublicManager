#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <time.h>

#include "client.h"
#include "property.h"

using namespace std;

void createDir();
void createNew();
void searchFor();
void addNew();
void deleteClient();
void outputFile(Client&, Property&);
void menu();

int main()
{
	menu();
	system("PAUSE");
	return 0;
}

void menu()
{
	system("cls");
	int choice;
	cout << "Welcome to the Public Property Manager." << endl;
	cout << "=======================================" << endl;
	cout << "Please select an option: " << endl << endl;
	cout << "(1) Add/Delete a client. " << endl;
	cout << "(2) Search for existing client." << endl;
	cout << "(3) Exit Property Manager." << endl;
	cin >> choice;

	createDir();				//Creates directory to store .dat files containing client data

	if (choice == 1)
	{
		system("cls");
		createNew();
	}
	else if (choice == 2)
		searchFor();
	else
		cout << "Exiting..." << endl;
}
void createDir()
{
	string OutputFolder = "Sentry_Files";
	CreateDirectory(OutputFolder.c_str(), NULL);

}


void createNew()
{
	int choice;
	cout << "Select an option: " << endl;
	cout << "(1) Add new client " << endl;
	cout << "(2) Delete existing client " << endl;
	cout << "(3) Return to menu" << endl;
	cin >> choice;

	if(choice == 1)
		addNew();
	else if (choice == 2)
		deleteClient();
	else
		menu();
	return;
}

void searchFor()
{
	cout << "Enter client name: " << endl;
}


void addNew()
{
	system("cls");

	string client_name;
	string prop_type;
	string location;

	string output;

	int prop_price;
	int bedrooms;
	int garages;
	int gardens;
	

	cout << "Enter client name: ";
	cin >> client_name;
	cout << "Property price: ";
	cin >> prop_price;
	cout << "Type of Property: ";
	cin >> prop_type;
	cin.ignore();
	cout << "Location: ";
	getline(cin, location);
	cout << "No. of Bedrooms: ";
	cin >> bedrooms;
	cout << "Garages: ";
	cin >> garages;
	cout << "Gardens: ";
	cin >> gardens;

	Client add;
	add.setName(client_name);

	srand(time(NULL));											//create random ID
	int random = rand() % 9000 + 1000;
	add.setID(random);

	Property new_prop;
	new_prop.location = location;
	new_prop.bedrooms = bedrooms;
	new_prop.garages = garages;
	new_prop.gardens = gardens;
	new_prop.type = prop_type;
	new_prop.price = prop_price;

	outputFile(add, new_prop);
	
	cout << "Returning to menu..." << endl;
	cin.ignore();
	cin.get();
	menu();

}

void outputFile(Client& add, Property& new_prop)
{
	string output;

	output = "Sentry_Files\\" + add.getName() + ".txt";
	ofstream file(output);
	file << add.getID() << endl;
	file << add.getName() << endl;
	file << new_prop.price << endl;
	file << new_prop.type << endl;
	file << new_prop.location << endl;
	file << new_prop.bedrooms << endl;
	file << new_prop.garages << endl;
	file << new_prop.gardens << endl;
}


void deleteClient()
{
	system("cls");

	string name;
	string file_name;

	cout << "Enter client name: ";
	cin >> name;

	file_name = "\Sentry_Files\\" + name + ".txt";
	remove(file_name.c_str());


	cout << "Returning to menu..." << endl;
	cin.ignore();
	cin.get();
	menu();
}