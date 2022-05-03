#pragma once
#include <iostream>
#include <string>
#include <map>
#include "json.hpp"

using json = nlohmann::json;

class ShoppingCart
{
private:
	std::string payMethod;
	std::map<int, int> shoppingCart;
public:
	ShoppingCart();
	ShoppingCart(const std::string&);
	std::string& getPayMethod();
	void setPayMethod(const std::string&);
	int getQuantity(int);
	void addProduct(int id, int quantity);
	void raiseQuantity(int id, int quantity);
	void lowerQuantity(int id, int quantity);
	void deleteProduct(int productID);
	std::map<int, int>& getShoppingCart();
	void displayShoppingCart();
	json toJSON();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShoppingCart, shoppingCart, payMethod)
};