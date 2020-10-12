#include "names_tree.h"


int16_t push(node** root, std::string name)
{
    node** pointer = root; // указатель на указатель текущего узла
    node* root_pointer = *root; // указатель на корневой объект
    node* p_parent = nullptr; // указатель на родител€
    while ((*pointer)->col != NIL) // пока не лист
    {
        p_parent = (*pointer);
        if (name > (*pointer)->name)
            pointer = &((*pointer)->right_child);
        else if (name < (*pointer)->name)
            pointer = &((*pointer)->left_child);
        else return -1;
    }

    /*
        —оздание нового узла и очищение пам€ти из под листа
        current - добавл€емый узел (col = red)
        temp - лист дл€ удалени€
        p_parent - родитель узла current
    */

    node* temp = *pointer;
    *pointer = new node(name); 
    node* current = *pointer;
    current->p_parent = p_parent;
    delete temp;

    if (p_parent != nullptr) // выполн€етс€ всегда, поскольку корень создаЄтс€ 
    {
        if (p_parent->col == BLACK) 
        /*
            ≈сли родитель черный, то всЄ в пор€дке и ничего мен€ть не нужно, возвращаем единицу 
        */
        {
            return int16_t(0);
        }
        else 
            while (p_parent->col == RED && current != root_pointer) // WHILE 
            /*
                ≈сли отец красный, то существует два случа€:
                1) ƒ€д€ тоже красный => перекрашиваем 
                2) ƒ€д€ черный => выполн€ем повороты и перекрашивани€
                “акже нужно учесть частные случаи, когда д€ди нет и др.
                
                grandfather - указатель на деда
                uncle - указатель на д€дю
                current - добавл€емый узел 
            */
            {
                node* grandfather = p_parent->p_parent; 
                node* uncle = grandfather->left_child == p_parent ? grandfather->right_child : grandfather->left_child;

                if (uncle->col == RED) 
                /*
                    ≈сли д€д€ красный:
                    1) ƒ€д€ и отец в чЄрный
                    2) ƒед в красый, если не корень
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
                            ≈сли д€д€ чЄрный, то нужно определить каким сыном €вл€етс€ добавл€емые узел и в зависимости от этого
                            произвести необходимые перекрашивани€ и повороты
                            1) –одитель - левый сын
                            2) –одитель - правый сын
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
