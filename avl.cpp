#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    int key;
    node *left;
    node *right;
    int height;

    node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};


int height(node* node){
    if(node == NULL)
        return 0;

    return node->height;
}


int balancefactor(node* node){
    if(node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

node *leftrotate(node *x){
    
    node *y = x->right;
    node *z = y->left;

    //perform rotation
    y->left = x;
    x->right = z;

    // update height;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

node *rightrotate(node *x){

    node *y = x->left;
    node *z = y->right;

    //perform rotation
    y->right = x;
    x->left = z;

    // update height;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

node* insert(node* root ,int key){
    if(root == NULL){
        cout << "\nadded Successfullyy\n";
        return new node(key);
    }

    if(key < root->key){
        root->left = insert(root->left, key);
    }  

    else if(key > root->key){
        root->right = insert(root->right, key);
    }  
    else{
        if (root != NULL){
            cout << "cann't enter duplicate key\n";
            return root;
        }
       
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int bf = balancefactor(root);

    if(bf > 1 && key < root->left->key){
        return rightrotate(root);
    }

    if(bf >1 && key > root->left->key){
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    if( bf < -1 && key < root->right->key){
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    if( bf < -1 && key > root->right->key){
        return leftrotate(root);
    }

    return root;
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void printLevelOrderTree(node* root) {
    if (root == nullptr) {
        std::cout << "Tree is empty!" << std::endl;
        return;
    }

    std::queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            node* current = q.front();
            q.pop();

            if (current != nullptr) {
                std::cout << current->key << " ";
                q.push(current->left);
                q.push(current->right);
            } else {
                std::cout << "X ";  // Print "X" for null nodes
            }
        }

        std::cout << std::endl; // Move to the next level
    }
}

int main(){
    node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);

    cout << "________________________________________________________________\n";

    // inorder(root);
    printLevelOrderTree(root);

    return 0;
}