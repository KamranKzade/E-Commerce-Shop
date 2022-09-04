#include <iostream>
#include<vector>
#include<string>
#include <Windows.h>

using namespace std;

#include"Person.h"
#include"Admin.h"
#include"Login.h"
#include"Customer.h"
#include"Product.h"
#include"ProductItem.h"
#include"DataBase.h"

using namespace HeaderFiles;



int main()
{
	LogIn l1;
	
	string start = "Welcome Babat Shop Online";
	for (size_t i = 0; i < start.size(); i++)
	{
		cout << ' ' << start[i] << ' ';
		Sleep(100);
	}


	int choose;
	size_t id;
	Database dataBase;
	Product temp;
	Customer customer;

	while (true)
	{

		cout << "\nChoices: " << endl
			<< "1) As Admin click" << endl
			<< "2) As Guest click  " << endl;

		cout << "Enter Choice, please: ";

		cin >> choose;
		cin.ignore();

		switch (choose)
		{
		case 1:
			cout << "\nEnter username: ";
			getline(cin, l1._username);
			cout << "Enter password: ";
			getline(cin, l1._password);
			l1._IsAdmin = true;

			try
			{
				dataBase.checkAdmin(l1);
			}
			catch (const exception& ex)
			{
				cout << ex.what() << endl;
				continue;
			}

			if (dataBase.checkAdmin(l1))
			{
				while (true)
				{
					cout << "\nChoices: " << endl
						<< "1) Uptade Product " << endl
						<< "2) Create Product" << endl
						<< "3) Read Product " << endl
						<< "4) Delete Product" << endl
						<< "5) Show All Product " << endl
						<< "0) Exit " << endl;
					cout << "Enter Choice: ";
					cin >> choose;
					cin.ignore();

					switch (choose)
					{
					case 1:
						cout << "\nEnter id of the product that you want to uptade: " << endl;
						cin >> id;
						cin.ignore();
						cin >> temp;

						try
						{
							dataBase.Update(id, temp);
						}
						catch (const exception& ex)
						{
							cout << ex.what() << endl;
						}
						system("cls");
						break;
					case 2:
						cout << "\nEnter product information: " << endl;
						cin >> temp;
						try
						{
							dataBase.Create(&temp);
						}
						catch (const exception& ex)
						{
							cout << ex.what() << endl;
						}
						system("cls");
						break;
					case 3:
						cout << "\nFor more information enter id of the product: " << endl;
						cin >> id;
						try
						{
							dataBase.Read(id);
						}
						catch (const exception& ex)
						{
							cout << ex.what() << endl;
						}
						break;
					case 4:
						cout << "\nEnter id of the product that you want to delete: " << endl;
						cin >> id;
						try
						{
							dataBase.Delete(id);
						}
						catch (const exception& ex)
						{
							cout << ex.what() << endl;
						}
						system("cls");
						break;
					case 5:
						dataBase.showAllProduct();
						break;
					default:
						break;
					}
					if (choose == 0)
						break;
				}
			}

			break;

		case 2:
			cin >> customer;

			dataBase.addCustomer(customer);

			while (true)
			{
				cout << "\nChoices " << endl
					<< "1) ShowAllProduct " << endl
					<< "2) Read " << endl;
				cout << "Enter Choice: ";
				cin >> choose;

				switch (choose)
				{
				case 1:
					dataBase.showAllProduct();
					break;
				case 2:
					cout << "\nFor more information enter id of the product: " << endl;
					cin >> id;
					try
					{
						dataBase.Read(id);
					}
					catch (const exception& ex)
					{
						cout << ex.what() << endl;
					}
					break;
				default:
					break;
				}
			}
			break;

		default:
			cout << "\nUnknown command" << endl;
			continue;
		}

	}
}