#pragma once
#include <string>
#include <pqxx/pqxx>
class student
{
public:
	std::string name() const;
	std::string gr()const;
	std::string login()const;
	std::string pass()const;

	student(const std::string& name, const std::string &gr, const std::string &login, const std::string &pass);
	student(pqxx::row pgrow);
private:
	std::string m_name, m_gr, m_login, m_pass;
};
