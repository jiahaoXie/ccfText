//////CCF 20141203 ���Ͼ���
//////���ýṹ�� �洢�����ÿһ������ ��������������Ч���ݴ洢��set�� 

#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

typedef long long ll;	//�������Ϊ������10^8�������� 
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
 	{	//�������� 
 		if(r[m].m=="cancel")
 		{
 			cin>>r[m].s;
 			r[r[m].s].e=false;	//��Ҫȡ�������ݱ�־λ����Ϊflase	
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
	 //����Ч�ص����ݲ���set��
	 for(int i=1;i<m;i++)
	 {
	 	if(r[i].m!="cancel" && r[i].e)
	 		st.insert(r[i].p);	
	  } 
//	  for(it=st.begin();it!=st.end();it++)		//������������setʱ����keyֵ����洢�� 
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
	  	
	  	if(maxsum<=sum)	//���� ����< ֻ��60�֣�<=Ϊ100�֣� ԭ����set��mapһ�� Ĭ��������ǰ���keyֵ������� 
	  	{
	  		maxsum=sum;
	  		p=p0;
		  }  	
	  		
	  }
	printf("%.2f ",p);
    cout<<maxsum<<endl;
 	return 0;
 }



