#include "User.hpp"

User::~User() {}

User::User() :lastName(std::string()), firstName(std::string()), email(std::string()), UserID(0)
{

}

User::User(const std::string& county, const std::string& locality, const std::string& street, int number, const std::string& block, int apartment, const std::string& county2, const std::string& locality2, const std::string& street2, int number2, const std::string& block2, int apartment2, int UserID, const std::string& lastName, const std::string& firstName, const std::string& email) :
	billingData(county, locality, street, number, block, apartment),
	deliveryData(county2, locality2, street2, number2, block2, apartment2), lastName(lastName), firstName(firstName), email(email), UserID(UserID)
{

}

User::User(const User& user) : lastName(user.lastName), firstName(user.firstName), email(user.email), UserID(user.UserID)
{

}

const User& User::operator=(const User& user)
{
	if (this != &user)
	{
		this->UserID = user.UserID;
		this->firstName = user.firstName;
		this->lastName = user.lastName;
		this->email = user.email;
		this->billingData = user.billingData;
		this->deliveryData = user.deliveryData;
	}
	return *this;
}

void User::setLastName(const std::string& lastName)
{
	this->lastName = lastName;
}

void User::setFirstName(const std::string& firstName)
{
	this->firstName = firstName;
}

void User::setEmail(const std::string& email)
{
	this->email = email;
}

void User::setUserID(int UserID)
{
	this->UserID = UserID;
}

void User::setBillingData(const Address& billingData)
{
	this->billingData = billingData;
}

void User::setDeliveryData(const Address& deliveryData)
{
	this->deliveryData = deliveryData;
}

std::string& User::getLastName()
{
	return this->lastName;
}

std::string& User::getFirstName()
{
	return this->firstName;
}

std::string& User::getEmail()
{
	return this->email;
}

int User::getUserID() const
{
	return this->UserID;
}

Address& User::getBillingData()
{
	return this->billingData;
}

Address& User::getDeliveryData()
{
	return this->deliveryData;
}

json User::toJSON()
{
	return json(*this);
}