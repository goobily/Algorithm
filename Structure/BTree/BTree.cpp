#include <iostream>
#include "BTree.h"
#include "StackByTemplate.h"
using namespace std;


template <class T>
void Tree<T>::BuildTree(TreeNode<T> ** root)
{
	T x;
	cin >> x;
	if(x < 0){
		*root = NULL;
		return;
	}
	try{
		*root = new TreeNode<T>(x);
	}
	catch(std::bad_alloc & e)
	{
		cerr<<"Fail to call new: " << e.what();
		abort();
	}
	BuildTree(&((*root)->left));
	BuildTree(&((*root)->right));
}

template <class T>
void Tree<T>::FreeTree(TreeNode<T> * root)
{
	if(root == NULL)
		return;
	FreeTree(root->left);
	FreeTree(root->right);
	delete root;
}

template <class T>
void Tree<T>::PreOrder_Recur(TreeNode<T> * root)
{
	if(NULL != root){
		cout << root->data << " ";
		PreOrder_Recur(root->left);
		PreOrder_Recur(root->right);
	}
}

template <class T>
void Tree<T>::PreOrder_UnRecur(TreeNode<T> * root)
{
	stack<TreeNode<T>*> s;
	TreeNode<T> * p = root;
	while(p!=NULL || !s.isEmpty()){
		while(p!=NULL){
			cout << p->data << " ";
			s.push(p);
			p = p->left;
		}
		if(!s.isEmpty()){
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}

/* PreOrder without stack */
template <class T>
void Tree<T>::PreOrder_UnRecur_Without_Stack(TreeNode<T> * root)
{
	TreeNode<T> *curr=root, *prev=NULL;
	while(curr != NULL)
	{
		if(curr->left == NULL) {
			cout << curr->data << " ";
			curr = curr->right;
		}
		else {
			prev = curr->left;
			while(prev->right != NULL && prev->right != curr) 
				prev = prev->right;
			if (prev->right == NULL) {
				cout << curr->data << " ";
				prev->right = curr;
				curr = curr->left;
			}
			else {
				prev->right = NULL;
				curr = curr->right;
			}
		}
	}
}

template <class T>
void Tree<T>::InOrder_Recur(TreeNode<T> * root)
{
	if(NULL != root){
		InOrder_Recur(root->left);
		cout << root->data << " ";
		InOrder_Recur(root->right);
	}
}

/* InOrder with stack */
template <class T>
void Tree<T>::InOrder_UnRecur(TreeNode<T> * root)
{
	stack<TreeNode<T> *> s;
	TreeNode<T> * p = root;
	while(p!=NULL || !s.isEmpty()){
		while(p!=NULL){
			s.push(p);
			p = p->left;
		}
		if(!s.isEmpty()){
			p = s.top();
			cout << p->data << " ";
			s.pop();
			p = p->right;
		}
	}
}

/* InOrder without stack */
template <class T>
void Tree<T>::InOrder_UnRecur_Without_Stack(TreeNode<T> * root)
{
	if (root == NULL)
		return;
	TreeNode<T> * curr=root, *prev=NULL;
	while(curr != NULL)
	{
		if(curr->left == NULL){
			cout << curr->data << " ";
			curr = curr->right;
		}
		else {
			prev = curr->left;
			while(prev->right != NULL && prev->right != curr) {
				prev = prev->right;
			}
			if(prev->right == NULL) {
				prev->right = curr;
				curr = curr->left;
			}
			else {
				prev->right = NULL;
				cout << curr->data <<" ";
				curr = curr->right;
			}
		}
	}
}

template <class T>
void Tree<T>::PostOrder_Recur(TreeNode<T> * root)
{
	if(NULL != root){
		PostOrder_Recur(root->left);
		PostOrder_Recur(root->right);
		cout << root->data << " ";
	}
}

template <class T>
void Tree<T>::PostOrder_UnRecur_1(TreeNode<T> * root)
{
	if (NULL == root)
		return;
	stack<TreeNode<T> *> s;
	TreeNode<T> * curr;
	TreeNode<T> * pre = NULL;
	s.push(root);
	while(!s.isEmpty())
	{
		curr = s.top();
		if( (curr->left == NULL && curr->right == NULL ) ||
			(pre!=NULL && (pre==curr->left || pre==curr->right))
			){
			cout << curr->data << " ";
			s.pop();
			pre = curr;
		}
		else {
			if(curr->right != NULL)
				s.push(curr->right);
			if(curr->left != NULL)
				s.push(curr->left);
		}
	}
}

template <class T>
void Tree<T>::PostOrder_UnRecur_2(TreeNode<T> * root)
{
	if (NULL == root)
		return;
	stack<TreeNode<T> *> sTraverse, sVisit;
	sTraverse.push(root);
	TreeNode<T> * p = NULL;
	while(!sTraverse.isEmpty())
	{
		p = sTraverse.top();
		sTraverse.pop();
		sVisit.push(p);
		if(p->left != NULL)
			sTraverse.push(p->left);
		if(p->right != NULL)
			sTraverse.push(p->right); // make sure the right child pushed into sVisit ahead of left child
	}
	while(!sVisit.isEmpty())
	{
		p = sVisit.top();
		sVisit.pop();
		cout << p->data << " ";
	}
}

template <class T>
void Tree<T>::PostOrder_UnRecur_3(TreeNode<T> * root)
{
	if (NULL == root)
		return;
	stack<TreeNode<T> *> s;
	TreeNode<T> * p = root, *q = NULL; // q is the pre visited node
	while(p!=NULL || !s.isEmpty())
	{
		while(p!=NULL){
			s.push(p);
			p = p->left;
		}
		if(!s.isEmpty()) {
			p = s.top();
			if(p->right == NULL || p->right == q) {
				cout << p->data << " ";
				q = p;
				p = NULL;
				s.pop();
			}
			else 
				p = p->right;
		}
	}
}

/* PostOrder without stack */

template <class T>
void Tree<T>::Reverse(TreeNode<T>* from, TreeNode<T>* to)
{
	if(from==NULL || to==NULL || from==to)
		return;
	TreeNode<T> *x=from, *y=from->right, *z=NULL;
	while(1)
	{
		z = y->right;
		y->right = x;
		x = y;
		y = z;
		if(x == to)
			break;
	}
}

template <class T>
void Tree<T>::PrintReverse(TreeNode<T>* from, TreeNode<T>* to)
{
	Reverse(from, to);
	TreeNode<T> *p = to;
	while(1)
	{
		cout << p->data << " ";
		if(p == from)
			break;
		p = p->right;
	}
	Reverse(to, from);
}

template <class T>
void Tree<T>::PostOrder_UnRecur_Without_Stack(TreeNode<T> * root)
{
	TreeNode<T> * tmp = new TreeNode<T>(0);
	tmp->left = root;
	TreeNode<T> *curr=tmp, *prev=NULL;
	while(curr)
	{
		if(curr->left == NULL) {
			curr = curr->right;
		}
		else {
			prev = curr->left;
			while(prev->right != NULL && prev->right != curr) {
				prev = prev->right;
			}
			if(prev->right == NULL) {
				prev->right = curr;
				curr = curr->left;
			}
			else {
				PrintReverse(curr->left, prev);
				prev->right = NULL;
				curr = curr->right;
			}
		}
	}
}

 int main()
 {
 	Tree<int> tree;
// 
// 	cout << "Pre-Order-Recur:\t";
// 	tree.PreOrder_Recur(tree.GetRoot());
// 	cout << endl;
// 
// 	cout << "Pre-Order-UnRecur:\t";
// 	tree.PreOrder_UnRecur(tree.GetRoot());
// 	cout << endl;
// 
	cout << "In-Order-Recur:\t\t";
	tree.InOrder_Recur(tree.GetRoot());
	cout << endl;


	cout << "In-Order-UnRecur:\t";
	tree.InOrder_UnRecur(tree.GetRoot());
	cout << endl;

	cout << "In-Order-UnRecur-without-stack:\t";
	tree.InOrder_UnRecur_Without_Stack(tree.GetRoot());
	cout << endl;

// 	cout << "Post-Order-Recur:\t";
// 	tree.PostOrder_Recur(tree.GetRoot());
// 	cout << endl;
// 
// 	cout << "Post-Order-UnRecur_1:\t";
// 	tree.PostOrder_UnRecur_1(tree.GetRoot());
// 	cout << endl;
// 
// 	cout << "Post-Order-UnRecur_2:\t";
// 	tree.PostOrder_UnRecur_2(tree.GetRoot());
// 	cout << endl;
// 
	cout << "Post-Order-UnRecur_3:\t";
	tree.PostOrder_UnRecur_3(tree.GetRoot());
	cout << endl;

	cout << "Post-Order-UnRecur-Without-Stack:\t";
	tree.PostOrder_UnRecur_Without_Stack(tree.GetRoot());
	cout << endl;
 
 	return 0;
 }