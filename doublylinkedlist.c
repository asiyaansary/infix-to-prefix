#include<stdio.h>
#include<stdlib.h>
typedef struct node{
        int data;
        struct node*next;
	struct node*prev;
}node;
node*createnode(int data){
        node*newnode=(node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
	newnode->prev=NULL;
        return newnode;
}
void insertatbeginning(node** head,int data){
        node*newnode=createnode(data);
	if(*head==NULL){
        *head=newnode;
	return;
	}
	newnode->next=*head;
	(*head)->prev=newnode;
	*head=newnode;
}
void insertatend(node** head,int data){
        node*newnode=createnode(data);
        if(*head==NULL){
        *head=newnode;
        return;
        }
        node*temp=*head;
        while(temp->next!=NULL){
        temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}
void insertatposition(node**head,int data,int position){
        if(position<1){
                printf("Position should be>=1.\n");
                return;
        }
	if(position==1){
		insertatbeginning(head,data);
		return;
	}
	node*newnode=createnode(data);
	node*temp=*head;
	for(int i=1;temp!=NULL&&i<position-1;i++){
		temp=temp->next;
	}
	if(temp==NULL){
		printf("Position greater than the number of nodes.\n");'
		return;
	}
	newnode->next=temp->next;
	newnode->prev=temp;
	if(temp->next!=NULL){
		temp->next->prev=newnode;
	}
	temp->next=newnode;
}
void deleteatbeginning(node** head){
        if(*head==NULL){
        printf("The list is already empty.\n");
        return;
        }
        node*temp=*head;
        *head=(*head)->next;
	if(*head!=NULL){
		(*head)->prev=NULL;
	}
        free(temp);
}
void deleteatend(node**head){
        if(*head==NULL){
                printf("The list is already Empty\n");
                return;
        }
        node*temp=*head;
        if(temp->next==NULL){
                *head=NULL;
		free(temp);
                return;
        }
        while(temp->next!=NULL){
		 temp=temp->next;
	}
	temp->prev->next=NULL;
        free(temp);
        t->next=NULL;
}
void deleteatposition(node**head,int position){
        if(*head==NULL){
                printf("The list is already Empty\n");
                return;
        }
        node*temp=*head;
	if(position==1){
		deleteatbeginning(head);
		return;
	}
	for(int i=1;temp!=NULL&&i<position,i++){
		temp=temp->next;
	}
	if(temp==NULL){
		printf("Position is greater than the number of nodes.\n");
		return;
	}
	if(temp->next!=NULL){
		temp->next->prev;
	}
	if(temp->prev!=NULL){
		temp->prev->next=temp->next;
	}
	free(temp);
}
void printlistforward(node* head){
	node* temp=head;
	printf("Forward list:");
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void printlistreverse(node* head){
	node* temp=head;
	if(temp==Null){
		printf("The list is empty.\n");
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	printf("Reverse List:");
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
int main(){
        node*head=NULL;
        int choice,data,position;
        while(1){
                printf("\n1.Insert at beginning\n2.Insert at End \n3.Insert at Position \n4.Delete at beginning\n5.Delete at End \n6.Delete at Position \n7.Print Forward \n8.Print Reverse \n9.Exit\n");
		printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice){
                case 1:
                        printf("Enter Data:");
                        scanf("%d",&data);
                        insertatbeginning(&head,data);
                        break;
                case 2:
                        printf("Enter Data:");
                        scanf("%d",&data);
                        insertatend(&head,data);
                        break;
                case 3:
                        printf("Enter Data:");
                        scanf("%d",&data);
                        printf("Enter position:");
                        scanf("%d",&position);
                        insertatposition(&head,data,position);
                        break;
                case 4:
                        deleteatbeginning(&head);
                        break;
                case 5:
                        deleteatend(&head);
                        break;
                case 6:
                        printf("Enter position:");
                        scanf("%d",&position);
                        deleteatposition(&head,position);
                        break;
                case 7:
                        printListForward(head);
                        break;
                case 8:
			printListReverse(head);
                        break;
		case 9:
			exit(0);
                default:
                        printf("Invalid choice.\n");
                }
        }
	return 0;
}








