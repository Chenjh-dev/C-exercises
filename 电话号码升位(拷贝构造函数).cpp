//�绰������λ(�������캯��)

//��Ŀ����
//����һ���绰������CTelNumber,����1���ַ�ָ�����ݳ�Ա,�Լ����졢��������ӡ���������캯����
//�ַ�ָ�������ڶ�̬����һ���ַ����飬Ȼ�󱣴���������ĵ绰����
//���캯���Ĺ�����Ϊ�������ü��������7λ�绰���룬
//�������캯���Ĺ�������ԭ��7λ����Ķ�����λΪ8λ�������,Ҳ����˵��������Ķ�����Դ���������.�绰��λ�Ĺ�����ԭ2��3��4��ͷ�ĵ绰����ǰ���8��ԭ5��6��7��8��ͷ��ǰ���2��
//ע��:�绰����ֻ��ȫ���������ַ�������������������������Ϊ�Ƿ�)

//����
//�������ݵ����� t
//��һ��7λ����
//�ڶ���7λ����
//......

//���
//��һ��������λ��ĺ���
//�ڶ���������λ��ĺ���
//......

//��������������ɹ��������������Ϣ�����忴ʾ��

//��������
//3
//6545889
//3335656
//565655

//�������
//26545889
//83335656
//Illegal phone number


//����ĿҪ����CTelNumber��(�����ڳ�Ա��������cin����),
//ͬʱ��дһ��ȫ�ֺ����жϵ绰����Ϸ���
//(����绰����ֻ����7λ�����ַ����ҵ�1�����ֲ�����0��1��9)��
//����������7λ���벢�����жϺ���,���Ϸ�����һ������oldtel��
//����oldtel���󿽱�����newtelʵ�ֺ���������
//�����newtel���ô�ӡ��Ա�������������λ�����

#include<iostream>
#include<string.h>
using namespace std;

class CTelNumber
{
	public:
		CTelNumber(char *a)
		{
			oldtel = new char[9];
			strcpy(oldtel,a);
		}
		CTelNumber(const CTelNumber &r)
		{
			int i;
			switch(r.oldtel[0])
			{
				case '2':
				case '3':
				case '4':newtel[0]=8+'0';break;
				case '5':
				case '6':
				case '7':
				case '8':newtel[0]=2+'0';break;
				default:break;
			}
			for(i=0;i<7;i++)
			{
				newtel[i+1]=r.oldtel[i]; 
			} 
		}
		void print()
		{
			newtel[8] = '\0' ;
			cout<<newtel<<endl;
		}
		~CTelNumber(){}
	private:
		char *oldtel;
		char newtel[9];
};

int Judge(char *p)
{
	int m=1;
	int L;
	L=strlen(p);
	if(L != 7 || p[0]== '0' || p[0]=='1' || p[0]=='9')
	{
		cout << "Illegal phone number" << endl;
		m = 0;
	}
	if(m!=0)
	{
		int i;
		for(i=0;i<L;i++)
		{
			if(p[i]<'0' || p[i]>'9')
			{
				m=0;
				cout << "Illegal phone number" << endl;
			}
			if(m==0)
				break;
		}
	}
	return m;
}

int main()
{
	int t,m;
	cin>>t;
	char a[9];
	while(t--)
	{
		cin>>a;
		m = Judge(a);
		if(m!=0)
		{
			CTelNumber b1(a);
			CTelNumber b2(b1);
			b2.print() ;
		}	
	}
	return 0;
}
