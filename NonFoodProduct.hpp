#pragma once
#include "Product.hpp"

class NonFoodProduct :public Product
{
protected:
	std::string producer;
	float price;
	int yearsOfWarranty;
public:
	NonFoodProduct();
	NonFoodProduct(const std::string&, int, const std::string&, const std::string&, float, int, int);
	NonFoodProduct(const NonFoodProduct& pn);
	const NonFoodProduct& operator=(const NonFoodProduct&);
	bool operator==(const NonFoodProduct&) const;
	void setYearOfWarranty(int);
	void setPrice(float);
	void setProducer(const std::string&);
	int getYearsOfWarranty();
	float getPrice();
	std::string& getProducer();
	std::string getProductType();
	json toJSON();
	void display();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(NonFoodProduct, name, quantity, category, id, producer, yearsOfWarranty, price)
};