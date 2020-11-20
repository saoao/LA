#include <QtCore/QCoreApplication>
#include <QDebug>
#include <vector>

int binarySearch(std::vector<int>& data, int left, int right, int x)
{
	if (data.empty() || left<0 || left > right)
	{
		return -1;
	}
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (x > data[mid])
		{
			left = mid + 1;
		}
		else if (x < data[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int binarySearchLast(std::vector<int>& data, int left, int right, int x)
{
	if (data.empty() || left<0 || left > right)
	{
		return -1;
	}
	int mid = 0;
	while (left + 1 < right)
	{
		mid = left + (right - left) / 2;
		if (x >= data[mid])
		{
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (data[right] == x)
	{
		return right;
	}
	else if (data[left] == x)
	{
		return left;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	std::vector<int> arr{ 1,3,3,5 };
	qDebug() << binarySearch(arr, 0, arr.size() - 1, 5);
	qDebug() << binarySearchLast(arr, 0, arr.size()-1, 3);
	return a.exec();
}
