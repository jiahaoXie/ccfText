////ccf 20170902 公共钥匙盒
////这题的核心在于题目的核心是把每一个上下课表示成两个取放钥匙的动作，然后对动作进行排序。
////首先根据时间的先后排序。
////时间相同，根据取放排序，先放后取。
////时间相同，是相同的操作，先房间号低的操作。
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int MAX=2010;
//struct Event
//{
//	bool borrow;
//	int keyid;
//	int time;
//}e[MAX];
//
//int key[MAX];	//表示基于位置的钥匙 
//int keypos[MAX];	//表示基于钥匙的位置
//
////首先根据时间的先后排序。
////时间相同，根据取放排序，先放后取。
////时间相同，是相同的操作，先房间号低的操作。
//bool cmp(const Event &a,const Event &b )
//{
//	if(a.time<b.time)	return true;
//	else if(a.time==b.time)
//	{
//		if(!a.borrow&&b.borrow)	//先放后取 
//			return true;
//		else if(!a.borrow&&!b.borrow)
//		{
//			if(a.keyid<b.keyid)
//				return true;
//		}
//	}
//	return false;
//}
//int main()
//{
//	int n,k,i;
//	int w,s,c;
//	cin>>n>>k;
//	for(i=1;i<=n;i++)
//	{	//钥匙以及位置进行初始化 
//		key[i]=i;
//		keypos[i]=i;
//	}
//	for(i=0;i<k;i++)
//	{
//		cin>>w>>s>>c;
//	    e[2*i].borrow = true;
//        e[2*i].keyid = w;
//        e[2*i].time = s;
//        
//        e[2*i+1].borrow = false;
//        e[2*i+1].keyid = w;
//        e[2*i+1].time = s+c;
//        
//	}
//	sort(e,e+2*k,cmp);	//时间的先后排序 
//	for(i=0;i<2*k;i++)
//	{
//		if(e[i].borrow)	//取钥匙 置0 
//		{
//			key[keypos[e[i].keyid]]=0;
//			keypos[e[i].keyid]=0;
//		 } 
//		 else	//还钥匙(放入左边第一个为0的位置)	置1 
//		{
//			for(int pos=1;pos<=n;pos++)
//			{
//				if(key[pos]==0)
//				{
//					key[pos]=e[i].keyid;
//					keypos[e[i].keyid]=pos;
//					break;
//				}
//			}
//		} 
//	}
//	//输出
//	for(i=1;i<=n;i++)
//		cout<<key[i]<<" ";
//	cout<<endl;
//	 
//	return 0;
// } 

//利用vector存储钥匙 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Event{
	public:
		int borrow;	//0为放回 1为借 
		int keyid;
		int time;
		Event(int b,int k,int t){
			borrow=b;
			keyid=k;
			time=t;
		}
};

bool cmp(const Event& a,const Event& b)
{
	if(a.time<b.time) return true;
	else if(a.time==b.time && a.borrow<b.borrow)	return true;
	else if(a.time==b.time && a.borrow==b.borrow &&a.keyid<b.keyid) return true;
	
	return false;
}
int main()
{
	int N,K,i;
	cin>>N>>K;
	vector<int> v;
	vector<int>::iterator it;
	vector<Event> e;
	
	
	for(i=1;i<=N;i++)
		v.push_back(i);
		
	for(i=1;i<=K;i++)
	{
		int w,s,c;
		cin>>w>>s>>c;
		e.push_back(Event(1,w,s));//true表示借钥匙 借钥匙的钥匙号和时间 
		e.push_back(Event(0,w,s+c));//false表示还钥匙 借钥匙的钥匙号和时间   
	}
	//对其进行的操作进行排序
	sort(e.begin(),e.end(),cmp); 
	
	//排序结束后 对其进行有序处理
	for(i=0;i<(int)e.size();i++) 
	{
		if(e[i].borrow)
		{//表示借钥匙 
//			for(int n=0; n<N; n++) {
//                if(v[n] == e[i].keyid) {
//                    v[n] = -1;//-1是对拿走钥匙后对空位置的标记 
//                    break;
//                }
//            }
			for(it=v.begin();it!=v.end();it++)
			{
				if(*it==e[i].keyid)
				{
					*it=-1;
					break;
				}
			}
		}
		else{
			//放回
			for(int n=0;n<N;n++)
			{
				if(v[n]==-1)
				{
					
					v[n]=e[i].keyid; 
				    break;	
				}
			}
				
		}
	}
	for(it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
		
//	for(i=1;i<=N;i++)
//		cout<<v[i]<<" ";
	cout<<endl;
	return 0;
 } 


