#include <QtCore/QCoreApplication>
#include <vector>
#include <QDebug>

void bubbleSort(std::vector<int>& d)
{
	if (d.empty())
	{
		return;
	}
	int len = d.size() - 1;
	for (int i = len;i>=0;i--)
	{
		for (int j = i-1;j>=0;j--)
		{
			if (d[i] < d[j])
			{
				std::swap(d[i], d[j]);
			}
		}
	}
}


void bubbleSort2(std::vector<int>& arr)
{
	if (arr.empty())
	{
		return;
	}
	int last = arr.size() - 1;
	while (last > 0)
	{
		int current = 0;
		for (int i = 0; i < last; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				current = i;
			}
		}
		last = current;
	}
}

void insertSort(std::vector<int>& arr)
{
	if (arr.empty())
	{
		return;
	}
	int len = arr.size() - 1;
	for (int i = 1;i<= len;++i)
	{
		for (int j = i;j>0;--j)
		{
			if (arr[j] < arr[j - 1]) {
				std::swap(arr[j], arr[j - 1]);
			}
		}
	}
}

void shellSort(std::vector<int>& arr)
{
	if (arr.empty())
	{
		return;
	}
	int len = arr.size() - 1;
	int index = len / 2;
	while (index >= 1)
	{
		for (int i = index;i<len;++i)
		{
			for (int j = i-index;j>=0;j-=index)
			{
				if (arr[j] > arr[j + index]) {
					std::swap(arr[j], arr[j - index]);
				}
			}
		}
		index = index / 2;
	}
}




int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	std::vector<int> arr{1,3,8,2,7,5,10};
	bubbleSort2(arr);
	//shellSort(arr);


	qDebug() << arr;

	return a.exec();
}
