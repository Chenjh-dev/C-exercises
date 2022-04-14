#include<iostream>
using namespace std;

const int hmax=26; 

class Info 
{ 
	private: 
		//联系人，用一个链表结点表示
		string name; //姓名
		int phoneNo; //电话
	public:
		Info* next;  //指向下一个结点
		Info(string tn= "no name", int pno=0)
		{	
			name = tn;
			phoneNo = pno;
			next = NULL; 
		}
		void Print()
		{	cout<<name<<"--"<<phoneNo<<endl;	}
		//属性的get和set方法....自行定义
		string get()
		{
			return name;
		}
		int getphone()
		{
			return phoneNo;
		}
		void set(string a,int b)
		{
			if(next==NULL)
			{	
				name=a;
				phoneNo=b;
			}
			else
			{
				Info *p;
				p=next;
				while(p->next!=NULL)
					p=p->next;
				p->name=a;
				p->phoneNo=b;
			}
		}
};

class PhoneBook
{
	public:
		Info Table[hmax];
		void Input()
		{
			int n,phone;
			string name;
			cin>>n;
			while(n--)
			{
				cin>>name>>phone;
				if(Table[name[0]-65].getphone()==0)
					Table[name[0]-65].set(name,phone);
				else
					this->insert(name,phone); 
			}
		}
		Info* find(string a)
		{
			Info *p;
			if(Table[a[0]-65].get()==a)
			{
				p=new Info;
				p->set(Table[a[0]-65].get(),Table[a[0]-65].getphone());
				return p;
			}
			else if(Table[a[0]-65].next==NULL)
				return NULL;
			p=Table[a[0]-65].next; 
			while(p->get()!=a&&p->next!=NULL)
				p=p->next;
				
			if(p->get()==a)
				return p;
			else 
			{
				p=NULL;
				return p;
			}
				
		}
		Info* operator () (string a)
		{
			return find(a); 
		}
		void insert(string a,int b)
		{
			Info *p;
			p=new Info;
			p->next=Table[a[0]-65].next;
			p->set(Table[a[0]-65].get(),Table[a[0]-65].getphone());
			Table[a[0]-65].set(a,b);
			Table[a[0]-65].next=p;
		}
		void operator += (Info &h)
		{
			if(this->find(h.get()))
				Table[h.get()[0]-65].set(h.get(),h.getphone());
			else 
				this->insert(h.get(),h.getphone());
		}
		PhoneBook operator + (PhoneBook &h)
		{
			this->combine(h);
			return *this; 
		}
		void combine(PhoneBook &a)
		{
			int i,j;
			Info *h,p;
			for(i=0;i<hmax;i++)
			{
				if(a.Table[i].getphone()==0)
					continue;
				p.set(a.Table[i].get(),a.Table[i].getphone());
				p.next=NULL;
				*this += a.Table[i];
				
				if(a.Table[i].next==NULL)
					continue;
				h=a.Table[i].next;
				
				while(h->next != NULL)
				{
					p.set(h->get(),h->getphone());
					*this += p;
					h=h->next;
				}
				p.set(h->get(),h->getphone());
				*this += p;	
			}
		}
		void Print()
		{
			char k;
			int i;
			Info *p;
			for(i=0;i<hmax;i++)
			{
				if(Table[i].getphone()==0)
					continue;
				k=65+i;
				cout<<k<<"--"<<Table[i].get()<<"."<<Table[i].getphone()<<"--";
				if(Table[i].next==NULL)
				{
					cout<<endl;
					continue;
				}
					
				p=Table[i].next;
				while(p->next!=NULL)
				{
				//	if(p->getphone()!=0)
					cout<<p->get()<<"."<<p->getphone()<<"--";
					p=p->next;
				}
				if(p->getphone()!=0)
					cout<<p->get()<<"."<<p->getphone()<<"--";
				cout<<endl;
			}
		}
};

int main()
{	
	string tname;
	int i, tno;
	Info *p;
	PhoneBook pb;
	pb.Input();
	for(i=0; i<2; i++)
	{	
		cin>>tname;
		p = pb(tname);
		if (p)	p->Print();
		else cout<<"查找失败"<<endl;
	}
	cin>>tname>>tno;
	Info temp(tname, tno);
	pb += temp;
	PhoneBook pc;
	pc.Input();cout<<"1"<<endl;pb.Print();cout<<"2"<<endl;pc.Print();cout<<"3"<<endl;
	pb = pb+pc;
	pb.Print();
	return 0;
}

/*
int main()
{	
	string tname;
	int i, tno;
	Info *p;
	PhoneBook pb;
	pb.Input(); //接收输入数据，初始化第一个通讯录
	//两次姓名查找
	for(i=0; i<2; i++)
	{	
		cin>>tname;
		p = pb(tname); //调用()运算符，实现查找
		if (p)	p->Print(); //查找成功，输出联系人信息
		else cout<<"查找失败"<<endl; //查找失败，输出提示信息
	}
	//一次插入
	cin>>tname>>tno;
	Info temp(tname, tno);
	pb += temp; //调用+=运算符，实现插入新联系人
	//通讯录合并
	
	PhoneBook pc;
	pc.Input(); //初始化第二个通讯录
	pb = pb+pc; //调用+运算符，实现合并
	pb.Print(); //输出所有操作后的通讯录
	return 0;
}
*/

