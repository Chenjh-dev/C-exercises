/*

电视机与遥控器（友元类）

题目描述
有如下的电视类和遥控器类，遥控器在电视开机的情况下可以控制电视。
http://172.31.221.21/JudgeOnline/upload/pimg1100_1.png
http://172.31.221.21/JudgeOnline/upload/pimg1100_2.png
要求如下：
1.     实现并完善Tv类；其中构造函数需修改和完善。另：最大频道为100；
2.     将Remote设为Tv的友元类，以支持在Remote类中对Tv方法的调用。
3.     在main函数中，通过Remote实例对TV实例进行操作。

输入
第一行，电视初始状态，依次为state,volume,channel,mode,input的初始值。
第二行，利用遥控器对上述状态的操作指令，用对应的函数名表示，如增加音量为volup

输出
第一行，执行遥控器操作后的状态。

样例输入
off 10 19 Cable VCR
onoff volup chanup set_mode set_input

样例输出
on 11 20 Antenna TV

按题目要求完成Tv类和Remote类。主函数输入数据、定义对象、
调用Remote类的相关成员函数设置Tv类对象的数据，最后调用Tv类的打印成员函数输出。
*/

#include<iostream>
#include<string>
using namespace std;

class Remote;
class Tv
{
	public:
		Tv(int s,int y,int c,int m,int i)
		{
			state=s;
			volume=y;
			channel=c;
			mode=m; 
			input=i;
		}
		void onoff(){ state==1?state=0:state=1; }
		bool ison() const{ return state==1?true:false; }//换开关 
		void volup()
		{
			if(volume>19)
				volume=20;
			else
				volume++; 
		}
		void voldown()
		{
			if(volume<1)
				volume=0;
			else
				volume++; 
		}
		void chanup()
		{ 
			if(channel>99)
				channel=100;
			else
				channel++; 
		}
		void chandown()
		{ 
			if(channel<1)
				channel=0;
			else
				channel--;
		}
		void set_mode(){ mode==1?mode=0:mode=1; }//换mode 
		void set_input(){ input==1?input=0:input=1; }//换input 
		void settings() const         //输出 
		{
			if(state==1)
				cout<<"on ";
			else
				cout<<"off ";
			cout<<volume<<" "<<channel<<" ";
			if(mode==1)
				cout<<"Cable ";
			else
				cout<<"Antenna ";
			if(input==1)
				cout<<"VCR";
			else
				cout<<"TV";
		}
		friend class Remote;
	private:
		int state;
		int volume;
		int maxchannel;
		int channel;
		int mode;          //cable 1
		int input;         //vcr 1;
};

class Remote
{
	public:
		Remote(){}
		void volup(Tv &t){ t.volup(); }
		void voldown(Tv &t){ t.voldown(); }
		void onoff(Tv &t){t.onoff();}
		void chanup(Tv &t){t.chanup();}
		void chandown(Tv &t){t.chandown();}
		void set_chan(Tv &t,int c){t.channel = c;}
		void set_mode(Tv &t){t.set_mode();}
		void set_input(Tv &t){t.set_input();}	
};

int main()
{
	string k1,k2,k3,s;
	int h1,h2,h3,h4,h5,k;
	cin>>k1>>h2>>h3>>k2>>k3;
	if(k1=="on") 	h1=1;
	else	h1=0;
	if(k2=="Cable")  h4=1;
	else	h4=0;
	if(k3=="VCR")	h5=1;
	else	h5=0;
	Tv a(h1,h2,h3,h4,h5);
	Remote b;
	while(cin>>s)
	{
		if(s=="onoff")
			b.onoff(a);
		if(a.ison() ) 
		{
			if(s=="volup")
				b.volup(a);
			if(s=="voldown")
				b.voldown(a);
			if(s=="chanup")
				b.chanup(a);
			if(s=="chandown")
				b.chandown(a);
			if(s=="set_mode")
				b.set_mode(a);
			if(s=="set_input")
				b.set_input(a);
			if(s=="set_chan")
			{
				cin>>k;
				b.set_chan(a,k); 
			}
			
		}		
	}
	a.settings() ;
}
