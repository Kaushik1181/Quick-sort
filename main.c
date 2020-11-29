#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//*****************************************************
//Randomize Partitioning to avoid worst time complexity
//*****************************************************

int partition(int *A,int start,int end) {
  int pivot = A[end];
  int pIndex = start;
  for(int i=start;i<end;i++) {
    if(A[i] <= pivot) {
      swap(&A[i],&A[pIndex]);
      pIndex++;
    }
  }
  swap(&A[pIndex],&A[end]);
  return pIndex;
}

void quickSort(int *A,int start,int end) {
  if(start < end) {
    int pIndex = partition(A,start,end);
    quickSort(A,start,pIndex-1);
    quickSort(A,pIndex+1,end);
  }
}

int main(void) {
  int A[] = {5,3,8,6,2,8,9,3,8,9,5};
  int size = sizeof(A) / sizeof(A[0]);
  quickSort(A,0,size-1);
  for(int i=0;i<size;i++){
    printf("%d ",A[i]);
  }
  return 0;
}