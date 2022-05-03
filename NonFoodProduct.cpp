#include "NonFoodProduct.hpp"

NonFoodProduct::NonFoodProduct() :producer(std::string()), price(0), yearsOfWarranty(0)
{

}

NonFoodProduct::NonFoodProduct(const std::string& category, int id, const std::string& producer, const std::string& name, float price, int yearsOfWarranty, int quantity): Product(category, id, name, quantity), producer(producer), price(price), yearsOfWarranty(yearsOfWarranty)
{
	
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct& nfp) :Product(nfp), producer(nfp.producer), price(nfp.price), yearsOfWarranty(nfp.yearsOfWarranty)
{

}

void NonFoodProduct::setYearOfWarranty(int yearsOfWarranty)
{
	this->yearsOfWarranty = yearsOfWarranty;
}

void NonFoodProduct::setPrice(float price)
{
	this->price = price;
}

void NonFoodProduct::setProducer(const std::string& producer)
{
	this->producer = producer;
}

int NonFoodProduct::getYearsOfWarranty()
{
	return this->yearsOfWarranty;
}

float NonFoodProduct::getPrice()
{
	return this->price;
}

std::string& NonFoodProduct::getProducer()
{
	return this->producer;
}

bool NonFoodProduct::operator==(const NonFoodProduct& nfp) const
{
	return (this->yearsOfWarranty == nfp.yearsOfWarranty && this->price == nfp.price && this->producer == nfp.producer);
}

const NonFoodProduct& NonFoodProduct::operator=(const NonFoodProduct& nfp)
{
	if (this != &nfp)
	{
		this->yearsOfWarranty = nfp.yearsOfWarranty;
		this->price = nfp.price;
		this->producer = nfp.producer;
		Product::operator=(nfp);
	}
	return *this;
}

std::string NonFoodProduct::getProductType()
{
	return "NonFoodProduct";
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	std::cout << "Product Nealimentar" << std::endl;
	std::cout << "Nume Product: " << this->name << std::endl;
	std::cout << "Producator: " << this->producer << std::endl;
	std::cout << "Categorie: " << this->category << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "Cantiate: " << this->quantity << std::endl;
	std::cout << "Garantie: " << this->yearsOfWarranty << " ani" << std::endl;
	std::cout << "Pret: " << this->price << std::endl 
		<< std::endl;
}