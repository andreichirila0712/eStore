#pragma once
#include "DiscountedProduct.hpp"
#include "ReturnedProduct.hpp"

class ResealedProduct :public DiscountedProduct, public ReturnedProduct
{
private:
	int wearPercentage;
public:
	ResealedProduct();
	ResealedProduct(const std::string&, int, const std::string&, const std::string&, float, int, int, const std::string&, int, int);
	ResealedProduct(const ResealedProduct&);
	std::string getProductType();
	void setWearPercentage(int);
	float getWearPercentage();
	const ResealedProduct& operator=(const ResealedProduct&);
	json toJSON();
	void display();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(ResealedProduct, name, quantity, category, id, producer, yearsOfWarranty, price, reason, discountPercentage, wearPercentage)
};