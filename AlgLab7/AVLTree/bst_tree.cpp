#include "bst_tree.h"
#include "internal_sorts.cpp"

bst_tree::bst_tree()
{
    root = NULL;
}
//вставка
void bst_tree::insert(int data){
    root = insert(data, root);
    setDepInd(root);
}

void bst_tree::remove(int data){
    root = remove(data, root);
    setDepInd(root);
}

void bst_tree::squereRoot(){
    int size = getCount();
    int* array = new int[size];
    root->data = root->data * root->data;
    int index = 0;
    fillArray(root, &array, index);
    SimpleInsertSort(&array, size);
    clear();
    int mid = size/2;
    insert(array[mid]);
    for (int i = mid - 1, j = mid + 1;i >= 0 || j <= size; i--, j++) {
        if (i >= 0) {
            insert(array[i]);
        }
        if (j < size) {
            insert(array[j]);
        }
    }
}

int bst_tree::search(int data){
    return search(root, data);
}

void bst_tree::setCurrentOnIndex(int index){
    current = toFindItem(root, index);
};

void bst_tree::clear(){
    clearTree(root);
    root = NULL;
}
