#pragma once
#include "QuerySolver.hpp"
#include "JSONSerializer.hpp"
#include "FinalQuestionsHelper.hpp"
#include "json.hpp"

using json = nlohmann::json;

class TestHelper
{
	Server* server;
	QuerySolver rezolvatorul;
	json input;
public:
	TestHelper(const std::string&);
	~TestHelper();
	void Init();
	json TestProductClass();
	json TestUserClass();
	json TestCartClass();
	json Test_2();
	json Test_3a();
	json Test_3b();
	json Test_3c();
	json Test_3d();
	json Test_3e();
	json Test_3f();
	json Test_4();
	json Test_5(const std::string&);
};
