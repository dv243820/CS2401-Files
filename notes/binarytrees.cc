/*

VOCAB

--

    root -
    start of binary tree
    only one node without a parent
    each node in the tree can have exactly one parent and up to two children
    LEAF - Node with no children
    DEPTH - how many steps to get to the root (depth of lowest leaf = depth of tree)
    SUBTREE - any piece of a tree


    */

class Bnode
{
public:
    Bnode(int d = 0, Bnode *l = nullptr, Bnode *r = nullptr);
    int data(const) { return data_field; }
    Bnode *left() const { return left_child; }
    Bnode *right() const { return right_child; }

    void set_data(int d) { data_field = d; }
    void set_left(Bnode *l) { left_child = l; }
    void set_right(Bnode *r) { right_child = r; }

private:
    int data_field;
    Bnode *left_child;
    Bnode *right_child;
};

void clear_tree(Bnode *&root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        clear_tree(root->left());
        clear_tree(root->right());
        delete root;
        root = nullptr;
    }
}

Bnode *copy(Bnode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else
    {
        Bnode *tmp = new Bnode(root->data());
        tmp->set_left(copy(root->left()));
        tmp->set_right(copy(root->right()));
        return tmp;
    }
}

int size(Bnode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + size(root->left()) + size(root->right());
    }
}

// Binary search tree
// Everything left of root is < root
// Everything right of root is >= root
Bnode *search(Bnode *root, int target)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (target < root->data())
        {
            return search(root->left(), target);
        }
        else if (target > root->data())
        {
            return search(root->right(), target);
        }
        else
        {
            return root;
        }
    }
}


