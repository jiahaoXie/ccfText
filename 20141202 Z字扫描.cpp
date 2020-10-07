//ccf 20141202 Z字扫描
 #include<iostream>
 using namespace std;
 int a[500][500];
 

 struct Direct{
 	int xrow;
 	int xcol;
 }direct[4]={{0,1},{1,0},{1,-1},{-1,1}};
 
 int main()
 {
 	const int right=0;		//表示移动的四个方向 
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
	 	
	 	//这里实则写出移动时到达边缘的集中情况 
		if(next==right && row==0)	//在第一行上一步为向右 则下一步为左下
		 	next=leftdown;
		else if(next==right && row==n-1)	//在最后一行上一步为向右 则下一步为右上 
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
//	 {	//关键在与while()的判断语句 这里row盒col都是从0开始 当输出到a[n-1][n-1] 跳出循环 
//	 	row+=direct[next].xrow;
//	 	col+=direct[next].xcol;
//	 	cout<<a[row][col]<<" ";
//	 	
//	 	//这里实则写出移动时到达边缘的集中情况 
//		if(next==right && row==0)	//在第一行上一步为向右 则下一步为左下
//		 	next=leftdown;
//		else if(next==right && row==n-1)	//在最后一行上一步为向右 则下一步为右上 
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


