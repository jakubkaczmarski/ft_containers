#include <iostream>

struct node
{
    int     data;
    node *parent;
    node *left;
    node *right;
};
class tree
{
    public:
        node * create_node(int data)
        {
            node * tmp = new node;
            tmp->data = data;
            return tmp;
        }
        void insert_node()
        {

        }
    private:
        node *root;
};

int main()
{
    tree z;
    z.create_node(2);
    z.create_node(2);
}