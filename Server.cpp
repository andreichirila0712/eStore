#include "Server.hpp"

Server::Server()
{

}

Server* Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}
	
	return instance;
}

Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID_ProductsCarts__()
{
	std::list<User*>::iterator it;
	for (it = usr.begin(); it != usr.end(); it++)
	{
		__UserID__ProductsCart__.insert(std::pair<int, ShoppingCart*>((*it)->getUserID(), new ShoppingCart()));
	}
}

std::list<Product*>& Server::getProductsList()
{
	return this->prod;
}

std::list<User*>& Server::getUsersList()
{
	return this->usr;
}

std::map<int, ShoppingCart*> Server::get__UserID__ProductsCart__()
{
	return this->__UserID__ProductsCart__;
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	if (quantity <= 0)
		return false;

	std::list<User*>::iterator it_user;

	for (auto it_user : usr)
	{
		if (it_user->getUserID() == userID)
			continue;
		else break;
	}

	std::list<Product*>::iterator it_prod, it_prod_copy;
	for (it_prod = prod.begin(); it_prod != prod.end(); ++it_prod)
	{
		if ((*it_prod)->getId() == productID)
		{
			if (!(*it_prod)->checkQuantity(quantity))
				break;
		}
		else break;

		if ((*it_prod)->getId() == productID)
		{
			if ((*it_prod)->checkQuantity(quantity))
			{
				it_prod_copy = it_prod;
				continue;
			}
		}
	}

	std::map<int, ShoppingCart*>::iterator it_map = __UserID__ProductsCart__.find(userID);
	
	if (it_map->second->getShoppingCart().find(productID) == it_map->second->getShoppingCart().end())
	{
		it_map->second->addProduct(productID, quantity);

		for (auto it_prod : prod)
		{
			if (it_prod->getId() == productID)
				it_prod->decreaseQuantity(quantity);
		}

		if (it_map->second->getShoppingCart().find(productID) != it_map->second->getShoppingCart().end())
		{
			it_map->second->raiseQuantity(productID, quantity);
			
			for (auto it_prod : prod)
				it_prod->decreaseQuantity(quantity);
		}
	}
	return true;
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	if (quantity <= 0)
		return false;

	std::list<User*>::iterator it_user;

	for (auto it_user : usr)
		if (it_user->getUserID() == userID)
			continue;
		else break;

	std::list<Product*>::iterator it_prod;
	
	for (auto it_prod : prod)
		if (it_prod->getId() == productID)
			continue;
		else break;

	std::map<int, ShoppingCart*>::iterator it_map = __UserID__ProductsCart__.find(userID);

	if (it_map->second->getShoppingCart().find(productID) == it_map->second->getShoppingCart().end())
		return false;
	else
	{
		std::map<int, int>::iterator it_map2 = it_map->second->getShoppingCart().find(productID);
		
		if (it_map2->second >= quantity)
		{
			for (auto it_prod : prod)
				if (it_prod->getId() == productID)
					it_prod->increaseQuantity(quantity);

			it_map->second->lowerQuantity(productID, quantity);
		}
		
		else if (it_map2->second < quantity)
		{
			for (auto it_prod : prod)
				if (it_prod->getId() == productID)
					it_prod->increaseQuantity(it_map2->second);

			it_map->second->deleteProduct(productID);
		}
	}

	return true;
}

void Server::populateProducts(const json& input)
{
	this->prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

void Server::populateUsers(const json& input)
{
	this->usr = ObjectFactory::getUserList(input["useri"]);
}