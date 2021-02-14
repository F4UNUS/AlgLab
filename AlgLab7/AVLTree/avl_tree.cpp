#include "avl_tree.h"

avl_tree::avl_tree()
{
    root = NULL;
}
//вставка
void avl_tree::insert(int data){
    root = insert(data, root);
    setDepInd(root);
}

void avl_tree::remove(int data){
    root = remove(data, root);
    setDepInd(root);
}

int avl_tree::search(int data){
    return search(root, data);
}

void avl_tree::setCurrentOnIndex(int index){
    current = toFindItem(root, index);
};

void avl_tree::clear(){
    clearTree(root);
    root = NULL;
}
