#include "names_tree.h"
#include <iostream>

int16_t push(node** root, std::string name)
{
    node** pointer = root; // ��������� �� ��������� �������� ����
    node* root_pointer = *root; // ��������� �� �������� ������
    node* p_parent = nullptr; // ��������� �� ��������
    while ((*pointer)->col != NIL) // ���� �� ����
    {
        p_parent = (*pointer);
        if (name > (*pointer)->name)
            pointer = &((*pointer)->right_child);
        else if (name < (*pointer)->name)
            pointer = &((*pointer)->left_child);
        else return -1;
    }

    /*
        �������� ������ ���� � �������� ������ �� ��� �����
        current - ����������� ���� (col = red)
        temp - ���� ��� ��������
        p_parent - �������� ���� current
    */

    node* temp = *pointer;
    *pointer = new node(name); 
    node* current = *pointer;
    current->p_parent = p_parent;
    delete temp;

    if (p_parent != nullptr) // ����������� ������, ��������� ������ �������� 
    {
        if (p_parent->col == BLACK) 
        /*
            ���� �������� ������, �� �� � ������� � ������ ������ �� �����, ���������� ������� 
        */
        {
            return int16_t(0);
        }
        else 
            while (p_parent->col == RED && current != root_pointer) // WHILE 
            /*
                ���� ���� �������, �� ���������� ��� ������:
                1) ���� ���� ������� => ������������� 
                2) ���� ������ => ��������� �������� � ��������������
                ����� ����� ������ ������� ������, ����� ���� ��� � ��.
                
                grandfather - ��������� �� ����
                uncle - ��������� �� ����
                current - ����������� ���� 
            */
            {
                node* grandfather = p_parent->p_parent; 
                node* uncle = grandfather->left_child == p_parent ? grandfather->right_child : grandfather->left_child;

                if (uncle->col == RED) 
                /*
                    ���� ���� �������:
                    1) ���� � ���� � ������
                    2) ��� � ������, ���� �� ������
                */
                {
                    p_parent->col = BLACK;
                    uncle->col = BLACK;
                    grandfather->col = (int)(grandfather->p_parent == nullptr);
                }
                else 
                    if (uncle->col == BLACK || uncle->col == NIL) 
                    {
                        /*
                            ���� ���� ������, �� ����� ���������� ����� ����� �������� ����������� ���� � � ����������� �� �����
                            ���������� ����������� �������������� � ��������
                            1) �������� - ����� ���
                            2) �������� - ������ ���
                        */
                        if (grandfather->left_child == p_parent) 
                        {
                            if (p_parent->right_child == current) 
                            {
                                current = current->p_parent;
                                leftRotate(current);
                            }
                            current->p_parent->col = BLACK;
                            current->p_parent->p_parent->col = RED;
                            rightRotate(current->p_parent->p_parent);
                        }
                        else if (grandfather->right_child == p_parent) 
                        {
                            if (p_parent->left_child == current) {
                                current = current->p_parent;
                                rightRotate(current);
                            }
                            current->p_parent->col = BLACK;
                            current->p_parent->p_parent->col = RED;
                            leftRotate(current->p_parent->p_parent);
                        }
                    }
            }
    }
    return 0;
}

void leftRotate(node* x)
{
    std::cout << "\nLeft rotation\n";
    node* y = x->right_child;
    x->right_child = y->left_child;
    if (y->left_child->col != NIL) y->left_child->p_parent = x;
    if (y->col != NIL) y->p_parent = x->p_parent;
    if (x->p_parent) {
        if (x == x->p_parent->left_child)
            x->p_parent->left_child = y;
        else
            x->p_parent->right_child = y;
    }
    //else {
     //   root = y;
    //}

    /* link x and y */
    y->left_child = x;
    if (x->col != NIL) x->p_parent = y;
}

void rightRotate(node* x)
{
    std::cout << "\nRight rotation\n";
    node* y = x->left_child;
    x->left_child = y->right_child;
    if (y->right_child->col != NIL) y->right_child->p_parent = x;
    if (y->col != NIL) y->p_parent = x->p_parent;
    if (x->p_parent) {
        if (x == x->p_parent->right_child)
            x->p_parent->right_child = y;
        else
            x->p_parent->left_child = y;
    }
    //else {
      //  root = y;
    //}
    y->right_child = x;
    if (x->col != NIL) x->p_parent = y;
}
