#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    int key;
    node *left;
    node *right;

    node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};


node* insert(node* root , int key){
    if(root == NULL){
        cout << "Added successfully\n";
        return new node(key);
    }

    if(key < root->key){
        root->left = insert(root->left, key);
    }
    else if( key > root->key){
        root->right = insert(root->right, key);
    }
    else{
        if(root != NULL)
            cout << "\nDuplicate are not allowed";
    }

    return root;
}



int main(){

     
    return 0;
}