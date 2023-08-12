#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    // Constructor
    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

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

ListNode *middleNode(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }

    int mid = len / 2 + 1;
    mid--;
    while (mid--)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    ListNode *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        // Add insert function of linkedlist : "linkedlistinsert"
        insert(head, temp);
    }

    ListNode *ans = middleNode(head);
    cout << ans->data;

    return 0;
}