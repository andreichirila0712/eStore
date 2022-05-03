#include "Address.hpp"

Address::Address() :county(std::string()), locality(std::string()), street(std::string()), number(0), block(std::string()), apartment(0)
{

}

Address::Address(const Address& a) : county(a.county), locality(a.locality), street(a.street), number(a.number), block(a.block), apartment(a.apartment)
{

}

Address::Address(const std::string& county, const std::string& locality, const std::string& street, int number, const std::string& block, int apartment) : county(county), locality(locality), street(street), number(number), block(block), apartment(apartment)
{

}

const Address& Address::operator=(const Address& a)
{
	if (this != &a)
	{
		this->county = a.county;
		this->locality = a.locality;
		this->street = a.street;
		this->number = a.number;
		this->block = a.block;
		this->apartment = a.apartment;
	}
	return *this;
}

void Address::setCounty(const std::string& county)
{
	this->county = county;
}

void Address::setLocality(const std::string& locality)
{
	this->locality = locality;
}

void Address::setStreet(const std::string& street)
{
	this->street = street;
}

void Address::setNumber(int number)
{
	this->number = number;
}

void Address::setBlock(const std::string& block)
{
	this->block = block;
}

void Address::setApartment(int apartment)
{
	this->apartment = apartment;
}

std::string& Address::getCounty()
{
	return this->county;
}

std::string& Address::getLocality()
{
	return this->locality;
}

std::string& Address::getStreet()
{
	return this->street;
}

int Address::getNumber()
{
	return this->number;
}

std::string& Address::getBlock()
{
	return this->block;
}

int Address::getApartment()
{
	return this->apartment;
}

bool Address::operator==(const Address& a)
{
	return (this->county == a.county)
		&& (this->locality == a.locality)
		&& (this->street == a.street)
		&& (this->number == a.number)
		&& (this->block == a.block)
		&& (this->apartment == a.apartment);
}

bool Address::operator!=(const Address& a)
{
	return !operator==(a);
}

std::ostream& operator<<(std::ostream& os, const Address& a)
{
	os << a.county << " " << a.locality << " " << a.street << " " << a.number << " " << a.block << " " << a.apartment;
	return os;
}

json Address::toJSON()
{
	return json(*this);
}