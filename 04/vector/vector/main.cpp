#include <iostream>
#include <vector>
using namespace std;
void main()
{
	int n = 5;
	vector<int> v1;
	for (int i = 0; i < n; ++i)
		v1.push_back(i);

	cout << "max_sz: " << v1.max_size() << endl;
	vector<int>::iterator it;
	cout << "v1 foward: ";
	for (it = v1.begin(); it != v1.end(); ++it)
		cout << *it << " ";
	cout << endl;

	vector<int>::reverse_iterator rit;
	cout << "v1 reverse: ";
	for (rit = v1.rbegin(); rit != v1.rend(); ++rit)
		cout << *rit << " ";
	cout << endl;

	for (int i = 0 ; i < v1.size(); ++i)
		v1.at(i) = i * 10; //v1[i] = i * 10;

	cout << "v1*10 : ";
	for (int i = 0; i < v1.size(); ++i)
		cout << v1[i] << " "; // cout << v1.at(i) << " ";
	cout << endl;

	v1.pop_back();
	cout << "v1 pop_backed: ";
	for (int i = 0; i < v1.size(); ++i)
		cout << v1.at(i) << " ";
	cout << endl;

	vector<int> v2(3, 100);
	cout << "v2 : ";
	for (int i = 0; i < v2.size(); ++i)
		cout << v2.at(i) << " ";
	cout << endl;
	v1.swap(v2);

	cout << "v1 : ";
	for (int i = 0; i < v1.size(); ++i)
		cout << v1.at(i) << " ";
	cout << endl;
	cout << "v2 : ";
	for (int i = 0; i < v2.size(); ++i)
		cout << v2.at(i) << " ";
	cout << endl;

	// inserting
	vector<int> myvector(3, 100);
	vector<int>::iterator iter;

	iter = myvector.begin();
	iter = myvector.insert(iter, 200);

	myvector.insert(iter, 1, 300);

	iter = myvector.begin();

	vector<int> anothervector(2, 400);
	myvector.insert(iter + 2, anothervector.begin(), anothervector.end());

	int myarray[] = { 501,502,503 };
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	cout << "myvector contains:";
	for (iter = myvector.begin(); iter<myvector.end(); iter++)
		cout << ' ' << *iter;
	cout << '\n';

	// erasing
	myvector.clear();
	for (int i = 1; i <= 10; i++) 
		myvector.push_back(i);

	// erase the 6th element
	myvector.erase(myvector.begin() + 5);

	// erase the first 3 elements:
	myvector.erase(myvector.begin(), myvector.begin() + 3);

	std::cout << "myvector contains:";
	for (unsigned i = 0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}