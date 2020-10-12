#include "names_tree.h"


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
                            if (uncle->col == BLACK) 
                            {

                            
                            }
                            else // NIL
                            {

                            }
                        }
                        else // if (p_parent->left_child != current)
                        {
                            if (uncle->col == BLACK)
                            {


                            }
                            else // NIL
                            {

                            }
                        }
                    }
            }
    }
}

node* leftRotate(node* q)
{
    node* p = q->right_child;
    q->right_child = p->left_child;
    if (p->left_child->col != NIL)p->left_child->p_parent = q;
    if (p->col != NIL)p->p_parent = q->p_parent;
    
    if (q->p_parent) {
        if (q == q->p_parent->left_child)
            q->p_parent->left_child = p;
        else
            q->p_parent->right_child = p;
    }
    //else {
      //  root = y;
    //}
    p->left_child = q;
    if (q->col != NIL) q->p_parent = p;
}

node* rightRotate(node* x)
{
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
