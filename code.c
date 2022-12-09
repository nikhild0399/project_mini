SHRI G.S.INSTITUTE OF TECHNOLOGY AND SCIENCE
PROGRAMMING PRACTICE
Mini Project – Contact Management System
Submitted by – Nikhil Dwivedi     
Roll No-0801CS211D03
--------------------------------------------------------
Mini Project Source Code –
//allows input\output function (ie,printf(); , scanf(); , flush(); , fclose();)
#include<stdio.h>
//defines one variable type, one macro, and various functions for manipulating arrays of characters.(ie,Null; )
#include<string.h>
//information of memory allocation/freeing functions (ie,exit();)/
#include<stdlib.h>

//creating structure variables called person for general details
struct person
{
    char        name[35];
    char        address[50];
    long int    mobileNo;
    char        mail[100];
};

void menu();
void got();
void start();
void back();
void addRecord();
void listRecord();
void modifyRecord();
int main()        //starts the start function
{
    start();
    return 0;
}
void back()         //back to the menu
{
    start();
}
void start()        // starts the menu function
{
    menu();
}
void menu()          //menu Screen of phonebook
{
    system("clear");      // clear the screen
    printf("\t\t**WELCOME TO CONTACT MANAGEMENT SYSTEM*");

    printf("\n\n\t\t\t  MENU\t\t\n\n");
    printf("\t1.Add New  Contact  \t2.List Contact \t3.Modify Record \t4.Exit \n\n ");
    char temp;
    scanf("%c",&temp); //choice for option
    switch(temp)
    {
    case '1':
    addRecord();
    break;
    case '2': 
    listRecord();
    break;
    case '3':
    modifyRecord();
    break;
    case '4': 
    exit(0);
    break;
    default:
                system("clear");
                printf("\nEnter 1 to 4 only");
                printf("\n Enter any key");
                scanf("%c",&temp); 
                menu();
}
}
//function to add the records in phonebook
void addRecord()
{
        system("clear");
        FILE *f;        // Declare the file pointer
        struct person p;         // Create a structure variable of person called p
        f=fopen("project","ab+");
        printf("\n\n Enter Details to Save Record \n\n\n ");
        printf("\n Enter name: ");
        scanf("%s",p.name);
        printf("\nEnter the address: ");
        scanf("%s",p.address);
        printf("\nEnter phone no.:");
        scanf("%ld",&p.mobileNo);
        printf("\nEnter e-mail:");
        scanf("%s",p.mail);
        fwrite(&p,sizeof(p),1,f);
        fflush(stdin);
        printf("\nrecord saved");
        fclose(f);
        printf("\n\nEnter any key for exit");
     //getch();
     char temp;
     scanf("%c",&temp);
         system("clear");
         menu();
}
//function to list the records
void listRecord()
{
    struct person p;
    FILE *f;     // Declare the file pointer
    f=fopen("project","rb");        // Open the existing file phonebook.c using fopen() for reading in binary mode
    if(f==NULL)
    {
    printf("\nfile opening error in listing :");

    exit(1);
    }
    char temp;
    while(fread(&p,sizeof(p),1,f)==1)
    {
    printf("\n\n\n YOUR Saved RECORD IS\n\n ");
    printf("\nName=%s\nAdress=%s\nMobile no=%ld\nE-mail=%s",p.name,p.address,p.mobileNo,p.mail);
      scanf("%c",&temp);
      system("clear");
    }
    fclose(f);      // Closing the file using fclose()
    printf("\n Enter any key for exit ");
    scanf("%c",&temp);
    system("clear");
    menu();
}

void modifyRecord()
{
    int      c;
    char     tempr;
    FILE *f;
    int      flag=0;
    struct   person p,s;
    char     name[50];
    f=fopen("project","rb+");
    if(f==NULL)
        {

              printf("CONTACT'S DATA NOT ADDED YET.");
              exit(1);

        }
    else
    {
        system("clear");
            printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            scanf("%s",name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {

                    printf("\n Enter name:");
                    scanf("%s",s.name);
                    printf("\nEnter the address:");
                    scanf("%s",s.address);
                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mobileNo);
                    printf("\nEnter e-mail:");
                    scanf("%s",s.mail);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;

                }
                fflush(stdin);

            }
            if(flag==1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);
    }
     printf("\n Enter any key");
     scanf("%c",&tempr);
    system("clear");
    menu();

}


