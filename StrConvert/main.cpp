#include <QtCore/QCoreApplication>
#include <QDebug>

int strToInt(char* str)
{
	int number = 0;
	if (str != nullptr)
	{
		bool isMinus = false;
		if (*str == '+')
		{
			++str;
		}
		else if (*str == '-')
		{
			++str;
			isMinus = true;
		}
		while ((*str >='0') && (*str <='9'))
		{
			number = number * 10 + (*str - '0');
			++str;
		}
		if (*str == '\0')
		{
			if (isMinus)
			{
				number = 0 - number;
			}
		}
		else
		{
			number = 0;
		}
	}
	return number;
}

int extractNum(char* str)
{
	int number = 0;
	if (str != nullptr)
	{
		while (*str != '\0')
		{
			if ((*str >= '0') && (*str <= '9'))
			{
				number = number * 10 + (*str - '0');
			}
			++str;
		}
	}
	return number;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	qDebug() << extractNum("-5a689");
	return a.exec();
}
