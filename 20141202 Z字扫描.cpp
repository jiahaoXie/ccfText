//ccf 20141202 Z��ɨ��
 #include<iostream>
 using namespace std;
 int a[500][500];
 

 struct Direct{
 	int xrow;
 	int xcol;
 }direct[4]={{0,1},{1,0},{1,-1},{-1,1}};
 
 int main()
 {
 	const int right=0;		//��ʾ�ƶ����ĸ����� 
 	const int down=1;
 	const int leftdown=2;
 	const int rightup=3;
 
 	int n,i,j,row,col,next;
 	cin>>n;
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		 	cin>>a[i][j];
	 }
	 
	 row=0,col=0;
	 next=right;
	for(row,col,next;row<n&&col<n;)
	{
		cout<<a[row][col]<<" ";
		row+=direct[next].xrow;
	 	col+=direct[next].xcol;
	 	
	 	//����ʵ��д���ƶ�ʱ�����Ե�ļ������ 
		if(next==right && row==0)	//�ڵ�һ����һ��Ϊ���� ����һ��Ϊ����
		 	next=leftdown;
		else if(next==right && row==n-1)	//�����һ����һ��Ϊ���� ����һ��Ϊ���� 
		 	next=rightup;
		
		if(next==down && col==0)	
			next=rightup;
		else if(next==down && col==n-1)
			next=leftdown;
		
		if(next==rightup &&  col==n-1)
			next=down;
		else if(next==rightup && row==0)
			next=right;
			
		if(next==leftdown && row==n-1)
			next=right;
		else  if(next==leftdown && col==0)
			next=down;
	}

	 cout<<endl;
 	return 0;
 }

//	 row=0,col=0;
//	 next=right;
//	 cout<<a[row][col]<<" ";
//	 
//	 while(row!=n-1 ||col!=n-1)
//	// while(row<n && col<n)
//	 {	//�ؼ�����while()���ж���� ����row��col���Ǵ�0��ʼ �������a[n-1][n-1] ����ѭ�� 
//	 	row+=direct[next].xrow;
//	 	col+=direct[next].xcol;
//	 	cout<<a[row][col]<<" ";
//	 	
//	 	//����ʵ��д���ƶ�ʱ�����Ե�ļ������ 
//		if(next==right && row==0)	//�ڵ�һ����һ��Ϊ���� ����һ��Ϊ����
//		 	next=leftdown;
//		else if(next==right && row==n-1)	//�����һ����һ��Ϊ���� ����һ��Ϊ���� 
//		 	next=rightup;
//		
//		if(next==down && col==0)	
//			next=rightup;
//		else if(next==down && col==n-1)
//			next=leftdown;
//		
//		if(next==rightup &&  col==n-1)
//			next=down;
//		else if(next==rightup && row==0)
//			next=right;
//			
//		if(next==leftdown && row==n-1)
//			next=right;
//		else  if(next==leftdown && col==0)
//			next=down;
//				 
//	 }


