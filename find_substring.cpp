#include <iostream>
#include <map>
#include <string>
using namespace std;
int find_substring(string str, string sub_str)
{
	int size_str = str.size();
	int size_sub_str = sub_str.size();
	map<char, int> table_offset;
	for (int i = 0; i < 256; ++i)
	{
		table_offset.insert(make_pair(i, size_sub_str));
	}
	for (int i = 0; i < size_sub_str - 1; ++i)
	{
		table_offset[sub_str[i]] = size_sub_str - i - 1;
	}
	int k = size_sub_str - 1;
	while (k < size_str)
	{
		int j = 0;
			while ((j < size_sub_str) && str[k - j] == sub_str[size_sub_str - j - 1])
			{
				j++;
			}
		if (j != size_sub_str)
			k += table_offset[str[k]];
		else
			return k - size_sub_str + 1;
	}
	return -1;
}
