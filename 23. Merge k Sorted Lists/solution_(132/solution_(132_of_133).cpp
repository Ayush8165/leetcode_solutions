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

void insert(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
    {
        return NULL;
    }

    // Calculate total length
    int totalLength = 0;
    for (int i = 0; i < lists.size(); i++)
    {
        totalLength = totalLength + lengthoflist(lists[i]);
    }

    ListNode *ans;
    int thisLen = 0;

    while (thisLen != totalLength)
    {
        int index = -1;
        int min = INT_MAX;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL and lists[i]->val <= min)
            {
                min = lists[i]->val;
                index = i;
            }
        }
        lists[index] = lists[index]->next;
        insert(ans, min);
        thisLen++;
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}