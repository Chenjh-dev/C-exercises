//���� : �����������������
//��Ŀ����
//�������������彡���ж��ָ�꣬����BMI����֬�ʵ�
//���һ�����彡���࣬����˽�г�Ա�����������(��)������(����)����Χ(����)��ʵ���������з������£�
//BMI����������BMI��ֵ(����)�����㹫ʽBMI= ���� / ��ߵ�ƽ��
//��֬�ʷ�����������֬����ֵ(������)������������£�
//1������a=��Χ��cm����0.74
//2������b=���أ�kg����0.082+34.89
//3����֬��������kg��=a��b
//4����֬�� = ��֬������������
//��������������Ҫ���ж���


//����
//��һ������t��ʾ��t������ʵ��
//�ڶ�����ÿ�������ĸ���������������ߡ����أ���Χ
//��������t��

//���
//���t�У�ÿ������һ��ʵ����BMI����֬�ʣ�С����ֵ��ȷ��С�����2λ���ÿո����


//��������
//2
//�Ÿ� 1.85 78.5 85.2
//��Բ 1.55 67.6 77.3

//�������
//�Ÿߵ�BMIָ��Ϊ23--��֬��Ϊ0.28
//��Բ��BMIָ��Ϊ28--��֬��Ϊ0.25

//����ĿҪ����BMI�࣬�����캯��������BMI�ĳ�Ա������������֬�ʵĳ�Ա����
//�Լ���ָ����ʽ������ݳ�Աֵ�ĳ�Ա������������ʵ�����ݵ����롢����Ķ��塢
//������س�Ա������ɼ��㡢������������(��cout << fixed << setprecision(2)�������2λС��)��


#include<iostream>
#include<iomanip>
using namespace std;

class Body
{
	public:
		Body(string a,float b,float c, float d);
		void Jisuan();
		void print();
	private:
		string name;
		float height;
		float weight;
		float waistline;
		int BMI;
		float BFR;
};

Body::Body (string a,float b,float c,float d)
{
	name =a;
	height =b;
	weight =c;
	waistline =d;	
} 

void Body::Jisuan()
{
	BMI = weight/(height*height)+0.5;
	BFR = (waistline*0.74-(weight*0.082+34.89))/weight;
}

void Body::print()
{
	cout<<name<<"��BMIָ��Ϊ"<<BMI<<"--��֬��Ϊ"<< fixed << setprecision(2) <<BFR<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string x1;
		float x2,x3,x4;
		cin>>x1>>x2>>x3>>x4;
		Body s(x1,x2,x3,x4);
		s.Jisuan() ;
		s.print() ;
	}
}








