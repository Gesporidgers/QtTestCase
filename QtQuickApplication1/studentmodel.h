#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H


#include <QAbstractListModel>
#include <QString>
#include "student.h"
class StudentModel :
	public QAbstractListModel
{
	Q_OBJECT
public:
	enum Roles {
		FIO_Role = Qt::UserRole +1,
		GroupRole, LoginRole, PasswordRole
	};

	StudentModel(QObject *parent = nullptr);
	void AddStudent(const student &student);
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
protected:
	QHash <int, QByteArray> roleNames() const;
private:
	QList<student> students;
};

#endif // !