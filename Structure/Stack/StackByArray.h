#ifndef _STACK_BY_TEMPLATE_H_
#define _STACK_BY_TEMPLATE_H_

#include <stdexcept>

#define DEFAULT_STACK_SIZE 32

template <class ElemType>
class stack {
public:
	stack(int capacity) : elements_(NULL), top_(0), capacity_(capacity)
	{
		if(capacity <=0){
			throw std::invalid_argument("The stack capacity should be larger than 0");
		}
		try {
			elements_ = new ElemType[capacity_];
		}
		catch(std::bad_alloc & e) {
			cerr << "Fail to new : " << e.what();
			abort();
		}
	}
	stack() : elements_(NULL), top_(0), capacity_(DEFAULT_STACK_SIZE)
	{
		try {
			elements_ = new ElemType[capacity_];
		}
		catch(std::bad_alloc & e) {
			cerr << "Fail to new : " << e.what();
			abort();
		}
	}
	~stack() {
		delete[] elements_;
	}
	int size() {return top_;}
	int getCapacity() {return capacity_;}
	bool isFull() { return top_ >= capacity_;}
	bool isEmpty() {return top_ == 0;}
	void push(ElemType val){
		if (isFull()){
			ElemType* tmpElements = elements_;
			capacity_ = capacity_ * 2;
			try {
				elements_ = new ElemType[capacity_];
			}
			catch(std::bad_alloc & e)
			{
				cerr << "Fail to new : " << e.what();
				abort();
			}
			for (int i=0; i<top_; ++i){
				elements_[i] = tmpElements[i];
			}
			elements_[top_++] = val;
			delete[] tmpElements;
		}
		else {
			elements_[top_++] = val;
		}
	}

	ElemType pop() {
		if (isEmpty()){
			throw std::underflow_error("stack is empty!");
		}
		else {
			return elements_[--top_];
		}
	}

	ElemType top() {
		if(!isEmpty())
			return elements_[top_-1];
		else
			throw std::underflow_error("stack is empty!");
	}

	void print() {
		for(int i=0; i<top_; ++i)
			cout << elements_[i] <<" ";
		cout << endl;
	}
private:
	ElemType * elements_;
	int top_;
	int capacity_;
};

#endif