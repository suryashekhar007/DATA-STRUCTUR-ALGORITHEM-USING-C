#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;
struct node *temp;

void insert_at_begining(struct node*);
void insert_at_end(struct node*);
void delete_at_begining();
void delete_at_end();
void traverse1();
void traverse2();

int main(){
	int choice, n;
	struct node *new1;
	
	while(1){
		printf("\n------------------DOUBLY LINKED LIST----------------");
		printf("1. insert at begining\n2. insert at end\n3. delete at begining\n4. delete at end\n5. traverse1\n6. traverse2\n7. exit\n");
		printf("\nenter the choice\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d", &new1->data);
					new1->next = NULL;
					new1->prev = NULL;
					ins_beg(new1);
					break;
			case 2:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					new1->prev = NULL;
					ins_end(new1);
					break;
			case 3:
					del_beg();
					break;
					
			case 4:
					del_end();
					break;
			case 5:
					traverse1();
					break;
			case 6:
					traverse2();
					break;
			default:
					exit(1);
		}
	}
}
	void ins_beg(struct node *new1){
		if(head == NULL)
			head = new1;
		else{
			head->prev = new1;
			new1->next = head;
			head = new1;
		}
	}
	
	void ins_end(struct node *new1){
		struct node *temp = head;
		if(head == NULL)
			head = new1;
		else{
			while(temp->next!= NULL)
				temp = temp->next;
			new1->prev = temp;
			temp->next = new1;
			}
		}
		
	void del_beg(){
		struct node *temp = head;
		if(head == NULL)
			printf("no item to delete\n");
		else
			head = head->next;
			head->prev = NULL;
			free(temp);
			temp = NULL;
	}
	
	void del_end(){
		struct node *temp = head;
		struct node *temp1 = head;
		if(head == NULL)
			printf("no item to delete\n");
		else{
			while(temp1->next != NULL){
				temp = temp1;
				temp1 = temp1->next;
				}
	    	if(temp1 == head)
	    		head = NULL;
			else
			 	temp->next = NULL;
			 	temp1->prev = NULL;
				free(temp1);
				temp1 = NULL;
			}
	}

	void traverse1(){
		struct node *temp = head;
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
	
	void traverse2(){
	struct node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->prev;
			}
	}
	
