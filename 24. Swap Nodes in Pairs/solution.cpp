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

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *temp = head;
    head = fast;

    while (1)
    {
        temp->next = fast;
        slow->next = fast->next;
        fast->next = slow;
        swap(fast, slow);
        if (fast->next != NULL and fast->next->next != NULL)
        {
            temp = fast;
            fast = fast->next->next;
            slow = slow->next->next;
        }
        else
        {
            break;
        }
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

    ListNode *ans = swapPairs(head);
    print(ans);

    return 0;
}