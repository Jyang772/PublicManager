#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <Shlwapi.h>
#include <algorithm>
#pragma comment(lib, "Shlwapi.lib")
#include "client.h"
#include "property.h"


using namespace std;

void createDir();
void createNew();
void searchFor();
void searchForProp();
void addNew();
void editClient(Client&, Property&, bool);
void deleteClient();
void outputFile(Client&, Property&);
void menu();
int GetFiles(const string &path, vector<string> &files);
void displayResult(string);

int main()
{
	menu();
	system("PAUSE");
	return 0;
}

void menu()
{
	bool done = false;
	while (done != true)
	{
		system("cls");
		int choice;
		cout << "Welcome to the Public Property Manager." << endl;
		cout << "=======================================" << endl;
		cout << "Please select an option: " << endl << endl;
		cout << "(1) Add/Delete a client. " << endl;
		cout << "(2) Search for existing client." << endl;
		cout << "(3) Search for properties" << endl;
		cout << "(4) Exit Property Manager." << endl;
		cin >> choice;

		createDir();				//Creates directory to store .dat files containing client data

		if (choice == 1)
		{
			system("cls");
			createNew();
		}
		else if (choice == 2)
			searchFor();
		else if (choice == 3)
			searchForProp();
		else
		{
			cout << "Exiting..." << endl;
			//system("PAUSE");
			//exit(0);
			return;
		}
	}
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
	return;
}

void searchFor()
{
	int choice;

	Client existing_client;
	Property existing_prop;
	string file_name;
	string client_name;
	string line;
	string label[8] = { "Client ID: ", "Client Name: ", "Property Price: ", " Property Type: ", "Location: ", "# of Bedrooms: ", "# of Garages: ", "# of Gardens: " };
	int count = 0;

	cout << "Enter client name: " << endl;
	cin >> client_name;
	

	file_name = "\Sentry_Files\\" + client_name + ".dat";

	ifstream existing(file_name);

	if (existing.is_open())
	{
		while (getline(existing, line))
		{

			cout << label[count];
			cout << line << endl;
			if (count == 0)
				existing_client.setID(stoi(line));
			else if (count == 1)
				existing_client.setName(line);
			else if (count == 2)
				existing_prop.price = stoi(line);
			else if (count == 3)
				existing_prop.type = line;
			else if (count == 4)
				existing_prop.location = line;
			else if (count == 5)
				existing_prop.bedrooms = stoi(line);
			else if (count == 6)
				existing_prop.garages = stoi(line);
			else if (count == 7)
				existing_prop.gardens = stoi(line);
			count++;
		}
		existing.close();
	}
	
	cout << "\n\nSelect an option: " << endl;
	cout << "(1) Edit client information" << endl;
	cout << "(2) Return to main menu" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		{bool search = false;
		editClient(existing_client, existing_prop, search);
		break; }
	case 2:
		return;
	}
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
	return;

}

void outputFile(Client& add, Property& new_prop)
{
	string output;

	output = "Sentry_Files\\" + add.getName() + ".dat";
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

	file_name = "\Sentry_Files\\" + name + ".dat";
	remove(file_name.c_str());


	cout << "Returning to menu..." << endl;
	cin.ignore();
	cin.get();
	return;
}

