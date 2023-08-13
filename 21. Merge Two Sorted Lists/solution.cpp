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

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
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

    if (list1->data > list2->data)
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
        while (small != NULL && small->data <= large->data)
        {
            temp = small;
            small = small->next;
        }
        temp->next = large;
        swap(small, large);
    }

    print(newHead);
    return newHead;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    ListNode *head1 = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        // Add insert function of linkedlist : "linkedlistinsert"
        insert(head1, temp);
    }

    cin >> n;

    ListNode *head2 = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        // Add insert function of linkedlist : "linkedlistinsert"
        insert(head2, temp);
    }

    ListNode *ans = mergeTwoLists(head1, head2);
    return 0;
}