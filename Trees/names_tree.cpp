#include "names_tree.h"
#include <iostream>



int16_t push(node** root, std::string name)
{
    node** pointer = root; // указатель на указатель текущего узла
    node* root_pointer = *root; // указатель на корневой объект
    node* p_parent = nullptr; // указатель на родителя
    while ((*pointer)->col != NIL) // пока не лист
    {
        p_parent = (*pointer);
        if (name > (*pointer)->name)
            pointer = &((*pointer)->right_child);
        else if (name < (*pointer)->name)
            pointer = &((*pointer)->left_child);//
        else return -1;
    }

    /*
        cоздание нового узла и очищение рамяти из род листа
        current - добавляемый узел (col = red)
        temp - лист для удаления
        p_parent - родитель узла current
    */

    node* temp = *pointer;
    *pointer = new node(name); 
    node* current = *pointer;
    current->p_parent = p_parent;
    delete temp;

    if (p_parent != nullptr) // выполняется всегда, поскольку корень создаётся 
    {
        if (p_parent->col == BLACK)
            /*
                если родитель черный, то всё в порядке и ничего менять не нужно, возвращаем единицу
            */
        {
            return int16_t(0);
        }
        else
        {
            node* grandfather = p_parent->p_parent;
            node* uncle = grandfather->left_child == p_parent ? grandfather->right_child : grandfather->left_child;
  

            while (current != root_pointer && current->p_parent->col == RED) // WHILE 
               /*
                   Если отец красный, то существует два случая:
                   1) Дядя тоже красный => перекрашиваем
                   2) Дядя черный => выролняем повороты и перекрашивания
                   Также нужно учесть частные случаи, когда дяди нет и др.

                   grandfather - указатель на деда
                   uncle - указатель на дядю
                   current - добавляемый узел
               */
            {
                p_parent = current->p_parent;
                node* grandfather = current->p_parent->p_parent;
                node* uncle = grandfather->left_child == p_parent ? grandfather->right_child : grandfather->left_child;
                if (uncle->col == RED)
                    /*
                        Если дядя красный:
                        1) Дядя и отец в чррный
                        2) Дед в красый, если не корень
                    */
                {
                    p_parent->col = BLACK;
                    uncle->col = BLACK;
                    grandfather->col = (int)(grandfather == *root);
                    current = grandfather;
                }
                else
                    if (uncle->col == BLACK || uncle->col == NIL)
                    {
                        /*
                            Если дядя чёрный (в частности, если дяди нет),
                            то нужно определить каким сыном является добавляемые узел и в зависимости от этого
                            произвести необходимые перекрашивания и повороты
                            1) Родитель - левый сын
                            2) Родитель - правый сын
                        */
                        if (current->p_parent->p_parent->left_child == p_parent) // если отец левый сын
                        {
                            if (current->p_parent->right_child == current) 
                            {
                                /*
                                    Если добавляемый сын правый, то сделать левым с помощью
                                    левого поворота
                                */
                                current = current->p_parent;
                                leftRotate(current, root);
                            }
                            current->p_parent->col = BLACK;
                            current->p_parent->p_parent->col = RED;
                            // правый роворот
                            rightRotate(current->p_parent->p_parent, root);
                        }
                        else 
                            if (current->p_parent->p_parent->right_child == p_parent) // если отец рравый сын
                        {
                            if (current->p_parent->left_child == current) { 
                                /*
                                    Если добавляемый сын левый, то сделать правым с помощью
                                    правого роворота
                                */
                                current = current->p_parent;
                                rightRotate(current, root);
                            }
                            current->p_parent->col = BLACK;
                            current->p_parent->p_parent->col = RED;
                            // левый поворот
                            leftRotate(current->p_parent->p_parent, root);
                        }
                    }
            }
        }
    
    }
    if (root_pointer)
        root_pointer->col = BLACK;
    return 0;
}

void leftRotate(node* x, node** root)
{
    /*
        Функция для левого поворота
    */
    std::cout << "Left rotation for \"" << x->name << "\"\n";
    node* y = x->right_child;
    x->right_child = y->left_child;
    if (y->left_child->col != NIL) 
        y->left_child->p_parent = x;
    if (y->col != NIL)
        y->p_parent = x->p_parent;
    if (x->p_parent) {
        if (x == x->p_parent->left_child)
            x->p_parent->left_child = y;
        else
            x->p_parent->right_child = y;
    }
    else {
        *root = y;
    }
    y->left_child = x;
    if (x->col != NIL) 
        x->p_parent = y; 
}

void rightRotate(node* x, node** root)
{
    /*
    Функция для правого поворота
    */
    std::cout << "Right rotation for \"" << x->name << "\"\n";
    node* y = x->left_child;
    x->left_child = y->right_child;
    if (y->right_child ->col!= NIL) 
        y->right_child->p_parent = x;
    if (y->col != NIL) 
        y->p_parent = x->p_parent;
    if (x->p_parent) {
        if (x == x->p_parent->right_child)
            x->p_parent->right_child = y;
        else
            x->p_parent->left_child = y;;
    }
    else {
        *root = y;
    }
    y->right_child = x;
    if (x->col != NIL) 
        x->p_parent = y;
}

void print(node* node_, bool colors, int32_t level)
{
    if (node_->col == NIL)return;
    print(node_->left_child, colors, ++level);
    for (int i = 0; i < level; ++i)
        std::cout << '|';
    if (colors) 
        std::cout << node_->col << '\n';
    else 
        std::cout << node_->name << '\n';
    level -= 1;
    print(node_->right_child, colors, ++level);
}

void backward_pass(node* node_)
{
    if (node_->col == NIL)return;
    backward_pass(node_->left_child);
    backward_pass(node_->right_child);
    std::cout << node_->name << ' ';
}

void clear_memory(node* node_)
{
    if (node_->col == NIL)return;
    backward_pass(node_->left_child);
    backward_pass(node_->right_child);
    delete node_;
}

void symmetric_pass(node* node_)
{
    if (node_->col == NIL)return;
    symmetric_pass(node_->left_child);
    std::cout << node_->name << ' ';
    symmetric_pass(node_->right_child);
}

void path_length(node* node_, std::string name, int32_t N)
{
    if (node_->col == NIL)
    {
        std::cout << "There isn't \"" << name << "\" in the tree";
        return;
    }
    if (node_->name == name) 
    {
        std::cout << "Path to " << name << " length is " << N;
        return;
    }
    else
    {
        if (name > node_->name)
            path_length(node_->right_child, name, N + 1);
        else if (name < node_->name)
            path_length(node_->left_child, name, N + 1);
        else return;
    }
}

int32_t depth(node* node_)
{
    if (node_->col == NIL)
        return 0;
    else 
    {
        return std::fmax(depth(node_->left_child) + 1, depth(node_->right_child) + 1);
    }
}
