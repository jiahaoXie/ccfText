////ccf 20170902 ����Կ�׺�
////����ĺ���������Ŀ�ĺ����ǰ�ÿһ�����¿α�ʾ������ȡ��Կ�׵Ķ�����Ȼ��Զ�����������
////���ȸ���ʱ����Ⱥ�����
////ʱ����ͬ������ȡ�������ȷź�ȡ��
////ʱ����ͬ������ͬ�Ĳ������ȷ���ŵ͵Ĳ�����
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
//int key[MAX];	//��ʾ����λ�õ�Կ�� 
//int keypos[MAX];	//��ʾ����Կ�׵�λ��
//
////���ȸ���ʱ����Ⱥ�����
////ʱ����ͬ������ȡ�������ȷź�ȡ��
////ʱ����ͬ������ͬ�Ĳ������ȷ���ŵ͵Ĳ�����
//bool cmp(const Event &a,const Event &b )
//{
//	if(a.time<b.time)	return true;
//	else if(a.time==b.time)
//	{
//		if(!a.borrow&&b.borrow)	//�ȷź�ȡ 
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
//	{	//Կ���Լ�λ�ý��г�ʼ�� 
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
//	sort(e,e+2*k,cmp);	//ʱ����Ⱥ����� 
//	for(i=0;i<2*k;i++)
//	{
//		if(e[i].borrow)	//ȡԿ�� ��0 
//		{
//			key[keypos[e[i].keyid]]=0;
//			keypos[e[i].keyid]=0;
//		 } 
//		 else	//��Կ��(������ߵ�һ��Ϊ0��λ��)	��1 
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
//	//���
//	for(i=1;i<=n;i++)
//		cout<<key[i]<<" ";
//	cout<<endl;
//	 
//	return 0;
// } 

//����vector�洢Կ�� 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Event{
	public:
		int borrow;	//0Ϊ�Ż� 1Ϊ�� 
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
		e.push_back(Event(1,w,s));//true��ʾ��Կ�� ��Կ�׵�Կ�׺ź�ʱ�� 
		e.push_back(Event(0,w,s+c));//false��ʾ��Կ�� ��Կ�׵�Կ�׺ź�ʱ��   
	}
	//������еĲ�����������
	sort(e.begin(),e.end(),cmp); 
	
	//��������� �������������
	for(i=0;i<(int)e.size();i++) 
	{
		if(e[i].borrow)
		{//��ʾ��Կ�� 
//			for(int n=0; n<N; n++) {
//                if(v[n] == e[i].keyid) {
//                    v[n] = -1;//-1�Ƕ�����Կ�׺�Կ�λ�õı�� 
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
			//�Ż�
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


