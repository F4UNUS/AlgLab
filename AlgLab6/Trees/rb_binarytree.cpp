#include "rb_binarytree.h"

template<typename T>
RB_BinaryTree<T>::RB_BinaryTree()
{

}

template<typename T>
RB_BinaryTree<T>::~RB_BinaryTree()
{

}

template<typename T>
void RB_BinaryTree<T>::toCreateRoot(T data){
    root = new treeItem;
    root->data = data;
    root->index = 1;
    root->depth = 0;
    root->color = false;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    current = root;
}

template<typename T>
void RB_BinaryTree<T>::setcurrentOnIndex(int index){
    current = toFindItem(root, index);
};

template<typename T>
void RB_BinaryTree<T>::toAddItem(T data){
    treeItem *newItem = new treeItem;
    newItem->data = data;
    newItem->color = true;
    newItem->left = NULL;
    newItem->right = NULL;
    addItem(root, newItem);
    fixAdd(newItem);
    setDepInd(root);
}

template<typename T>
void RB_BinaryTree<T>::toDelItem(int index){
    treeItem *delItem = toFindItem(root, index);
    if(delItem != NULL){
        if(delItem->left != NULL){
            treeItem *tmp = delItem->left;
            while(tmp->right != NULL)
                tmp = tmp->right;
            swapData(delItem, tmp);
            if(tmp->color){
                if(tmp->parent != delItem)
                    tmp->parent->right = NULL;
                else
                    tmp->parent->left = NULL;
                delete tmp;
            }else if(tmp->left != NULL){
                swapData(tmp, tmp->left);
                tmp = tmp->left;
                tmp->parent->left = NULL;
                delete tmp;
            }else{
                fixDelete(tmp);
                if(tmp->parent->left == tmp)
                    tmp->parent->left == NULL;
                else
                    tmp->parent->right = NULL;
                delete tmp;
            }
        }else if(delItem->right != NULL){
            treeItem *tmp = delItem->right;
            while(tmp->left != NULL)
                tmp = tmp->left;
            swapData(delItem, tmp);
            if (tmp->color){
                if(tmp->parent != delItem)
                    tmp->parent->left = NULL;
                else
                    tmp->parent->right = NULL;
                delete tmp;
            }else if(tmp->right != NULL){
                swapData(tmp, tmp->right);
                tmp = tmp->right;
                tmp->parent->right = NULL;
                delete tmp;
            }else{
                fixDelete(tmp);
                if (tmp->parent->left == tmp)
                    tmp->parent->left = NULL;
                else
                    tmp->parent->right = NULL;
                delete tmp;
            }
        }else{
            if(delItem->color){
                if(delItem->parent->left == delItem)
                    delItem->parent->left = NULL;
                else
                    delItem->parent->right = NULL;
                delete delItem;
            }else if(delItem->right != NULL || delItem->left != NULL){
                if(delItem->left != NULL){
                    swapData(delItem, delItem->left);
                    delItem = delItem->left;
                    delItem->parent->left = NULL;
                }else{
                    swapData(delItem, delItem->right);
                    delItem = delItem->right;
                    delItem->parent->right = NULL;
                }
                delete delItem;
            }else if(delItem == root){
                clearTree(root);
                root = NULL;
            }else{
                fixDelete(delItem);
                if(delItem->parent->left == delItem)
                    delItem->parent->left = NULL;
                else
                    delItem->parent->right = NULL;
                delete delItem;
            }
        }
        setDepInd(root);
    }
}

template<typename T>
void RB_BinaryTree<T>:: clear(){
    clearTree(root);
    root = NULL;
}
