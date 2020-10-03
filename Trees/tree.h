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

	int16_t push(T info, node** node_ = &(this->Root)){
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

}

#endif