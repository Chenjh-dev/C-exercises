/*


������(�ṹ)

��Ŀ����
��������Ĵ洢�ṹSNode���������֣����ݡ���һ���ָ�롣
�������׸����ĵ�ַheadΪ��ͷָ��,����SNode *head=NULL��ʾ�������ʼΪ�ա�
������Ĵ�����createList(SNode *&head, int *value, int n)����value�����е�n����������һ��������(��ͷָ��Ϊhead)��
������������printList(SNode *head),��ͷ��β������headΪ��ͷ�ĵ��������ÿ����������ֵ��
���������ݲ���: insertNode(SNode *head, int pos, int value),�ڵ������pos(1<=pos<=L)�����λ�ú�����½�㣬����Ϊvalue�������벻�ɹ������error�� 
����������ɾ��: removeNode(SNode *head, int pos), ɾ���������pos(1<=pos<=L)����㡣��ɾ�����ɹ������error�� 
������ĳ�����deleteList(SNode *head),ɾ����headΪ��ͷ�ĵ��������ͷ�����ÿ�����Ķ��ڴ档
ע:���������κ���ʽ��������ʵ���������򲻼Ƴɼ���

����
��һ�У����Դ���t
��ÿ��������ݣ���ʽ����:
���ݸ���n ����1 ����2 ����3 ... ����n
�������m
����λ��1 ����1
...
����λ��m ����m
ɾ������o
ɾ��λ��1
...
ɾ��λ��o

���
��ÿ���������:
������������������ȫ����������
��ÿ������������:
������������������ȫ����������
��ÿ��ɾ����������:
���ɾ��������������ȫ����������

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


����ĿҪ���д5������������������������Ӧ����ʵ������Ĵ�����
����ڵ㡢ɾ���ڵ㡢ɾ��������������Ĳ�����


*/

#include<iostream>
using namespace std;

struct SNode
{
	int date;
	SNode *next;
};

void createList(SNode *&head, int *value, int n);
void printList(SNode *head);
int insertNode(SNode *head, int pos, int value);
int removeNode(SNode *&head, int pos);
void deleteList(SNode *head);


int main()
{
	int t;
	SNode *head = NULL;
	cin>>t;
	int *value;
	while(t--)
	{
		int n;
		cin>>n;
		value = new int[n];
		for(int i=0;i<n;i++)
			cin>>value[i];
		createList(head, value, n);
		printList(head);
		int m;
		cin>>m;
		while(m--)
		{
			int k1,k2;
			cin>>k1>>k2;
			if( insertNode(head,k1,k2) )
				printList(head);
			else
				cout<<"error"<<endl;
		}
		int o;
		cin>>o;
		while(o--)
		{
			int k3;
			cin>>k3;

			if( removeNode(head,k3) )
				printList(head);
			else
				cout<<"error"<<endl;
		}
		delete [] value;
		deleteList(head);
	}
}

void createList(SNode *&head, int *value, int n)
{
	int i;
	head = new SNode;
	SNode *ps,*pk;
	head->date = value[0];
	head->next = NULL;
	pk = head;	
	for( i=1 ; i<n ;i++)
	{
		ps = new SNode;
		ps->date = value[i];
		ps->next = NULL;
		pk->next = ps;
		pk = ps;
	}
}

void printList(SNode *head)
{
	int i;
	SNode *p;
	p = head;
	for( i=0; p->next != NULL ; i++ )
	{
		cout<< p->date <<" ";
		p = p->next ;
	}
	cout<< p->date <<endl;
}

int insertNode(SNode *head, int pos, int value)
{
	int i;
	SNode *ps,*pk;
	ps = new SNode;
	pk = head;
	for(i=1; i<pos ;i++ )
	{
		pk = pk->next ;
	}
	if(pk==NULL)
		return 0;
	else
	{
		ps->next =pk->next ;
		ps->date = value;
		pk->next  =ps ;
		return 1;
	}
}

int removeNode(SNode *&head, int pos)
{
	int i;
	SNode *p,*k;
	k = head ;
	if(pos == 1)
	{
		head = head->next ; 
		delete k;
		return 1;
	}
	else
	{
		for( i=1 ; i < pos-1 && k->next != NULL ; i++)	
			k = k->next;	
		if( k->next == NULL )
			return 0;
		else
		{
			p = k->next ;
			if(p->next == NULL)   
				k->next =NULL;
			else  
				k->next = p->next ;	
			delete p;
			return 1;
		}
	}
}

void deleteList(SNode *head)
{
	SNode *p,*q;
	p = head;
	for( ; p != NULL ; )
	{
		q = p;
		p = p->next ;
		delete q;
	}
}
