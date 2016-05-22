#if 0
//实现随机排序，使用的是分治法
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <queue>
#include <iomanip>

using namespace std;

struct mPair
{
	int data;
	int priv;
};
void in(mPair& m)
{
	cin>>m.data;
	m.priv=rand();
};
//将分治法的用途扩展到自定义的类别之中去
void merge_sort(mPair*(&m),int f,int l);
void merge(mPair*(&m),int f,int mid,int l);
void main()
{
	srand((unsigned)time(NULL));
	mPair* ran=new mPair[10];
	for_each(ran,ran+10,in);

	merge_sort(ran,0,9);

	for(int i=0;i<10;i++)
	{
		cout<<setw(10)<<ran[i].priv<<setw(10)<<ran[i].data<<endl;
	}

	system("pause");
}

void merge_sort(mPair*(&m),int f,int l)
{
	if(f<l)
	{
		int mid=(f+l)/2;
		merge_sort(m,f,mid);
		merge_sort(m,mid+1,l);
		merge(m,f,mid,l);
	}
}

void merge(mPair*(&m),int f,int mid,int l)
{
	queue<mPair> L,R;
	for(int i=f;i<=l;i++)
	{
		if(i<=mid)
			L.push(m[i]);
		else
			R.push(m[i]);
	}

	for(int i=f;i<=l;i++)
	{
		if((!L.empty()) && !(R.empty()))
		{
			if(L.front().priv<R.front().priv)
			{
				m[i]=L.front();
				L.pop();
			}else
			{
				m[i]=R.front();
				R.pop();
			}
		}else if(!L.empty())
		{
			m[i]=L.front();
			L.pop();
		}else if(!R.empty())
		{
			m[i]=R.front();
			R.pop();
		}
	}
}
#endif