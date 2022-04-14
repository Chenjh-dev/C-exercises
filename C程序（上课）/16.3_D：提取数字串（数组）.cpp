#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int i,j,w,n=0;
	double c[31],d;
	char a[1000]="A",b[500];
	while(gets(b)!=NULL){
		strcat(a,b);
	}	
	w=strlen(a);
	for(i=0;i<w;i++){
		if((a[i]>='0'&&a[i]<='9')||a[i]=='.'){
			for(j=i;j<w;j++){
				b[j-i]=a[j];
			}
			b[j-i]='\0';
			c[n++]=atof(b);
			int judge=0;
			while(1){
				i++;
				if(i>=w){
					break;
				}else if((a[i]>='0'&&a[i]<='9')||(a[i]=='.')){
					//Êý×Ö 
				}else{
					break;
				}
			}
 		}
 	}
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(c[j]<c[j+1]){
				d=c[j];
				c[j]=c[j+1];
				c[j+1]=d;
			}
		}
	}
	for(i=0;i<n-1;i++){
		printf("%.2lf ",c[i]);
	}
	printf("%.2lf\n",c[i]);
}
