#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    // Constructor
    ListNode(int value)
    {
        val = value;
        next = NULL;
    }
};

int lengthoflist(ListNode *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

void insert(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    ListNode *small;
    ListNode *large;

    if (list1->val > list2->val)
    {
        small = list2;
        large = list1;
    }
    else
    {
        small = list1;
        large = list2;
    }

    ListNode *newHead = small;

    while (small != NULL && large != NULL)
    {
        ListNode *temp = NULL;
        while (small != NULL && small->val <= large->val)
        {
            temp = small;
            small = small->next;
        }
        temp->next = large;
        swap(small, large);
    }

    return newHead;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
    {
        return NULL;
    }

    for (int i = 0; i < lists.size() - 1; i++)
    {
        lists[i + 1] = mergeTwoLists(lists[i], lists[i + 1]);
    }
    return lists[lists.size() - 1];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}