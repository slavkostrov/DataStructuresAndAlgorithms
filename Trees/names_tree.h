#ifndef NAMES_TREE_H
#define NAMES_TREE_H
#define RED 0
#define BLACK 1
#define NIL 2

#include <string>

struct node {
	std::string name;
	uint16_t col; // 0 - red, 1 - black, 2 - leaf
	node* left_child;
	node* right_child;
	node* p_parent;
	node()  
	{
		this->name = "";
		this->col = NIL;
		this->left_child = this->right_child = nullptr;
	}
	node(std::string name) 
	{
		this->name = name;
		this->col = RED;
		this->left_child = new node();
		this->right_child = new node();
	}

	node(std::string name, bool isRoot)
	{
		this->name = name;
		this->col = BLACK;
		this->left_child = new node();
		this->right_child = new node();
		this->p_parent = nullptr;
	}
};



int16_t push(node** root, std::string name);
void leftRotate(node* p, node** root);
void rightRotate(node* x, node** root);
void print(node* node_, bool colors = true, int32_t level = 0);
void backward_pass(node* node_);
void clear_memory(node* node_);
void symmetric_pass(node* node_);
void path_length(node* root, std::string name, int32_t N = 0);
int32_t depth(node* node_);


#endif // !NAMES_TREE_H
