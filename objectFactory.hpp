#pragma once
#include "json.hpp"
#include "FoodProduct.hpp"
#include "ResealedProduct.hpp"
#include "BasicUser.hpp"
#include "PremiumUser.hpp"
#include <fstream>
#include <list>

using json = nlohmann::json;

#define TYPE_KEY "type"

class ObjectFactory
{
public:
	static Product* createProduct(std::string, json::iterator);
	static std::list<Product*>getProductList(json j);
	static json getProductJson(std::list<Product*>&);
	static User* createUser(std::string, json::iterator);
	static std::list<User*> getUserList(json j);
	static json getUserJson(std::list<User*>&);
};