#if 0
//�����������.�����ǵݹ��ʹ��,�����ⲿѭ����֤���
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
//ʡ�µ�����,ֱ�ӽ�������Ϊȫ��.����ȡ�ķ����ǽ�������Ϊָ�����ô���DFS-VISIT������
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
	//��ʼ��
	for(int i=0;i<6;i++)
	{
		result[i].parent=-1;
		result[i].color=-1;
		result[i].index=i;
		result[i].ftime=-1;
		result[i].ltime=-1;
	}
	//ѭ������
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
	//��ʼ���
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
	//�������
	result[index].color=1;
	mtime++;
	result[index].ltime=mtime;
}
#endif