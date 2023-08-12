#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    // Constructor
    ListNode(int data)
    {
        data = data;
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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    // assuming list1->data is smaller
    ListNode *small = list1;
    ListNode *large = list2;

    // assigning small to whichever is smaller
    if (list1->data > list2->data)
        swap(small, large);
    ListNode *head = small;
    while (small != nullptr && large != nullptr)
    {
        ListNode *temp = nullptr;
        while (small != nullptr && small->data <= large->data)
        {
            temp = small;
            small = small->next;
        }
        temp->next = large;
        swap(small, large);
    }
    return head;
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
    print(ans);
    return 0;
}