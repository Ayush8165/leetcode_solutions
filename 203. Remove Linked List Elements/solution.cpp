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

ListNode *removeElements(ListNode *head, int val)
{
    if (head == NULL)
    {
        return head;
    }
    ListNode *temp = head;
    ListNode *fast = head;
    fast = fast->next;

    while (fast != NULL)
    {
        if (fast->val == val)
        {
            temp->next = fast->next;
            fast = temp->next;
            continue;
        }
        temp = fast;
        fast = fast->next;
    }
    if (head->val == val)
    {
        return head->next;
    }
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

    int target;
    cin >> target;

    ListNode *ans = removeElements(head, target);
    print(ans);
    return 0;
}