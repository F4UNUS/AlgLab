#include "stack_queue_dack.h"

//стэк
UD_List::UD_List(){
    head = NULL;
}

UD_List::~UD_List(){
    Node *cur;
    if (count != 0){
        while(count != 0){
            cur = head;
            head = head->link;
            delete cur;
            count--;
        }
    }
}

keys UD_List::getKey(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return cur->key;
}

int UD_List::getInt(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return cur->i;
}

double UD_List::getDoub(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return cur->d;
}

QChar UD_List::getChar(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return cur->c;
}

void UD_List::addIntItem(int inf){
    if (count == 0){
        count++;
        head = new Node;
        head->i = inf;
        head->link = NULL;
        head->key = integ;
        current = head;
    }else{
        count++;
        current->link = new Node;
        current = current->link;
        current->i = inf;
        current->key = integ;
        current->link = NULL;
    }
}

void UD_List::addDoubItem(double inf){
    if (count == 0){
        count++;
        head = new Node;
        head->d = inf;
        head->link = NULL;
        head->key = doub;
        current = head;
    }else{
        count++;
        current->link = new Node;
        current = current->link;
        current->d = inf;
        current->key = doub;
        current->link = NULL;
    }
}

void UD_List::addCharItem(QChar inf){
    if (count == 0){
        count++;
        head = new Node;
        head->c = inf;
        head->link = NULL;
        head->key = ch;
        current = head;
    }else{
        count++;
        current->link = new Node;
        current = current->link;
        current->c = inf;
        current->key = ch;
        current->link = NULL;
    }
}

void UD_List::delItem(int N){
    Node *tmp;
    Node *del = head;

    for (int i = 1; i < N && del != NULL;i++)
        del = del->link;
    if (del != NULL){
        if (del == head){
            head = head->link;
            delete del;
        }else{
            tmp = head;
            while (tmp->link != del)
                tmp = tmp->link;
            tmp->link = del->link;
            delete del;
        }
        count--;
    }
    current = head;
    for (int i = 1; i < count && current != NULL;i++)
        current = current->link;
}

void UD_List::insertIntItem(int index, int inf){
    Node *cur = head;
    Node *tmp;
    Node *beforeCur;

    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    if (cur != NULL){
        if(cur == head){
            tmp = new Node;
            tmp->i = inf;
            tmp->key = integ;
            tmp->link = head;
            head = tmp;
            count++;
        }else{
            tmp = new Node;
            tmp->i = inf;
            tmp->key = integ;
            beforeCur = head;
            while (beforeCur->link != cur)
                beforeCur = beforeCur->link;
            tmp->link = cur;
            beforeCur->link = tmp;
            count++;
        }
    }
}

void UD_List::insertDoubItem(int index, double inf){
    Node *cur = head;
    Node *tmp;
    Node *beforeCur;

    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    if (cur != NULL){
        if(cur == head){
            tmp = new Node;
            tmp->d = inf;
            tmp->key = doub;
            tmp->link = head;
            head = tmp;
            count++;
        }else{
            tmp = new Node;
            tmp->d = inf;
            tmp->key = doub;
            beforeCur = head;
            while (beforeCur->link != cur)
                beforeCur = beforeCur->link;
            tmp->link = cur;
            beforeCur->link = tmp;
            count++;
        }
    }
}

void UD_List::insertCharItem(int index, QChar inf){
    Node *cur = head;
    Node *tmp;
    Node *beforeCur;

    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    if (cur != NULL){
        if(cur == head){
            tmp = new Node;
            tmp->c = inf;
            tmp->key = ch;
            tmp->link = head;
            head = tmp;
            count++;
        }else{
            tmp = new Node;
            tmp->c = inf;
            tmp->key = ch;
            beforeCur = head;
            while (beforeCur->link != cur)
                beforeCur = beforeCur->link;
            tmp->link = cur;
            beforeCur->link = tmp;
            count++;
        }
    }
}
//двунаправленный
BD_List::BD_List(){
    head = NULL;
}

