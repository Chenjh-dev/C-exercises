/*


�����������жϣ�ѭ����
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 2816  ���: 919
[�ύ][״̬][���۰�]
��Ŀ����


  �������������ж��Ƿ񹹳������Ρ�������������Σ��ж����������ͣ������������������

   

   ��������������:

   ���������Σ�isosceles triangle
   ֱ�������Σ�right triangle
   ����ֱ�������Σ�isosceles right triangle
   �ȱ������ͣ�equilateral triangle
   һ�������Σ�general triangle
   ���ܹ��������Σ�no triangle


   ����a,b,cΪ�����������ߣ�������������㹫ʽ���£�

   s = (a+b+c)/2;

   

      


   ��ʾ���������������ڼ�����ڲ���ʾ��ԭ���������΢С�����,������==�ж���ȡ��������ж������|a-b|<e , eΪ�㹻С����������0.001��C�����о���ֵ����ԭ���ǣ�double fabs(double x)��ͷ�ļ�math.h��




����


 ���Դ���n

 ���n�У�ÿ��һ��������ݣ���1 ��2 ��3����Ϊ��������

���


 ��ÿ��������ݣ�������������͡�����������Σ����ͺ�������������������1λС������

��������

3
3.0 2.0 6.0
3.0 4.0 5.0
1.0 1.0 1.414


�������

no triangle
right triangle, 6.0
isosceles right triangle, 0.5


*/

#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c,s,A;
	int t,k;
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf%lf",&a,&b,&c);
		if(a<b){
			k=a;
			a=b;
			b=k;
		}
		if(b<c){
			k=b;
			b=c;
			c=k;
		}
		if(a<b){
			k=a;
			a=b;
			b=k;
		}
		if(b+c<a||fabs(b+c-a)<0.001){//���������� 
			printf("no triangle\n");
			continue;
		}
		else if(fabs(b*b+c*c-a*a)<0.001){//ֱ�������� 
			if(fabs(b-c)<0.001){
				printf("isosceles right triangle, ");
			}
			else{
				printf("right triangle, ");
			}
		}
		else if(fabs(b-c)<0.001){//���������� �� �ȱ������� 
			if(fabs(a-c)<0.001){
				printf("equilateral triangle, ");
			}
			else{
				printf("isosceles triangle, ");
			}
		}
		else{
			printf("general triangle, ");
		}
		s=(a+b+c)/2;
		A=sqrt(s*(s-a)*(s-b)*(s-c));
		printf("%.1lf\n",A);
	}
}
