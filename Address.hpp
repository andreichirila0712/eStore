#pragma once
#include <string>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

class Address
{
private:
	std::string county;
	std::string locality;
	std::string street;
	int number;
	std::string block;
	int apartment;
public:
	Address();
	Address(const Address&);
	Address(const std::string&, const std::string&, const std::string&, int, const std::string&, int);
	const Address& operator=(const Address&);
	bool operator==(const Address&);
	bool operator!=(const Address&);
	friend std::ostream& operator<<(std::ostream&, const Address&);
	void setCounty(const std::string&);
	void setLocality(const std::string&);
	void setStreet(const std::string&);
	void setNumber(int);
	void setBlock(const std::string&);
	void setApartment(int);
	std::string& getCounty();
	std::string& getLocality();
	std::string& getStreet();
	int getNumber();
	std::string& getBlock();
	int getApartment();
	json toJSON();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Address, county, locality, street, number, block, apartment)
};