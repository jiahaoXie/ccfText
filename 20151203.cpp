//CCF 20151203 ��ͼ����
//��һ���ѵ����� ��������m n q Ϊn��m��ִ��q������(�߼��״�) ���ݷ���λ �����ǻ��߻������ͼ��
//����һ���ѵ��� ���õݹ���ö��������� �Դ���Ҫ�ȶ���һ���ṹ�������������������ʾ�ݹ��ƶ����ĸ�����
 

#include<iostream>
using namespace std;

////����һ���ṹ�� ������ʾ��ʼλ�õ����������ĸ�����
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
		//�������д��a[ny][nx]!=c ���������� ֻ������һ�в�������û���ҵ�ԭ�� 
		//������һ����������Ϊ����λ�ÿ�ʼ�����ܵݹ� ��Ϊ���û��д��һ��Ļ����ֵ�ĵ������Զͣ����ʼλ��,���ﲻ���ݹ�Ч���� 
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
	cin>>m>>n>>q; 	//n�� m�� q������ 
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j]='.';		//��ά�����ʼ��Ϊ'.' 
		}
	 
 	}
 	
 	for(k=0;k<q;k++)
 	{
 		cin>>flag;
 		if(flag==0)		//flagΪ0 ִ�л��߲��� 
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
		 else if(flag==1)	//flagΪ1 ִ�������������õ��ݹ麯���� 
		 {
		 	cin>>x>>y>>c;
			 cfill(x,y,c,m,n); 
		 }
	 }

	 
	 for(i=n-1;i>=0;i--)	//���ݵڶ����������� ����Ǵ�a[n-1][0]��ʼ������״��� 
	 {
	 	for(j=0;j<m;j++)
	 	{
	 		cout<<a[i][j];
		 }
		 cout<<endl;
	 }
 	return 0;
 }
