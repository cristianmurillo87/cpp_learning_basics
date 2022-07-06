/*
 * When dealing stacks, only the top element can be accessed; 
 * new elements can only be added to the top of the stack
 * and only the top most element in the stack can be removed. 
 * This means for example that iterators do not work with this type of containers 
 */
#include <iostream>
#include <stack>

template <typename T>
void display(std::stack<T> s)
{
	std::cout << "[";
	while(!s.empty())
	{
		T elem = s.top();
		s.pop();
		std::cout << elem << " ";
	}
	std::cout << "]" << std::endl;
}

int main()
{
	std::stack<int> s;
	
	for(int i : {1, 2, 3, 4, 5})
		s.push(i); // add elements on top of the stack
	display(s); // [5 4 3 2 1]
	
	s.push(100);
	display(s); // [100 5 4 3 2 1]
	
	s.pop(); // [5 4 3 2 1]
	s.pop(); // [4 3 2 1]
	
	while(!s.empty())
		s.pop();
	display(s) // []
	
	std::cout << "Size: " << s.size() << std::endl;
	
	s.push(10);
	display(s); // [10]
	
	s.top() = 100;
	display(s); // [100]
	return 0;
}