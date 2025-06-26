#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int a)
	{
		data=a;
		next=NULL;
	}
};

class sll
{
	Node* head;

public:
	sll()
	{
		head=NULL;
	}

	void inserth(int a)
	{
		Node* newnode=new Node(a);
		newnode->next=head;
		head=newnode;
	}

	void insertt(int b)
	{
		Node* newnode=new Node(b);
		if(head==NULL)
		{
			head=newnode;
			//return;
		}

		Node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}

	void deleteh()
	{
		Node* temp=head;
		head=head->next;
		delete temp;

		display();
	}

	void deletet()
	{
		if (head == NULL)
		{
			cout << "List is empty!\n";
			return;
		}
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			display();
			return;
		}

		Node* temp = head;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;

		display();
	}

	void deleteany(int value)
	{
		if(head==NULL)  return;
		if(head->data==value)
		{
			Node* temp=head;
			head=head->next;
			delete temp;
			return ;
		}

		Node* temp=head;
		while(temp->next!=NULL && temp->next->data!=value)
		{
			temp=temp->next;
		}

		if(temp->next==NULL) return;
		Node* todelete=temp->next;
		temp->next=temp->next->next;
		delete todelete;

		// display();
	}

	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL\n";
	}

};


int main()
{
	sll s;
	int a;
	do
	{
		cout<<"\n\nWHAT DO YOU WANT TO DO?";
		cout<<"\n1.ADD ELEMENT AT HEAD\n2.ADD ELEMENT AT TAIL\n3.REMOVE ELEMENT FROM HEAD\n4.REMOVE ELEMENT AT TAIL\n5.REMOVE ANY ELEMENT\n6.DISPLAY SLL\n7.EXIT";
		cout<<"\nSELECTION:";
		cin>>a;
		switch(a)
		{
		case 1:
		{
			cout<<"ENTER ELEMENT TO INSERT:";
			int b;
			cin>>b;
			s.inserth(b);
			break;
		}

		case 2:
		{
			cout<<"ENTER ELEMENT TO INSERT:";
			int b;
			cin>>b;
			s.insertt(b);
			break;
		}

		case 3:
		{
			cout<<"PERFORMING DELETE OPERATION:\n\t\t";
			s.deleteh();
			break;
		}

		case 4:
		{
			cout<<"PERFORMING DELETE OPERATION:\n\t\t";
			s.deletet();
			break;
		}

		case 5:
		{

			cout<<"ENTER ELEMENT TO DELETE:";
			int b;
			cin>>b;
			s.deleteany(b);
			break;
		}

		case 6:
		{
			cout<<"ELEMENTS IN SLL:";
			s.display();
			break;
		}

		case 7:
			cout<<"EXITED";
			break;

		default:
			cout<<"INAVLID CHOICE!";
		}
	} while(a!=7);
	return 0;
}
