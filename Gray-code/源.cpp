#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

/*当n = 1时，为[0, 1]
当n = 2时，为[00, 01, 11, 10]
当n = 3时，为[000, 001, 011, 010, 110, 111, 101, 100]
由此可以看出新的序列其实是在前面序列基础上插入新的值
其中前半部分的数值不变，后半部分的数值为上个序列中每个元素第n个位变1，逆向插入*/
//如果必须显示001，可以用string；可以两个string交替着来进行操作，得到最终结果
class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> res;
		if (n == 0)
		{
			res.push_back(0);
			return res;
		}
		res.push_back(0);
		res.push_back(1);
		for (int i = 2; i <= n; ++i)
		{
			for (int j = (1 << (i - 1))-1; j >= 0; --j)
			{
				res.push_back(res[j] + (1 << (i - 1)));
			}
		}
		return res;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		Solution Res;
		vector<int> res = Res.grayCode(n);
		for (int i = 0; i < res.size(); ++i)
			cout << res[i] << endl;//输出的是十进制数，如要求转二进制的话，自己写除二求余运算进行转换
	}
	return 0;
}
