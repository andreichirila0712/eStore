#include "TestHelper.hpp"

const json failJson = json::parse("{\"result\": \"fail\"}");
const json successJson = json::parse("{\"result\": \"success\"}");

TestHelper::TestHelper(const std::string& inFile)
{
	std::ifstream inStream(inFile);

	inStream >> input;

	inStream.close();

	this->server = Server::GetInstance();
}

void TestHelper::Init()
{
	this->server->populateProducts(input);
	this->server->populateUsers(input);
	this->server->set__UserID_ProductsCarts__();
}

TestHelper::~TestHelper()
{
	if (this->server != nullptr)
		this->server = nullptr;
}

json TestHelper::TestProductClass()
{
	std::string str = "check";

	FoodProduct* pa = new FoodProduct();
	FoodProduct* pa2 = new FoodProduct(str, 78, str, 7.89, str, 200);

	if (pa2 == NULL)
		return failJson;

	float val = 9.27;
	std::string taraOrigine = "Spania";

	pa->setLeiPerKg(val);
	pa->setCountryOfOrigin(taraOrigine);

	if (pa->getLeiPerKg() != val)
		return failJson;

	if (pa->getCountryOfOrigin() != taraOrigine)
		return failJson;


	NonFoodProduct* pn = new NonFoodProduct();
	NonFoodProduct* pn2 = new NonFoodProduct(str, 20, str, str, 4.78, 30, 40);

	if (pn2 == NULL)
		return failJson;

	int garantie = 5;
	float pret = 5.79;
	std::string producator = "Adibas";

	pn->setYearOfWarranty(garantie);
	pn->setPrice(pret);
	pn->setProducer(producator);

	if (garantie != pn->getYearsOfWarranty())
		return failJson;

	if (pret != pn->getPrice())
		return failJson;

	if (producator != pn->getProducer())
		return failJson;


	DiscountedProduct* pr = new DiscountedProduct();
	DiscountedProduct* pr_ref = new DiscountedProduct(str, 69, str, str, 4.20, 2, 60, 100);

	if (pr_ref == NULL)
		return failJson;

	int procentReducere = 60;

	pr->setPrice(pret);
	pr->setDiscountPercentage(procentReducere);

	if (pr->getPrice() != pret)
		return failJson;

	if (pr->getDiscountPercentage() != procentReducere)
		return failJson;

	if (pr->priceAfterDiscount() != pret * (100 - procentReducere))
		return failJson;


	ReturnedProduct* prt = new ReturnedProduct();
	ReturnedProduct* prt_ref = new ReturnedProduct(str, 69, str, str, 4.20, 5, str, 51);

	if (prt_ref == NULL)
		return failJson;

	std::string motiv = "aiurea";

	prt->setReason(motiv);

	if (prt->getReason() != motiv)
		return failJson;


	ResealedProduct* pr_res = new ResealedProduct();
	ResealedProduct* pr_res2 = new ResealedProduct(str, 5, str, str, 6.89, 25, 28, str, 29, 30);

	if (pr_res2 == NULL)
		return failJson;

	int procent = 6;
	
	pr_res->setWearPercentage(procent);

	if (procent != pr_res->getWearPercentage())
		return failJson;

	return successJson;
}

json TestHelper::TestUserClass()
{
	std::string check = "check";
	std::string judet = "Constanta";
	std::string oras = "SatulDeVacanta";
	std::string strada = "Strada Bogatanilor";
	int numar = 20;
	std::string bloc = "Cel Mai Tare Bloc";
	int apartament = 1000;


	Address* adr = new Address();
	Address* adr2 = new Address(check, check, check, 70, check, 20);

	adr->setCounty(judet);
	adr->setLocality(oras);
	adr->setStreet(strada);
	adr->setNumber(numar);
	adr->setBlock(bloc);
	adr->setApartment(apartament);

	if (adr->getCounty() != judet)
		return failJson;

	if (adr->getLocality() != oras)
		return failJson;

	if (adr->getStreet() != strada)
		return failJson;
	
	if (adr->getNumber() != numar)
		return failJson;

	if (adr->getBlock() != bloc)
		return failJson;

	if (adr->getApartment() != apartament)
		return failJson;
		
	
	std::map<int, int> reduceri_test;
	reduceri_test[1] = 5;
	reduceri_test[3] = 10;
	PremiumUser* up = new PremiumUser();
	PremiumUser* up2 = new PremiumUser(check, check, check, 20, check, 200, check, check, check, 20, check, 30, 200, check, check, check, 20, reduceri_test);

	if (up2 == NULL)
		return failJson;

	std::string nume = "Salam";
	std::string prenume = "Florin";
	std::string email = "capitanulromaniei@gmail.com";
	int idUser = 1000;
	int cap = 10;


	up->setLastName(nume);
	up->setFirstName(prenume);
	up->setEmail(email);
	up->setUserID(idUser);
	up->setBillingData(*adr);
	up->setDeliveryData(*adr2);
	up->setDiscounts(reduceri_test);
	up->setPremiumSubscriptionCost(cap);

	if (up->getLastName() != nume)
		return failJson;

	if (up->getFirstName() != prenume)
		return failJson;

	if (up->getEmail() != email)
		return failJson;

	if (up->getUserID() != idUser)
		return failJson;

	if (up->getBillingData() != *adr)
		return failJson;

	if (up->getDeliveryData() != *adr2)
		return failJson;

	if (up->getDiscounts() != reduceri_test)
		return failJson;

	if (up->getPremiumSubscriptionCost() != cap)
		return failJson;


	int costTransport = 20;

	BasicUser* unp = new BasicUser();
	BasicUser* unp2 = new BasicUser(check, check, check, 40, check, 60, check, check, check, 20, check, 50, 200, check, check, check, 3.40);


	if (unp2 == NULL)
		return failJson;

	unp->setTransportCost(costTransport);

	if (unp->getTransportCost() != costTransport)
		return failJson;
		
	return successJson;
}

