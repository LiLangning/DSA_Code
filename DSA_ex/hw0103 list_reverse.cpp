#include<iostream>
#include<cstdio>
using namespace std;

struct listnode
{
	int value;
	struct listnode* next;
};
struct listnode* reverse_list(listnode* head)
{
	listnode* preprenode, * prenode = NULL;
	while (head != NULL)
	{
		preprenode = prenode;
		prenode = head;
		head = head->next;
		prenode->next = preprenode;
	}
	return prenode;
}
struct listnode* create_list()
{
	listnode* head = NULL, * pnew = NULL, * ptail = NULL;
	for (int i = 1; i < 4; i++)
	{
		pnew = new listnode;
		pnew->value = i;
		pnew->next = NULL;
		if (head == NULL)
			head = pnew;
		else
			ptail->next = pnew;
		ptail = pnew;
	}
	pnew = NULL;
	delete pnew;
	return head;
}
int main()
{

	listnode* head;
	head = create_list();
	head = reverse_list(head);
	return 0;
}