////ccf 20140301 �෴�� 
//#include<iostream>
//using namespace std;
//
//int a[501];
//int main()
//{
//	int n,i,j,count;
//	cin>>n;
//	for(i=0;i<n;i++)
//		cin>>a[i];
//	for(i=0;i<n;i++)
//	{
//		for(j=0;j<i;j++)
//		{
//			if(a[j]+a[i]==0)
//				count++;
//		}
//	}
//	cout<<count<<endl;
//	return 0;
//}

////ccf 20140302 ����	�����õڶ��� ��������ĿҪ�� 
//����1  
// #include<iostream>
// using namespace std;
// 
// const int N=10;
// int flag[2559][1439];
// int main()
// {
// 	int order[N],winx1[N],winy1[N],winx2[N],winy2[N];
// 		//�����order[]Ϊ������� �����ĸ�Ϊ�������ʾ���ĸ�ֵ 
// 	int n,m,i,j,k;
// 	int x1,y1,x2,y2;
// 	int x,y;
// 	int tmp;
// 	cin>>n>>m;
// 	for(k=1;k<=n;k++)
// 	{	//���ڳ�ʼ��Ϊ1,2,...,n (ʵ����Ǵ��ڵĴ���)
// 		cin>>winx1[k]>>winy1[k]>>winx2[k]>>winy2[k];
// 		for(i=winx1[k];i<=winx2[k];i++)
// 		{
// 			for(j=winy1[k];j<=winy2[k];j++)
// 				flag[i][j]=k;
//		 }
//	 }
//	 for(k=1;k<=m;k++)
//	 {
//	 	cin>>x>>y;
//	 	order[k]=flag[x][y];	//��ǵ���ĵ� 
//	 	if(flag[x][y])
//	 	{	//����� �޸Ĵ��ڵĴ��� 
//	 		tmp=flag[x][y];
//	 		//cout<<"tmp ="<<tmp<<endl;
//	 		for(i=winx1[tmp];i<=winx2[tmp];i++)
//			 {
//			 	for(j=winy1[tmp];j<=winy2[tmp];j++)
//			 		flag[i][j]=tmp;
//			  } 
//		 }
//	 }
//	 for(int i=1; i<=m; i++)  {   
//  
//        if(order[i] == 0)    
//            cout << "IGNORED" << endl;    
//        else    
//            cout << order[i] << endl;    
//    }  
// }
 
////����2 �ýṹ����������ʾ���ڵ��ĸ���		
//#include<iostream>
//#include<cstring>	//memsetͷ�ļ�		
//#include<algorithm>
////#include<vector>
//using namespace std;
//struct Win{
//	int x1;
//	int y1;
//	int x2;
//	int y2;
//	int id;
//}point[11]; 
// 
// int main()
// {
// 	int n,m,i,j,k;
// 	cin>>n>>m;	
//// 	int a[m][2];
//// 	memset(a,0,sizeof(a));
//	 int a[11][2]={0};	//��ʾ�����m������ 
// 	memset(point,0,sizeof(point));	//�ṹ���ʼ��Ϊ0
//	for(i=1;i<=n;i++)
//	{	//���ڳ�ʼ�� 
//		cin>>point[i].x1>>point[i].y1>>point[i].x2>>point[i].y2;
//		point[i].id=i;
//	 } 
//	reverse(point+1,point+n+1);	//�������� �������ķ������
//	 
////	 for(i=1;i<=n;i++)
////	 	cout<<point[i].id<<" ";
////	cout<<endl;
//	 for(i=0;i<m;i++)
//	 {
//	 	cin>>a[i][0]>>a[i][1];
//	 	
//	  } 
//	  for(i=0;i<m;i++)
//	  {
//	  	int flag=0;
//	  	for(j=1;j<=n;j++)
//	  	{
//	  		if(a[i][0]>=point[j].x1 && a[i][0]<=point[j].x2 &&a[i][1]>=point[j].y1 &&a[i][1]<=point[j].y2)
//	  		{
//	  			cout<<point[j].id<<endl;	//�ҵ���ǰ���ڵ�id�� �����
//				flag=1;
//				Win temp=point[j];
//				for(k=j;k>1;k--)
//					point[k]=point[k-1];
//				point[1]=temp;
//				break;
//			  }
//			  
//		  }
//		  if(flag==0)
//	  			cout<<"IGNORED"<<endl;
//		  
//	  }
//	  
//	  return 0;
// }

//����	��vector��д(����Ӧ������򵥵���)
#include<iostream>
#include<vector>
using namespace std;

struct Win{
	int x1;
	int y1;
	int x2;
	int y2;
	int pos;
}; 

int main()
{
	vector<Win> v;
	vector<Win>::iterator it;
	
	struct Win tmp;
	int N,M,i;
	cin>>N>>M;
	for(i=0;i<N;i++)
	{
		cin>>tmp.x1>>tmp.y1>>tmp.x2>>tmp.y2;
		tmp.pos=i+1;
		v.insert(v.begin(),tmp);	//ÿ�ν�Ԫ�ز������	
	
	}
	while(M--)
	{
		int x,y;
		cin>>x>>y;
		for(it=v.begin();it!=v.end();it++)
		{
			if(x>=(*it).x1 &&x<=(*it).x2 && y>=(*it).y1 && y<=(*it).y2)
			{
				cout<<(*it).pos<<endl;
				tmp=*it;
				v.erase(it);
				v.insert(v.begin(),tmp);
				break;
			}
		}
		if(it==v.end())
		 cout<<"IGNORED"<<endl;
	 } 
	return 0;
}
