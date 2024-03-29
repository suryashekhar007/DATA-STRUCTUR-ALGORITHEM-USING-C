#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;
//struct node *temp;

void insert_at_begining(struct node*);
void insert_at_end(struct node*);
void delete_at_begining();
void delete_at_end();
void traverse();

int main(){
	int choice, n;
	struct node *new1;
	
	while(1){
		printf("\n--------------circular linked list--------------");
		printf("\n1. insert at begining\n2. insert at end\n3. delete at begining\n4. delete at end\n5. traverse\n6. exit\n");
        printf("\nenter the choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					insert_at_begining(new1);
					break;
			case 2:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					insert_at_end(new1);
					break;
			case 3:
					delete_at_begining();
					break;
			case 4:
					delete_at_end();
					break;
			case 5: 
					traverse();
					break;
			default:
					exit(1);
		}
	}
}
	void insert_at_begining(struct node *new1){
			struct node *temp = head;
		if(head == NULL)
			{
				head = new1;
				head->next = head;
			}
		else{
			while(temp->next != head)
				temp = temp->next;
			new1->next = head;
			temp->next = new1;
			head = new1;
		}
	}
	
	void insert_at_end(struct node *new1){
		struct node *temp = head;
		if(head == NULL)
			{
				head = new1;
				head->next = head;
			}
		else{
			while(temp->next!= head)
				temp = temp->next;
			temp->next = new1;
			new1->next = head;
			}
		}
		
	void delete_at_begining(){
		struct node *temp = head;
		struct node *temp1 = head;
	if(head == NULL)
		printf("no elements in the list\n");
	else if(head->next == head){
		printf("Item deleted from the head  = %d\n",head->data);
		head = NULL;
	}
	else{
		while(temp->next!=head)
			temp = temp->next;
		printf("Item deleted from the head  = %d\n",head->data);
		head = head->next;
		temp->next = head;
		free(temp1);
		temp1 = NULL;
		
		}
		}
			
void delete_at_end(){
    struct node *temp = head;
    struct node *temp1 = head;
    
    if(head == NULL){
        printf("No elements in the list");
    }
    else if(head->next == head){
        head = NULL;
        free(temp);
    }
    else{
        while(temp1->next != head)
            temp1 = temp1->next;

        while(temp->next != temp1)
            temp = temp->next;
		temp1->next = NULL;
		temp->next = head;
		free(temp1);
		temp1 = NULL;
    }
}

	
	void traverse(){
	struct node *temp = head;
	if(head == NULL)
		printf("no elements in the list\n");
	else{
		do{
			printf("\t%d",temp->data);
			temp = temp->next;
			}while(temp!= head);
		}
	}