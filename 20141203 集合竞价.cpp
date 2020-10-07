//////CCF 20141203 集合竞价
//////利用结构体 存储输入的每一行数据 将其买单卖单的有效数据存储到set中 

#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

typedef long long ll;	//满足股数为不超过10^8的正整数 
typedef struct{
	string m;
	float p;
	ll s;
	bool e;	
}R;
const int MAX=5001;
R r[MAX];
 
 int main()
 {
 	set<float> st;
 	set<float>::iterator it;
 	int m=1;
 	while(cin>>r[m].m)
 	{	//数据输入 
 		if(r[m].m=="cancel")
 		{
 			cin>>r[m].s;
 			r[r[m].s].e=false;	//将要取消的数据标志位设置为flase	
 			m++;
			continue;
		 }
		 else if(r[m].m =="buy" ||r[m].m=="sell")
		 {
		 	cin>>r[m].p>>r[m].s;
		 	r[m].e=true;
		 	m++;
		 }
		
	 }
	 //将有效地的数据插入set中
	 for(int i=1;i<m;i++)
	 {
	 	if(r[i].m!="cancel" && r[i].e)
	 		st.insert(r[i].p);	
	  } 
//	  for(it=st.begin();it!=st.end();it++)		//这里用来测试set时按照key值升序存储的 
//	  {
//	  	cout<<*it<<" ";
//	   } 
//	   cout<<endl;
	  ll maxsum=0;
	  float p=0;
	  for(it=st.begin();it!=st.end();it++)
	  {
	  	float p0=*it;
	  	ll sumb=0,sums=0,sum;
	  	for(int i=1;i<m;i++)
	  		if(r[i].m=="buy"&&r[i].e &&r[i].p>=p0)
	  			sumb+=r[i].s;
	  	for(int i=1;i<m;i++)
	  		if(r[i].m=="sell"&&r[i].e &&r[i].p<=p0)
	  			sums+=r[i].s;
	  			
	  	sum=min(sumb,sums);
	  	
	  	if(maxsum<=sum)	//这里 若是< 只有60分；<=为100分！ 原因是set和map一样 默认情况下是按照key值升序输出 
	  	{
	  		maxsum=sum;
	  		p=p0;
		  }  	
	  		
	  }
	printf("%.2f ",p);
    cout<<maxsum<<endl;
 	return 0;
 }



