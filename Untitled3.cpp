//ºÚµ•±‡–¥hello world! 
//#include<iostream>
//#define MAX 100;
//using namespace std;
//
//
//int main()
//{
//	cout<<"hello world";
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x;
	float f;
	double d;
	
	scanf("%d",&x);
	scanf("%f",&f);
	scanf("%f",&d);
	
	x+=1;
	f+=x;
	d+=x;
	
	printf("x=%d\n",x);
	printf("f=%f\n",f);
	printf("d=%f\n",d);
	return 0;
	
}
