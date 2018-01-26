#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

bool mycomp(int l, int r)
{
	return l > r;
}

void main()
{
	int n = 10;
	default_random_engine gen;
	uniform_int_distribution<> dis(1, 100);
	vector<int> vec;
	for (int i = 0; i < n; ++i)
		vec.push_back(dis(gen));

	cout << "vector: ";
	for (int i = 0; i < n; ++i)
		cout << vec[i] <<" ";
	cout << endl;

	// max, min elements
	cout << "Maximum element of vector is: ";
	cout << *max_element(vec.begin(), vec.end()) << endl;
	cout << "Minimum element of vector is: ";
	cout << *min_element(vec.begin(), vec.end()) << endl;

	// sort
	sort(vec.begin(), vec.end());
	cout << "vector: ";
	for (int i = 0; i < n; ++i)
		cout << vec[i] << " ";
	cout << endl;

	// find
	int q = 101;
	vector<int>::iterator iter;
	iter = find(vec.begin(), vec.end(), q);
	if (iter == vec.end())
		cout << "not found " << q << endl;
	else
		cout << "found " << q << endl;

	// count
	q = vec[0];
	vec.push_back(q);
	cout << q << " occured: " <<count(vec.begin(), vec.end(), q) << endl;

	// sort descending order
	sort(vec.begin(), vec.end(), mycomp);
	cout << "vector: ";
	for (int i = 0; i < n; ++i)
		cout << vec[i] << " ";
	cout << endl;

	// sort ascending order again
	sort(vec.begin(), vec.end());

	// binary search
	q = vec[0];
	if(binary_search(vec.begin(), vec.end(), q))
		cout << "found " << q << endl;
	else
		cout << "not found " << q << endl;
}