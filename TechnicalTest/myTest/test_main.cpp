#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;

	//push $)CEW=:F.
	s.push(5);
	s.push(13);
	s.push(83);

	cout << "top=" << s.top() << endl;
	cout << "size=" << s.size() << endl;

	return 0;
}
