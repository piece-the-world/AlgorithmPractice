#if 0
#include <stdio.h>
#include <stdlib.h>
#include <deque>

using std::deque;

void merge(int*(& target),int f,int m,int l);
void merge_sort(int*(&tar),int f,int l);

int main()
{
	/*//�Ƿ���ͨ��sizeof����飨ָ�룩��С
	int*pp=new int[44];
	for(int i=0;i<7;i++)
	{
		pp[i]=i;
	}
	int a=sizeof(*pp);//4
	int b=sizeof(pp);//4

	char*pp1=new char[44];
	for(int i=0;i<7;i++)
	{
		pp1[i]='7';
	}
	int a1=sizeof(*pp1);//1
	int b1=sizeof(pp1);//4

	int bb[44];
	for(int i=0;i<7;i++)
	{
		bb[i]=i;
	}
	int a3=sizeof(bb);//176=44*4(not 7*4)
	*/

	//1.�������飨ָ�룩
	printf("�������������Ŀ��\n");
	int num;
	scanf("%d",&num);
	int* p=new int[num];
	printf("�����������е�Ԫ�أ��س�ȷ��\n");
	for(int i=0;i<num;i++)
	{
		scanf("%d",&p[i]);
	}
	//2.���η�����ע�����鲻��ֱ�����ô��Σ��ή�ף����д��������
	merge_sort(p,0,num-1);
	//3.���������
	for(int i=0;i<num;i++)
	{
		printf("%3d",p[i]);
	}

	system("pause");
}

//merge_sort��Ҫ�����
void merge_sort(int*(&tar),int f,int l)
{
	if(f<l)
	{
		int m=(f+l)/2;
		merge_sort(tar,f,m);
		merge_sort(tar,m+1,l);
		merge(tar,f,m,l);
	}
}
//merge����ϣ����ĵıȽ������﷢��
void merge(int*(&target),int f,int m,int l)
{
	deque<int> L,R;
	for(int i=f;i<=l;i++)
	{
		if(i<=m)
			L.push_back(target[i]);
		else
			R.push_back(target[i]);
	}

	for(int i=f;i<=l;i++)
	{
		if(0!=L.size() && 0!=R.size())
		{
			if(L.front()<=R.front())
			{
				target[i]=L.front();
				L.pop_front();
			}
			else
			{
				target[i]=R.front();
				R.pop_front();
			}
		}
		else if(0==L.size() && 0!=R.size())
		{
				target[i]=R.front();
				R.pop_front();
		}
		else if(0!=L.size() && 0==R.size())
		{
				target[i]=L.front();
				L.pop_front();
		}
	}

}
#endif