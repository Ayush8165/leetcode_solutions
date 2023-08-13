#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    // Constructor
    ListNode(int data)
    {
        val = data;
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = l1, *prev;
    int carry = 0;
    while (l1 && l2)
    {
        int sum = l1->val + l2->val + carry;
        if (sum > 9)
        {
            carry = 1;
            l1->val = sum - 10;
        }
        else
        {
            carry = 0;
            l1->val = sum;
        }
        prev = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (carry)
    {
        prev->next = l1 ? l1 : l2;
        while (l1)
        {
            int sum = l1->val + carry;
            if (sum > 9)
            {
                carry = 1;
                l1->val = sum - 10;
            }
            else
            {
                carry = 0;
                l1->val = sum;
            }
            prev = l1;
            l1 = l1->next;
        }
        while (l2)
        {
            int sum = l2->val + carry;
            if (sum > 9)
            {
                carry = 1;
                l2->val = sum - 10;
            }
            else
            {
                carry = 0;
                l2->val = sum;
            }
            prev = l2;
            l2 = l2->next;
        }
        if (carry)
        {
            ListNode *node = new ListNode(carry);
            prev->next = node;
        }
    }
    else
        prev->next = l1 ? l1 : l2;
    return ans;
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

    ListNode *ans = addTwoNumbers(head1, head2);
    print(ans);

    return 0;
}