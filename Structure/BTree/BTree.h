#ifndef _BTREE_H_
#define _BTREE_H_

template <class T>
struct TreeNode {
	T data;
	TreeNode<T> * left;
	TreeNode<T> * right;
	TreeNode<T>(T x) : data(x), left(NULL), right(NULL){}
};

template <class T>
class Tree {
public:
	Tree() : root(NULL) {
		BuildTree(&root);
	}
	~Tree() {
		FreeTree(root);
	};
	void PreOrder_Recur(TreeNode<T> * root);
	void PreOrder_UnRecur(TreeNode<T> * root);
	void PreOrder_UnRecur_Without_Stack(TreeNode<T> * root);

	void InOrder_Recur(TreeNode<T> * root);
	void InOrder_UnRecur(TreeNode<T> * root);
	void InOrder_UnRecur_Without_Stack(TreeNode<T> * root);

	void PostOrder_Recur(TreeNode<T> * root);
	void PostOrder_UnRecur_1(TreeNode<T> * root);
	void PostOrder_UnRecur_2(TreeNode<T> * root);
	void PostOrder_UnRecur_3(TreeNode<T> * root);
	void PostOrder_UnRecur_Without_Stack(TreeNode<T> * root);

	TreeNode<T> * GetRoot(){return root;}
	
private:
	void BuildTree(TreeNode<T> ** root);
	void FreeTree(TreeNode<T> * root);
	/*just for post order without stack output*/
	void Reverse(TreeNode<T>* from, TreeNode<T>* to);
	void PrintReverse(TreeNode<T>* from, TreeNode<T>* to);

	TreeNode<T> * root;
};

#endif