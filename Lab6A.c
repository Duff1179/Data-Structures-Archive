#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

void main(){
    struct node *head = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));
    struct node *four = malloc(sizeof(struct node));
    struct node *five = malloc(sizeof(struct node));
    struct node *six = malloc(sizeof(struct node));

    head->data = 1;
    two->data = 2;
    three->data = 3;

    head->next = two;
    two->next = three;
    three->next = NULL;

    struct node *temp = malloc(sizeof(struct node));
    temp = head;
    int sum = 0;
    while(temp != NULL){
        printf("Data: %d\n", temp->data);
        sum += temp->data;
        temp = temp->next;
    }   
    printf("Sum of all elements: %d\nAdding node four to the end\n", sum);
    
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }   
    temp->next = four;
    four->next = NULL;
    four->data = 4;

    temp = head;
    while(temp != NULL){
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }

    printf("Adding node five to the front\n");
    five->data = 5;
    five->next = head;
    head = five;

    temp = head;
    while(temp != NULL){
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }

    printf("Adding node six before node two (by it's data)\n");
    temp = head;
    struct node *prev = malloc(sizeof(struct node));
    while(temp->data != 2){
        prev = temp;
        temp = temp->next;
    }
    prev->next = six;
    six->data = 6;
    six->next = temp;

    temp = head;
    while(temp != NULL){
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }

    printf("Removing node three (by it's data)\n");
    temp = head;
    while(temp->data != 3){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);

    temp = head;
    while(temp != NULL){
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }

    printf("Searching for any nodes with a value of 4\n");
    temp = head;
    while(temp != NULL){
        if(temp->data == 4){
            printf("This node has a data value of 4\n");
        }
        else{
            printf("This node does not have a data value of 4 (it has %d instead)\n", temp->data);
        }
        temp = temp->next;
    }
}