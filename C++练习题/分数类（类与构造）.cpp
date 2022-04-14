//�����ࣨ���빹�죩

//��Ŀ����
//������з������ʵ��:
//class CFraction
//{
// private:
//      int fz, fm;
// public:
//      CFraction(int fz_val, int fm_val) ;
//      CFraction add(const CFraction &r);
//      CFraction sub(const CFraction &r);
//      CFraction mul(const CFraction &r);
//      CFraction div(const CFraction &r);
//      int getGCD();   // �����ķ��Ӻͷ�ĸ�����Լ��
//     void print();
//};
//������a��b�����Լ���ɲ���շת��������ֳ�ŷ������㷨���䲽��Ϊ:
//1. ����a, bʹa > b;
//2. ��a��b�õ�����r,��r=0,��bΪ���Լ��,�˳�.
//3. ��r��Ϊ0,����b����a, r����b,��ʱa,b������һ�ε�С,�����ģ��С��;
//4. ������2����

//����
//�������ݵ����� t
//��һ���һ������
//��һ��ڶ�������
//�ڶ����һ������
//�ڶ���ڶ�������
//......

//���
//��һ�����������ĺ�
//��һ�����������Ĳ�
//��һ�����������Ļ�
//��һ��������������

//�ڶ������������ĺ�
//�ڶ������������Ĳ�
//�ڶ������������Ļ�
//�ڶ���������������

//......

//��������
//3
//1/2
//2/3
//3/4
//5/8
//21/23
//8/13

//�������
//7/6
//-1/6
//1/3
//3/4

//11/8
//1/8
//15/32
//6/5

//457/299
//89/299
//168/299
//273/184
//


//����ĿҪ����CFraction��(�����ڳ�Ա��������cin����,���������򱣴��ھֲ����󲢷���)��
//������ʵ�����ݵ����롢����Ķ��塢�����ε�����س�Ա������ɷ������㼰�����������


#include<iostream>
using namespace std;

class CFraction
{
private:
    int fz, fm;
    int FZ,FM;
public:
    CFraction(int fz_val, int fm_val)
    {
    	fz = fz_val;
    	fm = fm_val;
	}
    CFraction add(const CFraction &r)
    {
    	FM = fm*r.fm ;
    	FZ = fz*r.fm + fm*r.fz ;
    	getGCD();
	}
    CFraction sub(const CFraction &r)
    {
    	FM = fm*r.fm ;
    	FZ = fz*r.fm - fm*r.fz ;
    	getGCD();
	}
    CFraction mul(const CFraction &r)
    {
    	FM = fm*r.fm ;
    	FZ = fz*r.fz ;
    	getGCD();
	}
    CFraction div(const CFraction &r)
    {
    	FM = fm*r.fz ;
    	FZ = fz*r.fm ;
    	getGCD();
	}
    int getGCD()
	{
		int n1,n2,r;
		if(FZ >= FM)
		{
			n1 = FZ;
			n2 = FM;
		}
		else
		{
			n1 = FM;
			n2 = FZ;
		}
		for(r=1 ; r != 0 ; )
		{
			r = n1 % n2 ;
			if(r != 0)
			{
				n1 = n2;
				n2 = r;
			}
		}
		FZ = FZ/n2;
		FM = FM/n2;
		if(FM < 0)
		{
			FM = FM*-1;
			FZ = FZ*-1;
		}
		print();
	}
    void print()
    {
    	cout << FZ << "/" << FM <<endl;
	}
};

int main()
{
	int t,x1,x2,x3,x4;
	char k1,k2;
	cin>>t;
	while(t--)
	{
		cin >> x1 >> k1 >> x2 ;
		CFraction a(x1,x2);
		cin >> x3 >> k2 >> x4;
		CFraction b(x3,x4);
		a.add(b); 
		a.sub(b);
		a.mul(b);
		a.div(b);
		cout <<endl;
	}
	return 0;
}

