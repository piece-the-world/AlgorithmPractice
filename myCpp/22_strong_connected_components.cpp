#if 0
//*******************************************************************************************
//感悟:                                                                                     *
//	1.DFS只提供了一种森林的可能性,而且形成森林时舍弃了部分边的信息                          *
//	2.后序遍历很好的使用了DFS形成森林的结构												    *
//	3.设计节点时有三种属性(关系及标志|颜色工具|进度标志)								    *
//	4.使用递归时,最重要的实际是结构,条件的宽或严放在不同的结构位置体现					    *
//AND tips:																					*
//		之前老是用传入指针引用,实际上可以用传入数组(一维或二维)的方法,而且传指针没有必要引用*
//*******************************************************************************************
#include <iostream>
#include <cstdlib>

using namespace std;

	/*
	二维数组传参->>
	|:
	方法一:
		将二维数组强制转化为指针后,对其操作要像下边的一样,而不能直接[]下标了
		一维数组可以自动弱化为指针,行信息自动丢失
	int a[2][2]={1,2,3,4};
	test((int**)a);
	void test(int** a)
	{
		cout<<*a<<endl;
		cout<<*(a+1)<<endl;
	}
	方法二:
		用(*a)[]的方式传递数组,可以在函数体内按照数组的操作习惯进行操作	
	void test(int(*a)[2])
	{
		cout<<a[0][1]<<endl;//可以输出
		cout<<a<<endl;//输出地址
		cout<<(a+1)<<endl;
		cout<<(*(a+1))<<endl;//与上一句效果相同:输出地址.因为(a+1)是int**,而(*(a+1))是int* 都是要输出地址的节奏
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
			//算法导论提倡先按照完成时刻进行排序,而我这里
			//1.尝试使用ftime,ltime来判断可达性(失败)
			//2.使用了穷举同peer的元素来判断此index是否可达i.(结果依然失败)
			//3.设想:可以用DFS(BFS)返回值true or false来判断
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
			//最后还是采用书上的做法,按照完成时刻(树的后序遍历)降序排列.这利用了DFS搜索结果树的结构
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