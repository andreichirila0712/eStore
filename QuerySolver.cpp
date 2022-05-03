#include "QuerySolver.hpp"

QuerySolver::QuerySolver():server(Server::GetInstance()), lru()
{

}

QuerySolver::~QuerySolver()
{
	if (this->server != nullptr)
		this->server = nullptr;
}

std::list<Product*> QuerySolver::Query_3a()
{
	std::list<Product*> lista = this->server->getProductsList(), lista_return;
	std::list<Product*>::iterator it;
	for (auto it : lista)
		if (it->getCategory() == "espressor" && it->getProductType() == "DiscountedProduct")
			lista_return.push_back(it);

	return lista_return;
}

std::list<User*> QuerySolver::Query_3b()
{
	std::list<User*> lista = this->server->getUsersList(), lista_return;
	std::list<User*>::iterator it;

	for (auto it : lista)
		if (it->getUserType() == "BasicUser" && it->getTransportCost() <= 11.5)
			lista_return.push_back(it);

	return lista_return;
}

std::list<Product*> QuerySolver::Query_3c()
{
	std::list<Product*> lista = this->server->getProductsList(), lista_return;
	std::list<Product*>::iterator it;

	for (auto it : lista)
	{
		ResealedProduct produs;

		if (ResealedProduct* produs = dynamic_cast<ResealedProduct*>(it))
			if (produs->getReason() == "lipsa_accesorii")
				lista_return.push_back(it);
	}

	lista_return.sort(Utility::comparePrice);
	return lista_return;
}

std::list<Product*> QuerySolver::Query_3d()
{
	std::list<Product*> lista = this->server->getProductsList(), lista_return;
	std::list<Product*>::iterator it;

	for (auto it : lista)
		if (it->getProductType() == "FoodProduct")
			lista_return.push_back(it);

	lista_return.sort(Utility::compareName);
		return lista_return;
}

std::list<User*> QuerySolver::Query_3e()
{
	Utility u;
	std::list<User*> lista = this->server->getUsersList(), lista_return;
	std::vector<std::string> v;
	std::string elem, county;
	std::list<User*>::iterator it;

	for (auto it : lista)
	{
		elem = it->getDeliveryData().getCounty();
		v.push_back(elem);
	}

	county = u.functie(v);

	for (auto it : lista)
		if (it->getBillingData().getCounty() == county
			&& it->getDeliveryData().getCounty() == county
			&& it->getBillingData().getBlock() == "-"
			&& it->getDeliveryData().getBlock() == "-"
			&& it->getBillingData().getApartment() == 0
			&& it->getDeliveryData().getApartment() == 0)
			lista_return.push_back(it);

	lista_return.sort(Utility::compareUserID);
	return lista_return;
}

std::list<User*> QuerySolver::Query_3f()
{
	std::list<User*> lista = this->server->getUsersList(), lista_return;
	std::list<User*>::iterator it;
	std::list<Product*> lista_p = this->server->getProductsList();
	std::list<Product*>::iterator it_p;

	for (auto it : lista)
		if (it->getUserType() == "PremiumUser")
		{
			PremiumUser p;

			if (PremiumUser* p = dynamic_cast<PremiumUser*>(it))
			{
				std::map<int, int> mp = p->getDiscounts();

				for (std::map<int, int>::iterator it2 = mp.begin(); it2 != mp.end(); it2++)
					for (auto it_p : lista_p)
						if (it_p->getId() == it2->first)
							if (it_p->getCategory() == "imprimanta" || it_p->getCategory() == "telefon")
								lista_return.push_back(it);
			}
		}

	lista_return.unique(Utility::compareUserIDIdentic);
	return lista_return;
}