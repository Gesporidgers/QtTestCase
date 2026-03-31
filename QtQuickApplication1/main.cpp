#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
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
	StudentModel model(connectionString);
	try
	{
		model.InitModel();
	}
	catch (const std::exception& e)
	{
		qDebug() << e.what();
	}

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty("studentModel", QVariant::fromValue(&model));
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	
	return app.exec();
}

void onClick() {
	std::cout << "clicked";
}

