/*
���� F: ������ģ��

��Ŀ����
�����������Ϊint�ĵ�������CIntList�ɶ�������:
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
void append(int a); //�ӵ��������
void insert(int a, int n); //�ڵ�n�������
void remove(int n); //�Ƴ���n�����
int get(int n); //���ص�n����������
void set(int a, int n); //����n���ڵ�����ݸĳ�a
void print();
~CIntList();
};
�Խ���ĳɽ�����������ò�����ʾ����ģ��CList��

����
��һ��������Դ���
ÿ�β�������5��,��ʽΪ��
��������(I:int, D:double, S:string) ���ݸ���n ����1 ����2 ... ����n
����ڵ��(0��ʾ���ڵ�1�����ǰ��) ����
���ؽ���
ɾ������
�޸Ľ��� ����

���
ÿ�β����������.��1��������ز�����õ�����(����������error),
��2��������в���������ȫ����������.

��������
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

�������
error
2 40 3 5 7 -10
60.4
2.3 10.05 -3.7 60.4 -1.8 5.9
good
good this is work test.

����ĿҪ����һ����ģ�壬�����������������ݶ�����󲢵�����Ӧ��Ա����ʵ�ֳ����ܡ�

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
		void append(T a) //�ӵ��������
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
		void insert(T a, int n) //�ڵ�n�������
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
		int remove(int n) //�Ƴ���n�����
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
		T get(int n) //���ص�n����������
		{
			int i;
			CNode<T> *p;
			p=head;
			for(i=0;i<n-1;i++)
					p = p->next ;
			return p->data ;
		}
		void set(T a, int n) //����n���ڵ�����ݸĳ�a
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
			for(i=0;i<length-1;i++)  //���� 
			{
				cin>>a;
				h.append(a) ;
			}
			
			cin>>n>>a;               //���� 
			h.insert(a,n);
			
			cin>>n;                  //���� 
			if(n<length)
				cout<<h.get(n)<<endl;  
			else
				cout<<"error"<<endl;
			
			cin>>n;                  //ɾ�� 
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
			for(i=0;i<length-1;i++)  //���� 
			{
				cin>>a;
				h.append(a) ;
			}
			
			cin>>n>>a;               //���� 
			h.insert(a,n);
			
			cin>>n;                  //���� 
			if(n<length)
				cout<<h.get(n)<<endl;  
			else
				cout<<"error"<<endl;
			
			cin>>n;                  //ɾ�� 
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
			for(i=0;i<length-1;i++)  //���� 
			{
				cin>>a;
				h.append(a) ;
			}
			
			cin>>n>>a;               //���� 
			h.insert(a,n);
			
			cin>>n;                  //���� 
			if(n<length)
				cout<<h.get(n)<<endl;  
			else
				cout<<"error"<<endl;
			
			cin>>n;                  //ɾ�� 
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
















