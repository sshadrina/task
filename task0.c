#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct node{
  int x;
  int y;
  int size;
  int weight;
};

struct node* create(int *size){
  srand(time(NULL));
  struct node *arr;
  int n;
  printf("Enter number of points: ");
  scanf("%d", &n);
  *size=n;
  arr = (struct node*)malloc(n*sizeof(struct node));
  arr->size = n;
  for(int i = 0; i < n; i++){
    (arr + i)->x = rand() % 10;
    (arr + i)->y = rand() % 10;
    (arr + i)->weight = (rand() % 20);
  }    
  return arr;
}

struct node* del(struct node** arr, int index){
  struct node* temp = (*arr + index);
  for (int i = index; i <= (*arr)->size; i++){
    ((*arr) + i)->x = ((*arr) + i + 1)->x;
    ((*arr) + i)->y = ((*arr) + i + 1)->y;
    ((*arr) + i)->weight = ((*arr) + i + 1)->weight;
  }
  (*arr)->size--;
  return temp;  
}

int minweight(struct node* arr){
  struct node* min = (arr);
  int index = 0;
  for (int i = 0; i < arr->size; i++){
    if (((arr+i)->weight) < ((min)->weight)){
      min = (arr + i);
      index = i;
    }
  }
  return index;
}

void mindistance(struct node** arr){
  int min = minweight(*arr);
  struct node* node = ((*arr) + min);
  printf("Minimal weight =  %d\n",node->weight);
  double mindist = 1000000;
  int minind = 0;
  if ((*arr)->size != 1){
    for (int i = 1; i < (*arr)->size; i++){
      double dist = sqrt((((*arr) + i)->x - node->x)*(((*arr)+i)->x - node->x)+(((*arr) + i)->y - node->y)*(((*arr) + i)->y - node->y));
      if ((dist < mindist) && (dist != 0)){
        mindist = dist;
        minind = i;  
      }
    }
    printf("Point: x = %d, y = %d, weight = %d\nClosest point: x = %d, y = %d, weight = %d\n",node->x, node->y, node->weight,((*arr)+minind)->x,((*arr) + minind)->y,((*arr) + minind)->weight);
    ((*arr) + minind)->weight = ((*arr) + minind)->weight + node->weight;
    del(arr, min);
  } 
}

void print(struct node* arr){
    for (int i = 0; i < arr->size; i++){
        printf("Point: (%d, %d) weigth = %d\n", (arr + i)->x, (arr + i)->y, (arr + i)->weight);
    }
  printf("\n");  
}

int main(){
    int size;
    struct node *arr = create(&size);
    print(arr);
    for (int i = 0; i < size-1; i++){
    	mindistance(&arr);
      	print(arr);
    }
    return 0; 
}
