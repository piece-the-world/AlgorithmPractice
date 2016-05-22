#if 0
//������
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
	cout<<"�����뽫Ҫ�����int���������"<<endl;
	cin>>count;
	cout<<"�����������������ݣ�"<<endl;
	int* data=new int[count];
	//istream_iterator<int,char> it=istream_iterator<int,char>(cin);//��ȥ�����û�и��õ��÷�������
	for(int i=0;i<count;i++)
		cin>>data[i];
	print(data,count);
	heap_sort(data,count);
	print(data,count);


	system("pause");
}

/*//���ִ�ӡ������ƫ�����
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

//��֪�߶ȺͿ�ȣ���ӡ����������Ϊ�˴�ӡ�����������ĵĶ�������ÿ�еļ����Ԥ��Ķ�����
void print(int*(&heap),int size)
{
	int height=(int)(log((double)size)/log(2.0))+1;//û��log2���û��׹�ʽ�õ��߶�
	int width=(int)pow(2.0,height-1);//���ݺ���pow�õ����һ��Ԫ�ظ���
	int inter=width*2;
	int index=0;

	//������һ���������������ͬ��n���ַ��������ˣ�����putҲ����write,��ɶ��
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

//���������������ʣ���ɶ�����ĺ��ģ�
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

//��������תΪ�����������Ե����ϣ�
void build_max_heap(int*(&heap),int size)
{
	for(int i=(size/2-1);i>=0;i--)
		max_heapify(heap,i,size);

}

//��ɶ������������£�
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