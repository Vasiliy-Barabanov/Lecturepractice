#include <iostream>
#include <vector>

using namespace std;

void foo(vector<int> vec, int n) {
	try
	{
		vec.at(n);
		cout << n << endl;
		foo(vec, n + 1);
	}
	catch (...)
	{
		return;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	foo(vec, 0);
}

