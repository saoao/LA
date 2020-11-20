#include <QtCore/QCoreApplication>
#include <vector>
#include <QDebug>
#include <QRandomGenerator>

int partions(std::vector<int>& nums, int l, int r)
{
	int pivot = nums[r]; // 选取数组最右边的元素作为基准
	int i = l - 1;
	for (int j = l; j <= r - 1; ++j) {
		if (nums[j] <= pivot) { 
			i++;
			std::swap(nums[i], nums[j]);
		}
	}
	std::swap(nums[i + 1], nums[r]); //将基准值归位
	return i + 1;
}

int randomizedPartition(std::vector<int>& nums, int l, int r)
{
	//(rand() % (b-a))+ a [a,b)
	//(rand() % (b-a+1))+ a [a,b]
	//(rand() % (b-a))+ a + 1 (a,b]
	int i = std::rand() % (r - 1 + 1) + 1; //产生一个[1,r]闭区间的随机整数
	std::swap(nums[r], nums[i]);
	return partions(nums, l, r);
}

void quickSort(std::vector<int>& nums, int l, int r)
{
	if (l<r)
	{
		int pos = randomizedPartition(nums, l, r);
		quickSort(nums, l, pos - 1);
		quickSort(nums, pos + 1, r);
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	std::vector<int> arr{ 1,5,43,6,3,7,9 };
	quickSort(arr, 0, arr.size()-1);
	qDebug() << arr;

	return a.exec();
}
