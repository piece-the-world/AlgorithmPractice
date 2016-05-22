#if 0
//堆排序
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <iterator>
#include <algorithm>

using namespace std;

void print(int*(&heap),int size);
void max_heapify(int*(&heap),int index,int size);
void build_max_heap(int*(&heap),int size);
void heap_sort(int*(&heap),int size);

void main()
{
	int count;
	cout<<"请输入将要排序的int数组个数："<<endl;
	cin>>count;
	cout<<"现在请输入数组内容："<<endl;
	int* data=new int[count];
	//istream_iterator<int,char> it=istream_iterator<int,char>(cin);//回去查查有没有更好的用法来输入
	for(int i=0;i<count;i++)
		cin>>data[i];
	print(data,count);
	heap_sort(data,count);
	print(data,count);


	system("pause");
}

/*//这种打印方法，偏向左边
void print(int*(&heap),int size)
{
	int height=(int)(log((double)size)/log(2.0))+1;
	int width=(int)pow(2.0,height-1);
	int inter=width;
	int index=0;

	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((j%inter)==0 && index<size)
			{
				cout<<setw(3)<<heap[index];
				index++;
			}
			else
				cout<<setw(3)<<" ";
		}
		cout<<endl;
		inter=inter/2;
	}

}*/

//已知高度和宽度，打印二叉树。（为了打印出顶点在中心的二叉树，每行的间距是预想的二倍）
void print(int*(&heap),int size)
{
	int height=(int)(log((double)size)/log(2.0))+1;//没有log2，用换底公式得到高度
	int width=(int)pow(2.0,height-1);//用幂函数pow得到最后一层元素个数
	int inter=width*2;
	int index=0;

	//好像有一个函数可以输出相同的n个字符，忘记了，不是put也不是write,是啥？
	for(int i=0;i<width*6;i++)
		cout<<"*";
	cout<<endl;

	for(int i=0;i<height;i++)
	{
		for(int j=0;j<(width*2-1);j++)
		{
			if((j%inter)==(inter/2-1) && index<size)
			{
				cout<<setw(3)<<heap[index];
				index++;
			}
			else
				cout<<setw(3)<<" ";
		}
		cout<<endl;
		inter=inter/2;
	}

	for(int i=0;i<width*6;i++)
		cout<<"*";
	cout<<endl;
}

//保持最大二叉树性质（完成堆排序的核心）
void max_heapify(int*(&heap),int index,int size)
{
	int l=index*2+1;
	int r=l+1;
	int largest;
	if(l<size && heap[l]>heap[index])
		largest=l;
	else
		largest=index;
	if(r<size && heap[r]>heap[largest])
		largest=r;
	if(largest!=index)
	{
		int temp=heap[index];
		heap[index]=heap[largest];
		heap[largest]=temp;
		max_heapify(heap,largest,size);
	}
}

//将二叉树转为最大二叉树（自底向上）
void build_max_heap(int*(&heap),int size)
{
	for(int i=(size/2-1);i>=0;i--)
		max_heapify(heap,i,size);

}

//完成堆排序（子上向下）
void heap_sort(int*(&heap),int size)
{
	build_max_heap(heap,size);
	for(int i=(size-1);i>0;i--)
	{
		int temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp;
		size--;
		max_heapify(heap,0,size);
	}
}
#endif