#include <iostream>


struct BST_Node {

    int key;
    BST_Node *left, *right;


    BST_Node(int key) : key(key){

        left = nullptr;
        right = nullptr;

    }

};

BST_Node* add(BST_Node* root, int key){

    if(root == nullptr) return new BST_Node(key);

    if(key > root->key) root->right = add(root->right, key);
    else root->left = add(root->left,key);

    return root;

}

BST_Node* search(BST_Node* root, int key){


    if(root == nullptr) return nullptr;
    if(root->key == key) return root;

    if(key > root->key) return search(root->right, key);
    else return search(root->left,key);

}


BST_Node* min(BST_Node* root){

    if(root->left == nullptr) return root;

    return min(root->left);

}

BST_Node* max(BST_Node* root){

    if(root->right == nullptr) return root;

    return max(root->right);

}

BST_Node* remove(BST_Node* root, int key){

    if(root == nullptr) return root;
    else if(key > root->key) root->right = remove(root->right,key);
    else if(key < root->key) root->left = remove(root->left, key);
    else {

        if(root->left == nullptr && root->right == nullptr) {

            delete root;
            root = nullptr;


        } else if(root->right == nullptr){

            auto* left = root->left;
            delete root;

            root = left;

        } else if(root->left == nullptr){

            auto* right = root->right;
            delete root;

            root = right;

        } else {


            auto* sc = min(root->right);
            root->key = sc->key;
            root->right = remove(root->right,root->key);

        }

    }

    return root;

}


BST_Node* clear(BST_Node* root){


    while(root != nullptr){

        root = remove(root,root->key);


    }

    return root;

}

int main() {

    BST_Node* root = nullptr;
    root = add(root,50);
    root = add(root,30);
    root = add(root,20);
    root = add(root,40);
    root = add(root,70);
    root = add(root,60);
    root = add(root, 80);

    root = remove(root,20);
    root = remove(root,30);

    root = clear(root);

    return 0;
}
