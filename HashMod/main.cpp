#include <QtCore/QCoreApplication>
#include <QList>
#include <QCryptographicHash>
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QList<int> nodes{ 1,5,6,7,8,9 };
	QString src = "hello worldffgf";

	auto hashData = QCryptographicHash::hash(src.toLocal8Bit(), QCryptographicHash::Md5);
	auto value = hashData.toHex();
	bool isOk = false;
	auto tmp = value.toLongLong(&isOk);
	if (isOk)
	{
		int index = (int)(tmp%nodes.size());
		qDebug() << nodes.at(index);
	}

	return a.exec();
}
