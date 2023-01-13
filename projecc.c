#include<stdio.h>
#include<stdlib.h>
#include"rlutil.h"
#include<time.h>

#define BUFFER_SIZE 1000
#define NR1 20

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
    printf("\t\t2 for Sign up:\n");
    scanf("%d", &var);
    switch(var){
        case 1: auth(); break;
        case 2: puts("upcoming future"); break;
    }
    
}

typedef struct userr
{
    char nume[NR1];
    char parola[NR1];
} user;

int login()
{
        FILE* f = fopen("accounts.txt","r");
        int n;
        fscanf(f,"%d",&n);
        user *v = malloc(n * sizeof(*v));
        char nume1[NR1],parola[NR1];
        int i=0;
        while(i<n)
        {
            fscanf(f,"%10s", v[i].nume);
            fscanf(f,"%10s", v[i].parola);
            i++;
        }
        printf("Name (minimum 3 characters): ");
        scanf("%10s", nume1);
        for(i=0;i<n;i++)
        if (strcmp(nume1,v[i].nume)==0)
            break;
        if(i==n)
            return 0;
        int j=i;
        printf("Password (minimum 3 characters): ");
    for(i=0; i <NR1-1;i++)
    {
        char c;
        c = getch();
        parola[i] = c;
        if ( parola[i] == '\b' && i!=0)
        {
            printf("\b \b");
            i-= 2;
            continue;
        }
        else if ( parola[i] == '\b' && i == 0)
        {
            i--;
            printf("\b \b");
            printf(" ");
            continue;
        }
        else if( parola[i] != '\r')
            printf("*");
        else
            break;
    }
    parola[i]='\0';
    if(strcmp(parola,v[j].parola) == 0)
        {
            free(v);
            return 1;
        }
    else
        {
            free(v);
            return -1;
        }
}

void auth(){
    while(login()!=1)
    {
        cls();
        printf("Wrong username or password!\n");
    } menu();
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
			search(); break;
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
    FILE* g = fopen("record.txt", "r"); 
    //n++; fseek(f,0, SEEK_SET); fprintf(f,"%d",n);
    
    int i=0, n;
	char singleline[1023]; fscanf(g,"%d",&n);
    int obs=0;
    while (!feof(g))
    {
        fgets(singleline, 1023, g);
        obs++;    
    }fprintf(f,"\n%d ", obs);
    
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
	printf("\nYour Flight Number is:\t %d", obs); //upcoming feature ;)
    fclose(f);
    
}

void read1()
{
    struct Customer s; char buffer[BUFFER_SIZE];
	FILE* g = fopen("record.txt", "r"); int i=0, n;
	char singleline[1023]; fscanf(g,"%d",&n);
	printf("Flights: ");
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf("Name\t\t| Phone Number  | Email\t\t| Adress\t | Id Number\t| From\t| To\n");
	while (!feof(g))
	{ 
	    fgets(singleline, 1023, g); 
	    printf("%s ",singleline); 
	 } 
	
	fclose(g);
}

void search()
{
    FILE *f= fopen("record.txt", "r"); int line, count=0;
    
    printf("Flight number: ");
    scanf("%d", &line);
    
    char singleline[1023]; 
    
    printf("Flight nr #%d: ", line); 
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf("Name\t\t| Phone Number  | Email\t\t| Adress\t | Id Number\t| From\t| To\n");
	while (!feof(f))
	{   
	    count++;
	    fgets(singleline, 1023, f); 
	    if (count==line+1) printf("%s ",singleline);
	     
	 } 
	
  
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
    int ogline=line;
    line++;
    
    file = fopen("record.txt", "r");
    tempfile = fopen("replace.tmp", "w+");
    
    
    count = 0; fflush(stdin);
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
            fputs(s.to,tempfile);fprintf(tempfile,"\n");
        }
        else
            fputs(buffer, tempfile);
    } fprintf(tempfile,"\b\b");
    fclose(file);
    fclose(tempfile);
    remove("record.txt");
    rename("replace.tmp", "record.txt");
    printf("\nSuccessfully updated flight #%d", ogline);
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
    int ogline=line;
    line++;
    
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
    printf("\nSuccessfully erased flight #%d", ogline);
    
}