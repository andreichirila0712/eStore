#include "objectFactory.hpp"

#define ALIMENTAR "alimentar"
#define NEALIMENTAR "nealimentar"
#define REDUS "redus"
#define RETURNAT "returnat"
#define RESIGILAT "resigilat"
#define PREMIUM "premium"
#define NONPREMIUM "nonPremium"

Product* ObjectFactory::createProduct(std::string type, json::iterator it)
{
	if (type == ALIMENTAR)
	{
		FoodProduct* newProdus = new FoodProduct();
		*newProdus = it->get<FoodProduct>();
		return newProdus;
	}

	else if (type == NEALIMENTAR)
	{
		NonFoodProduct* newProdus = new NonFoodProduct();
		*newProdus = it->get<NonFoodProduct>();
		return newProdus;
	}

	else if (type == REDUS)
	{
		DiscountedProduct* newProdus = new DiscountedProduct();
		*newProdus = it->get<DiscountedProduct>();
		return newProdus;
	}

	else if (type == RETURNAT)
	{
		ReturnedProduct* newProdus = new ReturnedProduct();
		*newProdus = it->get<ReturnedProduct>();
		return newProdus;
	}

	else if (type == RESIGILAT)
	{
		ResealedProduct* newProdus = new ResealedProduct();
		*newProdus = it->get<ResealedProduct>();
		return newProdus;
	}

	return NULL;
}

std::list<Product*>ObjectFactory::getProductList(json j)
{
	std::list<Product*> lst;
	for (json::iterator it = j.begin(); it != j.end(); ++it)
	{
		Product* p = createProduct((*it)[TYPE_KEY], it);
		lst.push_back(p);
	}
	return lst;
}

json ObjectFactory::getProductJson(std::list<Product*>& lst)
{
	json outj;

	for (auto it = lst.begin(); it != lst.end(); ++it)
	{
		outj.push_back((*it)->toJSON());
	}

	return outj;
}

User* ObjectFactory::createUser(std::string type, json::iterator it)
{
	if (type == PREMIUM)
	{
		PremiumUser* newUser = new PremiumUser();
		*newUser = it->get<PremiumUser>();
		return newUser;
	}

	if (type == NONPREMIUM)
	{
		BasicUser* newUser = new BasicUser();
		*newUser = it->get<BasicUser>();
		return newUser;
	}

	return NULL;
}

std::list<User*> ObjectFactory::getUserList(json j)
{
	std::list<User*> lst;
	for (json::iterator it = j.begin(); it != j.end(); ++it)
	{
		User* p = createUser((*it)[TYPE_KEY], it);
		lst.push_back(p);
	}
	return lst;
}

json ObjectFactory::getUserJson(std::list<User*>& lst)
{
	json outj;

	for (auto it = lst.begin(); it != lst.end(); ++it)
	{
		outj.push_back((*it)->toJSON());
	}

	return outj;
}