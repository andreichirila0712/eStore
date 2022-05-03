#pragma once
#include <list>
#include <iterator>
#include <algorithm>
#include "ResealedProduct.hpp"
#include "FoodProduct.hpp"
#include "BasicUser.hpp"
#include "PremiumUser.hpp"
#include "ShoppingCart.hpp"
#include "objectFactory.hpp"

class Server
{
private:
	static Server* instance;
	int usersCapacity;
	std::list<User*> usr;
	std::list<Product*> prod;
	std::map<int, ShoppingCart*>__UserID__ProductsCart__;
	Server();
public:
	static Server* GetInstance();
	~Server();
	std::map<int, ShoppingCart*> get__UserID__ProductsCart__();
	void populateProducts(const json&);
	void populateUsers(const json&);
	void set__UserID_ProductsCarts__();
	std::list<Product*>& getProductsList();
	std::list<User*>& getUsersList();
	bool requestAddProduct(int userID, int productID, int quantity);
	bool requestDeleteProduct(int userID, int productID, int quantity);
};