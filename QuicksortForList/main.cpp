#include <QtCore/QCoreApplication>

struct ListNode
{
	int value;
	ListNode *next;
};


ListNode* partition(ListNode* head, ListNode* end)
{
	ListNode* ret = nullptr;
	if (head != nullptr && end != nullptr)
	{
		if (head == end || head->next == end)
		{
			return head;
		}
		int pivot = head->value;
		ListNode* i = head;
		ListNode *j = head;
		while (j!=end)
		{
			if (j->value < pivot)
			{
				i = i->next;
				std::swap(i->value, j->value);
			}

		}

	}
	return ret;
}


void quickSort(ListNode* head,ListNode* end)
{
	if (head != nullptr && end != nullptr)
	{
		if (head == end || head->next == end)
		{
			return;
		}
		ListNode* mid = partition(head, end);
		quickSort(head, mid);
		quickSort(mid->next, end);
	}

}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);




	return a.exec();
}
