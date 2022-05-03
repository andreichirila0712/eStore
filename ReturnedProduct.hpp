#pragma once
#include "NonFoodProduct.hpp"

class ReturnedProduct : virtual public NonFoodProduct
{
protected:
	std::string reason;
public:
	ReturnedProduct();
	ReturnedProduct(const std::string&, int, const std::string&, const std::string&, float, int, const std::string&, int);
	ReturnedProduct(const ReturnedProduct&);
	const ReturnedProduct& operator=(const ReturnedProduct&);
	std::string& getReason();
	void setReason(std::string&);
	std::string getProductType();
	json toJSON();
	void display();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(ReturnedProduct, name, quantity, category, id, producer, yearsOfWarranty, price, reason)
};