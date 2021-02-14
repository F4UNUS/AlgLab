#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <QApplication>

template<class T>
class BinaryTree
{
private:
    struct treeItem {
        T data;
        int index;
        int depth;
        treeItem* left;
        treeItem* right;
    };
    treeItem *root;
    treeItem *current;

    treeItem *toFindItem(treeItem *cur, int index){//работает
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

    void reDepInd(treeItem *cur){
          if(cur == root){
              root->index = 1;
              root->depth = 0;
          }
          if(cur->left != NULL){
              cur->left->index = cur->index*2;
              cur->left->depth = cur->depth + 1;
              reDepInd(cur->left);
          }
          if(cur->right !=NULL){
              cur->right->index = cur->index*2 + 1;
              cur->right->depth = cur->depth + 1;
              reDepInd(cur->right);
          }
    };

    void clearTree(treeItem *cur){
        if(cur != NULL){
            clearTree(cur->left);
            clearTree(cur->right);
            delete(cur);
        }
    };
public:
    BinaryTree();
    ~BinaryTree();
    void toCreateRoot(T data);
    void toAddLeftItem(T data, int index);
    void toAddRightItem(T data, int index);
    void toDelItem(int index);
    void toGoLeft(){current = current->left;};
    void toGoRight(){current = current->right;};
    //обходы дерева
    void preOrderBT();
    //геттеры
    T getCurrentData(){return current->data;};
    int getCurrentIndex(){return current->index;};
    int getCurrentDepth(){return current->depth;};
    //сеттеры
    void setCurrentOnRoot(){current = root;};
    void setcurrentOnIndex(int index);
    //проверки пустоты
    bool empty(){return ((root == NULL) ? true : false);};
    bool currentBranchEmpty(){return ((current == NULL) ? true : false);};
    bool leftBranchEmpty(){return ((current->left == NULL) ? true : false);};
    bool rightBranchEmpty(){return ((current->right == NULL) ? true : false);};
    bool indexIn(int index){return (toFindItem(root, index) != NULL) ? true : false;};
    void clear();
};

#endif // BINARYTREE_H
