#include <QtCore/QCoreApplication>
#include <QDebug>
#include "Age.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	Age a;
	//(a++)++;
	//++(a++);
	a++;
	++a = 10;
	//a = 10;
	//++a = 2;
	//(++a)++;
	//++(++a);
	//++a = 1;

	qDebug() << a;

	return app.exec();
}
