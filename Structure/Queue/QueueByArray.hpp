#include "QueueByArray.h"

template <class T>
queue<T>::queue(int capacity) : pList_(NULL), capacity_(capacity), front_(0), rear_(0), size_(0) 
{
	if(capacity <=0 )
		throw std::invalid_argument("The capacity of queue should be larger than 0");
	try {
		pList_ = new T[capacity_];
	}
	catch (std::bad_alloc & e){
		cerr << "Fail to call new : " << e.what();
		abort();
	}
}

template <class T>
queue<T>::~queue()
{
	if(pList_ != NULL)
		delete[] pList_;
	pList_ = NULL;
}

template <class T>
bool queue<T>::empty()
{
	return size_ == 0;
}

template <class T>
int queue<T>::size()
{
	return size_;
}

template <class T>
void queue<T>::push(T val)
{
	if(size_ == capacity_){
		T * tmpList = pList_;
		int old_capacity = capacity_;
		capacity_ = capacity_ * 2;
		try{
			pList_ = new T[capacity_];
		}
		catch(std::bad_alloc & e) {
			cerr << "Fail to call new : " << e.what();
			abort();
		}
		int i = front_, j = 0;
		for(; j<size_; ++j,i=(i+1)%old_capacity) {
			pList_[j] = tmpList[i];
		}
		delete[] tmpList;
		pList_[size_++] = val;
		front_ = 0;
		rear_ = size_;	
	}
	else {
		pList_[rear_] = val;
		rear_ = (rear_+1)%capacity_;
		++size_;
	}
}

template <class T>
void queue<T>::pop()
{
	if(size_ > 0){
		front_ = (front_+1) % capacity_;
		--size_;
	}
	else{
		throw std::underflow_error("The queue is empty");
	}
}

template <class T>
T queue<T>::front()
{
	if(size_ > 0) {
		return pList_[front_];
	}
	else {
		throw std::underflow_error("The queue is empty");
	}
}

template <class T>
T queue<T>::back()
{
	if(size_ > 0) {
		return rear_ == front_ ? pList_[(rear_-1+capacity_)%capacity_] : pList_[rear_-1];
	}
	else {
		throw std::underflow_error("The queue is empty");
	}
}
