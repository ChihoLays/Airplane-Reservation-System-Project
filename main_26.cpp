#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
# define MAXSEAT 50

using namespace std;

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

char const* pilot(int a,int timeset)
{
    if(timeset == 1)
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
            case 8: return "Alexander";
            case 9: return "Uki";
            case 10: return "Tik";
            default: return "There is only 10 planes";
        }
    }
    else if(timeset == 2)
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

char const* departure_time(int a,int timeset)
{
    if(timeset == 1)
    {
        switch(a)
        {
            case 1: return "08:00:00";
            case 2: return "08:30:00";
            case 3: return "05:10:00";
            case 4: return "06:50:00";
            case 5: return "07:20:00";
            case 6: return "04:05:00";
            case 7: return "09:00:00";
            case 8: return "11:45:00";
            case 9: return "10:00:00";
            case 10: return "03:30:00";
            default: return "There is only 10 planes";
        }
    }
    else if(timeset == 2)
    {
        switch(a)
        {
            case 1: return "12:30:00";
            case 2: return "15:20:00";
            case 3: return "17:25:00";
            case 4: return "19:30:00";
            case 5: return "13:00:00";
            case 6: return "16:10:00";
            case 7: return "20:50:00";
            case 8: return "14:40:00";
            case 9: return "22:40:00";
            case 10: return "18:45:00";
            default: return "There is only 10 planes";
        }
    }
    else
    {
        return "";
    }
}

char const* arrival_time(int a,int timeset)
{
    if(timeset == 1)
    {
        switch(a)
        {
            case 1: return "13:45:00";
            case 2: return "18:50:00";
            case 3: return "07:40:00";
            case 4: return "12:10:00";
            case 5: return "20:25:00";
            case 6: return "13:25:00";
            case 7: return "12:10:00";
            case 8: return "15:00:00";
            case 9: return "14:10:00";
            case 10: return "23:50:00";
            default: return "There is only 10 planes";
        }
    }
    else if(timeset == 2)
    {
        switch(a)
        {
            case 1: return "18:15:00";
            case 2: return "01:40:00(Tomorrow)";
            case 3: return "19:55:00";
            case 4: return "00:50:00(Tomorrow)";
            case 5: return "02:05:00(Tomorrow)";
            case 6: return "01:30:00(Tomorrow)";
            case 7: return "00:00:00(Tomorrow)";
            case 8: return "18:35:00";
            case 9: return "02:50:00(Tomorrow)";
            case 10: return "15:05:00(Tomorrow)";
            default: return "There is only 10 planes";
        }
    }
    else
    {
        return "";
    }
}

char const* cost(int a)
{
    switch(a)
    {
        case 1: return "7152 Baht";
        case 2: return "9670 Baht";
        case 3: return "5600 Baht";
        case 4: return "7329 Baht";
        case 5: return "16063 Baht";
        case 6: return "15847 Baht";
        case 7: return "5236 Baht";
        case 8: return "8570 Baht";
        case 9: return "9437 Baht";
        case 10: return "18039 Baht";
        default: return "Invalid information";
    }
}

struct Infor
{
    char passenger[MAXSEAT+1][30];
    char passport[MAXSEAT+1][14];
}morning[10],evening[10];


