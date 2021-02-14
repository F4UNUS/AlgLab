#ifndef STACK_QUEUE_DACK_H
#define STACK_QUEUE_DACK_H
#include <QApplication>

enum keys{integ, doub, ch};
//однонаправленный список
class UD_List{
private:
    struct Node{
      int i;
      double d;
      QChar c;
      keys key;
      Node *link = NULL;
    };
    Node *head;
    Node *current;
    int count = 0;//счетчик элементов списка
public:
    //конструктор
    UD_List();
    //дкструктор
    ~UD_List();
    //добавление элементов в список
    void addIntItem(int inf);//целого
    void addDoubItem(double inf);//вещественного
    void addCharItem(QChar inf);//символьного
    //удаление указанного элемента
    void delItem(int N);
    //вставка нового элемента после заданного
    void insertIntItem(int index, int inf);//вставка целого
    void insertDoubItem(int index, double inf);//вставка вещественного
    void insertCharItem(int index, QChar inf);//вставка символьного
    //геттеры, возвращают всевозможные значения текущего элемента, а также кол-во элементов списка
    int getCount(){return count;}
    keys getKey(){return current->key;}
    int getInt(){return current->i;}
    double getDoub(){return current->d;}
    QChar getChar(){return current->c;}
    //геттеры возвращающие значение по номеру элемента
    keys getKey(int index);
    int getInt(int index);
    double getDoub(int index);
    QChar getChar(int index);
};
//двунаправленный список
class BD_List{
private:
    struct Node{
      int i;
      double d;
      QChar c;
      keys key;
      Node *next = NULL, *prev = NULL;
    };
    Node *head;
    Node *current;
    int count = 0;//счетчик элементов списка
public:
    //конструктор
    BD_List();
    //деструктор
    ~BD_List();
    //добавление элементов в список
    void addIntItem(int inf);//целого
    void addDoubItem(double inf);//вещественного
    void addCharItem(QChar inf);//символьного
    //удаление указанного элемента
    void delItem(int N);
    //вставка нового элемента после заданного
    void insertIntItem(int index, int inf);//вставка целого
    void insertDoubItem(int index, double inf);//вставка вещественного
    void insertCharItem(int index, QChar inf);//вставка символьного
    //геттеры, возвращают всевозможные значения текущего элемента, а также кол-во элементов списка
    int getCount(){return count;}
    keys getKey(){return current->key;}
    int getInt(){return current->i;}
    double getDoub(){return current->d;}
    QChar getChar(){return current->c;}
    //геттеры возвращающие значение по номеру элемента
    keys getKey(int index);
    int getInt(int index);
    double getDoub(int index);
    QChar getChar(int index);
};

#endif // STACK_QUEUE_DACK_H
