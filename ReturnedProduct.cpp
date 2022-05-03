#include "ReturnedProduct.hpp"

ReturnedProduct::ReturnedProduct() :reason(std::string())
{

}

ReturnedProduct::ReturnedProduct(const std::string& category, int id, const std::string& producer, const std::string& name, float price, int yearsOfWarranty, const std::string& reason, int quantity) : NonFoodProduct(category, id, producer, name, price, yearsOfWarranty, quantity), reason(reason)
{

}

ReturnedProduct::ReturnedProduct(const ReturnedProduct& rp) : NonFoodProduct(rp), reason(rp.reason)
{

}

const ReturnedProduct& ReturnedProduct::operator=(const ReturnedProduct& rp)
{
	if (this != &rp)
	{
		this->reason = rp.reason;
		NonFoodProduct::operator=(rp);
	}
	return *this;
}

std::string& ReturnedProduct::getReason()
{
	return this->reason;
}

void ReturnedProduct::setReason(std::string& reason)
{
	this->reason = reason;
}

std::string ReturnedProduct::getProductType()
{
	return "ReturnedProduct";
}

json ReturnedProduct::toJSON()
{
	return json(*this);
}

void ReturnedProduct::display()
{
	std::cout << "Product Returnat" << std::endl;
	std::cout << "Nume Product: " << this->name << std::endl;
	std::cout << "Producator: " << this->producer << std::endl;
	std::cout << "Categorie: " << this->category << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "Cantitate: " << this->quantity << std::endl;
	std::cout << "Garantie: " << this->yearsOfWarranty << " ani" << std::endl;
	std::cout << "Pret: " << this->price << std::endl;
	std::cout << "Motiv : " << this->reason << std::endl
		<< std::endl;
}