#pragma once




namespace HeaderFiles::Products
{
	class Product {
	public:
		static int staticId;
		int _id = 0;
		string _name = "";
		double _price = 0;
		string _color = "";
		string _country = "";
		string _dateOfProduction = "";
		string _expirationDate = "";


		Product() = default;


		Product(string name, double price, string color, string country, string dateOfProduction, string expirationDate)

		{
			_id = staticId++;
			_name = name;
			_price = price;
			_color = color;
			_country = country;
			_dateOfProduction = dateOfProduction;
			_expirationDate = expirationDate;
		}

		const string getName() const { return _name; }
		const double getPrice() const { return _price; }
		const string getColor() const { return _color; }
		const string getCountry() const { return _country; }
		const string getDateOfProduction() const { return _dateOfProduction; }
		const string getExpirationDate() const { return _expirationDate; }


		void print() const
		{
			cout << "\nId: " << _id << endl;
			cout << "Name: " << _name << endl;
			cout << "Price: " << _price << endl;
			cout << "Color: " << _color << endl;
			cout << "Country: " << _country << endl;
			cout << "DateOfProduction: " << _dateOfProduction << endl;
			cout << "ExpirationDate: " << _expirationDate << endl;

		}
		friend istream& operator>>(istream& input, Product& p);
	};

	int Product::staticId = 0;




	istream& operator>>(istream& input, Product& p) {
		cout << "Enter name: ";
		getline(input, p._name);

		cout << "Enter price: " ;
		input >> p._price;
		cin.ignore();

		cout << "Enter color: ";
		getline(input, p._color);

		cout << "Enter country: ";
		getline(input, p._country);

		cout << "Enter dateOfProduction: ";
		getline(input, p._dateOfProduction);

		cout << "Enter expirationDate: ";
		getline(input, p._expirationDate);

		return input;
	}
}