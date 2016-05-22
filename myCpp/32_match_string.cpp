#if 0
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

void rabin_karp_matcher(string &T,string &P,unsigned int d,unsigned int q);


void main()
{
	ifstream in("match_string.txt");
	string src;
	src.reserve(2000);
	char c;
	//���ܰ�get(c)����ѭ���ڲ�,�����Ļ���ȡ�ļ���������ʱ��Ҳ��src+=c;�������һ���ַ���һ��
	while(in.get(c))
	{
		src+=c;
	}
	cout<<src[6]<<endl;
	string patten="roll";
	rabin_karp_matcher(src,patten,128,131);
	system("pause");
}

//������λ������ȡ��,�����ȽϿ�
void rabin_karp_matcher(string &T,string &P,unsigned int d,unsigned int q)
{
	unsigned int n=T.size();
	unsigned int m=P.size();
	unsigned int h=pow((double)d,(int)(m-1));
	unsigned int p=0;
	unsigned int t=0;
	for(int i=0;i<m;i++)
	{
		p=(d*p+P[i])%q;
		t=(d*t+T[i])%q;
	}
	for(int i=0;i<n-m;i++)
	{
		if(p==t)
		{
			bool mark=true;
			for(int j=0;j<m;j++)
			{
				if(P[j]!=T[i+j])
				{
					mark=false;
					break;
				}
			}
			if(mark)
				cout<<"λ��:"<<i<<endl;

		}else
		{
			t=((abs((int)(t-T[i]*h)))*d+T[i+m])%q;
		}
	}
}
#endif