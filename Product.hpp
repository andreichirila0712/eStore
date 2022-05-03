#pragma once
#include <iostream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

#define placeHolder "?"

class Product
{
protected:
	std::string name;
	int quantity;
	std::string category;
	int id;
public:
	virtual ~Product() = 0;  /* Destructor */
	Product(); /* Constructor without parameters*/
	Product(const std::string&, int, const std::string&, int); /* Constructor with parameters*/
	Product(const Product& p); /* Copy constructor*/
	const Product& operator=(const Product&); 
	void setCategory(const std::string& category);
	void setId(int);
	void setQuantity(int);
	void setName(const std::string&);
	std::string& getCategory();
	int getQuantity();
	int getId();
	std::string& getName();
	virtual std::string getProductType() = 0;
	bool checkQuantity(int);
	void decreaseQuantity(int);
	void increaseQuantity(int);
	virtual void display() = 0;
	virtual json toJSON();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Product, name, quantity, category, id)
};
