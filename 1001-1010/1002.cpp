/*
这个题难度比上一题难度小了很多，只需要对map的一个确定，对mai的解引用访问和迭代器访问之间的差距有了解就好
原题地址：http://poj.org/problem?id=1002&lang=zh-CN
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using std::string;
using std::pair;
using std::map;
int main()
{
	const map<char, char> dic{
		{ 'A', '2' },{ 'B', '2' },{ 'C', '2' },
		{ 'D', '3' },{ 'E', '3' },{ 'F', '3' },
		{ 'G', '4' },{ 'H', '4' },{ 'I', '4' },
		{ 'J', '5' },{ 'K', '5' },{ 'L', '5' },
		{ 'M', '6' },{ 'N', '6' },{ 'O', '6' },
		{ 'P', '7' },{ 'R', '7' },{ 'S', '7' },
		{ 'T', '8' },{ 'U', '8' },{ 'V', '8' },
		{ 'W', '9' },{ 'X', '9' },{ 'Y', '9' } };
	map<string, size_t>final_book;
	int number;
	std::cin >> number;
	getchar();
	std::vector<string> lines(number);
	for (int i = 0; i < number; ++i)
		std::getline(std::cin, lines[i]);
	for (auto &it : lines)
	{
		auto its = std::stable_partition(it.begin(), it.end(), [](char ch) {return ch != '-'; });
		it.erase(its, it.end());
		string temp;
		for (auto its : it)
			temp.push_back(dic.find(its) == dic.end() ? its : dic.at(its));
		temp.insert(temp.begin() + 3, '-');
		++final_book[temp];
	}
	bool duplicates = 0;
	for (auto it : final_book)
	{
		std::cout << it.first << " " << it.second << std::endl;
		if (it.second > 2)
			duplicates = 1;
	}
	if (!duplicates)
		std::cout << "No duplicates. " << std::endl;
	return 0;
}