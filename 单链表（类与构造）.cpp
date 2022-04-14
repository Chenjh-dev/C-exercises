/*

���������빹�죩

��Ŀ����
������ڵ�Ĵ洢�ṹΪ:
struct SNode
{
    int data;
    SNode *next;
};
���嵥������CList�����ݳ�Ա�б�ͷָ��(SNode *head)����Ա�����У�
1. ���캯������ʼ��head.
2. createList(int *value, int n): ��value�е�n�����ݴ���������.
3. printList(): ��headΪ��ͷ�������ÿ���ڵ������ֵ��
4. insertNode(int pos, int value): �ڵ������pos���ڵ�λ�ú�����½ڵ㣬����Ϊvalue������벻�ɹ����error��
5. removeNode(int pos): ɾ����pos���ڵ㣬��ɾ�����ɹ����error��
6. �����������ͷ�����ÿ���ڵ�Ķ��ڴ档

����
��һ�У����Դ���
ÿ�β��Ը�ʽΪ��
���ݸ���n ����1 ����2 ... ����n
�������m
����λ��1 ����1
...
����λ��m ����m
ɾ������k
ɾ��λ��1
...
ɾ��λ��k

���
ÿ�β��Բ����������ʽΪ��
������������ȫ���ڵ������
��ÿ�����������ݣ�
����������������ȫ���ڵ������
��ÿ��ɾ���������ݣ�
���ɾ������������ȫ���ڵ������

��������
2
5 2 3 5 7 3
2
1 40
7 60
2
7
3
6 1 2 10 0 1 5
2
1 40
7 60
2
1
3

�������
2 3 5 7 3
2 40 3 5 7 3
error
error
2 40 5 7 3
1 2 10 0 1 5
1 40 2 10 0 1 5
1 40 2 10 0 1 5 60
40 2 10 0 1 5 60
40 2 0 1 5 60
*/

#include<iostream>
using namespace std;

struct SNode
{
    int data;
    SNode *next;
};

class CList
{
	private:
		SNode *head;
	public:
		CList();
		void creatList(int *value,int n);
		void printList();
		int insertNode(int pos,int value);
		int removeNode(int pos);
		~CList();
};

CList::CList() 
{
	head = NULL;
}

void CList::creatList(int *value,int n)
{
	int i;
	SNode *p,*k;
	head = new SNode;
	head->data = value[0];
	head->next = NULL;
	k = head;
	for(i=1;i<n;i++)
	{
		p = new SNode;
		p->data = value[i];
		p->next = NULL;
		k->next = p;
		k = p;
	}
}

void CList::printList()
{
	SNode *p;
	p = head;
	while( p->next != NULL )
	{
		cout<<p->data <<' ';
		p = p->next ;
	}
	cout<<p->data <<endl;
}

int CList::insertNode(int pos,int value)
{
	int i;
	SNode *p,*k;
	p = new SNode;
	k = head;
	for(i=1 ; i<pos ; i++ )
		k = k->next ;
	if( k == NULL)
		return 0;
	else 
	{
		p->data = value;
		p->next = k->next ;
		k->next = p;
		return 1;
	}	
} 

int CList::removeNode(int pos)
{
	int i;
	SNode *p,*k;
	p = new SNode;
	k = head;
	if( pos == 1 )
	{
		head = head->next  ;
		delete k;
		return 1;
	}	
	else
	{
		for(i=1; i<pos-1 && k->next != NULL ; i++)
			k = k->next ;
		if(k->next == NULL )
			return 0;
		p = k->next ;
		if(p->next != NULL)
			k->next = p->next ;
		else
			k->next = NULL;
		delete p;
		return 1;
	}
} 

CList::~CList() 
{
	SNode *p,*k;
	p = head ; 
	while( p != NULL )
	{
		k = p;
		p = p->next ;
		delete k;
	}
}

int main()
{
	int t,i;
	cin>>t;
	int *value;
	while(t--)
	{
		CList a;
		int n;
		cin>>n;
		value = new int[n];
		for(i=0;i<n;i++)
			cin>>value[i];
		a.creatList(value,n);
		a.printList() ;
		int m;
		cin>>m;
		while(m--)
		{
			int pos,val;
			cin>>pos>>val;
			if( a.insertNode(pos,val) )
				a.printList() ;
			else 
				cout<<"error"<<endl;
		} 
		int k;
		cin>>k;
		while(k--)
		{
			int pos;
			cin>>pos;
			if( a.removeNode(pos) )
				a.printList() ;
			else
				cout<<"error"<<endl;
		}
	}
}



















