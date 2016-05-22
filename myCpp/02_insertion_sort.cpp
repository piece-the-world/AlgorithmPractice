#if 0
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{

	printf("请输入数组中数字的个数\n");
	int num;
	scanf("%d",&num);
	int* pInt=new int[num];
	printf("请输入数组中数字\n");
	for(int i=0;i<num;i++)
	{
		scanf("%d",&pInt[i]);
	}


	for(int i=1;i<num;i++)
	{
		int key=pInt[i];
		int j=i-1;
		for(;j>=0 && key<pInt[j];j--)
		{
			pInt[j+1]=pInt[j];
		}
		pInt[j+1]=key;
	}

	printf("插入排序的结果是：\n");
	for(int i=0;i<num;i++)
	{
		printf("%3d",pInt[i]);
	}

	system("pause");
}
#endif