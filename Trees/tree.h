#ifndef TREE_H
#define TREE_H

template <class T>
class BinaryTree{
private:
	node* Root;
	int32_t size;
public:
	struct node{
		node(T info){
			this->info = info;
			this->left_child = this->right_child = nullptr;
		}
		T info;
		node* left_child;
		bode* right_child;
	}
	
	BinaryTree(){
		this->size = 0;
		this->Root = nullptr;
	}

	int16_t push(T info){
		if (this->node_ == nullptr)
		{
			this->node_ = new node(info);
			return 1;
		}
		if (info > this->Root->info)
			if (this->Root->right_child == nullptr)
				this->Root->right_child = new node(info);
			else
				return push(info, this->Root->right_child);
		else
			if (this->Root->left_child == nullptr)
				this->Root->left_child = new node(info)
			else
				return push(info, this->Root->left_child);
		return -1;
	}

	int16_t push(T info, node* node_){
		if (info > node_->info)
			if (node_->right_child == nullptr)
				node_->right_child = new node(info);
			else
				return push(info, node_->right_child);
		else
			if (node_->left_child == nullptr)
				node_->left_child = new node(info)
			else
				return push(info, node_->left_child);
		return -1;
	}

}

#endif