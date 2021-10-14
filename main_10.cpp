#include <string.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
# define MAXSEAT 50

char const* count(int cc)
{
    switch(cc)
    {
        case 1: return "Tokyo, Japan";
        case 2: return "Moscow, Russia";
        case 3: return "Singapore, Singapore";
        case 4: return "Seoul, South Korea";
        case 5: return "London, England";
        case 6: return "Sydney, Australia";
        case 7: return "Manila, Philippines";
        case 8: return "Shanghai, China";
        case 9: return "New Delhi, India";
        case 10: return "Washington,D.C., America";
        default: return "";
    }
}

char const* pilot(int a,int pt)
{
    if(pt == 1)
    {
        switch(a)
        {
            case 1: return "John";
            case 2: return "Bob";
            case 3: return "Steve";
            case 4: return "Sam";
            case 5: return "Mark";
            case 6: return "Deen";
            case 7: return "Non";
            case 8: return "Visit";
            case 9: return "Uki";
            case 10: return "Tik";
            default: return "There is only 10 planes";
        }
    }
    else if(pt == 2)
    {
        switch(a)
        {
            case 1: return "Sam";
            case 2: return "Bob";
            case 3: return "Smith";
            case 4: return "Dech";
            case 5: return "Sea";
            case 6: return "Tar";
            case 7: return "Mu";
            case 8: return "Aom";
            case 9: return "Wuth";
            case 10: return "Wave";
            default: return "There is only 10 planes";
        }
    }
    else
    {
        return "";
    }
}

    

struct Infor
{
    char* passenger[MAXSEAT];
    int passport[MAXSEAT];
}plane1;


int main()
{
    FILE*input = fopen("/Users/USER/Desktop/beforetest.txt", "r");
    FILE*output = fopen("/Users/USER/Desktop/aftertest.txt", "w");
    int choice;
    printf("**************************Welcome to Smile Airport**************************\n");
    printf("we wish the passenger will enjoy with our service\n\n");
    printf("There is 10 planes and 50 seats for each plane\n");
    for(int i=1;i<=10;i++)
        printf("1:%s\n",count(i));
    printf("\n");
    printf("_______________1.Information of airplane_______________\n");
    printf("_______________2.Reservation the seat_______________\n");
    printf("_______________3.Print bill for all the seats_______________\n");
    printf("_______________4.Clear_______________\n");
    printf("_______________5.Exit_______________\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                    int n,pt;
                    char* dd;
                    printf("1:Morning\n");
                    printf("2:Evening\n");
                    scanf("%d",&pt);
                    while(pt!=1 && pt!=2)
                    {
                        printf("Please choose only 1 or 2: ");
                        scanf("%d",&pt);
                    }
                    printf("Please select airplane number(1-10):");
                    scanf("%d",&n);
                    dd = (char*)pilot(n,pt);
                    printf("Pilot name:%s\n",dd);
                    //time
                    break;
            case 2:
                    int n,cc,re;
                    char* pass;
                    int port;
                    printf("Which airplane(1-10) you want to reserve:");
                    scanf("%d",&n);
                    //check from file
                    //show the seat
                    printf("There is %d available seat in plane %d",cc,n)
                    printf("Which seat number do you want to choose:");
                    scanf("%d",&re);
                    if(plane1.passenger[re] == "")
                    {
                        printf("Please enter your information\n");
                        ////////////////////
                        printf("Name:");
                        scanf("%s",&pass);
                        printf("Passport number:");
                        scanf("%s",&port);
                        if((port/1000000000000)<1 && (port/1000000000000)>10)
                        {
                            printf("PLEASE ENTER THE CORRECT PASSPORT NUMBER");
                            break;
                        }
                        strcpy( plane1.passenger[re], pass);
                        plane1.passport[re]=port
                        printf("Reserve successful");
                    }
                    else
                        printf("We apologist, this seat has been reserved.");
                    break;
            case 3:
                    int flight;
                    printf("Do you want to :");
            default: printf("There is only choice 1-5\n");
                    break;
        }
        printf("\n\n");
        printf("Do you want to choose other choices:");
        scanf("%d",&choice);
    }
}

//struct time
//{
    
//}arrival,departure (m,e)
//passengername and passport(Puttiphat123)
//seats
//when

//bill
//go only or go and back


//file has seat
//reserve successful 
//case2 doing about file so cc is unavailable




