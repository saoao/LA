#include <QtCore/QCoreApplication>
#include <QDebug>

void swepTwoValue(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	int a = 10;
	int b = 5;

	a ^= b;
	b ^= a;
	a ^= b;

	qDebug() << a;
	qDebug() << b;


	qDebug() << "--";

	int tmp = a;
	a = b;
	b = tmp;

	qDebug() << a;
	qDebug() << b;

	qDebug() << "--";

	int *pa = &a;
	int *pb = &b;

	int t = *pa;
	*pa = *pb;
	*pb = t;

	qDebug() << a;
	qDebug() << b;

	qDebug() << "--";
	a = a + b;
	b = a - b;
	a = a - b;

	return app.exec();
}
