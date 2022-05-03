#pragma once
#include "Product.hpp"

class FoodProduct :public Product
{
protected:
	float leiPerKg;
	std::string countryOfOrigin;
public:
	FoodProduct();
	FoodProduct(const std::string&, int, const std::string&, float, const std::string&, int);
	FoodProduct(const FoodProduct&);
	const FoodProduct& operator=(const FoodProduct&);
	void setLeiPerKg(float);
	void setCountryOfOrigin(const std::string& countryOfOrigin);
	float getLeiPerKg();
	std::string& getCountryOfOrigin();
	std::string getProductType();
	json toJSON();
	void display();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(FoodProduct, name, quantity, category, id, leiPerKg, countryOfOrigin)
};