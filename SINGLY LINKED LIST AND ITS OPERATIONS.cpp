#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int key;
        Node* next;
};
Node* newnode(int data)
{
    Node* n = new Node();
    n->key = data;
    n->next = NULL;
    return n;
}
Node* insert_begin(int data,Node* head)
{
    Node* nn = newnode(data);
    if(head == NULL)
    { 
        head = nn;
    }
    else
    {
        nn->next = head;
        head = nn;
    }
    return head;
}
Node* insert_end(int data,Node* head)
{
    Node* nn = newnode(data);
    if(head == NULL)
    {
        head = nn;
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return head;
}
Node* insert_mid(int data,Node* head,int pos)
{
    Node* nn = newnode(data);
    if(head == NULL)
    {
        head = nn;
    }
    else if(pos==1)
    {
        Node* temp = head;
        nn->next = head;
        head = nn;
    }
    else
    {
        int count = 1;
        Node* temp = head;
        while(temp->next != NULL)
        {
            count++;
            if(count == pos)
            {
                break;
            }
            temp = temp->next;
        }
        if(count == pos)
        {
            nn->next = temp->next;
            temp->next = nn;
        }
        else
        {
            cout << "Invalid" << " ";
        }
    }
    return head;
}
Node* display(Node* head)
{
    Node*temp = head;
    while(temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << NULL << " " << endl;
    return head;
}
Node* delete_node(Node* head)
{
    Node* temp = head;
    if(head == NULL)
    {
        cout << "Invalid" << " ";
    }
    else if(head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    return head;
}
Node* delete_first(Node* head)
{
    if(head == NULL)
    {
        cout << "Invalid" << " ";
    }
    else
    {
        head = head->next;
    }
    return head;
}
Node* delete_pos(int pos,Node* head)
{
    if(head == NULL)
    {
        cout << "Invalid" << " ";
    }
    else if(pos == 1)
    {
        head = delete_first(head);
    }
    else
    {
        int count = 1;
        Node* temp = head;
        while(temp != NULL)
        {
            Node* temp1 = temp->next;
            count++;
            if(count == pos)
            {
                temp->next = temp1->next;
                //temp1->next = NULL;
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}
bool search_element(int data,Node* head)
{
    if(head == NULL)
    {
        cout << "Not found" << " ";
    }
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->key == data)
            {
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}
Node* displayreverse(Node* head)
{
    if(head==NULL)
    {
        cout << "No elements" << " ";
    }
    else if(head->next == NULL)
    {
        cout << "Only one element";
    }
    else
    {
        Node* temp1 = NULL;
        Node* temp2 = head;
        Node* temp3 = head->next;
        while(temp3!=NULL)
        {
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp2->next;
        }
        temp2->next = temp1;
        head = temp2;
    }
    return head;
}
int main() {
	Node* head = NULL;
	head = insert_begin(100,head);
	head = insert_begin(90,head);
	head = insert_end(110,head);
	head = insert_end(120,head);
	head = insert_end(130,head);
	head = insert_begin(80,head);
	head = insert_mid(70,head,1);
	//head = delete_node(head);
	//head = delete_pos(1,head);
	//head = delete_first(head);
	//bool a = search_element(110,head);
	//cout << "Searching result:" << a << endl;
	head = display(head);
	head = displayreverse(head);
	head = display(head);
	return 0;
}
