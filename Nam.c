#include<stdio.h>
#include"btree.h"
int main(){
    char pb[]="phonebook.db";
    BTint val;
    char key[50];
    //initialization
    btinit();
    BTA *book;
    int choice;
    int test;
do{
    printf("\n____________MENU____________\n");
    printf(" 1. Open A B-tree file!\n");
    printf(" 2. Add a new contact!\n");
    printf(" 3. Remove a contact!\n");
    printf(" 4. Find contact by name!\n");
    printf(" 5. Modify phone number!\n");
    printf(" 6. Quit!\n");
    printf("-> Your choice: ");
    scanf("%d%*c",&choice);
    switch(choice){
        case 1:
        //open a b-tree file
        book=btopn(pb,0,0);
        if(book==NULL)
        book=btcrt(pb,0,0);
        break;
        case 2:
        //add a new number
        printf("Enter name: ");
        gets(key);
        printf("Enter phone number: ");
        scanf("%d%*c",&val);
        binsky(book,key,val);
        printf("Added successfully!\n");
        break;
        case 3:
        //delete a number
        printf("Enter name of contact: ");
        gets(key);
        bdelky(book,key);
        printf("Removed successfully!\n");
        break;
        case 4:
        //find by name
        printf("Enter name of contact: ");
        gets(key);
        test=bfndky(book,key,&val);
        if(test==0) printf("The contact exists\n");
        else printf("The contact doesnt exist\n");
        break;
        case 5:
        //update value
        printf("Enter name of contact: ");
        gets(key);
        test=bfndky(book,key,&val);
        if(test!=0){printf("The contact doesnt exist\n");}
        else{
            printf("Enter phone number: ");
            scanf("%d%*c",&val);
            bupdky(book,key,val);
            printf("Successful!\n");
        }
        break;
        case 6:
        //close
        btcls(book);
        break;
        default:
        break;
    }
}while(choice!=6);
    return 0;
}