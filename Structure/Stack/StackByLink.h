#ifndef _STACK_BY_LINK_H_
#define _STACK_BY_LINK_H_

#include <stdexcept>

template <class ElemType>
struct Node {
	ElemType data;
	Node<ElemType> * next;
};

template <class ElemType>
class stack {
public:
	stack() : top_(NULL) {}
	~stack(){
		while(top_){
			Node<ElemType> * p = top_;
			top_ = top_->next;
			delete p;
		}
	}

	int size(){
		int sum = 0;
		Node<ElemType> * p = top_;
		while(p){
			++sum;
			p = p->next;
		}
		return sum;
	}
	void push(const ElemType & val){
		try{
			Node<ElemType> * p = new Node<ElemType>;
			p->next = top_;
			p->data = val;
			top_ = p;
		}
		catch(std::bad_alloc & e) {
			cerr << "Fail to new : " << e.what();
			abort();
		}	
			
	}

	ElemType pop(){
		if(top_){
			ElemType tmp = top_->data;
			Node<ElemType> * p = top_;
			top_ = top_->next;
			delete p;
			return tmp;
		}
		else
			throw std::underflow_error("stack is empty");
	}

	ElemType top(){
		if(top_)
			return top_->data;
		else
			throw std::underflow_error("stack is empty");
	}
	bool isEmpty()
	{
		return top_==NULL ? true : false;
	}
	void print(){
		Node<ElemType> * p = top_;
		while(p){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;	
	}
private:
	Node<ElemType> * top_;
};


#endif