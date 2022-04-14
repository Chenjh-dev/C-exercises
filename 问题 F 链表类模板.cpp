/*
问题 F: 链表类模板

题目描述
结点数据类型为int的单链表类CIntList可定义如下:
class CNode
{
public:
int data;
CNode *next;
};
class CIntList
{
private:
CNode *head;
public:
CIntList();
void append(int a); //加到链表最后
void insert(int a, int n); //在第n个结点后加
void remove(int n); //移除第n个结点
int get(int n); //返回第n个结点的数据
void set(int a, int n); //将第n个节点的数据改成a
void print();
~CIntList();
};
试将其改成结点数据类型用参数表示的类模板CList。

输入
第一行输入测试次数
每次测试输入5行,格式为：
数据类型(I:int, D:double, S:string) 数据个数n 数据1 数据2 ... 数据n
插入节点号(0表示插在第1个结点前面) 数据
返回结点号
删除结点号
修改结点号 数据

输出
每次测试输出二行.第1行输出返回操作获得的数据(如出错则输出error),
第2行输出所有操作后链表全部结点的数据.

样例输入
3
I 5 2 3 5 7 3
1 40
7
7
6 -10
D 6 1.1 2.3 10.05 0.0 -1.8 5.9
4 60.4
5
1
3 -3.7
S 4 this is a test.
0 good
1
8
4 work

样例输出
error
2 40 3 5 7 -10
60.4
2.3 10.05 -3.7 60.4 -1.8 5.9
good
good this is work test.

按题目要求定义一个类模板，并在主函数输入数据定义对象并调用相应成员函数实现程序功能。

*/

#include<iostream>
using namespace std;

template <class T>
class CNode
{
	public:
		T data;
		CNode *next;
		CNode(){}
};

template <class T>
class CList
{
	private:
		CNode<T> *head;
		int length; 
	public:
		CList(T a)
		{
			head=new CNode<T>;
			head->data=a;
			head->next=NULL;
			length=0;
		}
		void append(T a) //加到链表最后
		{
			CNode<T> *p,*pnew;
			p=head;
			pnew = new CNode<T>;
			pnew->data =a;
			pnew->next =NULL;
			while(p->next!=NULL)
			{
				p=p->next ;
			}
			p->next = pnew;
			length++;
		}
		void insert(T a, int n) //在第n个结点后加
		{
			int i;
			CNode<T> *p,*pnew;
			p=head;
			pnew = new CNode<T>;
			for(i=0;i<n;i++)
				p = p->next ;
			pnew->data = p->data ;
			pnew->next = p->next ;
			p->data = a;
			p->next = pnew ;
		}
		int remove(int n) //移除第n个结点
		{
			int i;
			CNode<T> *p,*pnew;
			p=head;
			if(n==1)
			{
				head=head->next ;
				delete p;
				return 1;
			}
			else
			{
				for(i=1;i<n-1;i++)
					p = p->next ;
				pnew=p->next ;
				
				if(pnew->next!=NULL)
					p->next =pnew->next ;
				else 
					p->next =NULL;
				delete pnew;
				return 1;
			}	
		}
		T get(int n) //返回第n个结点的数据
		{
			int i;
			CNode<T> *p;
			p=head;
			for(i=0;i<n-1;i++)
					p = p->next ;
			return p->data ;
		}
		void set(T a, int n) //将第n个节点的数据改成a
		{
			int i;
			CNode<T> *p;
			p=head;
			for(i=0;i<n-1;i++)
					p = p->next ;
			p->data = a;
		}
		void print()
		{
			int i;
			CNode<T> *p;
			p=head;
			for(i=0;p->next!=NULL;i++)
			{
				cout<<p->data <<" ";
				p = p->next ;
			}
			cout<<p->data <<endl;		
		}
		~CList()
		{
			int i;
			CNode<T> *p,*pnew;
			p=head;
			while(p!=NULL)
			{
				pnew=p;
				p=p->next;
				delete pnew; 
			}
		}
};

int main()
{
	int t,n,i,length;
	char judge;
	cin>>t;
	while(t--)
	{
		cin>>judge>>length;
		if(judge=='I')
		{
			int a;
			cin>>a;
			CList<int> h(a);
			for(i=0;i<length-1;i++)  //建表 
			{
				cin>>a;
				h.append(a) ;
			}
			
			cin>>n>>a;               //插入 
			h.insert(a,n);
			
			cin>>n;                  //返回 
			if(n<length)
				cout<<h.get(n)<<endl;  
			else
				cout<<"error"<<endl;
			
			cin>>n;                  //删除 
			if(n<length+1)
				h.remove(n); 
			
			cin>>n>>a;
			h.set(a,n);
			h.print() ; 
		}
		else if(judge=='D')
		{
			double a;
			cin>>a;
			CList<double> h(a);
			for(i=0;i<length-1;i++)  //建表 
			{
				cin>>a;
				h.append(a) ;
			}
			
			cin>>n>>a;               //插入 
			h.insert(a,n);
			
			cin>>n;                  //返回 
			if(n<length)
				cout<<h.get(n)<<endl;  
			else
				cout<<"error"<<endl;
			
			cin>>n;                  //删除 
			if(n<length+1)
				h.remove(n); 
			
			cin>>n>>a;
			h.set(a,n);
			h.print() ; 
		}
		else if(judge=='S')
		{
			string a;
			cin>>a;
			CList<string> h(a);
			for(i=0;i<length-1;i++)  //建表 
			{
				cin>>a;
				h.append(a) ;
			}
			
			cin>>n>>a;               //插入 
			h.insert(a,n);
			
			cin>>n;                  //返回 
			if(n<length)
				cout<<h.get(n)<<endl;  
			else
				cout<<"error"<<endl;
			
			cin>>n;                  //删除 
			if(n<length+1)
				h.remove(n); 
			
			cin>>n>>a;
			h.set(a,n);
			h.print() ; 
		}
		else
			cout<<"error"<<endl; 
	}
}
















