/*
第1001题，这个答案无法通过POJ官方的G++和C++编译，但是本人在GCC7+和VS2017 下均编译测试可行
题目地址：http://poj.org/problem?id=1001&lang=zh-CN
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using std::string;
using std::cout;
using std::cin;
class double2string;
void operator*=(double2string &flo1, double2string &flo2);
void swap(double2string &flo1, double2string &flo2);
void check_mv(int &move_in, int &res)
{
	move_in = 0;
	if (res >= 10)
	{
		move_in = res / 10;
		res %= 10;
	}
}
void _vec_plus_vec(std::vector<int> &vec2, std::vector<int> &vec1)
{
	auto rit = vec2.rbegin(), reit = vec2.rend(), drit = vec1.rbegin(), dreit = vec1.rend();
	int move_in = 0;
	for (; drit != dreit; ++drit, ++rit)
	{
		int res = *drit + *rit;
		res += move_in;
		check_mv(move_in, res);
		*rit = res;
		if (drit + 1 == dreit && move_in)
		{				
			if (move_in && (rit + 1) == reit)
			{
				vec2.insert(vec2.begin(), move_in);
				break;
			}
			else
			{
				++rit;
				for (; rit != vec2.rend(); ++rit)
				{
					res = *rit + move_in;
					check_mv(move_in, res);
					*rit = res;
					if (!move_in)
						break;
					if (rit + 1 == reit && move_in)
					{
						vec2.insert(vec2.begin(), move_in);
						std::vector<int>::reverse_iterator it(vec2.begin() + 1);
						rit = it;
					}
				}
				break;
			}
		}
	
	}
}
void str_p_str(string &str1, string &str2)
{
	int times = -1;
	bool modl = false;
	std::vector<int> vec1, vec2;
	for (auto ch : str1)
	{
		if (ch == '.');
		else
		{
			vec1.push_back(ch - '0');
		}
	}
	modl = false;
	for (auto ch : str2)
	{
		if (ch == '.');
		else
		{
			vec2.push_back(ch - '0');
		}
	}
	auto rit = vec2.rbegin(), reit = vec2.rend(), drit = vec1.rbegin(), dreit = vec1.rend();
	std::vector<std::vector<int>>plus_result;
	for (int i = 0; rit != reit; ++rit, ++i)
	{
		auto tmp_d = drit, tmp_de = dreit;
		std::vector<int> tmp_res_in_1;
		int move_in = 0;
		for (; tmp_d != tmp_de; ++tmp_d)
		{
			int res = *tmp_d **rit;
			res += move_in;
			check_mv(move_in, res);
			tmp_res_in_1.insert(tmp_res_in_1.begin(), res);
			if (tmp_d + 1 == tmp_de && move_in)
				tmp_res_in_1.insert(tmp_res_in_1.begin(), move_in); 
		}
		if (i == 0)
		{
			
			plus_result.push_back((std::vector<int> &&)tmp_res_in_1);
		}
		else
		{
			for (int j = 0; j != i; ++j)
				tmp_res_in_1.push_back(0);
			plus_result.push_back((std::vector<int> &&)tmp_res_in_1);
			_vec_plus_vec(plus_result[i], plus_result[i - 1]);
		}
	}
	str1.clear();
	int count = 0;
	for (auto i : plus_result.back())
	{
		str1.push_back(i + '0');
	}
}
class double2string
{
	friend void operator*=(double2string &flo1, double2string &flo2);
	friend void swap(double2string &flo1, double2string &flo2);
public:
	double2string(long double doub):base(doub),str_base(std::to_string(doub))
	{
		auto it = std::find_if(str_base.rbegin(), str_base.rend(), [](char str_em) {
			return str_em != '0' && str_em != 0; });
		str_base.erase(it.base(), str_base.end());
	}
	 ~double2string() = default;
	 string &str() { return str_base; }
private:
	long double base;
	string str_base;
};
void operator*=(double2string &flo1, double2string &flo2)
{
	if (flo1.str_base.length() < flo2.str_base.length())
		swap(flo1, flo2);
	str_p_str(flo1.str_base, flo2.str_base);
}
void swap(double2string &flo1, double2string &flo2)
{
	long double temp = flo1.base;
	std::swap(flo1.str_base, flo2.str_base);
}
int main()
{
	long double a;
	int b;
	while (std::cin >> a >> b)
	{
		double2string aa(a), bb(a);
		for (int i = 1; i != b; ++i)
			aa *= bb;
		auto it = find(bb.str().begin(), bb.str().end(), '.');
		auto nu = bb.str().end() - it - 1;
		aa.str().insert((aa.str().rbegin() + nu * b).base(), '.');
		if (a < 1.0)
		{
			auto it = find(aa.str().begin(), aa.str().end(), '.');
			aa.str().insert(++it, '0');
			aa.str().erase(aa.str().begin());
		}
		std::cout << aa.str() << std::endl;
	}
    return 0;
}