/*

单链表（类与构造）

题目描述
单链表节点的存储结构为:
struct SNode
{
    int data;
    SNode *next;
};
定义单链表类CList，数据成员有表头指针(SNode *head)，成员函数有：
1. 构造函数：初始化head.
2. createList(int *value, int n): 用value中的n个数据创建单链表.
3. printList(): 以head为表头依次输出每个节点的数据值。
4. insertNode(int pos, int value): 在单链表第pos个节点位置后插入新节点，数据为value。如插入不成功输出error。
5. removeNode(int pos): 删除第pos个节点，若删除不成功输出error。
6. 析构函数：释放链表每个节点的堆内存。

输入
第一行：测试次数
每次测试格式为：
数据个数n 数据1 数据2 ... 数据n
插入次数m
插入位置1 数据1
...
插入位置m 数据m
删除次数k
删除位置1
...
删除位置k

输出
每次测试产生的输出格式为：
输出创建链表后全部节点的数据
对每组插入测试数据：
输出插入操作后链表全部节点的数据
对每组删除测试数据：
输出删除操作后链表全部节点的数据

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



















