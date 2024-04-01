#include <iostream>
using namespace std;
struct irfan
{
	int data;
	irfan* link;
};
irfan * head = 0;
void insert(int v)
{
	if (head == 0)
	{
		irfan * temp = new irfan();
		temp->data = v;
		temp->link = temp;
		head =temp;
	}
	else
	{
		irfan * temp = new irfan();
		temp->data = v;
		temp->link = head;
		irfan * temp1 = head;
		while (temp1->link != head)
		{
			temp1= temp1->link;
		}
		temp1->link = temp;
		
	}
	
}
void display()
{
	if (head == 0)
	{
		cout <<"\nnothing to display\n";
	}
	else 
	{
		irfan * temp = head ;
		do
		{
			cout<<temp->data <<"  " <<temp->link << endl;
			temp= temp->link;
		}
		while(temp!= head);
		
	}
	
}
void search(int n)
{
	int c=-1;
	irfan * temp = head;
	do
	{
		if(temp->data == n)
		{
			c=n;
			cout <<"target element is found '" <<n<<"'. " <<endl;
		}
		temp= temp->link;
	}
	while(temp != head);
	if(c == -1)
	{
		cout <<"sorry target element is not found"<<endl;
	}
}
void dlt()
{
	if (head == 0)
	{
		cout <<"\nnothing to delete\n";
	}
	irfan * temp = head;
	irfan * temp1 = temp->link;
	if(temp == temp1)
	{
		cout<<"\nlast element in the list\n";
		head = 0;
		delete temp;
	}
	while(temp1->link != head)
	{
		temp = temp1;
		temp1 = temp->link;
	}
	
	temp->link = head;
	delete temp1;
   
}
void selectionSort()
{
	irfan *sort = head;
	do 
	{
		irfan * temp = sort;
		irfan * temp1 = sort->link;
		while(temp1 != head)
		{
			if(temp->data > temp1->data)
			{
				temp = temp1;
			}
			temp1 = temp1->link;
		}
		if(temp != sort)
		{
			int swap = temp->data;
			temp->data = sort->data;
			sort->data = swap;
		}
		sort= sort->link;
	}while(sort != head);
	irfan * dis= head;
	do{
		cout<<dis->data <<"\t" <<dis->link << endl;
		dis=dis->link;
	}while(dis != head);
}
int main()
{
    int n, choice;
	while (true)
	{
	cout <<"1. insert\n";
    cout <<"2. search\n";
    cout <<"3. delete\n";
    cout <<"4. display\n";
    cout <<"5. sorting\n";
    cin >>choice;
	switch(choice)
	{
		case 1:
			{
				cout<< "enter the data: ";
				cin >> n;
				insert(n);
				break;
			}
		case 2:
			{
				cout <<"enter the target element to search: ";
				cin>> n;
				search(n);
				break;
			}
		case 3:
			{
				dlt();
				break;
			}
		case 4:
			{
				display();
				break;
			}
		case 5:
			{
				selectionSort();
				break;
			}
		default:
			cout <<"invalid";
	}
}
}


