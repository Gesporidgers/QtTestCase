#include "studentmodel.h"
#include <QDebug>

void StudentModel::AddStudent(const student &newstudent) {
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	students << newstudent;
	endInsertRows();
}

StudentModel::StudentModel(std::string conn, QObject* parent) : QAbstractListModel(parent), connectionString(conn) {}

Q_INVOKABLE void StudentModel::searchDB(QString textToSearch, bool fio)
{
	beginResetModel();
	students.clear();
	try {
		pqxx::connection connectionObject(connectionString.c_str());
		//qDebug() << textToSearch.toStdString().c_str();
		pqxx::work worker(connectionObject);
		pqxx::result response;
		if (fio) {
			response = worker.exec_params("SELECT * FROM students WHERE fio like '%' || $1 || '%'", textToSearch.toStdString());

		}
		else {
			response = worker.exec_params("SELECT * FROM students WHERE gr like '%' || $1 || '%'", textToSearch.toStdString());
		}
		for (size_t i = 0; i < response.size(); i++)
		{
			AddStudent(response[i]);
		}
	}
	catch (const std::exception& e)
	{
		qDebug() << e.what();
	}
	endResetModel();
}


void StudentModel::InitModel() {

	pqxx::connection connectionObject(connectionString.c_str());

	pqxx::work worker(connectionObject);
	pqxx::result response = worker.exec("SELECT * FROM students");
	for (size_t i = 0; i < response.size(); i++)
	{
		AddStudent(response[i]);
	}
}

int StudentModel::rowCount(const QModelIndex &parent) const {
	Q_UNUSED(parent)
		return students.count();
}

QVariant StudentModel::data(const QModelIndex &index, int role) const {
	if (index.row() < 0 || index.row() >= students.count()) return QVariant();

	const student &st = students[index.row()];
	switch (role)
	{
	case FIO_Role: {
		return QString::fromStdString(st.name());
		break;
	}case GroupRole: {
		return QString::fromStdString(st.gr());
		break;
	}case LoginRole: {
		return QString::fromStdString(st.login());
		break;
	}case PasswordRole: {
		return QString::fromStdString(st.pass());
		break;
	}
	default:
		return QVariant();
	}
}

QHash<int, QByteArray> StudentModel::roleNames() const {
	QHash<int, QByteArray> hash;
	hash[FIO_Role] = "name";
	hash[GroupRole] = "gr";
	hash[LoginRole] = "login";
	hash[PasswordRole] = "pass";
	return hash;
}