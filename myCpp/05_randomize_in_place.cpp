#if 0
//原地随机排序，是个好方法，good
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iterator>
#include <algorithm>

using namespace std;

void main()
{

	srand((unsigned)time(NULL));

	int num[10]={1,2,3,4,5,6,7,8,9,0};
	for(int i=0;i<10;i++)
	{
		int temp,index=rand()%10;
		temp=num[i];
		num[i]=num[index];
		num[index]=temp;
	}

	copy(num,num+10,ostream_iterator<int,char>(cout,"\n"));
	
	system("pause");
}
#endif