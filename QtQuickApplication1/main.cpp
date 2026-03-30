#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <pqxx/pqxx>
#include <iostream>
#include "student.h"
#include "studentmodel.h"

int main(int argc, char *argv[])
{
	
#if defined(Q_OS_WIN)
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
	QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
	QGuiApplication app(argc, argv);
	
	std::string connectionString = "host=localhost port=5432 dbname=postgres user=postgres password =123456";
	StudentModel model;
	try
	{
		pqxx::connection connectionObject(connectionString.c_str());

		pqxx::work worker(connectionObject);
		pqxx::result response = worker.exec("SELECT * FROM students");

		for (size_t i = 0; i < response.size(); i++)
		{
			model.AddStudent(response[i]);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	QObject* mylist = engine.rootObjects().first()->findChild<QObject*>("listv");
	mylist->setProperty("model", QVariant::fromValue(&model));
	QObject* btn = engine.rootObjects().first()->findChild<QObject*>("buttonSearch");
	//QObject::connect(btn,QPus)
	return app.exec();
}

void onClick() {
	std::cout << "clicked";
}

