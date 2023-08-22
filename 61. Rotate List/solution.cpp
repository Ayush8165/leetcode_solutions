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

ListNode *rotateRight(ListNode *head, int k)
{
    // calculate length
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    if (len == 0)
    {
        return head;
    }
    len = k % len;

    ListNode *slast;
    while (len--)
    {
        temp = head;
        while (1)
        {
            if (temp->next->next == NULL)
            {
                slast = temp;
                break;
            }
            temp = temp->next;
        }
        temp = temp->next;

        temp->next = head;
        slast->next = NULL;
        head = temp;
    }
    return head;
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

    ListNode *newhead = rotateRight(head, k);
    print(newhead);

    return 0;
}