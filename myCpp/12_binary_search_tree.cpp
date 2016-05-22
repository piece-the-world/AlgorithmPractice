#if 0
//�����������Լ�����������Ҫǿ�ܶ�
//��������������Ĳ���û�п��ǵ��ڴ����,������Լ���ƵĶ�̬����Ļ�������ڴ�Ĵ����˷�.Ϊ�˿���hashmap��ʵ��

//*********************************
//       �������û��д           *
//ɾ���������ڵ���������		  *
//		1.ָ��index�޶���		  *
//		2.ָ��index�ж���,ɾ����  *
//		successor����presuccessor *
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
	//ʹ��λ����,Ч����΢��һ��
	if(index&1)
		index/=2;
	else
		index=(index/2-1);
	return index;
}
//*********************************
//Ѱ��successor���������		  *
//		1.ָ��index���Ҷ���		  *
//		2.ָ��index����Ϊ�����	  *
//		3.ָ��index������ӵ����� *
//*********************************
int tree_successor(int*(&data),int index,int size)
{
	if(data[index]==0 || index>=size)
	{
		cout<<"����index����!"<<endl;
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
				cout<<"ָ����indexû��successor(����indexΪ���ֵ���±�)"<<endl;
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
//Ѱ��presuccessorҲ���������	  *
//		1.ָ��index�������		  *
//		2.ָ��index����Ϊ�Ҷ���	  *
//		3.ָ��index���Ҷ��ӵ����� *
//*********************************
int tree_presuccessor(int*(&data),int index,int size)
{
	if(data[index]==0 || index>=size)
	{
		cout<<"����index����!"<<endl;
		return 0;
	}else if(data[left(index)]!=0 && left(index)<size)
		return tree_maximum(data,left(index),size);
	else
	{
		while(index&1)
		{
			if(0==index)
			{
				cout<<"ָ����indexû��presuccessor(����indexΪ��Сֵ���±�)"<<endl;
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

//ʵ���������(����������״),���������ѭ��������������,ѭ������������ô���ת����
void inorder_tree_walk(int*(&data),int index,int size)
{
	if(index<size && data[index]!=0)
	{
		inorder_tree_walk(data,left(index),size);
		cout<<setw(3)<<data[index];
		inorder_tree_walk(data,right(index),size);
	}
}
//���ﲢ������ȫ�ݹ�,�����õݹ�ķ�������һ��·��(������ѭ���ǿ���������).�����ѵ����ڵ���������Ļ��Ͳ����������ӽڵ���
void tree_search(int*(&data),int index,int target,int size)
{
	if(index>=size || data[index]==0)
		return;
	else if(data[index]==target)
		//���Ҫ���������н��(����һЩ�ظ���Ԫ��),��������ڲ��ٸ�һ���ݹ�,�ֱ�������������
		cout<<"���������,�±�Ϊ:"<<index<<endl;
	else if(target<data[index])
		tree_search(data,left(index),target,size);
	else
		tree_search(data,right(index),target,size);
}
//��ѭ������ִ�е���΢��һЩ,һ��������ֻ����������һ�����
void tree_search2(int*(&data),int index,int target,int size)
{
	while(index<size)
	{
		//���++Ȼ��continue������,��Ϊ������������sizeʱ,�Ѿ����������ҵ���һ��·����
		if(data[index]==0)
		{
			index++;
			continue;
		}
		else if(target==data[index])
		{
			cout<<"���������,�±�Ϊ:"<<index<<endl;
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
	cout<<"��Сֵ���±�Ϊ:"<<parent(index)<<"��Сֵ:"<<data[parent(index)]<<endl;
	return parent(index);
}
int tree_maximum(int*(&data),int index,int size)
{
	while(index<size && data[index]!=0)
		index=right(index);
	cout<<"���ֵ���±���:"<<parent(index)<<endl<<"���ֵ:"<<data[parent(index)]<<endl;
	return parent(index);
}
#endif