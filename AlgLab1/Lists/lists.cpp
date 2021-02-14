#include "lists.h"
#include "QDebug"

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

UD_List UD_List::searchInt(int value){
    UD_List searchResult;
    Node *cur;
    cur = head;
    while (cur != NULL) {
        if (cur->i == value && cur->key == integ)
            searchResult.addIntItem(value);
        cur = cur->link;
    }
    return searchResult;
}

UD_List UD_List::searchDoub(double value){
    UD_List searchResult;
    Node *cur;
    cur = head;
    while (cur != NULL) {
        if (cur->d == value && cur->key == doub)
            searchResult.addDoubItem(value);
        cur = cur->link;
    }
    return searchResult;
}

UD_List UD_List::searchChar(QChar value){
    UD_List searchResult;
    Node *cur;
    cur = head;
    while (cur != NULL) {
        if (cur->c == value && cur->key == ch)
            searchResult.addCharItem(value);
        cur = cur->link;
    }
    return searchResult;
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

BD_List BD_List::searchInt(int value){
    BD_List searchResult;
    Node *cur;
    cur = head;
    while (cur != NULL) {
        if (cur->i == value && cur->key == integ)
            searchResult.addIntItem(value);
        cur = cur->next;
    }
    return searchResult;
}

BD_List BD_List::searchDoub(double value){
    BD_List searchResult;
    Node *cur;
    cur = head;
    while (cur != NULL) {
        if (cur->d == value && cur->key == doub)
            searchResult.addDoubItem(value);
        cur = cur->next;
    }
    return searchResult;
}

BD_List BD_List::searchChar(QChar value){
    BD_List searchResult;
    Node *cur;
    cur = head;
    while (cur != NULL) {
        if (cur->c == value && cur->key == ch)
            searchResult.addCharItem(value);
        cur = cur->next;
    }
    return searchResult;
}
//однонаправленный циклический цикл
UD_Cicle::UD_Cicle(){
    head = NULL;
}

UD_Cicle::~UD_Cicle(){
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

QString UD_Cicle::getAdr(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return QString("0x%1").arg((qintptr)cur, QT_POINTER_SIZE * 2, 16, QChar('0'));
}

QString UD_Cicle::getLink(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return QString("0x%1").arg((qintptr)cur->link, QT_POINTER_SIZE * 2, 16, QChar('0'));
}

keys UD_Cicle::getKey(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return cur->key;
}

int UD_Cicle::getInt(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return cur->i;
}

double UD_Cicle::getDoub(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return cur->d;
}

QChar UD_Cicle::getChar(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->link;
    return cur->c;
}

void UD_Cicle::addIntItem(int inf){
    if (count == 0){
        count++;
        head = new Node;
        head->i = inf;
        head->link = head;
        head->key = integ;
        current = head;
    }else{
        count++;
        current->link = new Node;
        current = current->link;
        current->i = inf;
        current->key = integ;
        current->link = head;
    }
}

void UD_Cicle::addDoubItem(double inf){
    if (count == 0){
        count++;
        head = new Node;
        head->d = inf;
        head->link = head;
        head->key = doub;
        current = head;
    }else{
        count++;
        current->link = new Node;
        current = current->link;
        current->d = inf;
        current->key = doub;
        current->link = head;
    }
}

void UD_Cicle::addCharItem(QChar inf){
    if (count == 0){
        count++;
        head = new Node;
        head->c = inf;
        head->link = head;
        head->key = ch;
        current = head;
    }else{
        count++;
        current->link = new Node;
        current = current->link;
        current->c = inf;
        current->key = ch;
        current->link = head;
    }
}

void UD_Cicle::delItem(int N){
    Node *tmp;
    Node *del = head;

    for (int i = 1; i < N && del != NULL;i++)
        del = del->link;
    if (del != NULL){
        if (del == head){
            head = head->link;
            current->link = head;
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

void UD_Cicle::insertIntItem(int index, int inf){
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
            current->link = head;
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

void UD_Cicle::insertDoubItem(int index, double inf){
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
            current->link = head;
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

void UD_Cicle::insertCharItem(int index, QChar inf){
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
            current->link = head;
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

UD_Cicle UD_Cicle::searchInt(int value){
    UD_Cicle searchResult;
    Node *cur;
    cur = head;
    do {
        if (cur->i == value && cur->key == integ)
            searchResult.addIntItem(value);
        cur = cur->link;
    } while (cur != head);
    return searchResult;
}

UD_Cicle UD_Cicle::searchDoub(double value){
    UD_Cicle searchResult;
    Node *cur;
    cur = head;
    do {
        if (cur->d == value && cur->key == doub)
            searchResult.addDoubItem(value);
        cur = cur->link;
    } while (cur != head);
    return searchResult;
}

UD_Cicle UD_Cicle::searchChar(QChar value){
    UD_Cicle searchResult;
    Node *cur;
    cur = head;
    do {
        if (cur->c == value && cur->key == ch)
            searchResult.addCharItem(value);
        cur = cur->link;
    } while (cur != head);
    return searchResult;
}
//двунаправленный циклический список
BD_Cicle::BD_Cicle(){
    head = NULL;
}

BD_Cicle::~BD_Cicle(){
    Node *tmp;
    while(count != 0){
        tmp = head;
        head = head->next;
        delete tmp;
        count--;
    }
}

QString BD_Cicle::getAdr(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return QString("0x%1").arg((qintptr)cur, QT_POINTER_SIZE * 2, 16, QChar('0'));
}

QString BD_Cicle::getNext(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return QString("0x%1").arg((qintptr)cur->next, QT_POINTER_SIZE * 2, 16, QChar('0'));
}

QString BD_Cicle::getPrev(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return QString("0x%1").arg((qintptr)cur->prev, QT_POINTER_SIZE * 2, 16, QChar('0'));
}

keys BD_Cicle::getKey(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return cur->key;
}

int BD_Cicle::getInt(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return cur->i;
}

double BD_Cicle::getDoub(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return cur->d;
}

QChar BD_Cicle::getChar(int index){
    Node *cur;
    cur = head;
    for (int i = 1; i < index && cur != NULL;i++)
         cur = cur->next;
    return cur->c;
}

void BD_Cicle::addIntItem(int inf){
    if (count == 0){
        count++;
        head = new Node;
        head->i = inf;
        head->next = head;
        head->prev = head;
        head->key = integ;
        current = head;
    }else{
        Node *prevItem = current;
        count++;
        current->next = new Node;
        current = current->next;
        current->i = inf;
        current->key = integ;
        current->next = head;
        current->prev = prevItem;
        head->prev = current;
    }
};

void BD_Cicle::addDoubItem(double inf){
    if (count == 0){
        count++;
        head = new Node;
        head->d = inf;
        head->next = head;
        head->prev = head;
        head->key = doub;
        current = head;
    }else{
        Node *prevItem = current;
        count++;
        current->next = new Node;
        current = current->next;
        current->d = inf;
        current->key = doub;
        current->next = head;
        current->prev = prevItem;
        head->prev = current;
    }
}

void BD_Cicle::addCharItem(QChar inf){
    if (count == 0){
        count++;
        head = new Node;
        head->c = inf;
        head->next = head;
        head->prev = head;
        head->key = ch;
        current = head;
    }else{
        Node *prevItem = current;
        count++;
        current->next = new Node;
        current = current->next;
        current->c = inf;
        current->key = ch;
        current->next = head;
        current->prev = prevItem;
        head->prev = current;
    }
}

void BD_Cicle::delItem(int N){
    Node *del = head;

    for (int i = 1; i < N && del != NULL;i++)
        del = del->next;
    if (del != NULL){
        if (del == head){
            head = head->next;
            delete del;
            head->prev = current;
        }else{
            if(del->next == head){
                current = del->prev;
                del->prev->next = head;
                head->prev = del->prev;
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

void BD_Cicle::insertIntItem(int index, int inf){
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
            tmp->prev = current;
            head->prev = tmp;
            head = tmp;
            current->next = head;
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

void BD_Cicle::insertDoubItem(int index, double inf){
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
            tmp->prev = current;
            head->prev = tmp;
            head = tmp;
            current->next = head;
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

void BD_Cicle::insertCharItem(int index, QChar inf){
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
            tmp->prev = current;
            head->prev = tmp;
            head = tmp;
            current->next = head;
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

BD_Cicle BD_Cicle::searchInt(int value){
    BD_Cicle searchResult;
    Node *cur;
    cur = head;
    do {
        if (cur->i == value && cur->key == integ)
            searchResult.addIntItem(value);
        cur = cur->next;
    } while (cur != head);
    return searchResult;
}

BD_Cicle BD_Cicle::searchDoub(double value){
    BD_Cicle searchResult;
    Node *cur;
    cur = head;
    do {
        if (cur->d == value && cur->key == doub)
            searchResult.addDoubItem(value);
        cur = cur->next;
    } while (cur != head);
    return searchResult;
}

BD_Cicle BD_Cicle::searchChar(QChar value){
    BD_Cicle searchResult;
    Node *cur;
    cur = head;
    do {
        if (cur->c == value && cur->key == ch)
            searchResult.addCharItem(value);
        cur = cur->next;
    } while (cur != head);
    return searchResult;
}
