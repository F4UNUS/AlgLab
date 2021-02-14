#ifndef RB_BINARYTREE_H
#define RB_BINARYTREE_H
#include <QApplication>

template<class T>
class RB_BinaryTree
{
private:
    struct treeItem {
        T data;
        int index;
        int depth;
        bool color;//true = red, false = black
        treeItem *parent;
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
          if(cur->right != NULL){
              cur->right->index = cur->index*2 + 1;
              cur->right->depth = cur->depth + 1;
              setDepInd(cur->right);
          }
    };

    void swapData(treeItem *first, treeItem *second){
        T tmp = first->data;
        first->data = second->data;
        second->data = tmp;
    };

    void clearTree(treeItem *cur){
        if(cur != NULL){
            clearTree(cur->left);
            clearTree(cur->right);
            delete(cur);
        }
    };

    void addItem(treeItem *parent, treeItem* item){
        if(parent->data > item->data){
            if(parent->left == NULL){
                parent->left = item;
                item->parent = parent;
                item->index = parent->index * 2;
                item->depth = parent->depth + 1;
            }else{
                addItem(parent->left, item);
            }
        }else{
            if(parent->right == NULL){
                parent->right = item;
                item->parent = parent;
                item->index = parent->index*2 + 1;
                item->depth = parent->depth + 1;
            }else{
                addItem(parent->right, item);
            }
        }
    }
    //правый поворот
    void rightTurn(treeItem *parent, treeItem *son){
        if(son->parent->left == son){
            treeItem *pParent = parent->parent;
            if(pParent != NULL){
                if(pParent->left == parent){
                    pParent->left = son;
                }else{
                    pParent->right = son;
                }
            }else{
                root = son;
            }
            parent->parent = son;
            parent->left = son->right;
            if(son->right != NULL)
                son->right->parent = parent;
            son->right = parent;
            son->parent = pParent;
        }
    }
    //левый
    void leftTurn(treeItem *parent, treeItem *son){
        if(son->parent->right == son){
            treeItem *pParent = parent->parent;
            if(pParent != NULL){
                if(pParent->left == parent){
                    pParent->left = son;
                }else{
                    pParent->right = son;
                }
            }else{
                root = son;
            }
            parent->parent = son;
            parent->right = son->left;
            if(son->left != NULL)
                son->left->parent = parent;
            son->left = parent;
            son->parent = pParent;
        }
    }
    //балнсировка при добавлении
    void fixAdd(treeItem *item){
        if(item == root){
            if(item->color == true)
                item->color = false;
        }else{
            bool Left = false;
            treeItem *pParent = item->parent->parent;
            if(item->parent->index % 2 == 0)
                Left = true;
            if(item->parent->color){
                //красный дядя
                if((Left && pParent->right != NULL &&  pParent->right->color == true) || (!Left && pParent->left != NULL &&  pParent->left->color == true)){
                    pParent->left->color = pParent->right->color = false;
                    pParent->color = true;
                    fixAdd(pParent);
                //черный дядя папа и дед в разных сторонах
                }else if(Left && item->parent->right == item){
                    leftTurn(item->parent, item);
                    fixAdd(item->left);
                }else if(!Left && item->parent->left == item){
                    rightTurn(item->parent, item);
                    fixAdd(item->right);
                //черный дядя папа и дед в одной стороне
                }else if(Left && item->parent->left == item){
                    item->parent->color = false;
                    pParent->color = true;
                    rightTurn(pParent, item->parent);
                }else if(!Left && item->parent->right == item){
                    item->parent->color = false;
                    pParent->color = true;
                    leftTurn(pParent, item->parent);
                }
            }
        }
    }
    //балансировка при удалении
    void fixDelete(treeItem *item){
        if(item != root){
            bool Left = false;
            if(item->parent->left == item)
                Left = true;
            treeItem* brother;
            if(Left){
                brother = item->parent->right;
            }else{
                brother = item->parent->left;
            }
            if(item->parent->color){
                if(Left && (brother->right != NULL && brother->right->color)){
                    item->parent->color = false;
                    brother->color = true;
                    brother->right->color = false;
                    leftTurn(brother->parent, brother);
                }else if(!Left && (brother->left != NULL && brother->left->color)){
                    item->parent->color = false;
                    brother->color = true;
                    brother->left->color = false;
                    rightTurn(brother->parent, brother);
                }else if(((brother->left == NULL) || (brother->left->color == false)) && ((brother->right == NULL) || (brother->right->color == false))){
                    brother->parent->color = false;
                    brother->color = true;
                }
            }else{
                if(brother->color){
                    if(Left && brother->left->right != NULL && brother->left->right->color){
                        brother->left->right->color = false;
                        rightTurn(brother, brother->left);
                        leftTurn(brother->parent->parent, brother->parent);
                    }else if(!Left && brother->right->left != NULL && brother->right->left->color){
                        brother->right->left->color = false;
                        leftTurn(brother, brother->right);
                        rightTurn(brother->parent->parent, brother->parent);
                    }else if(((brother->right->left == NULL) || (brother->right->left != NULL && brother->left->color == false)) && ((brother->right->right == NULL) || (brother->right->right != NULL && brother->right->color == false))){
                        brother->color = false;
                        if(Left){
                            brother->left->color = true;
                            leftTurn(brother->parent, brother);
                        }else{
                            brother->right->color = true;
                            rightTurn(brother->parent, brother);
                        }
                    }
                }else if(Left && brother->left != NULL && brother->left->color){
                    brother->left->color = false;
                    rightTurn(brother, brother->left);
                    leftTurn(brother->parent->parent, brother->parent);
                }else if(!Left && brother->right != NULL && brother->right->color){
                    brother->right->color = false;
                    leftTurn(brother, brother->right);
                    rightTurn(brother->parent->parent, brother->parent);
                }else if(Left && brother->left == NULL && brother->right != NULL && brother->right->color){
                    brother->right->color = false;
                    leftTurn(brother->parent, brother);
                }else if(!Left && brother->right == NULL && brother->left != NULL && brother->left->color){
                    brother->left->color = false;
                    rightTurn(brother->parent, brother);
                }else{
                    brother->color = true;
                    fixDelete(brother->parent);
                }
            }
        }
    }

public:
    RB_BinaryTree();
    ~RB_BinaryTree();
    void toCreateRoot(T data);
    void toAddItem(T data);
    void toDelItem(int index);
    void toGoLeft(){current = current->left;};
    void toGoRight(){current = current->right;};
    //обходы дерева
    void preOrderBT();
    //геттеры
    T getCurrentData(){return current->data;};
    int getCurrentIndex(){return current->index;};
    int getCurrentDepth(){return current->depth;};
    bool getCurrentColor(){return current->color;};
    //сеттеры
    void setCurrentOnRoot(){current = root;};
    void setcurrentOnIndex(int index);
    //проверки пустоты
    bool empty(){return ((root == NULL) ? true : false);};
    bool currentBranchEmpty(){return ((current == NULL) ? true : false);};
    bool leftBranchEmpty(){return ((current->left == NULL) ? true : false);};
    bool rightBranchEmpty(){return ((current->right == NULL) ? true : false);};
    bool indexIn(int index){return (toFindItem(root, index) != NULL) ? true : false;};
    //очистка
    void clear();
};

#endif // RB_BINARYTREE_H
