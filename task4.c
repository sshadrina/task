#include <stdio.h>
#include <stdlib.h>

struct node{
  int val;
  struct node* next;
} node;

void print(struct node *head){
  struct node* current=head;
  while(current!=NULL){
    printf("value = %d\t", current->val);
    current=current->next;
  }
}

struct node* create(int val){
  struct node* temp = (struct node*)malloc(sizeof(node));
  if(!temp){
    printf("Memorry error!");
    exit(1);
  }
  temp -> next = NULL;
    temp -> val = val;
  return temp;
}

void pushend(struct node** head, int val){
   if(*head == NULL){
    *head = create(val);
    return;
  }
  struct node* current = *head;
  while(current->next!=NULL) current = current->next;
  struct node* temp = create(val);
  current->next = temp;
}


struct node* middle(struct node* head){  
  printf("Enter value, where you want to add: ");
  int chval;
  scanf("%d",&chval);
  struct node* current = head;
  while(current->val!=chval) 
  current=current->next;
  printf("Enter new value: ");
  int nval;
  scanf("%d", &nval);
  struct node* newnode = (struct node*)malloc(sizeof(node));
  newnode->val = nval;
  newnode->next=current->next;
  current->next=newnode;  
  return head;
}


void del(struct node** head, int index){
    if(index == 0) {
      struct node* temp = *head;
      *head = (*head) -> next;
      free(temp);
     return;
    }
    struct node* current = *head;
    for(int i = 0; current != NULL; i++, current = current->next ){
        if(i + 1 == index){
            struct node* temp = current -> next;
            current -> next = temp ->next;
            free(temp);
            return;
        }
    }
}

void valuebyindex(struct node* head, int index){
    double val = -1;
    for(int i = 0; head != NULL; i++, head = head -> next){
        if(i == index){
            printf("Index = %d, val = %d\n", i, head->val);
            return;
      }
    }
}

void set(struct node* head, int index, int num){
    double val = -1;
    for(int i = 0; head != NULL; i++, head = head -> next){
        if(i == index){
            head->val = num;
            return;
        }
    }
}


void size(struct node* head){
    int size = 0;
    printf("Size: ");
    for(int i =0; head!=NULL; i++, head = head -> next){
        size++;
    }
    printf("%d\n", size);
}

void memfree(struct node* head){
  if(!head) return;
  memfree(head->next);
  free(head);
}

int main(){
    struct node *head=NULL;
    while(1){
      printf("\n Menu\n");
      printf("1. Add new value\n");
        printf("2. Add new value after the specified\n");
        printf("3. Print your list\n");
        printf("4. Delete element\n");
      printf("5. Find value by index\n");
    printf("6. Size \n");
    printf("7. Replace current element by index\n");
    printf("8. Exit\n");
        int var;
    	int val;
    	int index;
        scanf("%d", &var);
        switch(var){
          case 1: 
            printf("Enter value:");
            scanf("%d", &val);
            pushend(&head, val);
            break;
          case 2:
            middle(head);
            break;  
          case 3:
            print(head);
            break;
          case 4:
           printf("Enter index: ");
                scanf("%d",&index);
    		del(&head,index);
            break;
       case 5:{
        	printf("Enter index: ");
                scanf("%d",&index);
                valuebyindex(head, index);
        break;
        }      
      case 6:{
          size(head);
          break;
        }    
      case 7:{
                  scanf("%d",&index);
                   printf("Enter new value: ");
                  scanf("%d",&val);
                  set(head, index, val);
          break;
        }
        case 8:
          memfree(head);
            return 0;
        }
    } 
}
