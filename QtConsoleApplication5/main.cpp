#include <QtCore/QCoreApplication>
#include <vector>
#include <QDebug>

int coinChange(std::vector<int>& coins, int amount) {
	int max = amount + 1;
	std::vector<int> dp(max, max);
	dp[0] = 0;
	for (size_t i=1;i<= amount;i++)
	{
		for (size_t j = 0; j <coins.size(); j++)
		{
			if (coins[j] <= i)
			{
				dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[amount] > amount ? -1 : dp[amount];
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	std::vector<int> arr{ 1,3,5 };
	qDebug() << coinChange(arr, 11);
	return a.exec();
}
