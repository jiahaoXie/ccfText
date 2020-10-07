////ccf 20160401 折点计数
////原理是 从第二个数开始中间数与前后两个数进行比较 趋势不同为折点 
//#include<iostream>
//using namespace std;
//
//int a[1000];
//int main()
//{
//	int n,left,mid,right,i;
//	int sum=0;
//	cin>>n;
//	cin>>left>>mid;
//	for(i=3;i<=n;i++)
//	{
//		cin>>right;
//		if((left>mid && mid<right) ||(left<mid && mid>right))
//		{
//			sum++;
//		}
//		left=mid;
//		mid=right;
//	}
//	
//	cout<<sum<<endl;
//	return 0;
// } 

//方法二 
#include<iostream>
using namespace std;
int a[1001];

int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	
	//折点查找从a[1]到a[n-2]中查找
	int count=0;
	for(i=1;i<n-1;i++)
	{
		if( (a[i-1]>a[i] && a[i]<a[i+1])||(a[i-1]<a[i] && a[i]>a[i+1]) )
		 count++;
	}	
	cout<<count<<endl;
	return 0;
}

/*
//ccf 20160402  俄罗斯方块
#include<iostream>
using namespace std;

const int M=15;
const int N=10;
const int K=4;


int main()
 { 
    int i,j,m; 
	int a[M][N],b[K][K] ;
	
    for(i=0;i<M;i++)    
        for( j=0;j<N;j++)  
           cin>>a[i][j];     
    for(i=0;i<K;i++)  
        for(j=0;j<K;j++)  
         cin>>b[i][j];   
    cin>>m;  
    m=m-1;  
    
	int temp=0;  
    int count=0;  
    while(1)
	{  
	   for( i=0;i<K;i++)
	   {  
	       for(j=0;j<K;j++)
		   {  
	       	if(b[i][j]==1){  
	           if(a[i+temp][j+m]==0)count++;  
	       	}  
	       } 
		} 
	   if(count!=4){  
	           for( i=0;i<K;i++)  
	              for( j=0;j<K;j++)  
	                 if(b[i][j]==1)  
	                    a[i+temp-1][j+m]=1;  // 此时说明不可以下移了，上一步则是最后一步可执行步骤 
	       break;  
	   }  
	   if(count==4){  
	       temp++;  
	       count=0;  
	   }    
	}  
   for(i=0;i<M;i++){  
       for( j=0;j<N;j++){  
           cout<<a[i][j]<<" ";  
       }  
       cout<<endl;  
    }  
    return 0;
 }
 */
 
// #include<iostream>
// using namespace std;
// int main()
// {
// int i=0,sum=0,n;
// cin>>n;
// for(i;i<=n;i++)
// {
// 	sum+=i;
// }
// cout<<sum<<endl;
//  return 0;
// }
