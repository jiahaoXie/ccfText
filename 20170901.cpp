////ccf 20170901 打酱油
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
//这一题不是真题
/********************************************** 
////利用map (key/value) 对value值惊醒升序处理（value值相同时 key值升序输出）		
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
//		a[i]=i;	//数组存储共有多少钥匙 
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
//	vector<PAIR> v1(m1.begin(),m1.end());	//把map中的元素转存到vector中 
////	sort(v1.begin(),v1.end(),CmpValue());	//对元素进行从小到进行排序
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
 
