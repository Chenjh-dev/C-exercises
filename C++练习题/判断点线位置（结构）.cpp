//���� : �жϵ���λ��(�ṹ)

//��Ŀ����

//�þ���x,y�������ͱ�����Ա�Ľṹ����SPoint����ʾ����㡣��SLine�ṹ�����������߶Σ����а���p1��p2����SPoint��Ա��
//��д����direction(const SLine &ab, const SPoint &c)����������ab��ac��˵�ֵ�жϵ�c��ֱ��ab��λ�ù�ϵ��
//����

//�жϴ���

//�ߵ���������x1��y1��x2��y2

//������x��y

//......

//���


//λ�ù�ϵ

//��������

//3
//1 5 2 9
//1 3
//5 6 7 8
//6 7
//2 3 1 0
//3 3

//�������

//clockwise
//intersect
//anti clockwise

#include<iostream>
using namespace std;


struct SPoint
{
	int x;
	int y;
};
struct SLine
{
	SPoint p1;
	SPoint p2;	
};
int direction(const SLine &ab,const SPoint &c);

int main()
{
	int t,i,m;
	SPoint c;
	SLine ab;
	cin>>t;
	while(t--)
	{
		cin>>ab.p1.x>>ab.p1.y >>ab.p2.x >>ab.p2.y >>c.x >>c.y ;
		m=direction(ab,c);
		if(m>0)
		cout<<"anti clockwise"<<endl;
		else if(m==0)
		cout<<"intersect"<<endl;
		else if(m<0)
		cout<<"clockwise"<<endl;
	}
	return 0;
}

int direction(const SLine &ab,const SPoint &c)
{
	int m;
	m=(ab.p1.x -ab.p2.x )*(ab.p1.y -c.y )-(ab.p1.y -ab.p2.y )*(ab.p1.x -c.x );
	return m;
}




