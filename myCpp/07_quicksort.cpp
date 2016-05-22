#if 0
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int *test;

void print()
{
	for(int i=0;i<5;i++)
		cout<<setw(4)<<test[i];
	cout<<endl;
}

int partion(int*(&arr),int f,int l);
void quicksort(int*(&arr),int f,int l);

void main()
{
	test=new int[10];
	test[0]=1;
	test[1]=2;
	test[2]=4;
	test[3]=3;
	test[4]=5;

	quicksort(test,0,4);
	

	system("pause");
}

int partion(int*(&arr),int f,int l)
{
	int temp=arr[l];
	int p=f-1;

	for(int i=f;i<l;i++)
	{
		if(arr[i]<temp)
		{
			p++;
			int extemp=arr[i];
			arr[i]=arr[p];
			arr[p]=extemp;
		}
	}

	arr[l]=arr[p+1];
	arr[p+1]=temp;

	return p+1;
}

void quicksort(int*(&arr),int f,int l)
{
	if(f<l)
	{
		int q=partion(arr,f,l);
		quicksort(arr,f,q-1);
		quicksort(arr,q+1,l);
	}
}
#endif