/*
 * With queues elements are added to the back and the first element added becomes the front of the queue;
 * and only the first element can be accessed. In order to access the next element, the current front
 * of the queue most be eliminated. the front() method allows to identify the front of the queue, whereas
 * the back() method allows to identify the value of its last element
 */

#include <iostream>
#include <queue>

template <typename T>
void display(std::queue<T> q)
{
	std::cout << "[ ";
	while(!q.empty())
	{
		T elem = q.front();
		q.pop();
		std::cout << elem << " ";
	}
	sstd::cout << " ]" << std::endl;
}

int main()
{
	std::queue<int> q;
	
	for(int i : {1, 2, 3, 4, 5})
		q.push(i);
	display(q);
	std::cout << "Front: " << q.front() << std::endl;
	std::cout << "Back: " << q.back() << std::endl;
	
	q.push(100);
	display(q);
	
	std::cout << "Size: " << q.size() << std::endl;
	
	q.push(10);
	q.push(100);
	q.push(1000);
	display(q);
	
	std::cout << "Front: " << q.front() << std::endl;
	std::cout << "Back: " << q.front() << std::endl;
	
}