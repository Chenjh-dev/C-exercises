/*

���ӻ���ң��������Ԫ�ࣩ

��Ŀ����
�����µĵ������ң�����࣬ң�����ڵ��ӿ���������¿��Կ��Ƶ��ӡ�
http://172.31.221.21/JudgeOnline/upload/pimg1100_1.png
http://172.31.221.21/JudgeOnline/upload/pimg1100_2.png
Ҫ�����£�
1.     ʵ�ֲ�����Tv�ࣻ���й��캯�����޸ĺ����ơ������Ƶ��Ϊ100��
2.     ��Remote��ΪTv����Ԫ�࣬��֧����Remote���ж�Tv�����ĵ��á�
3.     ��main�����У�ͨ��Remoteʵ����TVʵ�����в�����

����
��һ�У����ӳ�ʼ״̬������Ϊstate,volume,channel,mode,input�ĳ�ʼֵ��
�ڶ��У�����ң����������״̬�Ĳ���ָ��ö�Ӧ�ĺ�������ʾ������������Ϊvolup

���
��һ�У�ִ��ң�����������״̬��

��������
off 10 19 Cable VCR
onoff volup chanup set_mode set_input

�������
on 11 20 Antenna TV

����ĿҪ�����Tv���Remote�ࡣ�������������ݡ��������
����Remote�����س�Ա��������Tv���������ݣ�������Tv��Ĵ�ӡ��Ա���������
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
		bool ison() const{ return state==1?true:false; }//������ 
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
		void set_mode(){ mode==1?mode=0:mode=1; }//��mode 
		void set_input(){ input==1?input=0:input=1; }//��input 
		void settings() const         //��� 
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
