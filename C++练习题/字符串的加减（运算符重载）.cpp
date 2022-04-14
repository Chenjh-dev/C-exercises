/*

����ĿҪ����CStr���+��-��=��������غ���������������������������ַ����������a,b��
��ȱʡ���춨�����c,������c=a+b��c=c-b���ֱ����c��ֵ��

��Ŀ����
����һ���ַ�����str�������а���2�����ԣ��ַ������Ⱥ�һ��char��ָ�뱣���ַ������ݡ�
������������������أ�+��- ��+�������ʾ��2���ַ���ƴ�ӳ�һ���ַ�����
-�������ʾ����a2-a1����ɾ��a2�г��ֵ�a1�ַ�����
Ҫ�����£�
1.ʵ��str�ࣻ
2.��дmain��������ʼ��2��str����A��B�������2��������Ӻ�Ķ���C�Ľ����Ϣ��
���C��B֮�������Ľ����Ϣ��
(��ʾ:strstr(char *a,char*b)���Դ�a�ַ����в��ҳ�b�״γ��ֵĵ�ַ)

����
��1�У�����һ���ַ�������ʼ����һ��str����
(��ʾ:ͨ��cin. getline(char *,int strCount)��������һ���ַ�����char������)
��2�У�����һ���ַ�������ʼ���ڶ���str����

���
��1�У���������ַ�����Ӻ�ĳ��Ⱥ��ַ�����
��2�У���������ַ��������ĳ��Ⱥ��ַ�����

��������
i am a 
student!

�������
length=15 i am a student!
length=7 i am a 

*/

#include<iostream>
#include<string.h>
using namespace std;

class Str
{
	private:
		int length;
		char *p;
	public:
		Str(){ p=NULL,length=0; }
		Str(char *s)
		{ 
			p = new char[strlen(s)+1];	
			strcpy(p,s);
			length=strlen(s); 
		}
		Str(const Str &obj)
		{
			if(p!=NULL)
 				delete [] p;
 			p=new char[strlen(obj.p)+1];
 			strcpy(p,obj.p);
 			length=obj.length;
		} 
		~Str()
		{
			if(p!=NULL)
				delete [] p;
		}
		friend Str operator + (const Str &s1,const Str &s2)
		{
			Str h;
			h.length = s1.length +s2.length ;
			h.p=new char[h.length+1];
			strcpy(h.p,s1.p);
			strcat(h.p,s2.p);
			return h;
		}
		friend Str operator - (const Str &s1,const Str &s2)
		{
			int a;
			Str h;
			if(strstr(s1.p,s2.p)==NULL)
			{
				h=s1;
			}
			else
			{
				a=strlen(strstr(s1.p,s2.p));
				h.p=new char[strlen(s1.p)-a+1];
				h.length = s1.length -a ;
				for(int i=0;i<h.length;i++)
					h.p[i]=s1.p[i];
			}
			return h;
		}
		void operator = (const Str &obj)
		{
			length=obj.length;
			// cout<<obj.p<<endl;
			if(p==NULL)
 			{ 
  				p=new char[strlen(obj.p)+1];
  				strcpy(p,obj.p);
			}
 			else
 			{
  				delete [] p;
  				p=new char[strlen(obj.p)+1];
  				strcpy(p,obj.p);
				//  cout<<p<<endl;
 			}
		}
		void show()
		{
			cout<<"length="<<length<<' '<<p<<endl;
		}
};

int main()
{
	char str1[20],str2[20];
	cin.getline(str1,sizeof(str1));
	cin.getline(str2,sizeof(str2));
	Str a(str1),b(str2),c;
	c=a+b;
	c.show() ;
	c=c-b;
	c.show() ;
}

