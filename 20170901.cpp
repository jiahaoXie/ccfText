////ccf 20170901 ����
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n,sum,t1,t2,t3;
//	cin>>n;
//	sum+=7*(n/50);
//	t1=n%50;
//	if(t1>=30)
//	{
//		t2=t1/30;
//		t3=t1%30;
//		sum+=4*t2+t3/10;
//	}
//	else
//		sum+=t1/10;
//	
//	cout<<sum<<endl;
//	return 0;
// } 

/**********************************************
//��һ�ⲻ������
/********************************************** 
////����map (key/value) ��valueֵ����������valueֵ��ͬʱ keyֵ���������		
//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//using std::map;
//using std::vector;
//int a[1001];
//
//typedef pair<int,int> PAIR;
//bool compare(const PAIR& x,const PAIR& y)
//{
//	if(x.second==y.second)
//	{
//		return x.first<y.first;
//	}
//	else
//	{
//		return x.second<y.second;
//	}
//}
//int main()
//{
//	map<int,int> m1;
//	
//	int n,k,w,s,c,i;
//	cin>>n>>k;
//	for(i=1;i<=n;i++)
//	{
//		a[i]=i;	//����洢���ж���Կ�� 
//	}
//	for(i=1;i<=k;i++)
//	{
//		cin>>w>>s>>c;
//		m1[w]=s+c;		
//	}
//	for(i=1;i<=n;i++)
//	{
//		if(!m1[i])
//			m1[i]=0;
//	}
//	vector<PAIR> v1(m1.begin(),m1.end());	//��map�е�Ԫ��ת�浽vector�� 
////	sort(v1.begin(),v1.end(),CmpValue());	//��Ԫ�ؽ��д�С����������
//	sort(v1.begin(),v1.end(),compare);
//	
////	vector<PAIR>::iterator it;
////	for(it=v1.begin();it!=v1.end();it++)
////	{
////		cout<<*it<<" ";
////	 } 
//	for(i=0;i!=v1.size();i++)
//	{
//		cout<<v1[i].first<<" ";
//	 }
//	cout<<endl;
//	return 0;
//}
 
