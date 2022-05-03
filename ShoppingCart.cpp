#include "ShoppingCart.hpp"

ShoppingCart::ShoppingCart(): shoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const std::string& payMethod) : shoppingCart()
{
	this->payMethod = payMethod;
}

std::string& ShoppingCart::getPayMethod()
{
	return this->payMethod;
}

void ShoppingCart::setPayMethod(const std::string& payMethod)
{
	this->payMethod = payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
	if (shoppingCart.empty())
	{
		shoppingCart.insert(std::pair<int, int>(id, quantity));
	}

	if (shoppingCart.find(id) == shoppingCart.end())
	{
		shoppingCart.insert(std::pair<int, int>(id, quantity));
	}

	if (shoppingCart.find(id) != shoppingCart.end())
	{
		return;
	}
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	std::map<int, int>::iterator it = shoppingCart.find(id);
	it->second = it->second + quantity;
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	std::map<int, int>::iterator it = shoppingCart.find(id);
	it->second = it->second - quantity;
}

int ShoppingCart::getQuantity(int productID)
{
	std::map<int, int>::iterator it = shoppingCart.find(productID);

	if (it == shoppingCart.end())
	{
		it->second = -1;
	}

	return it->second;
}

void ShoppingCart::deleteProduct(int productID)
{
	std::map<int, int>::iterator it = shoppingCart.find(productID);
	shoppingCart.erase(it->first);
}

std::map<int, int>& ShoppingCart::getShoppingCart()
{
	return this->shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
	std::map<int, int>::iterator it;
	if (this->shoppingCart.empty())
	{
		std::cout << "Cosul de cumpărături este gol";
	}

	for (it = shoppingCart.begin(); it != shoppingCart.end(); it++)
	{
		std::cout << it->first << " " << it->second;
	}
}

json ShoppingCart::toJSON()
{
	return json(*this);
}
