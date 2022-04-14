/*
��ά�ռ�ĵ㣨�̳У�

��Ŀ����
����һ��ƽ���ϵĵ�C2D�࣬������һ��getDistance()�ĳ�Ա������
����õ㵽ԭ��ľ��룻��C2D����������ά�ռ�ĵ�C3D�࣬
����getDistance()��Ա��������õ㵽ԭ��ľ��롣
�Էֱ�����һ��C2D��C3D�Ķ��󣬼������ǵ�ԭ��ľ��롣
��ά�ռ�����㣨x, y, z���ͣ�x1, y1, z1���ľ��빫ʽ����
[(x-x1)^2+(y-y1)^2+(z-z1)^2]^(1/2) 

����
��һ�ж�ά�����λ��
�ڶ�����ά�����λ��1
��������ά�����λ��2

���
��һ�ж�ά�����λ�õ�ԭ��ľ���
�ڶ�����ά�����λ��1��ԭ��ľ���
��������ά�����λ��2��ԭ��ľ���
��������ά�����λ��2��ֵ����ά���������󣬶�ά����㵽ԭ��ľ���

��������
3 4
3 4 5
6 8 8

�������
5
7.07107
12.8062
10

����ĿҪ����ɻ���C2D��������C3D�Ķ���,�����඼���붨�幹�캯����
�������������ݡ�����C2D��C3D����󲢵�����Ӧ��getDistance��Ա������
*/

#include<iostream>
#include<math.h>
using namespace std;

class C2D
{
	public:
		C2D(int xx,int yy):x(xx),y(yy){}
		float d2getDistance(){ return sqrt(x*x+y*y); }
	protected:
		int x,y;
};

class C3D:public C2D
{
	public:
		C3D(int xx,int yy,int zz):C2D(xx,yy){ x=xx,y=yy,z=zz; }
		float d3getDistance(){ return sqrt(x*x+y*y+z*z); }
	protected:
		int z;
};

int main()
{
	int x,y,x1,x2,y1,y2,z1,z2;
	cin>>x>>y;
	C2D k1(x,y);
	cout<<k1.d2getDistance() <<endl;
	cin>>x1>>y1>>z1;
	C3D k2(x1,y1,z1);
	cout<<k2.d3getDistance() <<endl;
	cin>>x2>>y2>>z2;
	C3D k3(x2,y2,z2);
	cout<<k3.d3getDistance() <<endl;
	cout<<k3.d2getDistance() <<endl;
}



