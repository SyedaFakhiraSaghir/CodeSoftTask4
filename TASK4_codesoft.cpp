#include <iostream>
using namespace std;

class Node{
	public:
		bool complete;
		string TaskName;
		string task;
		Node *next;
		Node()
		{
			complete=0;
			next=NULL;
		}
		Node(string t, string task)
		{
			complete=0;
			TaskName=t;
			this->task=task;
			next=NULL;
		}
};

class Tasks{
	public:
		Node *head;
		Node *tail;
		void InsertTask(string te, string task)
		{
			Node *t = new Node(te,task);
			if(head==NULL)
			{
				head=t;
				tail=t;
				return;
			}
			else
			{
				Node *n=head;
				while(n->next!=NULL)
				{
					n=n->next;
				}
				n->next=t;
				tail=t;
			}
			return;
		}
		void RemoveTask(string t)
		{
			if(head==NULL)
			{
				return;
			}
			Node *n=head;
			if(n->TaskName==t)
			{
				head=n->next;
				delete n;
				n=NULL;
				return;
			}
			while(n->next->TaskName!=t)
			{
				n=n->next;
			}
			if(n->next->next==NULL)
			{
				tail=n;
				Node *temp=n->next;
				delete temp;
				temp=NULL;
				return;
			}
			if(n->next!=NULL)
			{
				Node *temp1=n->next;
				n->next=n->next->next;
				delete temp1;
				temp1=NULL;
				return;
			}
		}
		void viewTasks()
		{
			Node *t=head;
			while(t!=NULL)
			{
				cout<<"\n-------------------------------------";
				cout<< "\nTask Name : " << t->TaskName <<endl;
				cout<< "Task Status : " << t->complete <<endl;
				cout<< "Task : " << t->task <<endl << endl;
				cout<<"-------------------------------------\n";
				t=t->next;
			}
		}
		void MarkasDone(string taskname, bool c)
		{
			Node *t=head;
			while(t!=NULL)
			{
				if(t->TaskName==taskname)
				{
					t->complete=c;
				}
				t=t->next;
			}
		}
};

main()
{
	Tasks t;
	cout<<endl<<"****************************************************************************"<<endl ;
	cout<<"*********************** T A S K    M A N A G E R **********************" << endl;
	cout<<"****************************************************************************" << endl;
	bool complete;
	string TaskName;
	string task;
	int choice;
	while(1)
	{
		again:
		cout << "\nPress\n1. Enter a Task\n2. Mark Task as completed\n3. Remove a Task\n4. View Tasks\n";
		cin >> choice;
		switch(choice)
		{
			case 1:
				{
					cout<<"\nEnter Task Name : ";
					cin>>TaskName;
					cout<<"\nEnter Task : ";
					cin>>task;
					t.InsertTask(TaskName, task);
					break;
				}
			case 2:
				{
					cout<<"\nEnter Task Name : ";
					cin>>TaskName;
					cout<<"\nTask status : ";
					cin>> complete;
					t.MarkasDone(TaskName, complete);
					break;
				}
			case 3:
				{
					cout<<"\nEnter Task Name : ";
					cin>>TaskName;
					t.RemoveTask(TaskName);
					break;
				}
			case 4:
				{
					t.viewTasks();
					break;
				}
			default:
				{
					goto again;
					
				}
		}
	}
}