
// Will not run, as lists provided are not linked as in LEETCODE

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

int findLength(ListNode *node)
{
    int c = 0;
    while (node != NULL)
    {
        c++;
        node = node->next;
    }
    return c;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *dA = headA;
    ListNode *dB = headB;

    int lenA = findLength(dA);
    int lenB = findLength(dB);

    int diff = abs(lenA - lenB);

    ListNode *lh = headA;
    ListNode *sh = headB;

    if (lenA < lenB)
    {
        sh = headA;
        lh = headB;
    }

    // diff--;
    while (diff--)
    {
        lh = lh->next;
    }

    while (sh != lh)
    {
        sh = sh->next;
        lh = lh->next;
        if (sh == NULL and lh == NULL)
        {
            return NULL;
        }
    }
    return sh;
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
    ListNode *ans = getIntersectionNode(head1, head2);
    cout << ans->val;

    return 0;
}