void editClient(Client& existing_client, Property& existing_prop, bool search)
{
	int choice;

	system("cls");
	cout << "Editing Client Information" << endl;
	cout << "================================" << endl;
	cout << endl;
	cout << "(1) Client ID: ";
	cout << existing_client.getID() << endl;
	cout << "(2) Client Name: ";
	cout << existing_client.getName() << endl;
	cout << "(3) Property Price: ";
	cout << existing_prop.price << endl;
	cout << "(4) Property Type: ";
	cout << existing_prop.type << endl;
	cout << "(5) Property Location: ";
	cout <<
		existing_prop.location << endl;
	cout << "(6) # of Bedrooms: ";
	cout << existing_prop.bedrooms << endl;
	cout << "(7) # of Garages: ";
	cout << existing_prop.garages << endl;
	cout << "(8) # of Gardens: ";
	cout << existing_prop.gardens << endl;


	cout << "Select a value to edit: ";
	cin >> choice;


	switch (choice)
	{
	case 1:
		{int id;
		cout << "Change ID to: ";
		cin >> id;
		existing_client.setID(id);
		break;
		  }
	case 2:
		{
			string name;
			cout << "Change Client Name to: ";
			cin >> name;
			existing_client.setName(name);
			break;
		  }
	case 3:
		{
			int price;
			cout << "Change Property Price to: ";
			cin >> price;
			existing_prop.price = price;
			break;
		 }
	case 4:
		{
			string type;
			cout << "Change Property Type to: ";
			cin >> type;
			existing_prop.type = type;
			break;
		  }
	case 5:
		{
			string location;
			cout << "Change Property Location to: ";
			cin.ignore();
			getline(cin, location);
			existing_prop.location = location;
			break;
		  }
	case 6:
		{
			int bedrooms;
			cout << "Change # of Bedrooms to: ";
			cin >> bedrooms;
			existing_prop.bedrooms = bedrooms;
			break;
		  }
	case 7:
		{
			int garages;
			cout << "Change # of Garages to : ";
			cin >> garages;
			existing_prop.garages = garages;
			break;
		  }
	case 8:
		{
			int gardens;
			cout << "Change # of Gardens to : ";
			cin >> gardens;
			existing_prop.gardens = gardens;
			break;
		  }
	}

	cout << "\n\nSelect an option: " << endl;
	cout << "(1) Edit another value" << endl;
	if (search == false)
	{
		cout << "(2) Save to File" << endl;
		cout << "(3) Return to Main Menu" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			{
				search = false; 
				editClient(existing_client, existing_prop, search);
				break;
			  }
		case 2:
			{
				outputFile(existing_client, existing_prop);
				cout << "Data has been saved to file!" << endl;
				break;
			  }
		case 3:
			{
				return;
			  }

		}
	}
	else
	{
		cout << "(2) Return" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
				search = true;
				editClient(existing_client, existing_prop, search);
				break;
			  }
		case 2:
			return;
		}
	}
}


void searchForProp()
{
	int choice;
	int index;
	system("cls");
	cout << "Searching for Properties: \n\n";
	cout << "==============================\n\n";

	Client search_client;
	Property search_prop;

	cout << "(1) Client ID: ";
	cout << search_client.getID() << endl;
	cout << "(2) Client Name: ";
	cout << search_client.getName() << endl;
	cout << "(3) Property Price: ";
	cout << search_prop.price << endl;
	cout << "(4) Property Type: ";
	cout << search_prop.type << endl;
	cout << "(5) Property Location: ";
	cout << search_prop.location << endl;
	cout << "(6) # of Bedrooms: ";
	cout << search_prop.bedrooms << endl;
	cout << "(7) # of Garages: ";
	cout << search_prop.garages << endl;
	cout << "(8) # of Gardens: ";
	cout << search_prop.gardens << endl;

	cout << "Select an option: " << endl;
	cout << "(1) Edit Search Terms" << endl;
	//cout << "(2) Search" << endl;
	cout << "(2) Return to Main Menu" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		{		bool search = true;
		editClient(search_client, search_prop, search);
		/*	 }
		case 29:
		{*/
		cout << "Search results: " << endl;
		string path("Sentry_Files\\");
		vector<string> files;
		string matched[100];
		string list[100];
		GetFiles(path, files);
		string line;
		string troll;
		ifstream fin;
		for (int i = 0; i < files.size(); ++i) {
			int count = 0;
			//cout << files[i] << endl;

			fin.open(files[i].c_str());
			if (!fin.is_open()) {
				// error occurs!!
				// break or exit according to your needs
			}

			while (getline(fin, line)) {

				troll = line;
				std::transform(troll.begin(), troll.end(), troll.begin(), ::tolower);


				if (line == to_string(search_client.getID()) || troll == to_string(search_client.getID()) && count == 0)
					matched[i] = files[i];
				if (line == search_client.getName() || troll == search_client.getName() && count == 1)
					matched[i] = files[i];
				if (line == to_string(search_prop.price) || troll == to_string(search_prop.price) && count == 2)
					matched[i] = files[i];
				if (line == search_prop.type || troll == search_prop.type && count == 3)
					matched[i] = files[i];
				if (line == search_prop.location || troll == search_prop.location && count == 4)
					matched[i] = files[i];
				if (line == to_string(search_prop.bedrooms) || troll == to_string(search_prop.bedrooms) && count == 5)
					matched[i] = files[i];
				if (line == to_string(search_prop.garages) || troll == to_string(search_prop.garages) && count == 6)
					matched[i] = files[i];
				if (line == to_string(search_prop.gardens) || troll == to_string(search_prop.gardens) && count == 7)
					matched[i] = files[i];

				count++;
			}

			fin.clear();
			fin.close();
		}
		int z = 1;
		for (int i = 0; i < files.size(); i++)
		{
			if (matched[i] != "")
			{
				cout << "(" << z << ") ";
				cout << matched[i] << endl;
				list[z - 1] = matched[i];
				z++;
			}
		}

		cout << "Enter file index to open: ";
		cin >> index;

		list[index - 1] = list[index - 1].substr(12, list[index - 1].length());

		displayResult(list[index - 1]);

		cin.ignore();
		cin.get();
		/*break;
	  }*/
		  }
	case 2:
		return;
	}

}

	

