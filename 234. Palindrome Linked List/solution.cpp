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

bool isPalindrome(ListNode *head)
{
    vector<int> sample;
    ListNode *temp = head;
    while (temp != NULL)
    {
        sample.push_back(temp->val);
        temp = temp->next;
    }

    vector<int> sample2 = sample;
    reverse(sample2.begin(), sample2.end());
    if (sample2 == sample)
    {
        return true;
    }
    else
    {
        return false;
    }
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

    cout << isPalindrome(head);
    return 0;
}