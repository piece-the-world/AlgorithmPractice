#if 0
//深度优先搜索.核心是递归的使用,辅以外部循环保证广度
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct node
{
	int color;
	int ftime;
	int ltime;
	int index;
	int parent;
};
//省事的做法,直接将变量设为全局.更可取的方法是将数组作为指针引用传入DFS-VISIT函数中
	int mat[6][6]={0,1,1,0,0,0,
				   0,0,1,0,0,0,
				   0,0,0,1,0,0,
				   0,1,0,0,0,0,
				   0,0,0,1,0,1,
				   0,0,0,0,0,1};
	node result[6];
	int mtime=0;
void DFS_VISIT(int index);

void main()
{
	//初始化
	for(int i=0;i<6;i++)
	{
		result[i].parent=-1;
		result[i].color=-1;
		result[i].index=i;
		result[i].ftime=-1;
		result[i].ltime=-1;
	}
	//循环调用
	for(int i=0;i<6;i++)
	{
		if(result[i].color==-1)
		{
			DFS_VISIT(i);
		}
	}

	for(int i=0;i<6;i++)
		cout<<setw(3)<<result[i].ftime<<" | "<<setw(3)<<result[i].index<<" pa: "<<setw(3)<<result[i].parent<<" | "<<setw(3)<<result[i].ltime<<endl;
	system("pause");
}

void DFS_VISIT(int index)
{
	//开始标记
	result[index].color=0;
	mtime++;
	result[index].ftime=mtime;
	for(int i=0;i<6;i++)
	{
		if(result[i].color==-1 && mat[index][i])
		{
			result[i].parent=index;
			DFS_VISIT(i);
		}
	}
	//结束标记
	result[index].color=1;
	mtime++;
	result[index].ltime=mtime;
}
#endif