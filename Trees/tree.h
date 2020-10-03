#ifndef TREE_H
#define TREE_H

template <typename T>
class BinaryTree{
private:
	node* Root;
	int32_t size;
	bool empty;
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
		this->empty = true;
	}

	int16_t push(T info, node** node_ = &(this->Root)){
		this->size += 1;
		if (*(node_) = nullptr)
		{
			*(node_) = new node(info);
			return 1;
		}
		if (info > *(node_)->info)
			return this->push(info, &(*(node_)->right_child));
		else
			return this->push(info, &(*(node_)>left_child));
	}

	T* search(T value, node* node_ = this->Root){
		if (node_ == nullptr)return nullptr;
		if (node_->info == value)
			return &(node_->info);
		if (node_->info > value)
			return search(value, node_->right_child);
		else
			return search(value, bode_->left_child);
	}

	
}

#endif