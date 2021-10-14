// code in c++ of singly linked list creation , traversal , insertion and deletion

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void create_linked_list()
{
    printf("enter the data ");
    char choice = 'Y';
    while (choice == 'Y')
    {
        node *temp, *newnode;
        newnode = (node *)malloc(sizeof(struct node));
        cin >> newnode->data;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "to continue entering the elements, press Y else press any key  ";
        cin >> choice;
    }
}

void print()
{
    node *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "\nNo elements to be printed" << endl;
    }
    else
    {
        cout << endl;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << "\n";
}

void insert_at_beg()
{
    cout << "Enter the data to be insert at beginning";
    node *newnode;
    newnode = (node *)malloc(sizeof(struct node));
    cin >> newnode->data;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        return;
    }
    newnode->next = head;
    head = newnode;
    return;
}

void insert_at_end()
{
    cout << "Enter the data to be insert at last";
    node *newnode, *temp = head;
    newnode = (node *)malloc(sizeof(struct node));
    cin >> newnode->data;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    return;
}

void insert_at_pos()
{
    cout << "Enter the position ";
    int pos;
    cin >> pos;
    if (pos <= 0)
    {
        cout << "Invalid position";
        return;
    }
    else if (pos == 1)
    {
        insert_at_beg();
        return;
    }
    cout << "Enter the data to be inserted";
    node *newnode, *temp = head;
    newnode = (node *)malloc(sizeof(struct node));
    cin >> newnode->data;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        return;
    }
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return;
}

void delete_from_beg()
{
    if (head == NULL)
    {
        cout << "linked list is empty";
        return;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    return;
}

void delete_from_end()
{
    node *temp = head, *temp2;
    if (head == NULL)
    {
        cout << "linked list is empty";
        return;
    }
    while (temp->next != NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    if(temp==head){
        head=NULL;
    }
    temp2->next = NULL;
    free(temp);
    return;
}

void delete_from_pos()
{
    cout << "Enter the position ";
    int pos;
    cin >> pos;
    if (pos <= 0)
    {
        cout << "Invalid position";
        return;
    }
    else if (pos == 1)
    {
        delete_from_beg();
        return;
    }
    if (head == NULL)
    {
        cout << "linked list is empty";
        return;
    }
    node *temp = head, *temp2;
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    return;
}

int main()
{
    create_linked_list();
    int c = 0;
    while (c != 8)
    {
        cout << "\n For singly linked list , press :\n 1. print \n 2. insert node at beginning\n 3. insert node at end\n 4. insert node at given position\n 5. delete node from beginning \n 6. delete node from end\n 7. delete node from given position \n 8. exit \n \n your choice:  ";
        cin >> c;
        switch (c)
        {
        case 1:
            print();
            break;
        case 2:
            insert_at_beg();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            insert_at_pos();
            break;
        case 5:
            delete_from_beg();
            break;
        case 6:
            delete_from_end();
            break;
        case 7:
            delete_from_pos();
            break;
        case 8:
            exit(0);
        default:
            cout << "incorrect number";
        }
    }
    return 0;
}

