#ifndef BST_TREE_H
#define BST_TREE_H

#include <QApplication>

class bst_tree{
private:
    struct treeItem {
        int data;
        int index;
        int depth;
        treeItem* left;
        treeItem* right;
    };
    treeItem *root;
    treeItem *current;

    treeItem *toFindItem(treeItem *cur, int index){
        if (cur == NULL)
            return NULL;
        if(cur->index == index)
            return cur;
        if(toFindItem(cur->left, index) == NULL){
            cur = toFindItem(cur->right, index);
        }else{
            cur = toFindItem(cur->left, index);
        }
        return cur;
    };

    void setDepInd(treeItem *cur){
          if(cur == root){
              root->index = 1;
              root->depth = 0;
          }
          if(cur->left != NULL){
              cur->left->index = cur->index*2;
              cur->left->depth = cur->depth + 1;
              setDepInd(cur->left);
          }
          if(cur->right !=NULL){
              cur->right->index = cur->index*2 + 1;
              cur->right->depth = cur->depth + 1;
              setDepInd(cur->right);
          }
    };

    void clearTree(treeItem *cur){
        if(cur != NULL){
            clearTree(cur->left);
            clearTree(cur->right);
            delete(cur);
        }
    };

    int depth(treeItem *item){return (item == NULL ? -1 : item->depth);};

    treeItem* insert(int data, treeItem *item){
        if(item == NULL){
            item = new treeItem;
            item->data = data;
            item->depth = 0;
            item->index = 1;
            item->left = item->right = NULL;
        }else if(data < item->data){
            item->left = insert(data, item->left);
        }else if(data > item->data){
            item->right = insert(data, item->right);
        }
        item->depth = qMax(depth(item->left), depth(item->right)) + 1;
        return item;
    };

    treeItem* findMax(treeItem *item){
        if(item == NULL)
            return NULL;
        else if(item->right == NULL)
            return item;
        else
            return findMax(item);
    };

    treeItem* findMin(treeItem *item){
        if(item == NULL)
            return NULL;
        else if(item->left == NULL)
            return item;
        else
            return findMax(item);
    };

    treeItem* remove(int data, treeItem* item){
        treeItem* tmp;
        if(item == NULL)
            return NULL;
        else if(data < item->data)
            item->left = remove(data, item->left);
        else if(data > item->data)
            item->right = remove(data, item->right);
        else if(item->left && item->right){
            tmp = findMin(item->right);
            item->data = tmp->data;
            item->right = remove(item->data, item->right);
        }else{
            tmp = item;
            if(item->left == NULL)
                item = item->right;
            else if(item->right == NULL)
                item = item->left;
            delete tmp;
        }
        if(item == NULL)
            return item;

        item->depth = qMax(depth(item->left), depth(item->right)) + 1;
        return item;
    };

    int search(treeItem* item,int data){
        if(item == NULL)
            return -1;
        int index = item->index;
        if(item->data > data){
            index = search(item->left, data);
        }
        else if(item->data < data){
            index = search(item->right, data);
        }
        return index;
    };

    int count(treeItem *item, int &currentCount){
        if(item == NULL)
            return 0;
        currentCount++;
        count(item->left, currentCount);
        count(item->right, currentCount);
        return currentCount;
    }

    void fillArray(treeItem *item, int **array, int &index){
        if(item == NULL)
            return;
        (*array)[index] = item->data;
        index++;
        fillArray(item->left, &(*array), index);
        fillArray(item->right, &(*array), index);
    };
public:
    bst_tree();
    void insert(int data);
    void remove(int data);
    void squereRoot();
    int search(int data);
    void toGoLeft(){current = current->left;};
    void toGoRight(){current = current->right;};
    //обходы дерева
    void preOrderBT();
    //геттеры
    int getCurrentData(){return current->data;};
    int getCurrentIndex(){return current->index;};
    int getCurrentDepth(){return current->depth;};
    int getCount(){
        int c = 0;
        return count(root, c);};
    //сеттеры
    void setCurrentOnRoot(){current = root;};
    void setCurrentOnIndex(int index);
    //проверки пустоты
    bool empty(){return ((root == NULL) ? true : false);};
    bool currentBranchEmpty(){return ((current == NULL) ? true : false);};
    bool leftBranchEmpty(){return ((current->left == NULL) ? true : false);};
    bool rightBranchEmpty(){return ((current->right == NULL) ? true : false);};
    bool indexIn(int index){return (toFindItem(root, index) != NULL) ? true : false;};
    void clear();
};

#endif // BST_TREE_H