json TestHelper::TestCartClass()
{
	std::string check = "check";
	ShoppingCart* cp = new ShoppingCart();
	ShoppingCart* cp2 = new ShoppingCart(check);

	if (cp2 == NULL)
		return failJson;


	std::string metodaPlata = "Card";

	cp->setPayMethod(metodaPlata);
	cp->addProduct(5, 3);

	if (cp->getQuantity(5) != 3)
		return failJson;

	cp->lowerQuantity(5, 2);

	if (cp->getQuantity(5) != 1)
		return failJson;

	cp->raiseQuantity(5, 4);

	if (cp->getQuantity(5) != 5)
		return failJson;

	std::map<int, int> TestCos;
	TestCos[5] = 5;

	if (cp->getShoppingCart() != TestCos)
		return failJson;

	cp->deleteProduct(5);
	TestCos.clear();

	if (cp->getShoppingCart() != TestCos)
		return failJson;

	int res = cp->getQuantity(5);

	if (res != -1)
		return failJson;

	return successJson;
}

json TestHelper::Test_2()
{
	Init();
	json output;

	output["productList"] = ObjectFactory::getProductJson(this->server->getProductsList());
	output["useri"] = JSONSerializer::FromUserMap(this->server->get__UserID__ProductsCart__());

	auto y = this->server->get__UserID__ProductsCart__();

	for (auto const& i : y)
	{
		std::cout << i.first << " ";
		i.second->displayShoppingCart();
		std::cout << std::endl;
	}

	return output;
}

json TestHelper::Test_3a()
{
	Init();
	json output;

	auto result = this->rezolvatorul.Query_3a();

	output = ObjectFactory::getProductJson(result);

	return output;
}

json TestHelper::Test_3b()
{
	Init();
	json output;

	auto result = this->rezolvatorul.Query_3b();

	output = ObjectFactory::getUserJson(result);

	return output;
}

json TestHelper::Test_3c()
{
	Init();
	json output;

	auto result = this->rezolvatorul.Query_3c();

	output = ObjectFactory::getProductJson(result);

	return output;
}

json TestHelper::Test_3d()
{
	Init();
	json output;

	auto result = this->rezolvatorul.Query_3d();
	
	output = ObjectFactory::getProductJson(result);

	return output;
}

json TestHelper::Test_3e()
{
	Init();
	json output;

	auto result = this->rezolvatorul.Query_3e();

	output = ObjectFactory::getUserJson(result);
	
	return output;
}

json TestHelper::Test_3f()
{
	Init();
	json output;

	auto result = this->rezolvatorul.Query_3f();

	output = ObjectFactory::getUserJson(result);

	return output;
}

json TestHelper::Test_4()
{
	std::vector<int> lruTest = { 1,2,3,2,5,3,4,5,8,9 };
	LRUCache obj(4);

	std::vector<int> ans = obj.processRequests(lruTest);
	std::vector<int> test = { 9, 8, 5,4 };

	if (ans != test)
		return failJson;

	test = { 0,1,2,3 };
	obj.setLRU(test);
	std::vector<int> aux = obj.getLRU();

	if (test != aux)
		return failJson;

	obj.setCapacity(20);
	int cap = obj.getCapacity();

	if (cap != 20 && obj.getLRUCapacity() != 20)
		return failJson;

	return successJson;
}

json TestHelper::Test_5(const std::string& inFile)
{
	Init();
	std::ifstream in(inFile);
	json jin;
	in >> jin;
	LRUCache lru(5);
	
	std::vector<int> buff;
	json output;
	std::vector<Query> vec = getQuery(jin["queries"]);

	for (auto i = vec.begin(); i != vec.end(); i++)
	{
		if ((*i).operation == "ADD")
		{
			bool doUpdate = this->server->requestAddProduct((*i).userID, (*i).productID, (*i).quantity);
			if (doUpdate)
				buff.push_back((*i).productID);
		}
		else
		{
			this->server->requestDeleteProduct((*i).userID, (*i).productID, (*i).quantity);
		}
	}

	std::map<int, ShoppingCart*> res = this->server->get__UserID__ProductsCart__();

	output.push_back(JSONSerializer::FromUserMap(res));
	output.push_back(json(lru.processRequests(buff)));

	return output;
}