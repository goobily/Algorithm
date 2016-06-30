#ifndef _QUEUE_BY_ARRAY_H_
#define _QUEUE_BY_ARRAY_H_

#include <stdexcept>
#define DEFAULT_QUEUE_SIZE 32
template <class T>
class queue
{
public:
	queue(int capacity = DEFAULT_QUEUE_SIZE); 
	~queue();
	bool empty();
	int size();
	T back();
	T front();
	void push(T val);
	void pop();
private:
	T * pList_;
	int capacity_;
	int front_; // the first element pos
	int rear_; //the next pos of the last element
	int size_;
		
};

#endif