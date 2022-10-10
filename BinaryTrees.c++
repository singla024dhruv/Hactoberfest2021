/*For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.*/
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
int findIndex(int inOrder[], int val, int size)

{
    int index = -1;
    for (int i = 0; i < size; ++i)
    {
        if (inOrder[i] == val)
            return index = i; // return index if the element matches the given value
    }
    return index;
}
// function to constructBinaryTree from inOrder and postOrder Traversals
BinaryTreeNode<int> *constructBinaryTree(int inOrder[], int postOrder[], int startIndex, int endIndex, int *postIndex, int size)
{
    if (startIndex > endIndex or (*postIndex) < 0) // base case
        return nullptr;
    int rootIndex = findIndex(inOrder, postOrder[*postIndex], size); // subtree root Index
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(inOrder[rootIndex]);                       // create the subtree root Node
    *postIndex = *postIndex - 1;                                     // decrement the postIndex pointer maintained
    // construct right subtree
    root->right = constructBinaryTree(inOrder, postOrder, rootIndex + 1, endIndex, postIndex, size);
    // construct left subtree
    root->left = constructBinaryTree(inOrder, postOrder, startIndex, rootIndex - 1, postIndex, size);
    // return the root of the subtree.
    return root;
}
BinaryTreeNode<int>* buildTree(int *post,int psize,int *in,int insize)
{
    int postindex=psize-1;
    return constructBinaryTree(in,post,0,psize-1,&postindex,psize);
int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}
