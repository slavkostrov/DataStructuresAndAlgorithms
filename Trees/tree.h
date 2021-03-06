#ifndef TREE_H
#define TREE_H

template <typename T>
class BinaryTree {
public:
	struct node {
		node(T info) 
		{
			this->info = info;
			this->left_child = this->right_child = nullptr;
		}
		T info;
		node* left_child;
		node* right_child;
	};

	BinaryTree() 
	{
		this->size = 0;
		this->Root = nullptr;
		this->empty = true;
	}

	int16_t push(T info, node** node_ = 0) 
	{
		if (node_ == 0)node_ = &(this->Root);
		this->size += 1;
		if (*(node_) == nullptr)
		{
			*(node_) = new node(info);
			return 1;
		}
		if (info >= (*node_)->info)
			return this->push(info, &((*node_)->right_child));
		else
			return this->push(info, &((*node_)->left_child));
	}

	T* search(T value, node* node_ = 0, int32_t key = 0) 
	{
		if (key == 0)
			node_ = this->Root;
		if (node_ == nullptr)
			return nullptr;
		if (node_->info == value)
			return &(node_->info);
		if (node_->info <= value)
			return search(value, node_->right_child, 1);
		else
			return search(value, node_->left_child, 1);
	}

	void print() 
	{
		this->print(this->Root);
	}

	int32_t remove(T value)
	{
		node* parent = nullptr;
		node* current = this->Root;

		while (current != nullptr && current->info != value) 
		{
			parent = current;
			current = value >= current->info ? current = current->right_child : current = current->left_child;
		}

		node* temp;

		if (current != nullptr) 
		{
			if (current->left_child == nullptr || current->right_child == nullptr) 
			{
				if (parent == nullptr) 
				{
					temp = this->Root;
					this->Root = current->left_child == nullptr ? current->right_child : current->left_child;
				}
				else
				{
					temp = current;
					if (parent->left_child == current) 
					{	
						parent->left_child = current->right_child == nullptr ? current->left_child : current->right_child;
					}
					else // parent->right_child == current
					{
						parent->right_child = current->right_child == nullptr ? current->left_child : current->right_child;
					}
				}
			}
			else // current->left_child != nullptr && current->right_child != nullptr
			{
				node* p_parent = current;
				node* current_min = current->right_child;
				while (current_min->left_child != nullptr) 
				{
					p_parent = current_min;
					current_min = current_min->left_child;
				}

				current->info = current_min->info;
				temp = current_min;

				if (p_parent->left_child == current_min)
					p_parent->left_child = current_min->right_child;
				else
					p_parent->right_child = current_min->right_child;
				
				return 0;
			}
			delete temp;
			return 0;
		}
		else
			return -1;
	}

	int32_t pop(T value) {
		node* t = this->Root;
		while (t != nullptr) {
			if (t->info == value) {
				if (t->left_child == t->right_child && t->left_child == nullptr)
					return 0;

			}
			else
			{
				if (t->info > value)
					t = t->left_child;
				else
					t = t->right_child;
			}
		}
	}
private:
	node* Root;
	int32_t size;
	bool empty;
	void print(node* node_, int level = 0) {
		if (node_ == nullptr)return;
		this->print(node_->left_child, ++level);
		for (int i = 0; i < level; ++i)std::cout << '|';
		std::cout << node_->info << '\n';
		level -= 1;
		this->print(node_->right_child, ++level);
	}
};

#endif