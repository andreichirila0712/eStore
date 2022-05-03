#include "FoodProduct.hpp"

FoodProduct::FoodProduct() :leiPerKg(0), countryOfOrigin(std::string())
{

}

FoodProduct::FoodProduct(const std::string& category, int id, const std::string& name, float leiPerKg, const std::string& countryOfOrigin, int quantity) : Product(category, id, name, quantity), leiPerKg(leiPerKg), countryOfOrigin(countryOfOrigin)
{

}

FoodProduct::FoodProduct(const FoodProduct& fp) : Product(fp), leiPerKg(fp.leiPerKg), countryOfOrigin(fp.countryOfOrigin)
{

}

void FoodProduct::setLeiPerKg(float leiPerKg)
{
	this->leiPerKg = leiPerKg;
}

void FoodProduct::setCountryOfOrigin(const std::string& countryOfOrigin)
{
	this->countryOfOrigin = countryOfOrigin;
}

float FoodProduct::getLeiPerKg()
{
	return this->leiPerKg;
}

std::string& FoodProduct::getCountryOfOrigin()
{
	return this->countryOfOrigin;
}

const FoodProduct& FoodProduct::operator=(const FoodProduct& fp)
{
	if (this != &fp)
	{
		this->leiPerKg = fp.leiPerKg;
		this->countryOfOrigin = fp.countryOfOrigin;
		Product::operator=(fp);
	}
	return *this;
}

std::string FoodProduct::getProductType()
{
	return "FoodProduct";
}

json FoodProduct::toJSON()
{
	return json(*this);
}

void FoodProduct::display()
{
	std::cout << "Product alimentar" << std::endl;
	std::cout << "Nume Product:" << this->name << std::endl;
	std::cout << "Categorie : " << this->category << std::endl;
	std::cout << "ID : " << this->id << std::endl;
	std::cout << "Cantitate (stoc): " << this->quantity << std::endl;
	std::cout << "Lei per KG : " << this->leiPerKg << std::endl;
	std::cout << "Tara de Origine : " << this->countryOfOrigin << std::endl
		<< std::endl;
}
