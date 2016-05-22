#if 0
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <map>
#include <iterator>
#include <iostream>

typedef std::pair<int,int> mPair;

using std::multimap;
using std::iterator;
using std::cin;


int main(int argc,char*argv[])
{

	/*//不用srand（unsigned time（NULL））看不出什么不同，但最好别这样使用
	for(int i=0;i<100;i++)
	{
		printf("%6d\n",rand());
	}*/


	/*//将数组随机排序
	//1.定义变量，使用到了STL中的multimap
	int nums[9]={1,2,3,4,5,6,7,8,9};
	srand((unsigned)time(NULL));
	multimap<int,int> mMap;
	char mark='0';
	//2.支持循环输入（有点小bug，比如输入“yyyy”，可以用string代替char解决）
	do{
		//2.1:插入multimap中
		for(int i=0;i<9;i++)
		{
			mMap.insert(mPair(rand(),nums[i]));
		}
		//2.2:使用迭代器输出(不必排序了，因为插入multimap的时候数据结构自动进行了排序)
		multimap<int,int>::iterator mIt;
		for(mIt=mMap.begin();mIt!=mMap.end();mIt++)
			printf("%3d",(*mIt).second);
		//2.3:清空multimap，以便于下次随机排序
		mMap.clear();
		printf("是否要继续生成，继续（y）");
	}
	while(cin>>mark && 'y'==mark);*/



	system("pause");
}
#endif