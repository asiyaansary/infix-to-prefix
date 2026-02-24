#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*createnode(int data){
	struct node* n=malloc(sizeof(struct node));
	n->data=data;
	n->next=NULL;
	return n;
}
void insertatfirst(struct node** h,int d){
	struct node*n=createnode(d);
	n->next=*h;
	*h=n;
}
void insertatend(struct node** h,int d){
        struct node*n=createnode(d);
	if(!*h){
        *h=n;
	return;
	}
	struct node*t=*h;
	while(t->next)t=t->next;
	t->next=n;
}
void insertatposition(struct node**h,int d,int p){
	struct node* n=createnode(d);
	if(p==0){
		insertatfirst(h,d);
		return;
	}
	struct node*t=*h;
	for(int i=0;t&&i<p-1;i++)t=t->next;
	if(!t){
		printf("out\n");
		free(n);
		return;
	}
	n->next=t->next;
	t->next=n;
}
void deletefromfirst(struct node** h){
	if(!*h){
	printf("Empty\n");
	return;
	}
	struct node*t=*h;
	*h=t->next;
	free(t);
}
void deletefromend(struct node**h){
	if(!*h){
		printf("Empty\n");
		return;
	}
	struct node*t=*h;
	if(!t->next){
		free(t);
		*h=NULL;
		return;
	}
	while(t->next->next) t=t->next;
	free(t->next);
	t->next=NULL;
}
void deleteatposition(struct node**h,int p){
	if(!*h){
		printf("Empty\n");
		return;
	}
	if(p==0){
		deletefromfirst(h);
		return;
	}
	struct node* t=*h;
	for(int i=0;t&&i<p-1;i++)t=t->next;
	if(!t||!t->next){
		printf("Out\n");
		return;
	}
	struct node* n=t->next->next;
	free(t->next);
	t->next=n;
}
void print(struct node*h){
	while(h){
		printf("%d->",h->data);
		h=h->next;
	}
	printf("NULL\n");
}
int main(){
	struct node*head=NULL;
	int choice,data,pos;
	while(1){
		printf("\n1.Insert First \n2.Insert End \n3.Insert Pos \n4.Delete First \n5.Delete End \n6.Delete Pos \n7.Print \n8.Exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Data:");
			scanf("%d",&data);
			insertatfirst(&head,data);
			break;
		case 2:
                        printf("Data:");
                        scanf("%d",&data);
                        insertatend(&head,data);
                        break;
		case 3:
                        printf("Data:");
                        scanf("%d",&data);
			printf("pos:");
			scanf("%d",&pos);
                        insertatposition(&head,data,pos);
                        break;
		case 4:
                       	deletefromfirst(&head);
                        break;
		case 5:
                     	deletefromend(&head);
                        break;
		case 6:
			printf("pos:");
			scanf("%d",&pos);
			deleteatposition(&head,pos);
			break;
		case 7:
			print(head);
			break;
		case 8:
			return 0;
		default:
			printf("Invalid\n");
		}
	}
}



