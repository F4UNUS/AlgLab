#include <cstdlib>
#include <ctime>
int arrSize;//размер массива
int *array;//массив
//массивы для задания
int *a;
int *b;
int size_a;
int size_b;

//смена элементов местами
void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
};
//создание динамического массива в памяти
void toCreateArray(int **array, int size){
    srand(time(NULL));
    (*array) = new int[size];
    for (int i = 0;i < size;i++) {
        (*array)[i] = rand() % 100 +1;
    }
};
//сортировка простым выбором
void SimpleChoiceSort(int **array, int size){
    int min;
    for (int i = 0;i < size - 1;i++){
        min = i;
        for (int j = i + 1;j < size;j++)
            if ((*array)[j] < (*array)[min])
                min = j;
        swap((*array)[i], (*array)[min]);
    }
};
//пузырьковая сортировка
void BubbleSort(int **array, int size){
    for(int i = 0;i < size - 1; i++)
        for(int j = 0;j < size - 1 - i;j++)
            if((*array)[j] > (*array)[j + 1])
                swap((*array)[j], (*array)[j + 1]);
};
//сортировка простой вставкой
void SimpleInsertSort(int **array, int size){
    for(int i = 1;i < size;i++)
        for(int j = i;j > 0 && (*array)[j - 1] > (*array)[j]; j--)
                swap((*array)[j - 1],(*array)[j]);
};
//просеивание кучи
void Heap(int **array, int size, int index){
    int max = index;//индекс дна кучи
    int l = 2*index + 1;
    int r = 2*index + 2;
    if (l < size && (*array)[l] > (*array)[max])
        max = l;
    if (r < size && (*array)[r] > (*array)[max])
        max = r;
    if (max != index){
        swap((*array)[index], (*array)[max]);
        Heap(&(*array), size, max);
    }
};
//пирамидальная сортировка
void HeapSort(int **array, int size){
    for(int i = size / 2 - 1; i >= 0;i--)
        Heap(&(*array), size, i);
    for (int i = size - 1; i >= 0; i--){
            swap((*array)[0], (*array)[i]);
            Heap(&(*array), i, 0);
        }
};
//сортировка Шелла
void ShellSort(int **array, int size){
    for(int step = size / 2;step > 0;step /= 2)
        for(int i = step;i < size;i++)
            for(int j = i - step; j >= 0 && (*array)[j] > (*array)[j + step];j -= step)
                swap((*array)[j], (*array)[j + step]);
};
//быстрая сортировка
void QuickSort(int **array, int first, int last){
    int l = first, r = last;
    int support = (*array)[(l + r) / 2];
    do {
        while((*array)[l] < support)
            l++;
        while((*array)[r] > support)
            r--;
        if(l <= r){
            if(l < r)
                swap((*array)[l], (*array)[r]);
        l++;
        r--;
        }
    } while(l < r);
    if(l < last)
        QuickSort(&(*array), l, last);
    if(r > first)
        QuickSort(&(*array), first, r);
};
//сортировка слияниями
void MergeSort(int **array, int first, int last){
    if(last <= first)
        return;

    int support =  (first + last) / 2;

    MergeSort(&(*array), first, support);
    MergeSort(&(*array), support + 1, last);

    int l = first, r = support + 1;
    int *arrayBuf = new int[last + 1];
    for(int i = first; i <= last; i++)
        arrayBuf[i] = (*array)[i];
    for(int i = first;i <= last; i++)
        if (l > support) {
            (*array)[i] = arrayBuf[r];
            r++;
        } else if (r > last) {
            (*array)[i] = arrayBuf[l];
            l++;
        } else if (arrayBuf[r] < arrayBuf[l]) {
            (*array)[i] = arrayBuf[r];
            r++;
        } else {
            (*array)[i] = arrayBuf[l];
            l++;
        }
};
//задание
int *TheTask(int **a, int **b, int size_a, int size_b){
    int size_c = size_a + size_b;
    int *c = new int[size_c];
    int buf;

    int i = 0, j = 0;
    for (int k = size_c - 1; k >= 0; k--)
        if (i > size_a - 1) {
            buf = (*b)[j];
            c[k] = buf;
            j++;
        }
        else if (j > size_b - 1) {
            buf = (*a)[i];
            c[k] = buf;
            i++;
        }
        else if ((*a)[i] < (*b)[j]) {
            buf = (*a)[i];
            c[k] = buf;
            i++;
        }
        else {
            buf = (*b)[j];
            c[k] = buf;
            j++;
        }
    return c;
};
