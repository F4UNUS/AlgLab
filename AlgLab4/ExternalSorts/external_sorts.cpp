#include <QDebug>
//сортировка простым слиянием
void SimpleMergingSort (char *name){
  int a1, a2, i, j, count = 0;
  FILE *f, *f1, *f2;
  if ( (f = fopen(name,"r")) == NULL )
    qDebug() << "Исходный файл не может быть прочитан";
  else {
    while ( !feof(f) ) {
      fscanf(f,"%d",&a1);
      count++;
    }
    fclose(f);
  }
  for (int k = 1;k < count;k *= 2){
    f = fopen(name,"r");
    f1 = fopen("smsort_1","w");
    f2 = fopen("smsort_2","w");
    if ( !feof(f) ) fscanf(f,"%d",&a1);
    while ( !feof(f) ){
      for ( i = 0; i < k && !feof(f) ; i++ ){
        fprintf(f1,"%d ",a1);
        fscanf(f,"%d",&a1);
      }
      for ( j = 0; j < k && !feof(f) ; j++ ){
        fprintf(f2,"%d ",a1);
        fscanf(f,"%d",&a1);
      }
    }
    fclose(f2);
    fclose(f1);
    fclose(f);

    f = fopen(name,"w");
    f1 = fopen("smsort_1","r");
    f2 = fopen("smsort_2","r");
    if ( !feof(f1) ) fscanf(f1,"%d",&a1);
    if ( !feof(f2) ) fscanf(f2,"%d",&a2);
    while (!feof(f1) && !feof(f2)){
      i = 0;
      j = 0;
      while ( i < k && j < k && !feof(f1) && !feof(f2) ) {
        if ( a1 < a2 ) {
          fprintf(f,"%d ",a1);
          fscanf(f1,"%d",&a1);
          i++;
        }
        else {
          fprintf(f,"%d ",a2);
          fscanf(f2,"%d",&a2);
          j++;
        }
      }
      while ( i < k && !feof(f1) ) {
        fprintf(f,"%d ",a1);
        fscanf(f1,"%d",&a1);
        i++;
      }
      while ( j < k && !feof(f2) ) {
        fprintf(f,"%d ",a2);
        fscanf(f2,"%d",&a2);
        j++;
      }
    }
    while (!feof(f1)) {
      fprintf(f,"%d ",a1);
      fscanf(f1,"%d",&a1);
    }
    while (!feof(f2)) {
      fprintf(f,"%d ",a2);
      fscanf(f2,"%d",&a2);
    }
    fclose(f2);
    fclose(f1);
    fclose(f);
  }
  remove("smsort_1");
  remove("smsort_2");
}
//сортировка естественным слиянием
void NaturalMergingSort(char* name){

};