BD_List::~BD_List(){
    Node *tmp;
    while(count != 0){
        tmp = head;
        head = head->next;
        delete tmp;
        count--;
    }
}

keys BD_List::getKey(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return cur->key;
}

int BD_List::getInt(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return cur->i;
}

double BD_List::getDoub(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return cur->d;
}

QChar BD_List::getChar(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return cur->c;
}

void BD_List::addIntItem(int inf){
    if (count == 0){
        count++;
        head = new Node;
        head->i = inf;
        head->next = NULL;
        head->prev = NULL;
        head->key = integ;
        current = head;
    }else{
        Node *prevItem = current;
        count++;
        current->next = new Node;
        current = current->next;
        current->i = inf;
        current->key = integ;
        current->next = NULL;
        current->prev = prevItem;
    }
};

void BD_List::addDoubItem(double inf){
    if (count == 0){
        count++;
        head = new Node;
        head->d = inf;
        head->next = NULL;
        head->prev = NULL;
        head->key = doub;
        current = head;
    }else{
        Node *prevItem = current;
        count++;
        current->next = new Node;
        current = current->next;
        current->d = inf;
        current->key = doub;
        current->next = NULL;
        current->prev = prevItem;
    }
}

void BD_List::addCharItem(QChar inf){
    if (count == 0){
        count++;
        head = new Node;
        head->c = inf;
        head->next = NULL;
        head->prev = NULL;
        head->key = ch;
        current = head;
    }else{
        Node *prevItem = current;
        count++;
        current->next = new Node;
        current = current->next;
        current->c = inf;
        current->key = ch;
        current->next = NULL;
        current->prev = prevItem;
    }
}

void BD_List::delItem(int N){
    Node *del = head;

    for (int i = 1; i < N && del != NULL;i++)
        del = del->next;
    if (del != NULL){
        if (del == head){
            head = head->next;
            delete del;
            if(count != 1)
                head->prev = NULL;
        }else{
            if(del->next == NULL){
                current = del->prev;
                del->prev->next = NULL;
                delete del;
            }else{
                del->prev->next = del->next;
                del->next->prev = del->prev;
                delete del;
            }
        }
        count--;
    }
}

void BD_List::insertIntItem(int index, int inf){
    Node *cur = head;
    Node *tmp;

    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    if (cur != NULL){
        if(cur == head){
            tmp = new Node;
            tmp->i = inf;
            tmp->key = integ;
            tmp->next = head;
            tmp->prev = NULL;
            head->prev = tmp;
            head = tmp;
            count++;
        }else{
            tmp = new Node;
            tmp->i = inf;
            tmp->key = integ;
            tmp->next = cur;
            tmp->prev = cur->prev;
            cur->prev->next = tmp;
            cur->prev = tmp;
            count++;
        }
    }
}

void BD_List::insertDoubItem(int index, double inf){
    Node *cur = head;
    Node *tmp;

    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    if (cur != NULL){
        if(cur == head){
            tmp = new Node;
            tmp->d = inf;
            tmp->key = doub;
            tmp->next = head;
            tmp->prev = NULL;
            head->prev = tmp;
            head = tmp;
            count++;
        }else{
            tmp = new Node;
            tmp->d = inf;
            tmp->key = doub;
            tmp->next = cur;
            tmp->prev = cur->prev;
            cur->prev->next = tmp;
            cur->prev = tmp;
            count++;
        }
    }
}

void BD_List::insertCharItem(int index, QChar inf){
    Node *cur = head;
    Node *tmp;

    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    if (cur != NULL){
        if(cur == head){
            tmp = new Node;
            tmp->c = inf;
            tmp->key = ch;
            tmp->next = head;
            tmp->prev = NULL;
            head->prev = tmp;
            head = tmp;
            count++;
        }else{
            tmp = new Node;
            tmp->c = inf;
            tmp->key = ch;
            tmp->next = cur;
            tmp->prev = cur->prev;
            cur->prev->next = tmp;
            cur->prev = tmp;
            count++;
        }
    }
}
