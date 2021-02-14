#include "binarytree.h"

template<typename T>
BinaryTree<T>::BinaryTree()
{

}

template<typename T>
BinaryTree<T>::~BinaryTree(){

}

template<typename T>
void BinaryTree<T>::toCreateRoot(T data){
    root = new treeItem;
    root->index = 1;
    root->depth = 0;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    current = root;
}

template<typename T>
void BinaryTree<T>::toAddLeftItem(T data, int index){
    if(toFindItem(root, index) != NULL){
        current = toFindItem(root, index);
        if(current->left == NULL){
            current->left = new treeItem;
            current->left->index = current->index*2;
            current->left->depth = current->depth + 1;
            current = current->left;
            current->data = data;
            current->left = NULL;
            current->right = NULL;
        }else{
            treeItem* tmp = new treeItem;
            tmp->left = current->left;
            current->left = tmp;
            tmp->right = NULL;
            tmp->data = data;
            tmp->index = current->index*2;
            tmp->depth = current->depth + 1;
            reDepInd(root);
        }
    }
}

template<typename T>
void BinaryTree<T>::toAddRightItem(T data, int index){
    if(toFindItem(root, index) != NULL){
        current = toFindItem(root, index);
        if(current->right == NULL){
            current->right = new treeItem;
            current->right->index = current->index*2 + 1;
            current->right->depth = current->depth + 1;
            current = current->right;
            current->data = data;
            current->left = NULL;
            current->right = NULL;
        }else{
            treeItem* tmp = new treeItem;
            tmp->right = current->right;
            current->right = tmp;
            tmp->left = NULL;
            tmp->data = data;
            tmp->index = current->index*2 + 1;
            tmp->depth = current->depth + 1;
            reDepInd(root);
        }
    }
}

template<typename T>
void BinaryTree<T>::setcurrentOnIndex(int index){
    current = toFindItem(root, index);
};

template <typename T>
void BinaryTree<T>::toDelItem(int index){
    treeItem *precurrent;
    if(toFindItem(root,index) != NULL){
        if(index == 1){
            if(root->left == NULL && root->right == NULL){
                clearTree(root);
                root = NULL;
            }else if(root->left == NULL){
                current = root;
                root = root->right;
                delete(current);
            }else if(root->right == NULL){
                current = root;
                root = root->left;
                delete(current);
            }else{
                treeItem* tmp;
                treeItem* pretmp;
                tmp = root->left;
                while(tmp->left != NULL){
                    tmp = tmp->left;
                }
                tmp->left = root->left;
                tmp->right = root->right;
                pretmp = tmp;
                while(pretmp->left->index != tmp->index){
                    pretmp = pretmp->left;
                }
                pretmp->left = NULL;
                delete(root);
                root = tmp;
            }
        }else{
            current = toFindItem(root, index);
            if(toFindItem(root, index/2) != NULL){
                precurrent = toFindItem(root, index/2);
            }else if(toFindItem(root, (index - 1)/2) != NULL){
                precurrent = toFindItem(root, (index - 1)/2);
            }
            if(current->left == NULL && current->right == NULL){
                if((current->index % 2) == 0){
                    precurrent->left = NULL;
                    delete(current);
                }else{
                    precurrent->right = NULL;
                    delete(current);
                }
                delete(current);
            }else if(current->left == NULL){
                if((current->index % 2) == 0){
                    precurrent->left = current->right;
                    delete(current);
                }else{
                    precurrent->right = current->right;
                    delete(current);
                }
            }else if(current->right == NULL){
                if((current->index % 2) == 0){
                    precurrent->left = current->left;
                    delete(current);
                }else{
                    precurrent->right = current->left;
                    delete(current);
                }
            }else{
                treeItem* tmp;
                treeItem* pretmp;
                tmp = current->left;
                while(tmp->left != NULL){
                    tmp = tmp->left;
                }
                tmp->left = current->left;
                tmp->right = current->right;
                if((current->index % 2) == 0){
                    precurrent->left = tmp;
                }else{
                    precurrent->right = tmp;
                }
                pretmp = tmp;
                while(pretmp->left->index != tmp->index){
                    pretmp = pretmp->left;
                }
                pretmp->left = NULL;
                delete(current);
            }
        }
        if(root != NULL)
            reDepInd(root);
    }
}

template<typename T>
void BinaryTree<T>::clear(){
    clearTree(root);
    root = NULL;
}
