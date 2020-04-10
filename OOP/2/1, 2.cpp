#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <windows.h>

using namespace std;

struct list
{
	int a;
	list* next;
	list* prev;
};

class listc
{
public:
	list *head, *tail;
	int length;
	listc() : head(NULL), tail(NULL)
	{
		length = 0;
	}
	void push(int i)
	{
		length++;
		if (head == NULL)
		{
			struct list* tmp = new list;
			tmp->a = i;
			tmp->next = NULL;
			tmp->prev = NULL;
			head = tmp;
			tail = tmp;
		}
		else
		{
			struct list* tmp = new list;
			tmp->a = i;
			tmp->next = NULL;
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
		}
	}
	void output()
	{
		struct list* tmp = head;
		if (tmp == NULL) cout << "������ ����" << endl;
		else
		{
			while (tmp->next != NULL)
			{
				cout << tmp->a << " ";
				tmp = tmp->next;
			}
			cout << tmp->a <<" ";
		}
		cout << endl;
		cout << "����� ������: " << length << endl;
	}
	int popq()
	{
		int s;
		length--;
		//cout << length;
		if (head != tail)
		{
			s = head->a;
			head = head->next;
			delete head->prev;
			head->prev = NULL;
			return s;
		}
		else if (length!=-1)
		{
			s = head->a;
			head = tail = NULL;
			return s;
		}
		length = 0;
		return -1;
	}
	int pop()
	{
		int s;
		length--;
		if (tail != head)
		{
			s = tail->a;
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
			return s;
		}
		else if(length != -1)
		{
			s = tail->a;
			tail = head = NULL;
			return s;
		}
		length = 0;
		return -1;
	}
	void add(int i, int k)
	{
		if (k < length)
		{
			list* tmp = head, *temp, *p;
			for (int i = 1; i < k; i++)
			{
				tmp = tmp->next;
			}
			temp = tmp->next;
			p = tmp;
			tmp->next = new list;
			tmp = tmp->next;
			tmp->a = i;
			tmp->prev = p;
			tmp->next = temp;
			temp->prev = tmp;
			length++;
		}

		else if (k == length)
		{
			push(i);
		}
		else
			cout << "There isn't this number. Length of list: " << length << endl;
	}
	void PressF(int k)
	{
		{
			//cout << length << k << endl;
			if (k < length)
			{
				list* tmp = head, *temp, *p;
				for (int i = 1; i < k; i++)
				{
					tmp = tmp->next;
				}
				p = tmp->prev;
				temp = tmp->next;
				if (p != NULL)
					p->next = tmp->next;
				if (temp != NULL)
					temp->prev = tmp->prev;
				delete tmp;
				length--;
			}
			else if (k == length)
			{
				pop();
			}
			/*else
				//cout << "There isn't this number. Length of list: " << length << endl;*/
		}
	}
	void swap(int p, int k)
	{
		if ((k <= length)&&(p<=length))
		{
			list* tmp = head, *temp, *tt;
			for (int i = 1; i < p; i++)
			{
				tmp = tmp->next;
			}
			tt = tmp;
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			tmp = head;
			for (int i = 1; i < k; i++)
			{
				tmp = tmp->next;
			}
			temp = tmp->next;
			tmp->next = tt;
			tt->prev = tmp;
			tt->next = temp;
			temp->prev = tt;
		}
		else
			cout << "There isn't this number. Length of list: " << length << endl;
	}
	int check(int i)
	{
		list *tmp = head;
		while (tmp != NULL)
		{
			if (tmp->a == i) return 0;
			tmp = tmp->next;
		}
		return 1;
	}
	void clear(){
    list *temp = head;
	while(head!=NULL){
		temp=head->next;
		delete head;
		head=temp;
	}
	length = 0;
}
};

int main()
{
	//setlocale(LC_ALL, "Rus");	
	srand(time(NULL));
	
	const int N = 50;
	char ch;
	int value;
	int a[N];
	listc ah;
	while (ch != '0')
	{
		system("CLS");
		cout << "1. ������������ ������ ������ ���������" << endl;
		cout << "2. ���������� �����" << endl;
		cout << "3. ���������� �������" << endl;
		cout << "0. �����" << endl;
		cin >> ch;
		system("CLS");
		switch (ch)
		{
			case '1':
				cout << "�������� ������ - ";
				for (int i = 0; i < N; i++)
				{
					a[i] = rand() % 100;
					cout << a[i] << " ";
				}
				cout << endl;
				
				for(int i = 0; i < N; i++)
				{
					if (ah.check(a[i]))
					{
						for (int j = 0; j < 100; j++)
						{
							if (a[i] == j*j)
							{
								ah.push(a[i]);
							}
						}
					}
				}
				cout << "������ �������� - ";
				ah.output();
				ah.clear();
				break;
			case '2':
   
				for (int i = 0; i < 10; i++)
				{
					ah.push(rand()%100);
					ah.output();
					Sleep(500);
					system("CLS");
				}
				for (int i = 0; i < 10; i++)
				{
					ah.pop();
					ah.output();
					Sleep(500);
					system("CLS");
				}
				break;
			case '3':
				for (int i = 0; i < 10; i++)
				{
					ah.push(rand() % 100);
					ah.output();
					Sleep(500);
					system("CLS");
				}
				for (int i = 0; i < 10; i++)
				{
					ah.popq();
					ah.output();
					Sleep(500);
					system("CLS");
				}
				break;
			default:
				break;
		}
		system("pause");
	}

	return 0;
}
