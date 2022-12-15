#include<stdio.h>
#include<stdlib.h>
#include"rlutil.h"
#include<time.h>

#define BUFFER_SIZE 1000
/// Book-A-Flight-Inator

void create(); 
void read1(); //aici nu ar fi mers doar read de la rlutil.h
void update();  
void delete();
void search();
void auth();
void menu();

struct Customer{
	char fname[20], lname[20], phonenumber[20], email[20], address[24], id[20], from[20], to[20], class[20];
	struct date{
		int day, month, year; double hour;
	}num;
};

enum {
    ecreate=1,
    eread=2,
    esearch=3,
    edelete=4,
    eupdate=5
};


int main()
{

    int var;
    printf("\t\t\tWelcome:\n");
    printf("\t\t1 for Log in:\n");
    printf("\t\t2 for Sign in:\n");
    scanf("%d", &var);
    switch(var){
        case 1: auth(); break;
        case 2: puts("upcoming future"); break;
    }
}

void auth(){
        FILE *f=fopen("accounts.txt", "r");
    char username[15], vfuser[15];
    char pass[9], password[9], vfpass[9];
    printf("Enter your username:\n");
    scanf("%s", username);
    printf("Enter your password (must be at least 3 characters long):\n");
    int p=0;
        do{
            password[p]=getch();
            if(password[p]!='\r'){
            printf("*");
            }
            p++;
        }while(password[p-1]!='\r');
    password[p-1]='\0';
    int n, i=0, k=0, k1=1, k2=1;
    fscanf(f, "%d",&n);
    for(i=1; i<=n; ++i)
    { k1=1; k2=1;
        fscanf(f, "%14s %8s", vfuser, vfpass);
        if(strcmp(username,vfuser)==0)
        {
            if(strcmp(password,vfpass)==0){
                printf("\n\nWelcome.Login Success!"); k=1;
            }else{
                    k1=0;
            }
        }else{
                    k2=0;
        } if(k==1) break; menu();
    }
    if (k1==0) puts("\t- User Incorrect");
    else if(k2==0) puts("\t- Wrong Password");
}

void menu ()
{   
    struct Customer s;
	int i=0; 
	time_t t;
	time(&t);
	int choice;
	
		printf("\t\t\tBook-A-Flight-Inator!\n");
		for(i=0;i<80;i++) {
			printf("-");
		} printf("\n");
		printf("\t\t *Enter your choice from the menu*:");
		printf("\n\n");
		printf(" \n \t\tEnter '1' >>to Book a flight");
		printf(" \n \t\tEnter '2' >>to View All Booked Flights");
		printf(" \n \t\tEnter '3' >>to Search For A Specific Booked Flight");
		printf(" \n \t\tEnter '4' >>to Delete a flight");
		printf(" \n \t\tEnter '5' >>to Edit Record");
		printf("\n\n\n");
		printf("\t\t%s", ctime(&t));
		
		printf("\t\tYour choice:\t"); scanf("%d",&choice);
	switch(choice){
		case ecreate:
			create(); break;
		case eread:
			read1(); break;
		case esearch:
			puts("\n\t\tSearch feature is not available at the moment"); break;
		case edelete:
			delete(); break;
		case eupdate:
			update(); break;
		default: puts("Incorrect input\n");
	} 
}

