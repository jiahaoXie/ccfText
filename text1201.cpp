//#include <iostream>  
//#include <string>    
//using namespace std;    
//int main()  
//{  
//    string s;  
//  
//    // ��������  
//    cin >> s;  
//  
//    // ����ʶ����  
//    int sum = 0, j = 1,t;  
//    for(int i=0; i<s.length()-1; i++) {  
//        if(s[i] != '-')  
//            sum += (s[i] - '0') * j++;  
//    }  
//  
//    // ʶ����ת�ַ�  
//    char c;  
//    t = sum % 11;  
//    if(t == 10)  
//        c = 'X';  
//    else  
//        c = t + '0'; 
//  
//    // �ж�ʶ���롢У�������  
//    if(c == s[s.length()-1])  
//        cout << "Right" << endl;  
//    else {  
//        s[s.length()-1] = c;  
//        cout << s << endl;  
//    }  
//  
//    return 0;  
//} 

#20151203 ��ͼ����

#include<iostream>
using namespace std;

struct Local{
	int lx;
	int ly;
}local[4]={{-1,0},{1,0},{0,1},{0.-1}};
 //�ṹ������ ������ʾ�����ĸ�λ��
 
 char a[101][101];
 
 int main() 
 {
 	int m.n.q,i,j;
	cin>>m>>n>>q;
	int flag;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		  a[i][j]='.';
	}
	while(q--)
	{
		cin>>flag;
		if(flag==0)
		{
			int x1,y1,x2,y2;
			 
		}
		
	}
 	return 0;
 }
