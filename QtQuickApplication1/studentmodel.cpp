#include "studentmodel.h"

void StudentModel::AddStudent(const student &newstudent) {
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	students << newstudent;
	endInsertRows();
}

StudentModel::StudentModel(QObject* parent) : QAbstractListModel(parent) {}

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