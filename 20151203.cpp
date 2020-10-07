//CCF 20151203 画图操作
//这一题难点在于 理解输入的m n q 为n行m列执行q个操作(逻辑易错处) 根据符号位 决定是画线还是填充图案
//还有一个难点是 利用递归调用对其进行填充 对此需要先定义一个结构体数组或者类对象数组表示递归移动的四个方向
 

#include<iostream>
using namespace std;

////定义一个结构体 用来表示起始位置的上下左右四个方向
//struct loca{
//	int lx;
//	int ly;
//}loca[4]={{-1,0},{1,0},{0,-1},{0,1}};
class Local{
public:
	int lx;
	int ly;		
}; 

Local loca[]={{-1,0},{1,0},{0,-1},{0,1}};
int min(int n1,int n2)
{
	return (n1<=n2)?n1:n2;
} 
 
 int max(int n1,int n2)
 {
 	return (n1>=n2)?n1:n2;
 }
 
 const int MAX=101;
 char a[MAX][MAX];
 
 void cfill(int x,int y,char c,int m,int n)
 {
 	int nx,ny;
 	int i;
 	a[y][x]=c;
 	for(i=0;i<4;i++)
 	{
 		nx=x+loca[i].lx;
		ny=y+loca[i].ly;
		if(nx>=0 && nx<m && ny>=0 && ny<n && a[ny][nx]!='-' && a[ny][nx]!='|' && a[ny][nx]!='+'&& a[ny][nx]!=c )	
		//这里必须写上a[ny][nx]!=c 否则编译错误 只能输入一行操作（还没有找到原因？ 
		//猜想这一语句的作用是为了是位置开始随四周递归 因为如果没有写着一句的话填充值的点可能永远停在起始位置,而达不到递归效果） 
		{
			cfill(nx,ny,c,m,n);
			
		}
		
	 }
 }
 
 int main()
 {
 	int m,n,q,flag;
 	int x1,y1,x2,y2;
	int x,y;
	char c;
	int i,j,k;
	int start,end;
	cin>>m>>n>>q; 	//n行 m列 q个操作 
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j]='.';		//二维数组初始化为'.' 
		}
	 
 	}
 	
 	for(k=0;k<q;k++)
 	{
 		cin>>flag;
 		if(flag==0)		//flag为0 执行画线操作 
 		{
 			cin>>x1>>y1>>x2>>y2;
 			if(x1==x2 && y1!=y2)
 			{
 				start=min(y1,y2);
 				end =max(y1,y2);
 				for(i=start;i<=end;i++)
 				{
 					if(a[i][x1]=='-'||a[i][x1]=='+')
 						a[i][x1]='+';
 					else a[i][x1]='|';
				 }
 				
			 }
			 else if (x1!=x2 && y1==y2)
 			{
 				start=min(x1,x2);
 				end =max(x1,x2);
 				for(j=start;j<=end;j++)
 				{
 					if(a[y1][j]=='|'||a[y1][j]=='+')
 						a[y1][j]='+';
 					else a[y1][j]='-';	
				 }
 				
			 }
		 }
		 else if(flag==1)	//flag为1 执行填充操作（利用到递归函数） 
		 {
		 	cin>>x>>y>>c;
			 cfill(x,y,c,m,n); 
		 }
	 }

	 
	 for(i=n-1;i>=0;i--)	//根据第二个样本例子 输出是从a[n-1][0]开始输出（易错处） 
	 {
	 	for(j=0;j<m;j++)
	 	{
	 		cout<<a[i][j];
		 }
		 cout<<endl;
	 }
 	return 0;
 }
