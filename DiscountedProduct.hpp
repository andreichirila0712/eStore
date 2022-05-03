#pragma once
#include "NonFoodProduct.hpp"

class DiscountedProduct : virtual public NonFoodProduct
{
protected:
	int discountPercentage;
public:
	DiscountedProduct();
	DiscountedProduct(const std::string&, int, const std::string&, const std::string&, float, int, int, int);
	DiscountedProduct(const DiscountedProduct&);
	const DiscountedProduct& operator=(const DiscountedProduct&);
	void setDiscountPercentage(int);
	float getDiscountPercentage();
	std::string getProductType();
	float priceAfterDiscount() const;
	json toJSON();
	void display();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(DiscountedProduct, name, quantity, category, id, producer, yearsOfWarranty, price, discountPercentage)
};