#if 0
#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <unordered_set>

using namespace std;
typedef pair<int,int> edge;
const int N=9;
//这个类直接用点集就成,用这个tree{index;edges}接口太复杂了
struct tree
{
	int index;
	unordered_set<int,hash<int> > vers;
};
struct quanedge
{
	int quan;
	edge medge;
};
void quicksort(vector<quanedge> &e,int f,int l);
int partion(vector<quanedge> &e,int f,int l);
int find_tree_index(tree trees[],int size,int verindex);
void tree_union(tree &to,tree &from);

void main()
{
	int mat[N][N]={0,4,0,0,0,0,0,8,0,
				   4,0,8,0,0,0,0,11,0,
				   0,8,0,7,0,4,0,0,2,
				   0,0,7,0,9,14,0,0,0,
				   0,0,0,9,0,10,0,0,0,
				   0,0,4,14,10,0,2,0,0,
				   0,0,0,0,0,2,0,1,6,
				   8,11,0,0,0,0,1,0,7,
				   0,0,2,0,0,0,6,7,0};

	tree trees[N];
	for(int i=0;i<N;i++)
	{
		trees[i].index=i;
		trees[i].vers.insert(i);
	}
	vector<quanedge> sortededges;
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
		{
			if(mat[i][j])
			{
				quanedge me;
				me.quan=mat[i][j];
				me.medge.first=i;
				me.medge.second=j;
				sortededges.push_back(me);
			}
		}
	quicksort(sortededges,0,sortededges.size()-1);

	vector<edge> result;
	for(int i=0;i<sortededges.size();i++)
	{
		edge temp=sortededges[i].medge;
		int indexleft=find_tree_index(trees,N,temp.first);
		int indexright=find_tree_index(trees,N,temp.second);
		if(indexleft!=indexright)
		{
			result.push_back(temp);
			tree_union(trees[indexleft],trees[indexright]);
		}else if(trees[indexleft].vers.size()==N)
		{
			break;
		}
	}



	system("pause");
}
void quicksort(vector<quanedge> &e,int f,int l)
{
	if(f<l)
	{
		int q=partion(e,f,l);
		quicksort(e,f,q-1);
		quicksort(e,q+1,l);
	}
}
int partion(vector<quanedge> &e,int f,int l)
{
	int p=f-1;
	quanedge temp=e[l];
	for(int i=f;i<l;i++)
	{
		if(e[i].quan<temp.quan)
		{
			p++;
			quanedge t=e[i];
			e[i]=e[p];
			e[p]=t;
		}
	}
	e[l]=e[p+1];
	e[p+1]=temp;
	return p+1;
}

int find_tree_index(tree trees[],int size,int verindex)
{
	for(int i=0;i<size;i++)
	{
		if(trees[i].index!=-1)
		{
			if(trees[i].vers.find(verindex)!=trees[i].vers.end())
			{
				return trees[i].index;
			}
		}
	}
	return -1;
}
void tree_union(tree &to,tree &from)
{
	for(unordered_set<int,hash<int> >::iterator i=from.vers.begin();i!=from.vers.end();i++)
	{
		to.vers.insert(*i);
	}
	from.index=-1;
}
#endif