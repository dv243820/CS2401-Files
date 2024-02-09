/**
 *        @file: btreelab..cc
 *      @author: Drew VanAtta
 *        @date: December 01, 2022
 *       @brief: lab 13
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Bnode
{
    string data;
    Bnode *left;
    Bnode *right;
};

void inorder(Bnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}

void add(Bnode *&root, string item)
{
    if (root == NULL)
    {
        root = new Bnode;
        root->data = item;
        root->left = root->right = NULL;
    }
    else if (item <= root->data)
        add(root->left, item);
    else
        add(root->right, item);
}

int size(Bnode *root)
{
    if (root == NULL)
        return 0;
    else
        return size(root->left) + size(root->right) + 1;
}


//search - takes the root, and a target string, and returns how many times it appears in the tree
int search(Bnode *root, string target)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (target < root->data)
    {
        return (search(root->left, target));
    }
    else if (target > root->data)
    {
        return search(root->right, target);
    }
    else // not to left or right
    {
        if (root->data == target)
        {
            return search(root->left, target) + 1;
        }
        if (root->data != target)
        {
            return search(root->left, target) + 0;
        }
    }
}

//namesafter - takes the Bnode *root, and target string and returns the amount of names after
int namesafter(Bnode *root, string target)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (target < root->data) // target less than (left)
    {
        return namesafter(root->left, target) + size(root->right);
    }
    else if (target > root->data) // target greater than (right)
    {
        return namesafter(root->right, target);
    }
    else if (target == root->data)
    {
        return size(root->right)    ;
    }
}

int main()
{

    Bnode *names = NULL;
    ifstream fin;
    fin.open("names.txt");

    if (fin.fail())
    {
        cout << "Opening File Failed" << endl;
        return 0;
    }

    string name;
    string tmp;
    while (!fin.eof())
    {
        fin >> name;
        add(names, name);
    }
    inorder(names);


    cout << "Choose a name to search for: ";
    cin >> tmp;
    cout << "Your search name appears " << search(names, tmp) << " times." << endl;
    cout << "Choose a name to search amount after: ";
    cin >> tmp;

    cout << "The names after your name " << namesafter(names, tmp) << endl;

    return 0;
}