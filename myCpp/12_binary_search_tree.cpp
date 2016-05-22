#if 0
//二叉查找树的约束比我想象的要强很多
//构建二叉查找树的操作没有考虑到内存分配,如果用自己设计的动态数组的话将造成内存的大量浪费.为此考虑hashmap来实现

//*********************************
//       这个功能没有写           *
//删除二叉树节点分两种情况		  *
//		1.指定index无儿子		  *
//		2.指定index有儿子,删除其  *
//		successor或者presuccessor *
//*********************************

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int left(int index);
int right(int index);
int parent(int index);
int tree_successor(int*(&data),int index,int size);
int tree_presuccessor(int*(&data),int index,int size);
void inorder_tree_walk(int*(&data),int index,int size);
void tree_search(int*(&data),int index,int target,int size);
void tree_search2(int*(&data),int index,int target,int size);
int tree_minimum(int*(&data),int index,int size);
int tree_maximum(int*(&data),int index,int size);
void main()
{
	int data[7]={5,3,7,2,5,0,8};
	int* pdata=data;

	cout<<tree_presuccessor(pdata,6,7);

	system("pause");
}

int left(int index)
{
	return (2*index+1);
}
int right(int index)
{
	return (2*index+2);
}
int parent(int index)
{
	//使用位操作,效率稍微好一点
	if(index&1)
		index/=2;
	else
		index=(index/2-1);
	return index;
}
//*********************************
//寻找successor分三种情况		  *
//		1.指定index有右儿子		  *
//		2.指定index本身为左儿子	  *
//		3.指定index有左儿子的祖先 *
//*********************************
int tree_successor(int*(&data),int index,int size)
{
	if(data[index]==0 || index>=size)
	{
		cout<<"输入index有误!"<<endl;
		return 0;
	}else if(right(index)<size && data[right(index)]!=0)
	{
		return tree_minimum(data,right(index),size);
	}else
	{
		while(!(index&1))
		{
			if(0==index)
			{
				cout<<"指定的index没有successor(即此index为最大值的下标)"<<endl;
				break;
			}
			index=parent(index);
		}
		if(index&1)
			return parent(index);
		else
			return 0;
	}
}
//*********************************
//寻找presuccessor也分三种情况	  *
//		1.指定index有左儿子		  *
//		2.指定index本身为右儿子	  *
//		3.指定index有右儿子的祖先 *
//*********************************
int tree_presuccessor(int*(&data),int index,int size)
{
	if(data[index]==0 || index>=size)
	{
		cout<<"输入index有误!"<<endl;
		return 0;
	}else if(data[left(index)]!=0 && left(index)<size)
		return tree_maximum(data,left(index),size);
	else
	{
		while(index&1)
		{
			if(0==index)
			{
				cout<<"指定的index没有presuccessor(即此index为最小值的下标)"<<endl;
				break;
			}
			index=parent(index);
		}
		if(!(index&1))
			return parent(index);
		else
			return 0;
	}
}

//实现排序输出(按照树的形状),这个功能用循环是做不出来的,循环不可能有这么多的转向标记
void inorder_tree_walk(int*(&data),int index,int size)
{
	if(index<size && data[index]!=0)
	{
		inorder_tree_walk(data,left(index),size);
		cout<<setw(3)<<data[index];
		inorder_tree_walk(data,right(index),size);
	}
}
//这里并不是完全递归,而是用递归的方法搜索一条路径(所以用循环是可以做到的).而且搜到父节点满足题意的话就不会往下搜子节点了
void tree_search(int*(&data),int index,int target,int size)
{
	if(index>=size || data[index]==0)
		return;
	else if(data[index]==target)
		//如果要搜索到所有结果(包括一些重复的元素),这个分类内部再搞一个递归,分别搜索左右子树
		cout<<"搜索到结果,下标为:"<<index<<endl;
	else if(target<data[index])
		tree_search(data,left(index),target,size);
	else
		tree_search(data,right(index),target,size);
}
//用循环方法执行的稍微快一些,一棵子树上只可以搜索到一个结果
void tree_search2(int*(&data),int index,int target,int size)
{
	while(index<size)
	{
		//这个++然后continue都多余,因为当搜索到超出size时,已经不可能再找到另一个路径了
		if(data[index]==0)
		{
			index++;
			continue;
		}
		else if(target==data[index])
		{
			cout<<"搜索到结果,下标为:"<<index<<endl;
			index++;
			continue;
		}
			
		else if(target<data[index])
			index=left(index);
		else if(target>data[index])
			index=right(index);
	}
}

int tree_minimum(int*(&data),int index,int size)
{
	while(index<size && data[index]!=0)
		index=left(index);
	cout<<"最小值得下标为:"<<parent(index)<<"最小值:"<<data[parent(index)]<<endl;
	return parent(index);
}
int tree_maximum(int*(&data),int index,int size)
{
	while(index<size && data[index]!=0)
		index=right(index);
	cout<<"最大值的下标是:"<<parent(index)<<endl<<"最大值:"<<data[parent(index)]<<endl;
	return parent(index);
}
#endif