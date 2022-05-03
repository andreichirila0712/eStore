#include "DiscountedProduct.hpp"

DiscountedProduct::DiscountedProduct() :NonFoodProduct(), discountPercentage(0)
{

}

DiscountedProduct::DiscountedProduct(const std::string& category, int id, const std::string& producer, const std::string& name, float price, int yearsOfWarranty, int discountPercentage, int quantity) : NonFoodProduct(category, id, producer, name, price, yearsOfWarranty, quantity), discountPercentage(discountPercentage)
{

}

DiscountedProduct::DiscountedProduct(const DiscountedProduct& dp) : NonFoodProduct(dp), discountPercentage(dp.discountPercentage)
{

}

float DiscountedProduct::priceAfterDiscount() const
{
	return this->price * (100 - this->discountPercentage);
}

float DiscountedProduct::getDiscountPercentage()
{
	return this->discountPercentage;
}

const DiscountedProduct& DiscountedProduct::operator=(const DiscountedProduct& dp)
{
	if (this != &dp)
	{
		this->discountPercentage = dp.discountPercentage;
		NonFoodProduct::operator=(dp);
	}
	return *this;
}

void DiscountedProduct::setDiscountPercentage(int discountPercentage)
{
	this->discountPercentage = discountPercentage;
}

std::string DiscountedProduct::getProductType()
{
	return "DiscountedProduct";
}

json DiscountedProduct::toJSON()
{
	return json(*this);
}

void DiscountedProduct::display()
{
	std::cout << "Product Redus" << std::endl;
	std::cout << "Nume Product: " << this->name << std::endl;
	std::cout << "Producator: " << this->producer << std::endl;
	std::cout << "Categorie: " << this->category << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "Cantitate: " << this->quantity << std::endl;
	std::cout << "Garantie: " << this->yearsOfWarranty << " ani" << std::endl;
	std::cout << "Pret: " << this->price << std::endl;
	std::cout << "Procent reducere : " << this->discountPercentage << std::endl << 
		std::endl;

}