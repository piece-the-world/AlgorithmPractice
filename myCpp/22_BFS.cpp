#if 0
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct vertex
{
	int index;
	int color;
	int parent;
	int distance;
};
void checksizeof(int a[])
{
	int t=sizeof(a);//t=4��˵������aû���������ԣ�����Ϊָ����
	cout<<t<<endl;
}
void main()
{
	int mat[8][8]={0,1,1,0,0,0,0,0,
				   1,0,0,0,1,1,0,0,
				   1,0,0,1,0,0,0,0,
				   0,0,1,0,0,0,0,0,
				   0,1,0,0,0,1,1,0,
				   0,1,0,0,1,0,1,1,
				   0,0,0,0,1,1,0,1,
				   0,0,0,0,0,1,1,0};
	vertex v[8];//������ʱ����Ѿ������˿ռ�
	queue<vertex> q;
	//��ʼ������
	for(int i=0;i<8;i++)
	{
		v[i].index=i;
		v[i].color=-1;
		v[i].distance=-1;
		v[i].parent=-1;
	}
	v[0].color=0;
	v[0].distance=0;
	v[0].index=0;
	q.push(v[0]);
	//v[1]=new vertex();//�������������ʵ������Ϊnew���ص���ָ��,Ĭ�ϵĸ�ֵ�������޷�����.��explicit�йغ���.
	//BFS
	while(!q.empty())
	{
		vertex temp=q.front();
		v[temp.index].color=1;
		q.pop();

		for(int i=0;i<8;i++)
		{
			if(v[i].color==-1)
			{
				if(mat[i][temp.index])
				{
					v[i].parent=temp.index;
					v[i].distance=temp.distance+1;
					v[i].color=0;
					q.push(v[i]);
				}
			}
		}
	}

	system("pause");
}
#endif