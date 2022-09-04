#pragma once


namespace HeaderFiles::Products
{
	class ProductItem
	{
	public:
		static int staticId;
		int _id = 0;
		Product* _product;
		size_t _quantity = 0;



		ProductItem() = default;

		ProductItem(Product* product, size_t quantity) 
		{
			_id = staticId++;
			_product = product;
			_quantity = quantity;
		}


		double TotalPrice() 
		{
			if (_product == nullptr)
				throw exception("Product could not nullptr");

			if (_quantity <= 0)
				throw exception("Quantity could not negative number");

			return _product->_price * _quantity;
		}

		void print()const 
		{
			cout << "\nId: " << _id << endl;
			cout << "ProductName: " << _product->_name << endl;
			cout << "Price: " << _product->_price << endl;
			cout << "Quantity: " << _quantity << endl;
		}
	};
	int ProductItem::staticId = 0;
}