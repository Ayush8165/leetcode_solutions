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
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void solve(ListNode *head, int len)
{
    if (len <= 2)
    {
        return;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    for (int i = 2; i < len; i++)
    {
        fast = fast->next;
        slow = slow->next;
    }
    // Now fast is at target node, now adjust
    slow->next = fast->next;
    fast->next = head->next;
    head->next = fast;
    solve(head->next->next, len - 2);
}

void reorderList(ListNode *head)
{
    // calculate length
    int len = 0;

    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    if (len <= 2)
    {
        return;
    }

    solve(head, len);
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

    reorderList(head);
    print(head);

    return 0;
}