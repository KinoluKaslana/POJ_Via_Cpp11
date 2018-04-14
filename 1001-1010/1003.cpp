#include<iostream>
/*
*		这道题实际上就是给定一个卡片长度，求1/n!>=给定卡片长度的一个题目（翻译很麻烦的，其实很简单）
*/
int main()
{
	double cdLenth = 0.0;
	while (std::cin >> cdLenth, cdLenth != 0.0)
	{
		int cdCount = 0;
		double sumLenth = 0.0;
		for (int i = 2; sumLenth < cdLenth; ++i, ++cdCount)
			sumLenth += (1.0 / i);
		std::cout << cdCount << " card(s)" << std::endl;
	}
	return 0;
}