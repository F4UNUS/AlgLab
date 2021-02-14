int *arri;//целочисленный массив
int iSize = 0;//размер целочисленного масива
int ii = -1;//текущий индекс целочисленного массива
double *arrd;//вещественный массив
int dSize = 0;//размер вещественного массива
int id = -1;//текущий индекс вещественного массива

template <class T>
int LinearSearch(T *array, int size, T key){//последовательный поиск
    int i;
    for(i = 0;i < size;i++)
        if(array[i] == key) break;
    return (i < size) ? i : -1;
}
template <class T>
void SimpleInsertSort(T **array, int size){//сортировка для бинанрного поиска
    for(int i = 1;i < size;i++)
        for(int j = i;j > 0 && (*array)[j - 1] > (*array)[j]; j--){
            T tmp;
            tmp = (*array)[j - 1];
            (*array)[j - 1] = (*array)[j];
            (*array)[j] = tmp;
        }
}
template <class T>
int BinarySearch(T *array, int size, T key){//бинарный поиск
    bool found = false;
    int high = size - 1, low = 0;
    int middle = (high + low) / 2;
    while ( !found && high >= low ){
      if (key == array[middle])
        found = true;
      else if (key < array[middle])
        high = middle - 1;
      else
        low = middle + 1;
      middle = (high + low) / 2;
    }
    return found ? middle : -1 ;
}
template <class T>
void BinarySearchModify(T *array, int size, T key, int &first, int &last){//модифицироанный бинарный, показывает первое и последнее вхождение элемента
    bool found = false;
    int right = size - 1, left = 0;
    int middle = (right + left) / 2;
    while ( !found && right >= left ){
      if (key == array[middle])
        found = true;
      else if (key < array[middle])
        right = middle - 1;
      else
        left = middle + 1;
      middle = (right + left) / 2;
    }
    if(found){
        first = middle;
        last = middle;
        while(key == array[first - 1])
            first--;
        while(key == array[last + 1])
            last++;
    }else{
        first = -1;
    }
}
