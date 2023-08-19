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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *nextmy = head;

    while (current != NULL)
    {
        nextmy = nextmy->next;
        current->next = prev;
        prev = current;
        current = nextmy;
    }
    return prev;
}

int listlen(ListNode *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL or k == 1)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    int count = 0;

    while (cur->next != NULL)
    {
        cur = cur->next;
        count++;
    }

    while (count >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count -= k;
    }
    return dummy->next;
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
    int k;
    cin >> k;

    ListNode *ans = reverseKGroup(head, k);
    print(ans);

    return 0;
}