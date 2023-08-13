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

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // Move one pointer n ahead of head, during iteration it will reach null before the original pointer and you can then simply remove that node
    ListNode *slow = head;
    ListNode *fast = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == NULL)
    {
        return head->next; // edge case handled
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
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
    int index;
    cin >> index;

    ListNode *ans = removeNthFromEnd(head, index);
    print(ans);

    return 0;
}