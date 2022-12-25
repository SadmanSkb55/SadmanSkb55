#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define C 99

struct maindata
{
    int buscount;
    int seatcount;
    int seatcountarr[C];
    int routecount;
    char route[C];
    char driver[C];
    char helper[C];
};
typedef struct maindata office;

struct distance
{
    float km[C];//kilometers;
    float costperkm[C];//cost per kilometers;

};
typedef struct distance dst;

struct presentdate
{
    int day;
    int month;
    int year;
};
typedef struct presentdate date;

struct presentdepurturese
{
    int hours[C];
    int minutes[C];
    int depurturecount;
};
typedef struct presentdepurturese depurtures;

struct travellerinformation
{
    char Name[C];
    char phonenumber[C];
    int seatbook;
    float total;
    float discount;
    float paid;
    float change;
};
typedef struct travellerinformation traveller;

struct revenue
{
    float total;
    float target;
    float profit;
};
typedef struct revenue sumof;

void datalog
{

    office ;
    date ;//day month year
    depurtures;//hours & minutes

    int ans;

    getch();

    printf("\t\tWELCOME TO THE OFFICIAL INFORMATION REPOSITORY");
    printf("\nPlease enter the today's bus count:");
    scanf("%d",&office.buscount);
    printf("\nPlease enter the usable seat number:");
    printf("\n1.Avarage\n.2.Individually");
    scanf("%d",&ans);
    if(ans==1)
    {
        printf("Please enter avarage seat count(Usable):");
        scanf("%d",&office.seatcount);
    }
    else if(ans==2)
    {
        office.seatcount=0;
        for(int i=0; i<=office.buscount; i++)
        {
            printf("Please enter %d no. seat count (Usable) :",i);
            scanf("%d",&office.seatcountarr[i]);
            office.seatcount+=office.seatcountarr[i];
        }
    }
    else
        printf("Invalid data input\a");
//how to get back to if(ans==1)

    printf("\nPlease enter presnet day date :DD/MM/YY :");
    scanf("%d%d%d",&date.day,&date.month,&date.year);

    printf("\nPlease enter route numbers :");
    scanf("%d",&office.routecount);

    for(int j=0; j<=office.routecount; j++)
    {
        getch();

        printf("\nPlease enter the %d no. route info:",j);
        gets(office.route[j]);
        printf("\nPlease enter the depurture time for this route :");
        scanf("%d%d",&depurtures.hours[j],&depurtures.minutes[j]);
        printf("\nPlease enter the size of route in kilometers :");
        scanf("%f",&dst.km[j]);
        printf("\nPlease enter the cost per kilometers :");
        scanf("%f",&dst.costperkm[j]);
        printf("\nPlease enter bus driver name for this route:");
        gets(office.driver[j]);
        printf("\nPlease enter bus helper/supervisor name :");
        gets(office.helper[j]);
    }

    printf("\t\tOperation Compleated Succesfully!!!");
    printf("\t\t\nThanks for having patients & providing informations");
    printf("\t\t\nTicketing starting soon");
    //loading animation type thing
    travellerinfo(office,date,depurtures,dst);
}

