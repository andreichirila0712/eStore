#include "Product.hpp"

Product::Product() :name(std::string()),quantity(0),category(std::string()),id(0)
{

}

Product::Product(const std::string& category, int id, const std::string& name, int quantity) : name(name), id(id), category(category), quantity(quantity)
{

}

Product::Product(const Product& p) : name(p.name), quantity(p.quantity), id(p.id), category(p.category)
{

}

Product::~Product() {}

bool Product::checkQuantity(int requestedQuantity)
{
	if (this->quantity >= requestedQuantity)
	{
		return true;
	}

	return false;
}

void Product::decreaseQuantity(int requestedQuantity)
{
	if (checkQuantity(requestedQuantity) == true)
	{
		this->quantity = this->quantity - requestedQuantity;
	}
}

void Product::increaseQuantity(int requestedQuantity)
{
	if (checkQuantity(requestedQuantity) == true)
	{
		this->quantity = this->quantity + requestedQuantity;
	}
}

void Product::setCategory(const std::string& category)
{
	this->category = category;
}

void Product::setName(const std::string& name)
{
	this->name = name;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}

void Product::setId(int id)
{
	this->id = id;
}

std::string& Product::getCategory()
{
	return this->category;
}

int Product::getQuantity()
{
	return this->quantity;
}

int Product::getId()
{
	return this->id;
}

std::string& Product::getName()
{
	return this->name;
}

const Product& Product::operator=(const Product& p)
{
	if (this != &p)
	{
		this->category = p.category;
		this->name = p.name;
		this->id = p.id;
		this->quantity = p.quantity;
	}
	return *this;
}

json Product::toJSON()
{
	return json(*this);
}