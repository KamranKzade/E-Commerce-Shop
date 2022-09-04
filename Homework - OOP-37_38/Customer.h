#pragma once




namespace HeaderFiles::Users
{
	class Customer : public Person
	{
	private:

		static int StaticId;
		int _id = 0;
		string _username = "";
		string _password = "";


	public:
		Customer() = default;

		Customer(string username, string password, string name, string surname, string dateofBrith)
			: Person(name, surname, dateofBrith)
		{
			_id = StaticId++;
			_username = username;
			_password = password;
		}

		const string getUsername() const { return _username; }
		const string getPassword() const { return _password; }


		void print() const 
		{
			cout << "Id: " << _id << endl;
			Person::print();
			cout << "Username: " << _username << endl;
			cout << "Password: " << _password << endl << endl;
		}

		friend istream& operator>>(istream& input, Customer& p);

	};

	int Customer::StaticId = 0;

	istream& operator>>(istream& input, Customer& c) {
		cout << "Enter name: ";
		getline(input, c._name);

		cout << "Enter surname: ";
		getline(input, c._surname);

		cout << "Enter username: ";
		getline(input, c._username);

		cout << "Enter password: ";
		getline(input, c._password);

		return input;
	}
}