void travellerinfo(office,date,depurtures,dst)//busdata,date,depurture time log
{
    traveller;
    int ans2,ans3;
    float totalam;
    float pamt;
    float camt;
    float disc;//discount;
    int st;//seats taken;
    int stx;

    printf("\t\t\t======WELCOME======");
    printf("\n\n\t\t===Please provide necessary informations below===");
    int str=0;
    while(int k<=office.buscount)
    {
jump:
        str+=st;
        for(int l=0; l<=office.seatcount-str; l++)
        {
            printf("\n\t\tPlease enter passenger's full name:");
            gets(traveller.Name);
            printf("\n\t\tPlease enter passenger's phone number :");
            gets(traveller.phonenumber);
            printf("\nPlease enter Destination route:");
            printf("\nAvailable routes:");
            for(int y=0; y<=office.routecount; y++)
            {
                printf("\n%d :%s",k,office.route[y]);
            }
            scanf("%d",&ans2);
            printf("\nAvailable seats :%d",office.seatcountarr[ans2]);
            if(office.seatcountarr[ans2]==0)
            {
                printf("\nNo seats available for this bus,sorry");
goto:
                jump;
            }
            int tick=ans2;
            printf("\n Please enter the amount of seats passenger wants:");
            scanf("%d",&st);
            office.seatcountarr[ans2]=office.seatcountarr[ans2]-st;

            totalam=0;
            totalam+=st*(dst.km[ans2]*dst.costperkm[ans2]);
            printf("\nTotal cost:\t\t\t%f",totalam);
            printf("\nDiscount:");
            scanf("%f",&disc);
            totalam=totalam-(totalam*(disc/100));
            printf("\nPaid amount:");
            scanf("%f",&pamt);
            camt=pamt-totalam;
            printf("%f",&camt);
            if(totalam>0)
            {
                printf("\nPrint invoice?\n1.Yes\n2.No");
                scanf("%d",&ans3);
                if(ans3==1)
                {
jump:
                    printinvoice(traveller.Name,traveller.phonenumber,office.route[l],st,tick,totalam,pamt,camt);
                    officecopy(traveller.name,traveller.phonenumber,office.route[l],totalam);
                    revenueatrip(totalam);
                }
                else if(ans3==2)
                {
                    printf("\nThanks for your patience");
                    printinvoice(traveller.name,traveller.phonenumber,office.route[l],totalam,pamt,camt);
                    officecopy(traveller.name,traveller.phonenumber,office.route[l],totalam);
                }
                else
                {
                    printf("\n\t\tInvalid input\a");
goto:
                    jump;
                }
            }
        }
        k++;
    }
    void printinvoice()
    {
        int ans4;
jump:
        printf("\n\t\t\t====Ticket====");
        printf("\n\n\n\t\tPlease keep this ticket with you till arrival");
        printf("\n\n\t\t\tBasic information");
        printf("\n\nNAME\t\t\t :%s",traveller.Name);
        printf("\n\nPHONE NO.\t\t\t :%s",traveller.phonenumber);
        printf("\n\n=======================================================");
        printf("\n\n\t\t\t====DESTINATION====");
        printf("\n\n\t\t\t****%s****",office.route[a]);
        printf("\n\nDATE\t\t\t(DD/MM/YY) :%d/%d/%d",date.day,date.month,date,year);
        printf("\n\n\t\t\t====DEPURTURE====");
        printf("\n\n\t\t\t****%d:%d****",depurtures.hours[a],depurtures.minutes[a]);
        printf("\n\nSEATS HIRED\t\t\t : %d",str);
        printf("\n\n=======================================================");
        printf("\n\nTOTAL AMOUNT\t\t\t : %f",totalam);
        printf("\n\nPAID AMOUNT\t\t\t : %f",pamt);
        printf("\n\nPAID AMOUNT\t\t\t : %f",camt);
        printf("\n\n=======================================================");
        printf("\n\nSTATUS\t\t\t : PAID");
        printf("\n\n*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+");
        printf("\n\n\t\t\THAVE A SAFE JOURNEY");
        printf("\n\nExecution compleated,confirm printing :\n1.Print & continue \n2.Print & finish \n3.Undo & Redo information");
        scanf("%d",&ans4);
        if(ans4==1)
        {
            printf("\n\t\tPrinted Succesfully");
            printf("\n\t\tPress any key to Continue");
            scanf("%c",&inv);
goto:
            travellerinfo();
        }
        else if(ans4==2)
        {
            printf("\n\t\tPrinted Succesfully");
            printf("\n\t\tPress any key to Continue");
            scanf("%c",&inv);
goto:
            revenueatrip();
        }
        else if(ans4==3)
        {
goto:
            travellerinfo;
        }
        else
        {
            printf("\n\t\t\tInvalid Input\a");
goto:
            jump;
        }
    }
    void revenueatrip()
    {
        float sum=0;
        sum+=totalam;
        float cmpamt=0,cmpamt2=0,tgtamt1=0,tgtamt2=0;
        for(int w=0;w<=office.buscount;w++){
            tgtamt2=(office.seatcountarr[w])*(dst.costperkm[w])*(dst.km[w]);
            tgtamt1+=tgtamt2;
        }
        cmpamt=tgtamt1-sum;
        printf("\nTarget amount was\t\t :tgtamt1 \nIncome \t\t\t :cmpat");

    }
    void officecopy() {}
    int main()
    {
        datalog();
    }
