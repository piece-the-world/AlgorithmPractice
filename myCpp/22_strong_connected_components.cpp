#if 0
//*******************************************************************************************
//����:                                                                                     *
//	1.DFSֻ�ṩ��һ��ɭ�ֵĿ�����,�����γ�ɭ��ʱ�����˲��ֱߵ���Ϣ                          *
//	2.��������ܺõ�ʹ����DFS�γ�ɭ�ֵĽṹ												    *
//	3.��ƽڵ�ʱ����������(��ϵ����־|��ɫ����|���ȱ�־)								    *
//	4.ʹ�õݹ�ʱ,����Ҫ��ʵ���ǽṹ,�����Ŀ���Ϸ��ڲ�ͬ�Ľṹλ������					    *
//AND tips:																					*
//		֮ǰ�����ô���ָ������,ʵ���Ͽ����ô�������(һά���ά)�ķ���,���Ҵ�ָ��û�б�Ҫ����*
//*******************************************************************************************
#include <iostream>
#include <cstdlib>

using namespace std;

	/*
	��ά���鴫��->>
	|:
	����һ:
		����ά����ǿ��ת��Ϊָ���,�������Ҫ���±ߵ�һ��,������ֱ��[]�±���
		һά��������Զ�����Ϊָ��,����Ϣ�Զ���ʧ
	int a[2][2]={1,2,3,4};
	test((int**)a);
	void test(int** a)
	{
		cout<<*a<<endl;
		cout<<*(a+1)<<endl;
	}
	������:
		��(*a)[]�ķ�ʽ��������,�����ں������ڰ�������Ĳ���ϰ�߽��в���	
	void test(int(*a)[2])
	{
		cout<<a[0][1]<<endl;//�������
		cout<<a<<endl;//�����ַ
		cout<<(a+1)<<endl;
		cout<<(*(a+1))<<endl;//����һ��Ч����ͬ:�����ַ.��Ϊ(a+1)��int**,��(*(a+1))��int* ����Ҫ�����ַ�Ľ���
		cout<<(*(a+1))[0]<<endl;
		a[1][0]=5;
	}*/
struct ver
{
	int color;
	int index;
	int parent;
	int peer;
	int ftime;
	int ltime;
};
const int N=8;
ver node[N];
int time=0;
void DFS(int(*m)[N]);
void dfs_search(int(*m)[N],int index);
void FindStrong(int(*m)[N]);
void findstrong_search(int(*m)[N],int index);
void quicksort(ver n[],int f,int l);
int partion(ver n[],int f,int l);
void main()
{
	int mat[8][8]={0,1,0,0,1,0,0,0,
				   0,0,1,1,0,0,0,0,
				   0,1,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,
				   1,0,0,0,0,0,0,0,
				   1,0,0,0,0,0,1,0,
				   0,0,1,0,0,0,0,1,
				   0,0,0,0,0,1,0,0};
	for(int i=0;i<N;i++)
	{
		node[i].color=-1;
		node[i].index=i;
		node[i].parent=-1;
		node[i].peer=-1;
		node[i].ftime=-1;
		node[i].ltime=-1;
	}
	DFS(mat);
	quicksort(node,0,N-1);
	FindStrong(mat);
	system("pause");
}

void DFS(int(*m)[N])
{
	for(int i=0;i<N;i++)
	{
		if(node[i].color==-1)
		{
			dfs_search(m,i);
		}
	}
}
void dfs_search(int(*m)[N],int index)
{
	node[index].color=0;
	node[index].ftime=(++time);
	for(int i=0;i<N;i++)
	{
		if(node[i].color==-1)
		{
			if(m[index][i])
			{
				node[i].parent=node[index].index;
				dfs_search(m,i);
			}
		}
	}
	node[index].ltime=(++time);
}

void FindStrong(int(*m)[N])
{
	for(int i=0;i<N;i++)
	{
		if(node[i].color==0)
		{
			node[i].peer=node[i].index;
			node[i].color=1;
			findstrong_search(m,i);
		}
	}
}
void findstrong_search(int (*m)[N],int index)
{
	for(int i=0;i<N;i++)
	{
		if(node[i].color==0&&m[node[i].index][node[index].index])
		{
			//�㷨�����ᳫ�Ȱ������ʱ�̽�������,��������
			//1.����ʹ��ftime,ltime���жϿɴ���(ʧ��)
			//2.ʹ�������ͬpeer��Ԫ�����жϴ�index�Ƿ�ɴ�i.(�����Ȼʧ��)
			//3.����:������DFS(BFS)����ֵtrue or false���ж�
			/*bool mark=false;
			for(int j=0;j<N;j++)
			{
				if(node[j].peer==node[index].peer)
				{
					if(m[j][i])
					{
						mark=true;
						break;
					}
				}
			}
			if(mark)
			{
				node[i].color=1;
				node[i].peer=node[index].peer;
				findstrong_search(m,i);
			}*/
			//����ǲ������ϵ�����,�������ʱ��(���ĺ������)��������.��������DFS����������Ľṹ
			node[i].color=1;
			node[i].peer=node[index].peer;
			findstrong_search(m,i);
		}
	}
}

void quicksort(ver n[],int f,int l)
{
	if(f<l)
	{
		int q=partion(n,f,l);
		quicksort(n,f,q-1);
		quicksort(n,q+1,l);
	}
}
int partion(ver n[],int f,int l)
{
	int p=f-1;
	ver temp=node[l];
	for(int i=f;i<l;i++)
	{
		if(node[i].ltime>temp.ltime)
		{
			p++;
			ver t=node[i];
			node[i]=node[p];
			node[p]=t;
		}
	}
	node[l]=node[p+1];
	node[p+1]=temp;
	return p+1;
}
#endif