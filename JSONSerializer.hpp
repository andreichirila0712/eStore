#pragma once
#include "ShoppingCart.hpp"
#include "FoodProduct.hpp"
#include "ResealedProduct.hpp"
#include "PremiumUser.hpp"
#include "BasicUser.hpp"
#include "json.hpp"

using json = nlohmann::json;

class JSONSerializer
{
public:
	static json fromProductMap(const std::map<int, Product*> products)
	{
		json result;

		for (auto& it : products)
			result[std::to_string(it.first)] = it.second->toJSON();

		return result;
	}

	static json FromUserMap(const std::map<int, ShoppingCart*>& cartsOfProducts)
	{
		json result;

		for (auto& it : cartsOfProducts)
			result[std::to_string(it.first)] == it.second->toJSON();

		return result;
	}
};