#pragma once

namespace HeaderFiles
{
	using namespace HeaderFiles::Products;
	using namespace HeaderFiles::Users;

	class Database
	{
		vector<ProductItem> productItem;
		size_t productCount = 0;
		vector<Customer> customers;
		vector<Admin> admins;

	public:

		void Update(int id, Product& product)
		{
			for (size_t i = 0; i < productItem.size(); i++)
				if (productItem[i]._id == id)
				{
					productItem[i]._product->_name = product._name;
					productItem[i]._product->_color = product._color;
					productItem[i]._product->_country = product._country;
					productItem[i]._product->_price = product._price;
					productItem[i]._product->_dateOfProduction = product._dateOfProduction;
					productItem[i]._product->_expirationDate = product._expirationDate;
					return;
				}
				else
				{
					throw exception("Id could not found");
					return;
				}
			throw exception("Can not uptade");
		}
		void Create(Product* product)
		{

			if (product == nullptr)
				throw exception("Product could not nullptr");

			size_t quantity;
			cout << "Enter the quantity: ";
			cin >> quantity;

			ProductItem temp(product, quantity);
			productItem.push_back(temp);
		}
		void Read(int id)
		{
			for (size_t i = 0; i < productItem.size(); i++)
				if (productItem[i]._id == id)
				{
					productItem[i]._product->print();
					return;
				}

			throw exception("Id not found");
		}
		void Delete(int id)
		{
			for (size_t i = 0; i < productItem.size(); i++)
				if (productItem[i]._id == id)
				{
					productItem.erase(productItem.begin() + i);
					return;
				}

			throw exception("Id not fount");
		}


		void showAllProduct()
		{
			for (size_t i = 0; i < productItem.size(); i++)
				productItem[i].print();
		}
		bool checkAdmin(LogIn login)
		{
			for (size_t i = 0; i < admins.size(); i++)
				if (admins[i].getUsername() == login._username)
					if (admins[i].getPassword() == login._password)
						return 1;
					else
						throw exception("Wrong password");
				else
					throw exception("Wrong username");
		}
		bool checkCustomer(LogIn login)
		{
			for (size_t i = 0; i < admins.size(); i++)
				if (customers[i].getUsername() == login._username)
					if (customers[i].getPassword() == login._password)
						return 1;
					else
						throw exception("Wrong password");
				else
					throw exception("Wrong username");
		}
		void addCustomer(Customer customer)
		{
			customers.push_back(customer);
		}
		void addAdmin(Admin admin)
		{
			admins.push_back(admin);
		}
	
	};
}