#include "ResealedProduct.hpp"

ResealedProduct::ResealedProduct() :wearPercentage(0)
{

}

ResealedProduct::ResealedProduct(const std::string& category, int id, const std::string& producer, const std::string& name, float price, int yearsOfWarranty, int discountPercentage, const std::string& reason, int wearPercentage, int quantity) : DiscountedProduct(category, id, producer, name, price, yearsOfWarranty, discountPercentage, quantity), ReturnedProduct(category, id, producer, name, price, yearsOfWarranty, reason, quantity), wearPercentage(wearPercentage)
{

}

ResealedProduct::ResealedProduct(const ResealedProduct& rp) : DiscountedProduct(rp), ReturnedProduct(rp), wearPercentage(rp.wearPercentage)
{

}

void ResealedProduct::setWearPercentage(int wearPercentage)
{
	this->wearPercentage = wearPercentage;
}

float ResealedProduct::getWearPercentage()
{
	return this->wearPercentage;
}

const ResealedProduct& ResealedProduct::operator=(const ResealedProduct& rp)
{
	if (this != &rp)
	{
		this->wearPercentage = rp.wearPercentage;
		DiscountedProduct::operator=(rp);
		ReturnedProduct::operator=(rp);
	}
	return *this;
}

std::string ResealedProduct::getProductType()
{
	return "ResealedProduct";
}

json ResealedProduct::toJSON()
{
	return json(*this);
}

void ResealedProduct::display()
{
	std::cout << "Product Resigilat" << std::endl;
	std::cout << "Nume Product: " << this->name << std::endl;
	std::cout << "Producator: " << this->producer << std::endl;
	std::cout << "Categorie: " << this->category << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "Cantitate: " << this->quantity << std::endl;
	std::cout << "Garantie: " << this->yearsOfWarranty << " ani" << std::endl;
	std::cout << "Pret: " << this->price << std::endl;
	std::cout << "Procent Reducere: " << this->discountPercentage << std::endl;
	std::cout << "Procent Uzura: " << this->wearPercentage << std::endl;
	std::cout << "Motiv retur: " << this->reason << std::endl
		<< std::endl;
}