#pragma once

namespace HeaderFiles::Users
{
	class Admin : public Person 
	{
	private:
		static int StaticId;
		int _id = 0;
		string _username = "";
		string _password = "";

	public:

		Admin() = default;
		Admin(string username, string password, string name, string surname, string dateofBrith)
			: Person(name, surname, dateofBrith)
		{
			_id = StaticId++;
			_username = username;
			_password = password;
		}

		const string getUsername() const { return _username; }
		const string getPassword() const { return _password; }


		void print()const 
		{
			cout << "Id: " << _id << endl;
			Person::print();
			cout << "Username: " << _username << endl;
			cout << "Password: " << _password << endl << endl;
		}
	};
	int Admin::StaticId = 0;
}