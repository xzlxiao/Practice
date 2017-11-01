#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	void print(ListNode *);
	ListNode *ret = NULL, *pLast1 = NULL, *pLast2 = NULL, *pRet = NULL;
	pLast1 = l1; pLast2 = l2;
	int count = 0, num1 = 0, num2 = 0;
	ret = new ListNode((pLast1->val + pLast2->val) % 10);
	pRet = ret;
	count = (pLast1->val + pLast2->val) / 10;
	while (pLast1->next != NULL || pLast2->next != NULL || count>0)
	{
		if (pLast1->next != NULL)
		{
			pLast1 = pLast1->next;
			num1 = pLast1->val;
		}
		else
			num1 = 0;
		if (pLast2->next != NULL)
		{
			pLast2 = pLast2->next;
			num2 = pLast2->val;
		}
		else
			num2 = 0;
		pRet->next = new ListNode((num1 + num2 + count) % 10);
		pRet = pRet->next;
		count = (num1 + num2 + count) / 10;
	}
	return ret;
}

ListNode *InitNode(vector<int> &a)
{
	ListNode *ret = new ListNode(0);
	ListNode *pLas = ret;
	auto i = a.begin();
	ret->val = *i;
	while ((i+1) != a.end())
	{
		++i;
		pLas->next = new ListNode(*i);
		pLas = pLas->next;
	}
	return ret;
}

void print(ListNode *a)
{
	ListNode *pLas = a;
	cout << a->val;
	while (pLas->next != NULL)
	{
		cout << "->";
		pLas = pLas->next;
		cout << pLas->val;
	}
	cout << endl;
}

int main()
{
	vector<int> a = { 2, 4, 6 , 9 };
	vector<int> b = { 5, 6, 4 };
	ListNode *l1 = InitNode(a);
	ListNode *l2 = InitNode(b);
	print(l1);
	print(l2);
	ListNode *l3 = addTwoNumbers(l1, l2);
	print(l3);
	return 0;
}