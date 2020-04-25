#include "Stack_invenco.h"
#include <cassert>

Solution::Solution()
{
	topmost = -1;
	// 10^9
#ifdef _USE_POINTER_
	element = (int*)malloc(sizeof(int)*STACK_SIZE);
#endif
}

bool Solution::push(const int element)
{
	if (isFulled()) return false;

	topmost++;
	this->element[topmost] = element;

	return true;
}

long Solution::top()
{
	if (isEmpty()) return 0;

	return element[topmost];
}

void Solution::pop()
{
	if (!isEmpty()) topmost--;
}

bool Solution::isFulled()
{
	if (topmost == STACK_SIZE - 1) return true;
	return false;
}

bool Solution::isEmpty()
{
	if (topmost == -1) return true;
	return false;
}


#if 1 // provided by Invenco
void example1()
{
	Solution sol;
	sol.push(5);
	sol.push(2);	// stack [5, 2]
	assert(sol.top() == 2);// stack [5]
	sol.pop();
	assert(sol.top() == 5);

	Solution sol2;
	assert(sol2.top() == 0); //top of an empty stack is 0 
	sol2.pop();// pop should do nothing
}
void example2()
{
	Solution sol;
	sol.push(4);
	sol.begin();// start transaction 1

	sol.push(7);// stack : [4,7]
	sol.begin();// start transaction 2

	sol.push(2);// stack : [4,7,2]
	assert(sol.rollback() == true);// rollback transaction 2
	assert(sol.top() == 7); // stack : [4,7]
	sol.begin();// rollback transaction 3

	sol.push(10); // stack : [4,7,10]
	assert(sol.commit() == true);// transaction 3 is committed
	assert(sol.top() == 10);
	assert(sol.rollback() == true); // rollback transaction 1
	assert(sol.top() == 4);// stack : [4]
	assert(sol.commit() == false);// there is no open transaction
}
#endif