void create()
{ 
    struct Customer s;
    FILE* f = fopen("record.txt", "a+");
    printf("\nCustomer Details:");
	printf("\n-------------------------------\n");
	printf("\nFirst Name:");
	scanf("\n %20s", s.fname); 
	fputs(s.fname,f);fprintf(f,"  ");
	printf("\nSur-Name:");
	scanf("\n %20s", s.lname); 
	fputs(s.lname,f);fprintf(f,"\t");
	printf("\nPhone Number:");
	scanf("\n %20s", s.phonenumber);
	fputs(s.phonenumber,f);fprintf(f,"\t");
    printf("\nEmail:");
	scanf("\n %20s", s.email); 
	fputs(s.email,f);fprintf(f,"\t");
	printf("\nAdress:");
	scanf("\n %20s", s.address); 
	fputs(s.address,f);fprintf(f,"\t");
	printf("\nID Number:");
	scanf("\n %20s", s.id); 
	printf("\nFlight Details:");
	printf("\n-------------------------------\n");
	fputs(s.id,f);fprintf(f,"\t");
	printf("\nFrom:");
	scanf("\n %20s", s.from); 
	fputs(s.from,f);fprintf(f,"\t");
	printf("\nTo:");
	scanf("\n %20s", s.to); 
	fputs(s.to,f);fprintf(f,"\t");
	printf("\n-------------------------------\n");
	//printf("\nYour Flight Number is:\t %d", nrflght); //upcoming feature ;)
	fprintf(f,"\n");
    fclose(f);
}

void read1()
{
    struct Customer s; char buffer[BUFFER_SIZE];
	FILE* g = fopen("record.txt", "r"); int i=0;
	char singleline[1023];
	printf("Flights: ");
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf("Name\t\t| Phone Number  | Email\t\t| Adress\t | Id Number\t| From\t| To\n");
	while(fread(buffer, BUFFER_SIZE, 1, g)){ // am incercat si cu "fgets(buffer, BUFFER_SIZE , g)" dar nu afiseaza ce-i in fisier
	    fgets(singleline, 1023, g); 
	    puts(singleline); 
	 } 
	
	fclose(g);
}

void update()
{
    struct Customer s;
    FILE* file, *tempfile;
    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE]={};
    int line, count;
    
    printf("Flight number: ");
    scanf("%d", &line);
    scanf(" "); // am vazut ca mai merge si cu fpurge, dar nu stiu daca ar fi mai bine
    
    file = fopen("record.txt", "r");
    tempfile = fopen("replace.tmp", "w+");
    
    
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, file)) != NULL)
    {
        count++;
        if (count == line){
            printf("\nCustomer Details:");
            printf("\n-------------------------------\n");
            printf("\nFirst Name:");
            scanf("\n %20s", s.fname);
            fputs(s.fname,tempfile);fprintf(tempfile,"  ");
            printf("\nSur-Name:");
            scanf("\n %20s", s.lname);
            fputs(s.lname,tempfile);fprintf(tempfile,"\t");
            printf("\nPhone Number:");
            scanf("\n %20s", s.phonenumber);
            fputs(s.phonenumber,tempfile);fprintf(tempfile,"\t");
            printf("\nEmail:");
            scanf("\n %20s", s.email);
            fputs(s.email,tempfile);fprintf(tempfile,"\t");
            printf("\nAdress:");
            scanf("\n %20s", s.address); 
            fputs(s.address,tempfile);fprintf(tempfile,"\t");
            printf("\nID Number:");
            scanf("\n %20s", s.id);
            fputs(s.id,tempfile);fprintf(tempfile,"\t");
            printf("\nFrom:");
            scanf("\n %20s", s.from); 
            fputs(s.from,tempfile);fprintf(tempfile,"\t");
            printf("\nTo:");
            scanf("\n %20s", s.to); 
            fputs(s.to,tempfile);fprintf(tempfile,"\t");
        }
        else
            fputs(buffer, tempfile);
    }
    fclose(file);
    fclose(tempfile);
    remove("record.txt");
    rename("replace.tmp", "record.txt");
    printf("\nSuccessfully updated flight #%d", line);
}

void delete()
{
    struct Customer s;
    FILE* file, *tempfile;
    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE]={};
    int line, count;
    
    printf("Flight number: ");
    scanf("%d", &line);
    scanf(" ");
    
    file = fopen("record.txt", "r");
    tempfile = fopen("replace.tmp", "w+");
    
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, file)) != NULL)
    {
        count++;
        if (count == line)
            fputs(newline, tempfile);
        else
            fputs(buffer, tempfile);
    }
    fclose(file);
    fclose(tempfile);
    remove("record.txt");
    rename("replace.tmp", "record.txt");
    printf("\nSuccessfully erased flight #%d", line);
    
}