int main()
{
    FILE*input = fopen("/Users/USER/Desktop/beforetest.txt", "r");
    FILE*output = fopen("/Users/USER/Desktop/aftertest.txt", "w");
    if (input == NULL || output == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read/write privilege.\n");
        exit(0);
    }
    char c;
    char file_pass[30],file_port[14];           //1-10=morning 
    int count_pass, count_port, finish= 0;              //11-20=evening
    int seat=0;                         //seat count while reserving
    int all,plane__num = 1;
    while((c = fgetc(input)) != EOF)
    {
        if(isalpha(c))
        {
            file_pass[count_pass]=c;
            count_pass++;
        }
        else if(isdigit(c) && count_pass>0)
        {
            file_port[count_port]=c;
            count_port++;
        }
        else if(strcmp(file_pass,"morning")|| strcmp(file_pass,"evening"))
        {
            for(int i=0;i<=30;i++)
            {
                file_pass[i] = '\0';
            }
            count_pass=0;
        } 
        else if (((c == ' ' || c=='\n') && ((count_pass>0 && count_port>0) || strcmp(file_pass,"empty"))))
        {
            if(plane__num<=10)
            {
                strcpy(morning[plane__num].passenger[all],file_pass);
                strcpy(morning[plane__num].passport[all],file_port);
            }
            else
            {
                strcpy(evening[plane__num].passenger[all],file_pass);
                strcpy(evening[plane__num].passport[all],file_port);
            }
            for(int i=0;i<30;i++)
            {
                file_pass[i] = '\0';
            }
            for(int i=0;i<14;i++)
            {
                file_port[i] = '\0';
            }
            count_port=0;
            count_pass=0;
            all++;
        }
        if(all == 51)
        {
            all=1;
            plane__num++;
        }
    }
    int choice;
    char gender;
    char pass[30];
    char port[14];
    cout << "**************************Welcome to Smile Airport**************************\n";
    cout << "\t\tWe wish the passenger will enjoy with our service\n";
    cout << "\t\tWe also apologise that there is only one-ticket \n\n";
    cout << "Please enter your information" << endl;
    cout << "M or m: man" << endl;
    cout << "W or w: woman" << endl;
    cout << "Enter your gender:";
    cin >> gender;
    while(gender!='m' && gender!='M' && gender!='w' && gender!='W')
    {
        cout << "\nPlease enter the correct gender:";
        cin >> gender;
    }
    cout << "\nFirst Name:";
    fflush(stdin); // Remove trailing \n
    fgets(pass, 30, stdin);    //name
    int leave=0;
    while(leave==0)
    {
        for(int k=0;k<30;k++)
        {
            int d = (int)pass[k];
            if((d<65||d>122)||(d>90&&d<97))
            {
                cout << "Try again!" << endl;
                cout << "First Name:";
                fflush(stdin);
                fgets(pass, 30, stdin);
                break;
            }
            leave=1;
        }
    }
    cout << "ID card number:";
    fgets(port, 14, stdin);    //passport
    int error,sum,countcha = 0;     //count character
    char tab[5];
    while(error == 0)
    {
        error = 0;
        int a = strlen(port);
        if(a!=13)
        {
            cout << "invalid. Try again!" << endl;
            cout << "ID card number:";
            cin >> port;
        }
        else
        {
            int cost=0;
            for(int i=0;i<13;i++)
            {
                if(isalpha(port[i]))
                {
                    cout << "invalid. Try again!" << endl;
                    cout << "ID card number:";
                    cin >> port;
                    break;
                }
                if(i<13)
                    cost += port[i]*(13-i);
            }
            int last = 11-(cost%11);
            if(last==11)
                last=1;
            else if(last==10)
                last=0;
            if(last!=port[13])
            {
                cout << "invalid. Try again!" << endl;
                cin >> port;
                cout << "ID card number:";
                break;
            }
            error=1;
        }
    }
    if(gender=='m' || gender =='M')
        cout << "Welcome Mr." << pass << endl;
    else
        cout << "Welcome Mrs." << pass << endl;
        
    cout << "\n_______________1.Information of airplane____________________" << endl;
    cout << "_______________2.Reservation the seat_______________________" << endl; 
    cout << "_______________3.Print tickets for all the seats and bill_______________" << endl;
    cout << "_______________4.Clear_______________"<< endl;
    cout << "Enter the choice:";
    cin >> choice;
    
    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                    int n,timeset;
                    cout << "1:Morning" << endl;
                    cout << "2:Evening" << endl;
                    cin >> timeset;
                    cout << "\n";
                    while(timeset!=1 && timeset!=2)
                    {
                        cout << "Please choose only 1 or 2: ";
                        cin >> timeset;
                    }
                    for(int i=1;i<=10;i++)
                    {
                        cout << i << ":" << count(i) << endl;
                    }
                    cout << "\nPlease select airplane number(1-10):";
                    cin >> n;
                    cout << "Pilot name:\t" << pilot(n,timeset) << endl;
                    cout << "Departure time:\t" << departure_time(n,timeset) << endl;       //n is plane number
                    cout << "Arrival time:\t" << arrival_time(n,timeset) << endl;
                    break;
        /////////////////////////////done////////////////////////////////////////
            case 2: 
                    int x, reserve_seat, mor_evening,newseat;   //to reserve seat
                    cout << "Which airplane(1-10) you want to reserve:";
                    cin >> x;           //x is the plane number
                    while(0 > x >= 10)
                    {
                        cout << "invalid plane number" << endl;
                        cout << "Enter plane number that you reserve:";
                        cin >> x;
                    }
                    cout << "Enter \n1:if you want to reserve morning time " << endl;
                    cout << "2:if you want to reserve evening time" << endl;
                    cin >> mor_evening;
                    while(mor_evening != 1 && mor_evening!=2)
                    {
                        cout << "You enter an invalid number.Try again!" << endl;
                        cout << "Enter your 1: if u reserve morning or 2: if u reserve evening:";
                        cin >> mor_evening;
                    }
                    
                    if(mor_evening==1)
                    {
                        for(int i=1;i<=50;i++)
                        {
                            for(int j=1;j<=50;j++)
                            {
                                printf("%s",morning[j].passenger[i]);
                            }
                            if(strcmp(morning[x].passenger[i],"empty")==0)
                            {
                                if(i%5==0)
                                    printf("empty\n");
                                else
                                    printf("empty\t");
                                seat++;
                            }
                            else
                            {
                                if(i%5==0)
                                    printf("reserve\n");
                                else
                                    printf("reserve\t");
                            }
                        }
                    }
                    else
                        for(int i=1;i<=50;i++)
                        {
                            if(strcmp(evening[x].passenger[i],"empty")==0)
                            {
                                if(i%5==0)
                                    printf("empty\n");
                                else
                                    printf("empty\t");
                                seat++;
                            }
                            else
                            {
                                if(i%5==0)
                                    printf("reserve\n");
                                else
                                    printf("reserve\t");
                            }
                        }
                    cout << "There is " << seat << " available seat in plane" << x << endl;
                    cout << "Which seat number do you want to choose:";
                    cin >> reserve_seat;
                    if(mor_evening==1)
                    {
                        while(finish==0 && newseat==0)
                        {
                            newseat=0;
                            if(strcmp(morning[x].passenger[reserve_seat],"empty")==0)
                            {
                                strcpy(morning[x].passenger[reserve_seat], pass);
                                cout << "Reserve successful";
                                finish=1;
                            }
                            else
                            {
                                cout << "We apologist, this seat has been reserved.";
                            }
                            cout << "Enter\n1:if u want to reserve another seat" << endl;
                            cout << "2:else you want to exit this choice reserve" << endl;
                            cin >> newseat;
                            while(newseat!=1 && newseat!=2)
                            {
                                cout << "Please choose only 1 or 2: ";
                                cin >> newseat;
                            }
                            newseat=1;
                        }
                    }
                    else
                    {
                        int finish=0;
                        while(finish == 0)
                        {
                            if(strcmp(morning[x].passenger[reserve_seat],"empty")==0)
                            {
                                strcpy(morning[x].passenger[reserve_seat], pass);
                                cout << "Reserve successful";
                                finish=1;
                            }
                            else
                            {
                                cout << "We apologist, this seat has been reserved.";
                            }
                        }
                    }
                    break;
            case 3:
                    char tab[6];
                    int flightnum,seatnum,set;
                    char namee[30];
                    cout << "Enter plane number that you reserve:";
                    cin >> flightnum;
                    while(0 > flightnum >= 10)
                    {
                        cout << "invalid plane number" << endl;
                        cout << "Enter plane number that you reserve:";
                        cin >> flightnum;
                    }
                    cout << "Enter seat number that you reserve:";
                    cin >> seatnum;
                    while(0 > seatnum >= 50)
                    {
                        cout << "invalid plane number" << endl;
                        cout << "Enter seat number that you reserve:";
                        cin >> seatnum;
                    }
                    cout << "Enter your 1: if u reserve morning or 2: if u reserve evening:";
                    cin >> set;
                    while(set != 1 && set!=2)
                    {
                        cout << "You enter an invalid number.Try again!" << endl;
                        cout << "Enter your 1: if u reserve morning or 2: if u reserve evening:";
                        cin >> set;
                    }
                    cout << "Confirm your name:";
                    fflush(stdin); // Remove trailing \n
                    fgets(namee, 30, stdin);    //name
                    if(set==1)
                        if((strcmp(namee,morning[flightnum].passenger[seatnum]))!=0)
                        {
                            cout << "Name does not match with the seat that you enter";
                            continue;
                        }
                    else
                    {
                        if((strcmp(namee,evening[flightnum].passenger[seatnum]))!=0)
                        {
                            cout << "Name does not match with the seat that you enter";
                            continue;
                        }
                    }
                    for(int i=0;i<30;i++)
                    {
                        if(namee[i]!='\0')
                            countcha++;
                    }
                    if(countcha==1)
                        strcpy(tab,"\t\t\t\t\t");
                    else if(1 < countcha &&  countcha< 10)
                        strcpy(tab,"\t\t\t\t");
                    else if(10 <= countcha && countcha < 18)
                        strcpy(tab,"\t\t\t");
                    else if(18 <= countcha && countcha < 26)
                        strcpy(tab,"\t\t");
                    else if(26 <= countcha && countcha <= 30)
                        strcpy(tab,"\t");
                        
                    if(set==1)
                        cout << "Name: " << morning[flightnum].passenger[seatnum] << tab;
                    else
                        cout << "Name: " << evening[flightnum].passenger[seatnum] << tab;
                    cout << "|\tDeparture Time: \t"<<"departure_time(flightnum,set)"<<endl;
                    if(set==1)
                        cout << "ID card number: \t" << evening[flightnum].passport[seatnum];
                    else 
                        cout << "ID card number: \t" << evening[flightnum].passport[seatnum];
                    
                    cout << "\t\t|\tArrival time: \t\t" << "arrival_time(flightnum,set)" << endl;
                    cout << "From: \t\t"<<"Smile Airport"<<"\t\tTo: \t\t\t"<<"count(flightnum)"<< endl;
                    cout << "\n\t\t\t\t Cost : " << cost(flightnum) << endl;
                    break;
            case 4:
                    for(int i=1;i<=10;i++)
                    {
                        for(int j=1;j<=50;j++)
                        {
                            strcpy(morning[i].passenger[j],"empty");
                            strcpy(morning[i].passport[j],"empty");
                            strcpy(evening[i].passenger[j],"empty");
                            strcpy(evening[i].passport[j],"empty");
                        }
                    }
                    break;
            default: 
                    cout << "There is only choice 1-5" << endl;
                    break;
        }
        cout << "\n\n";
        cout << "Press 1-4 if you want to choose other choice" << endl;
        cout << "Press 5 to exit the program" << endl;
        cout << "::";
        cin >> choice;
    }
    int b=1;
    for(int i=1;i<=20;i++)
    {
        
        if(i==1)
            cout << "morning";
        else if(i==11)
            cout << "\nevening";
        cout << b << ".\n";
        for(int j=1;j<=50;j++)
        {
            if(i<=10)
            {
                if(j%5==0)
                {
                    if(strcpy(morning[i].passenger[j],"empty"))
                    {
                        cout << "empty\n";
                    }
                    else
                        cout << morning[i].passenger[j] << morning[i].passport[j] << "\n";
                }
                else
                {
                    if(strcpy(morning[i].passenger[j],"empty"))
                        cout << "empty ";
                    else
                        cout << morning[i].passenger[j] << " ";
                }
            }
            else
            {
                if(j%5==0)
                {
                    if(strcpy(evening[i].passenger[j],"empty"))
                    {
                        cout << evening[i].passenger[j] << evening[i].passport[j] << "\n";
                    }
                    else
                        cout << "empty\n";
                }
                else
                {
                    if(strcpy(evening[i].passenger[j],"empty"))
                        cout << evening[i].passenger[j] << " ";
                    else
                        cout << "empty ";
                }
            }
        }
        b++;
        if(b==11)
            b=1;
    }
}








