#ifndef _INVENCO_H_
#define _INVENCO_H_
#include <iostream>
using namespace std;

//#define STACK_SIZE 1000000000	// 10^9 !!! out of range for interger
#define STACK_SIZE 100000

//#define _USE_POINTER_
class Solution
{
public:
	Solution();
	bool push(const int element); // element=value
	long top();
	void pop();
	void begin();
	bool rollback();
	bool commit();
	bool isFulled();
	bool isEmpty();
private:
	long topmost; 
#ifdef _USE_POINTER_
	int* element;
#else
	int element[STACK_SIZE];
#endif
};

#else
#endif