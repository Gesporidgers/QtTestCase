#include "student.h"
student::student(const std::string &name, const std::string &gr, const std::string &login, const std::string &pass) : m_name(name), m_gr(gr), m_login(login), m_pass(pass) {}

student::student(pqxx::row pgrow) : m_name(pgrow[1].c_str()), m_gr(pgrow[2].c_str()), m_login(pgrow[3].c_str()), m_pass(pgrow[4].c_str()) {
}

std::string student::name()const { return m_name; }
std::string student::gr()const { return m_gr; }
std::string student::login()const { return m_login; }
std::string student::pass()const { return m_pass; }

