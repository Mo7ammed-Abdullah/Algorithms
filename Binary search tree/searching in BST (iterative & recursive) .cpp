#include <bits/stdc++.h>
using namespace std;

struct node                                                         /// node structure
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *createnode(int value)                                         /// create node (doubly linked list node)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

node *insert(node *root, int value)
{
    if (root == NULL)                                               // for first input , if root is empty create root
    {
        root = createnode(value);
    }
    else
    {
        node *curr_root = root;
        node *prev_root = NULL;
        while (curr_root != NULL)                                   // now our current root pointr will keep going till it reach null
        {
            prev_root = curr_root;                                  // previous root pointr will follow the current root

            if (value < curr_root->data)                            // if the value sent is smaller then current root data . current root pointr go left
            {
                curr_root = curr_root->left;
            }
            else if (value > curr_root->data)                       // if the value sent is greater then current root data. current root pointr go right
            {
                curr_root = curr_root->right;
            }
        }
        node *newnode = createnode(value);                          // once current root pointer reach null , we go to previous root pointer to decide the left or right node for our value
        if (value < prev_root->data)                                // then we create a new node and assign it to left or right of prev root
        {
            prev_root->left = newnode;
        }
        else
        {
            prev_root->right = newnode;
        }
    }
    return root;
}

node *search_rec(node *root, int key)                                // ********** recursive search ************ 
{
    if (root == NULL)                                               // this is base case that will return NULL
    {                                                               // Either first root is NULL or we keep on searching and we reached the last NULL root. indicating key not found
        return root;
    }
    else if (root->data == key)                                     // if the key is found in the root-> data return that root;
    {
        return root;
    }
    else if (key < root->data)                                      // if the key is small we go to left root (recursive)
    {
        return search_rec(root->left, key);
    }
    else                                                            // if the key is big we go to right root (recursive)
    {
        return search_rec(root->right, key);
    }
}

struct node *search_iter(struct node *root, int key)                // ********** iterative search ************ 
{
    while (root != NULL)                                            // if the root reach NULL root , break out of loop and return NULL
    {
        if (key == root->data)                                      // if key is found at root->data return that root
        {
            return root;
        }
        else if (key < root->data)                                  // if key is smaller then root->data go to left root
        {
            root = root->left;
        }
        else                                                        // if key is greater then root->data go to right root
            {
                root = root->right;
            }
    }
    return NULL;
}

int main()
{
    int n, value, key;
    node *root = NULL;                                                              // initially root is NULL

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }
    cout << "Enter key to search: ";
    cin >> key;

    if (search_iter(root, key) == NULL)                                              // search function sends root and key . the function will return NULL if key is not found , or the root where the key is found
    {
        cout << "The key " << key << " is <not found>";                          
    }
    else
    {
        cout << "The key " << key << " is <found>";
    }

    return 0;
}
