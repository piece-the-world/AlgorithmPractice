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

	/*//����srand��unsigned time��NULL����������ʲô��ͬ������ñ�����ʹ��
	for(int i=0;i<100;i++)
	{
		printf("%6d\n",rand());
	}*/


	/*//�������������
	//1.���������ʹ�õ���STL�е�multimap
	int nums[9]={1,2,3,4,5,6,7,8,9};
	srand((unsigned)time(NULL));
	multimap<int,int> mMap;
	char mark='0';
	//2.֧��ѭ�����루�е�Сbug���������롰yyyy����������string����char�����
	do{
		//2.1:����multimap��
		for(int i=0;i<9;i++)
		{
			mMap.insert(mPair(rand(),nums[i]));
		}
		//2.2:ʹ�õ��������(���������ˣ���Ϊ����multimap��ʱ�����ݽṹ�Զ�����������)
		multimap<int,int>::iterator mIt;
		for(mIt=mMap.begin();mIt!=mMap.end();mIt++)
			printf("%3d",(*mIt).second);
		//2.3:���multimap���Ա����´��������
		mMap.clear();
		printf("�Ƿ�Ҫ�������ɣ�������y��");
	}
	while(cin>>mark && 'y'==mark);*/



	system("pause");
}
#endif