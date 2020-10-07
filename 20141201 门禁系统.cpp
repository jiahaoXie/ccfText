//ccf 20141201 це╫Шо╣мЁ
 #include<iostream>
 using namespace std;
 
 int a[1000];
 int main()
 {
 	int n,i,j,count;
 	cin>>n;
 	for(i=0;i<n;i++)
 		cin>>a[i];
 	for(i=0;i<n;i++)
 	{
 		count=1;
 		for(j=0;j<i;j++)
 		{
 			if(a[j]==a[i])
 				count++;
 				
		 }
		 cout<<count<<" ";
	 }
	 cout<<endl;
 	return 0;
 }
