#include <iostream>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

void main()
{
	map<int, int> order;
	order[5] = 5 * 2;
	order[3] = 3 * 2;
	order[20] = 20 * 2;
	order[1] = 1 * 2;

	map<int, int>::iterator it = order.begin();
	for (; it != order.end(); ++it)
		cout << it->first << ":" << it->second << endl;

	cout << order[1] << endl;
	cout << order[20] << endl;
	cout << order[4] << endl;
	cout << endl;

	unordered_map<int, string> uorder;
	uorder[5] = "5 * 2";
	uorder[3] = "3 * 2";
	uorder[20] = "20 * 2";
	uorder[1] = "1 * 2";

	for (auto i = uorder.begin(); i != uorder.end(); ++i)
		cout << i->first << ":" << i->second << endl;

	string str = uorder[100] = "100 * 2"; // increase size by one
	cout << uorder[1] << endl;
	cout << uorder.at(20) << endl;
	cout << (uorder[4]) << endl; // increase size by one 

	int sz = uorder.size(); // 5 3 20 1 100 4

	unordered_map<int, string>::iterator iter = uorder.find(30);

	if (iter == uorder.end())
	{
		cout << "not found\ninserting...\n";
		uorder.insert(pair<int,string>(30, "30 *2"));
		cout << endl;
	}
	else
	{
		cout << "got it\n";
		cout << iter->first << ":" << iter->second << endl;
		cout << endl;
	}

	iter = uorder.find(30);
	if (iter == uorder.end())
	{
		cout << "not found\n";
		uorder.insert(pair<int, string>(30, "30 *2"));
		cout << endl;
	}
	else
	{
		cout << "got it\n";
		cout << iter->first << ":" << iter->second << endl;
		cout << endl;
	}

	return;
}