int GetFiles(const string &path, vector<string> &files)
{
	const string &wildcard = "\\*";
	string basepath(path.begin(), path.end());
	string wpath = basepath + string(wildcard.begin(), wildcard.end());

	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;

	hFind = FindFirstFile(wpath.c_str(), &ffd);

	if (INVALID_HANDLE_VALUE == hFind) {
		// display error messages
		return dwError;
	}

	TCHAR buf[MAX_PATH];
	do {
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			// directory
		}
		else {
			PathCombine(buf, basepath.c_str(), ffd.cFileName);
			string tmp(buf);
			files.push_back(string(tmp.begin(), tmp.end()));
		}
	} while (FindNextFile(hFind, &ffd));

	dwError = GetLastError();
	if (ERROR_NO_MORE_FILES != dwError) {
		// some errors
	}
	FindClose(hFind);
	return dwError;
	}

void displayResult(string file_)
{
	int choice;

	system("cls");
	Client existing_client;
	Property existing_prop;
	string file_name;
	string client_name;
	string line;
	string label[8] = { "Client ID: ", "Client Name: ", "Property Price: ", " Property Type: ", "Location: ", "# of Bedrooms: ", "# of Garages: ", "# of Gardens: " };
	int count = 0;

	cout << "Displaying Result Contents: " << endl;
	cout << file_ << endl;


	file_name = "\Sentry_Files\\" + file_;

	ifstream existing(file_name);

	if (existing.is_open())
	{
		while (getline(existing, line))
		{

			cout << label[count];
			cout << line << endl;
			if (count == 0)
				existing_client.setID(stoi(line));
			else if (count == 1)
				existing_client.setName(line);
			else if (count == 2)
				existing_prop.price = stoi(line);
			else if (count == 3)
				existing_prop.type = line;
			else if (count == 4)
				existing_prop.location = line;
			else if (count == 5)
				existing_prop.bedrooms = stoi(line);
			else if (count == 6)
				existing_prop.garages = stoi(line);
			else if (count == 7)
				existing_prop.gardens = stoi(line);
			count++;
		}
		existing.close();
	}

	cout << "\n\nSelect an option: " << endl;
	cout << "(1) Edit client information" << endl;
	cout << "(2) Return to main menu" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		{bool search = false;
		editClient(existing_client, existing_prop, search);
		break; }
	case 2:
		return;
	}
}