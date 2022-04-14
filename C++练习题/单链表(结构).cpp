/*


单链表(结构)

题目描述
单链表结点的存储结构SNode包含两部分：数据、下一结点指针。
单链表首个结点的地址head为表头指针,定义SNode *head=NULL表示单链表初始为空。
单链表的创建：createList(SNode *&head, int *value, int n)，用value数组中的n个数据生成一个单链表(表头指针为head)。
单链表的输出：printList(SNode *head),从头至尾遍历以head为表头的单链表，输出每个结点的数据值。
单链表数据插入: insertNode(SNode *head, int pos, int value),在单链表第pos(1<=pos<=L)个结点位置后插入新结点，数据为value。若插入不成功，输出error。 
单链表数据删除: removeNode(SNode *head, int pos), 删除单链表第pos(1<=pos<=L)个结点。若删除不成功，输出error。 
单链表的撤销：deleteList(SNode *head),删除以head为表头的单链表，即释放链表每个结点的堆内存。
注:不可以用任何形式的数组来实现链表，否则不计成绩。

输入
第一行：测试次数t
对每组测试数据，格式如下:
数据个数n 数据1 数据2 数据3 ... 数据n
插入次数m
插入位置1 数据1
...
插入位置m 数据m
删除次数o
删除位置1
...
删除位置o

输出
对每组测试数据:
输出创建链表后链表中全部结点的数据
对每组插入测试数据:
输出插入操作后链表中全部结点的数据
对每组删除测试数据:
输出删除操作后链表中全部结点的数据

样例输入
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

样例输出
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


按题目要求编写5个单链表函数。主函数调用相应函数实现链表的创建、
插入节点、删除节点、删除链表和输出链表的操作。


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
