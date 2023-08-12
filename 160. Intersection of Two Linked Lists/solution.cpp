#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // Constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node *reverseList(node *head)
{
    node *prev = NULL;
    node *current = head;
    node *next = head;

    while (current != NULL)
    {
        next = next->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void insert(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print(node *head)
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

    node *head = NULL;

    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int value;
        cin >> value;
        insert(head, value);
    }

    node *newHead = reverseList(head);

    print(newHead);

    return 0;
}