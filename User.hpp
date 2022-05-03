#pragma once
#include "Address.hpp"
#include <map>
#include "ResealedProduct.hpp"
#include "FoodProduct.hpp"

class User
{
protected:
	Address billingData;
	Address deliveryData;
	std::string lastName;
	std::string firstName;
	std::string email;
	int UserID;
public:
	virtual std::string getUserType() = 0;
	virtual float getTransportCost() = 0;
	virtual ~User() = 0;
	User();
	User(const std::string&, const std::string&, const std::string&, int, const std::string&, int, const std::string&, const std::string&, const std::string&, int, const std::string&, int, int, const std::string&, const std::string&, const std::string&);
	User(const User&);
	const User& operator=(const User&);
	void setLastName(const std::string&);
	void setFirstName(const std::string&);
	void setEmail(const std::string&);
	void setUserID(int);
	void setBillingData(const Address& billingData);
	void setDeliveryData(const Address& deliveryData);
	std::string& getLastName();
	std::string& getFirstName();
	std::string& getEmail();
	int getUserID() const;
	Address& getBillingData();
	Address& getDeliveryData();
	virtual void displayUser() = 0;
	virtual json toJSON();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(User, billingData, deliveryData, lastName, firstName, email, UserID)
};