#ifndef _JW_LINK_H_
#define _JW_LINK_H_

template <class DataType>
struct LinkNode
{
	DataType val;
	LinkNode<DataType> * next;
    LinkNode<DataType>(DataType & value) : val(value), next(NULL) {}
	LinkNode<DataType>() : next(NULL) {}
};


#endif