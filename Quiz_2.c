#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "btree/inc/btree.h" 


int  main(){
    char pb[]="phonebook.db ";
    BTA *book;

    char name[256],number[256],data[256];

    int rsize,choice,size=256;

    btinit();

    book=btopn(pb,0,0);
    if(book==NULL) book=btcrt(pb,0,0);

    printf("\n");
while(1){
    printf("\t  MENU\n");
    printf("\t1.Insert\n");
    printf("\t2.Find\n");
    printf("\t3.Delete\n");
    printf("\t4.Exit\n");
    printf("Your choice: ");
    scanf("%d",&choice);
    
    switch(choice){
        case 1: /* ADD */
            printf("Name: ");
            while(getchar()!='\n');
            scanf("%[^\n]%*c",name);
            printf("Number: ");
            scanf("%[^\n]%*c",number);

            if(btsel(book,name,data,size,&rsize)==0) 
                btupd(book,name,number,size);
            else btins(book,name,number,size);
        break;


      break;
        case 2: /* FIND */
            printf("Name: ");
            while(getchar()!='\n');
            scanf("%[^\n]%*c",name);
           
            if(btsel(book,name,data,size,&rsize)!=0) printf("Not found!\n");
            else{
                printf("Number: %s\n",data);
            }
        break;

        case 3: /* DELETE */
            printf("Name: ");
            while(getchar()!='\n');
            scanf("%[^\n]*c",name);
           
            if(btsel(book,name,data,size,&rsize)!=0) printf("Not found!\n");
            else btdel(book,name);
        break;

        case 4: /* EXIT */
            btcls(book);
        return 0;

        default: /* default */
        break;
    }

    printf("\n\n");
}

}