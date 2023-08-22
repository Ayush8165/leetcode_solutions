#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    // Constructor
    Node(int value)
    {
        val = value;
        next = NULL;
        random = NULL;
    }
};

void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node *copyRandomList(Node *head)
{
    Node *temp = head;
    Node *copyHead = NULL;

    // make structure of list
    while (temp != NULL)
    {
        insert(copyHead, temp->val);
        temp = temp->next;
    }

    // connecting randoms
    temp = head;
    Node *temp2 = head;

    Node *copyTemp = copyHead;
    Node *copyTemp2 = copyHead;

    while (temp != NULL)
    {
        Node *it = temp->random;

        temp2 = head;
        copyTemp2 = copyHead;
        while (temp2 != it and temp2 != NULL)
        {
            temp2 = temp2->next;
            copyTemp2 = copyTemp2->next;
        }
        copyTemp->random = copyTemp2;

        temp = temp->next;
        copyTemp = copyTemp->next;
    }
    return copyHead;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        // Add insert function of linkedlist : "linkedlistinsert"
        insert(head, temp);
    }

    return 0;
}