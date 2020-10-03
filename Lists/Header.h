#ifndef HEADER_H
#define HEADER_H

struct node {
    int value;
    node* pointer;
};
void input_list(node* temp, int N);
int update_list(node* temp);

#endif