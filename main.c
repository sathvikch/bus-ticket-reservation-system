#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[50];
	int bus_num;
	int num_of_seats;
}pd;
void reservation(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);
void login();
int main()

{
		system("cls");
		system("COLOR 0A");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|             BUS TICKET RESERVATION            |\n");
	printf("\t\t|                    SYSTEM                     |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");
	getch();
           system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("     BUS RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Bus");
	printf("\n------------------------");
	printf("\n3>> Exit");
	printf("\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		

                           case 2: 
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}


void viewdetails(void)
{
	system("cls");
printf("---------------------------------------------------------------------------------------");
printf("\nBus.No\tName\t\t\t Destinations  \t\t Charges  \t\tTime\n");
printf("---------------------------------------------------------------------------------------");
printf("\n1001\tGodavari Express    \t Hanmkondato Maharastra       \tRs.500    \t\t9:00  AM");
printf("\n1002\t SUPER Deluxe        \tHanamkonda To Chennai       \tRs.500  \t\t12:00 PM");
printf("\n1003\t Banglore express        \tBanglore To hanamkonda   \tRs.450   \t\t1:50  PM");
  printf("\n1004\t Venkatadhri Express         \tHanamkonda To Thirupathi    \tRs.450   \t\t11:00 AM");
printf("\n1005\tShirdi Express   \tHanamkonda To Shirdi \tRs.400  \t\t7:05  AM");
printf("\n1006\t Rajdhani Express     \tHanamkonda to Delhi  \tRs.400   \t\t9:30  AM");
   printf("\n1007\tKerala Express        \t Hanamkonda  to kerala\tRs.350   \t\t1:00  PM");
  printf("\n1008\t Orissa Express       \t  Hanamkonda to Orissa      \tRs.350   \t\t4:00  PM"); 
  printf("\n1009\tKathmandu Express    \tKathmandu To Hanmkonda  \tRs.600  \t\t5:35  PM");
 printf("\n1010\tMumbai Express       \tHnamkonda To Mumbai \tRs.600   \t\t4:15  PM");

}


void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Bus<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter bus number:> ");
	start1:
	scanf("%d",&passdetails.bus_num);
	if(passdetails.bus_num>=1001 && passdetails.bus_num<=1010)
	{
		charges=charge(passdetails.bus_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float charge(int bus_num,int num_of_seats)
{

	if (bus_num==1001)
	
	{
		return(500*num_of_seats);
	}
	if (bus_num==1002)
	{
		return(500*num_of_seats);
	}
	if (bus_num==1003)
	{
		return(450*num_of_seats);
	}
	if (bus_num==1004)
	{
		return(450*num_of_seats);
	}
	if (bus_num==1005)
	{
		return(400*num_of_seats);
	}
	if (bus_num==1006)
	{
		return(400*num_of_seats);
	}
	if (bus_num==1007)
	{
		return(350*num_of_seats);
	}
	if (bus_num==1008)
	{
		return(350*num_of_seats);
	}
	if (bus_num==1009)
	{
		return(600*num_of_seats);
	}
	if (bus_num==1010)
	{
		return(600*num_of_seats);
	}
}

void printticket(char name[],int num_of_seats,int bus_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nbus Number:\t\t%d",bus_num);
	specificbus(bus_num);
	printf("\nCharges:\t\t%.2f",charges);
}


void specificbus(int bus_num)
{

	if (bus_num==1001)
	{
		printf("\nbus:\t\t\tGodavari Express ");
		printf("\nDestination:\t\t Hanamkonda to Maharastra");
		printf("\nDeparture:\t\t9am ");
	}
	if (bus_num==1002)
	{
		printf("\nbus:\t\t\tSuper Deluxe ");
		printf("\nDestination:\t\t Hanamkonda T Chennai");
		printf("\nDeparture:\t\t12pm");
	}
	if (bus_num==1003)
	{
		printf("\nbus:\t\t\t Banglore Express ");
		printf("\nDestination:\t\tHanamkonda  to Banglore");
		printf("\nDeparture:\t\t8am");
	}
	if (bus_num==1004)
	{
		printf("\nbus:\t\t\t Venkatadhri Express");
		printf("\nDestination:\t\tHanamkonda to Thirupathi");
		printf("\nDeparture:\t\t11am ");
	}
	if (bus_num==1005)
	{
		printf("\nbus:\t\t\tShirdi Express ");
		printf("\nDestination:\t\tHanamkonda to Shirdi ");
		printf("\nDeparture:\t\t7am");
	}
	if (bus_num==1006)
	{
		printf("\nbus:\t\t\tRajdhani Express");
		printf("\nDestination:\t\t Hanamkonda to Delhi ");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (bus_num==1007)
	{
		printf("\nbus:\t\t\tKerala Express");
		printf("\nDestination:\t\tHanamkonda to Kerala ");
		printf("\nDeparture:\t\t1pm ");
	}
	if (bus_num==1008)
	{
		printf("\nbus:\t\t\t Orissa Express ");
		printf("\n Destination:\t\tHanamkonda to Orissa");
		printf("\nDeparture:\t\t4pm ");
	}
	if (bus_num==1009)
	{
		printf("\nbus:\t\t\tKathmandu Express");
		printf("\nDestination:\t\tHanamkonda To Kathmandu");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (bus_num==1010)
	{
		printf("\nbus:\t\t\tMumbai Express");
		printf("\nDestination:\t\tHanamkondato Mumbai");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10];
    char pass[10];
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"RTC")==0 && strcmp(pword,"TICKET")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR  BUS RESERVATION SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}


