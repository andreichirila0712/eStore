#include "utility.hpp"

bool Utility::comparePrice(Product* p1, Product* p2)
{
	if (NonFoodProduct* pr1 = dynamic_cast<NonFoodProduct*>(p1))
		if (NonFoodProduct* pr2 = dynamic_cast<NonFoodProduct*>(p2))
		{
			if (pr1->getPrice() < pr2->getPrice())
				return true;
			else if (pr1->getPrice() > pr2->getPrice())
				return false;
		}

	return false;

}

bool Utility::compareName(Product* p1, Product* p2)
{
	if (p1->getName() < p2->getName())
		return true;
	else if (p1->getName() > p2->getName())
		return false;

	if (FoodProduct* pr1 = dynamic_cast<FoodProduct*>(p1))
		if (FoodProduct* pr2 = dynamic_cast<FoodProduct*>(p2))
		{
			if (pr1->getCountryOfOrigin() < pr2->getCountryOfOrigin())
				return true;
			else if (pr1->getCountryOfOrigin() > pr2->getCountryOfOrigin())
				return false;
		}

	if (FoodProduct* pr1 = dynamic_cast<FoodProduct*>(p1))
		if (FoodProduct* pr2 = dynamic_cast<FoodProduct*>(p2))
		{
			if (pr1->getLeiPerKg() < pr2->getLeiPerKg())
				return true;
			else if (pr1->getLeiPerKg() > pr2->getLeiPerKg())
				return false;
		}

	return false;
}

std::string Utility::functie(std::vector<std::string> v)
{
	std::map<std::string, int> m;

	for (long unsigned int i = 0; i < v.size(); i++)
	{
		std::map<std::string, int>::iterator it = m.find(v[i]);

		if (it == m.end())
			m.insert(std::pair<std::string, int>(v[i], 1));
		else m[v[i]] += 1;
	}

	std::map<std::string, int>::iterator it = m.begin();

	for (std::map<std::string, int>::iterator it2 = m.begin(); it2 != m.end(); ++it2)
		if (it2->second > it->second)
			it = it2;

	return it->first;
}

bool Utility::compareUserID(User* u1, User* u2)
{
	if (u1->getUserID() < u2->getUserID())
		return true;
	else if (u1->getUserID() > u2->getUserID())
		return false;

	return false;
}

bool Utility::compareUserIDIdentic(User* u1, User* u2)
{
	return (u1->getUserID() == u2->getUserID());
}