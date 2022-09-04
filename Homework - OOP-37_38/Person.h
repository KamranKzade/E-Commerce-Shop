#pragma once

namespace HeaderFiles
{
	class Person 
	{
	protected:
		string _name = "";
		string _surname = "";
		string _dateOfBirth = "";


		Person() = default;
		Person(string name, string surname, string dateOfBirth)
		{
			_name = name;
			_surname = surname;
			_dateOfBirth = dateOfBirth;
		}

		string getName()const { return _name; }
		string getSurname()const { return _surname; }
		string getDateOfBirth()const { return _dateOfBirth; }


		void print()const 
		{
			cout << "Name: " << _name << endl;
			cout << "Surname: " << _surname << endl;
			cout << "DateOfBrith: " << _dateOfBirth << endl;
		}
	};
}