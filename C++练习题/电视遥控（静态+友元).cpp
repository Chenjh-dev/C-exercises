/*电视遥控（静态+友元）(15分)

根据题目要求完成CTV电视机类和实现遥控的全局函数remote的定义。
主函数定义CTV类对象指针数组、输入数据、动态创建对象并调用相关函数实现程序功能
并输出相应的信息、最后析构动态创建的对象。
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
			cout<<"TV模式--频道"<<channelnum<<"--音量"<<voice<<endl;
		}
		void showDVD()
		{
			cout<<"DVD模式--频道99--音量"<<voice<<endl;
		}
		static void show2()
		{
			cout<<"播放电视的电视机数量为"<<CTV::TVnum <<endl;
			cout<<"播放DVD的电视机数量为"<<CTV::DVDnum <<endl;
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
		cout<<"第"<<i<<"号电视机--";
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































