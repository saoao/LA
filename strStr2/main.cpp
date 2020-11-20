#include <QtCore/QCoreApplication>
#include <string>
#include <vector>
#include <QDebug>

int strStr2(std::string haystack, std::string needle)
{
	if (needle.empty()) return 0;
	// 求前缀表
	std::vector<int> prefix_table(needle.length() + 1);
	prefix_table[0] = 0;
	int len = 0, i = 1;
	while (i < needle.length()) {
		if (needle[i] == needle[len]) {
			len++;
			prefix_table[i] = len;
			i++;
		}
		else {
			if (len > 0) {
				len = prefix_table[len - 1];
			}
			else {
				prefix_table[i] = len;
				i++;
			}
		}
	}
	// 将前缀表的向后移动一位，并将第一位改为 -1
	for (int j = prefix_table.size() - 1; j > 0; j--) {
		prefix_table[j] = prefix_table[j - 1];
	}
	prefix_table[0] = -1;

	// KMP_search
	int k = 0, j = 0;
	while (k < haystack.length()) {
		if (j == needle.length() - 1 && haystack[k] == needle[j]) {
			return k - j;
		}
		if (haystack[k] == needle[j]) {
			k++;
			j++;
		}
		else {
			j = prefix_table[j];
			if (j == -1) {
				k++;
				j++;
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	//qDebug() << strStr2("hello", "ll");

	int arr[2][2] = { {2,3},{4,5} };

	for (int i = 0;i<2;++i)
	{
		for (int j=0;j<2;++j)
		{
			qDebug() << *(*(arr + i) + j) << "\n";
		}
	}

	return a.exec();
}