/*����ң�أ���̬+��Ԫ��(15��)

������ĿҪ�����CTV���ӻ����ʵ��ң�ص�ȫ�ֺ���remote�Ķ��塣
����������CTV�����ָ�����顢�������ݡ���̬�������󲢵�����غ���ʵ�ֳ�����
�������Ӧ����Ϣ�����������̬�����Ķ���
*/

#include<iostream>
using namespace std;

class CTV
{
	public:
		CTV()
		{
			mode = 0;
			voice = 50;
			channelnum = 0;
			g = 0;
		} 
		~CTV(){}
		friend void remote(CTV *p,int k,int x,int v)
		{
			p->changevoice(v); 
			if(k == 1)
			{
				p->changechannelnum(x);
				p->showTV() ; 
			}
			else
			{
				p->showDVD() ;
			}
			if(p->mode == 0)
			{
				p->mode = k;
				if(k==2)
				{
					CTV::TVnum --;
					CTV::DVDnum ++;
				}
			}
			else
			{
				if(p->mode != k)
				{
					p->mode = k;
					if(k==1)
					{
						CTV::TVnum ++;
						CTV::DVDnum --;
					}
					if(k==2)
					{
						CTV::TVnum --;
						CTV::DVDnum ++;
					}
				}
				else
					p->mode = k;
			}
		}
		void changechannelnum(int x)
		{
			channelnum = x;
		}
		void changevoice(int v)
		{
			voice += v;
			if(voice>100)
				voice = 100;
			if(voice<0)
				voice = 0;
		}
		void showTV()
		{
			cout<<"TVģʽ--Ƶ��"<<channelnum<<"--����"<<voice<<endl;
		}
		void showDVD()
		{
			cout<<"DVDģʽ--Ƶ��99--����"<<voice<<endl;
		}
		static void show2()
		{
			cout<<"���ŵ��ӵĵ��ӻ�����Ϊ"<<CTV::TVnum <<endl;
			cout<<"����DVD�ĵ��ӻ�����Ϊ"<<CTV::DVDnum <<endl;
		}
		static void changeTVnum(int n)
		{
			CTV::TVnum = n;
		}
	private:
		static int TVnum;
		static int DVDnum;
		int mode;
		int voice;
		int channelnum;
		int g;
};

int CTV::TVnum = 0;
int CTV::DVDnum = 0;

int main()
{
	int n,t;
	int i,k,x,v;
	cin>>n>>t;
	CTV* p[20];
	CTV::changeTVnum(n);
	int a[20] = {0};
	while(t--)
	{
		cin>>i>>k>>x>>v;
		cout<<"��"<<i<<"�ŵ��ӻ�--";
		if(a[i]==0)
			p[i] = new CTV();
		remote(p[i],k,x,v);
		a[i]=1;
	}
	CTV::show2();
	for(i=0;i<20;i++)
	{
		if(a[i]==1)
			delete p[i];
	}
}































