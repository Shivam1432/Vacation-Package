#include <stdio.h>
#include <stdlib.h>
struct Date
{
    int d, m, y;
};
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int countLeapYears(struct Date d)
{
    int years = d.y;
    if (d.m <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}
int getDifference(struct Date dt1,struct Date dt2)
{
    long int n1 = dt1.y*365 + dt1.d;
    int i;
    for (i=0; i<dt1.m - 1; i++)
        n1 += monthDays[i];
    n1 += countLeapYears(dt1);
    long int n2 = dt2.y*365 + dt2.d;
    for (i=0; i<dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
    return (n2 - n1);
}
int india(int t);
int international(int t);
int rail(int t);
int air(int t);
int main()
{
    printf("\t\t\t\t\t\t\t\t*************\n");
    printf("\t\t\t\t\t\t\t\tT R A V E L     C O N N E C T I O N\n\n\n");
    int t,a,c,date1,date2,month1,month2,year1,year2;
    int r,sub_rate1,sub_rate2,sub_rate3,sub,total;
    printf("Enter number of total members: \n");
    scanf("%d",&t);
    printf("\nEnter number of adults: \n");
    scanf("%d",&a);
    printf("\nFrom date (dd mm yyyy): \n");
    scanf("%d %d %d",&date1,&month1,&year1);
    printf("\nTo date(dd mm yyyy): \n");
    scanf("%d %d %d",&date2,&month2,&year2);
    struct Date dt1,dt2;
    dt1.d=date1;
    dt2.d=date2;
    dt1.m=month1;
    dt2.m=month2;
    dt1.y=year1;
    dt2.y=year2;
    r=getDifference(dt1,dt2);
    c=t-a;
    int des;
    int ticket_rate;
    printf("\nAre you looking for domestic(1) or international(2) destination?: \n");
    scanf("%d",&des);
    switch(des)
    {
        case 1:
            ticket_rate=india(t);
            break;
        case 2:
            ticket_rate=international(t);
            break;
    }
    int rooms=0,ren;
    while(t>=2)
    {
        if((t%2)==0)
        {
            rooms++;
        }
        else
        {
            rooms++;
        }
        t=t-2;
    }
    if(t>0)
    {
        rooms++;
    }
    printf("\n\nRooms booked:%d",rooms);
    printf("\nEnter your budget(rent per room fixed for 1-3 days):\n*\tUnder 10000(1)\n*\t10000-20000(2)\n*\t20000-30000(3)\n*\t30000-40000(4)\n*\t40000-50000(5)\n*\t50000-60000(6)\n*\tAbove 600000(7)\n");
    scanf("%d",&ren);
    switch(ren)
    {
    case 1:
        printf("\nWe can find a 3 star hotel according to your selected price range.");
        sub_rate1=5000*rooms;
        if(r>=4 && r<=10)
        {
        while(r!=3)
        {
            sub_rate1+=750;
            r--;
        }
        }
        if(r>10)
        {
        while(r!=10)
        {
            sub_rate1+=1000;
            r--;
        }
        }
        break;
    case 2:
        printf("\nWe can find a 3 or a 4 star hotel according to your selected price range.");
        sub_rate1=7500*rooms;
        if(r>=4 && r<=10)
        {
        while(r!=3)
        {
            sub_rate1+=1000;
            r--;
        }
        }
        if(r>10)
        {
        while(r!=10)
        {
            sub_rate1+=1500;
            r--;
        }
        }
        break;
    case 3:
        printf("\nWe can find a 3 or a 4 star hotel according to your selected price range.");
        sub_rate1=12500*rooms;
        if(r>=4 && r<=10)
        {
           while(r!=3)
           {
                sub_rate1+=1250;
                r--;
           }
        }
        if(r>10)
        {
            while(r!=10)
            {
                sub_rate1+=1500;
                r--;
            }
        }
        break;
    case 4:
        printf("\nWe can find a 4 star hotel according to your selected price range.");
        sub_rate1=15000*rooms;
        if(r>=4 && r<=10)
        {
        while(r!=3)
        {
            sub_rate1+=1500;
            r--;
        }
        }
        if(r>10)
        {
        while(r!=10)
        {
            sub_rate1+=2000;
            r--;
        }
        }
        break;
    case 5:
        printf("\nWe can find a 4 or a 5 star hotel according to your selected price range.");
        sub_rate1=17500*rooms;
        if(r>=4 && r<=10)
        {
        while(r!=3)
        {
            sub_rate1+=1750;
            r--;
        }
        }
        if(r>10)
        {
        while(r!=10)
        {
            sub_rate1+=2500;
            r--;
        }
        }
        break;
    case 6:
        printf("\nWe can find a 5 star hotel according to your selected price range.");
        sub_rate1=20000*rooms;
        if(r>=4 && r<=10)
        {
        while(r!=3)
        {
            sub_rate1+=2000;
            r--;
        }
        }
        if(r>10)
        {
        while(r!=10)
        {
            sub_rate1+=3000;
            r--;
        }
        }
        break;
    case 7:
        printf("\nWe can find a 5+ star hotel according to your selected price range.");
        sub_rate1=22500*rooms;
        if(r>=4 && r<=10)
        {
        while(r!=3)
        {
            sub_rate1+=2500;
            r--;
        }
        }
        if(r>10)
        {
        while(r!=10)
        {
            sub_rate1+=3500;
            r--;
        }
        }
        break;
    }
    if((month1==2 || month1==3 || month1==4 || month1==5 || month1==6 ||month1==7||month1==8)&& ticket_rate>=20000)
    {
        printf("\nOff season discount provided at 30 percent off.\n");
        sub=sub_rate1*(0.3);
        sub_rate1=sub_rate1-sub;
    }
    if((month1==10 || month1==11 || month1==12 || month1==1 || month1==2 ||month1==3||month1==4)&& ticket_rate<20000)
    {
        printf("\nOff season discount provided at 20 percent off.\n");
        sub=sub_rate1*(0.2);
        sub_rate1=sub_rate1-sub;
    }
    int meal;
    printf("\nEnter your meal plan:\n*\tEuropean Plan(1)\n*\tContinental Plan(2)\n*\tAmerican Plan(3)\n*\tModified American Plan(4)\n");
    scanf("%d",&meal);
    switch(meal)
    {
    case 1:
        printf("\nRoom rent only.");
        sub_rate2=0;
        break;
    case 2:
        printf("\nRoom rent and breakfast included.");
        sub_rate2=350*rooms;
        break;
    case 3:
        printf("\nRoom rent and 3 meals included.");
        sub_rate2=1500*rooms;
        break;
    case 4:
        printf("\nRoom rent and breakfast + either lunch/dinner included.");
        sub_rate2=750*rooms;
        break;
    }
    while(r!=1)
    {
        sub_rate2+=sub_rate2;
        r--;
    }
    sub_rate3=sub_rate1+sub_rate2;
    int act,charge1;
    printf("\n\nWould you like to include activities(1) or not(2)?\n");
    scanf("%d",&act);
    switch(act)
    {
    case 1:
        printf("\nActivities may include adventure,nature,Hill stations,religion exploring or water activities depending upon location.\n\n");
        if(ticket_rate>=15000)
        {
            charge1=45000;
        }
        else
        {
            charge1=10000;
        }
        break;
    case 2:
        printf("\nYou have opted out of any activities.\n\n");
        charge1=0;
        break;
    }
    total=ticket_rate+sub_rate3+charge1;
    printf("\t\t\t\t\t*******************\n");
    printf("\t\t\t\t\tTOTAL   TOUR   PACKAGE   WILL   BE\t:\t%d\n",total);
    printf("\t\t\t\t\t*******************\n");
    printf("\n\t\t\t\t\t\t\t\t^_^");
    return 0;
}
int india(int t)
{
    int tic,tot;
    printf("Do you want to book a railway(1) or flight(2) ticket?\n");
    scanf("%d",&tic);
    switch(tic)
    {
        case 1:
            tot=rail(t);
            break;
        case 2:
            tot=air(t);
            break;
    }
    return tot;
}
int international(int t)
{
    int x,rate,tot_rate;
    printf("\n\nEnter your destination among our selected packages: \n");
    printf("\tEurope(1)\n\tSingapore(2)\n*\tMauritius(3)\n*\tAustralia(4)\n*\tNew Zealand(5)\n*\tThailand(6)\n*\tBali(7)\n*\tMaldives(8)\n*\tDubai(9)\n*\tHong Kong(10)\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
            printf("\nYou have selected Europe.");
            rate=44000;
            tot_rate=t*rate;
            break;
        case 2:
            printf("\nYou have selected Singapore.");
            rate=29000;
            tot_rate=t*rate;
            break;
        case 3:
            printf("\nYou have selected Mauritius.");
            rate=21000;
            tot_rate=t*rate;
            break;
        case 4:
            printf("\nYou have selected Australia.");
            rate=42000;
            tot_rate=t*rate;
            break;
        case 5:
            printf("\nYou have selected New Zealand.");
            rate=47000;
            tot_rate=t*rate;
            break;
        case 6:
            printf("\nYou have selected Thailand.");
            rate=15000;
            tot_rate=t*rate;
            break;
        case 7:
            printf("\nYou have selected Bali.");
            rate=23000;
            tot_rate=t*rate;
            break;
        case 8:
            printf("\nYou have selected Maldives.");
            rate=19000;
            tot_rate=t*rate;
            break;
        case 9:
            printf("\nYou have selected Dubai.");
            rate=17000;
            tot_rate=t*rate;
            break;
        case 10:
            printf("\nYou have selected Hong Kong.");
            rate=22000;
            tot_rate=t*rate;
            break;
    }
    int local,r1,r2,total_rate;
    printf("\nDo you want cab services for local(1) or destination(2)?\n");
    scanf("%d",&local);
    switch(local)
    {
    case 1:
        printf("\nCab services only include from airport to hotel and back.");
        r1=500+500*(t%4);
        r2=0;
        break;
    case 2:
        printf("\nCab services include ride from airport to hotel and back along with sightseeing.");
        r1=500+500*(t%4);
        r2=35000+35000*(t%4);
        break;
    }
    total_rate=tot_rate+r1+r2;
    return total_rate;
}
int rail(int t)
{
    int rate,i;
    float tot_rate=0;
    int x;
    printf("\nA railway ticket is more compatible.\n");
    printf("\nEnter your destination among our selected packages: \n");
    printf("\tManali(1)\n\tShimla(2)\n*\tUdaipur(3)\n*\tDehradun(4)\n*\tMussoorie(5): \n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
            printf("\nYou have selected Manali.");
            rate=400;
            tot_rate=rate*t;
            break;
        case 2:
            printf("\nYou have selected Shimla.");
            rate=500;
            tot_rate=rate*t;
            break;
        case 3:
            printf("\nYou have selected Udaipur.");
            rate=2000;
            tot_rate=rate*t;
            break;
        case 4:
            printf("\nYou have selected Dehradun.");
            rate=1500;
            tot_rate=rate*t;
            break;
        case 5:
            printf("\nYou have selected Mussoorie.");
            rate=1600;
            tot_rate=rate*t;
            break;
    }
    int r1,r2,local,total;
    printf("\nDo you want cab services for local(1) or destination(2)?\n");
    scanf("%d",&local);
    switch(local)
    {
    case 1:
        printf("\nCab services only include from airport to hotel and back.");
        r1=200+200*(t%4);
        r2=0;
        break;
    case 2:
        printf("\nCab services include ride from airport to hotel and back along with sightseeing.");
        r1=200+200*(t%4);
        r2=2500+2500*(t%4);
        break;
    }
    total=tot_rate+r1+r2;
    return total;
}
int air(int t)
{
    int rate,i;
    float tot_rate=0;
    int x;
    printf("\nA domestic flight ticket will be booked.\n");
    printf("\nEnter your destination among our selected packages: \n");
    printf("\tAndaman & Nicobar Islands(1)\n\tKerala(2)\n*\tNorth East(3)\n*\tGoa(4)\n*\tLeh Ladakh(5)\n*\tJammu & Kashmir(6)\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
            printf("\nYou have selected Andaman & Nicobar Islands.");
            rate=10000;
            tot_rate=rate*t;
            break;
        case 2:
            printf("\nYou have selected Kerala.");
            rate=7000;
            tot_rate=rate*t;
            break;
        case 3:
            printf("\nYou have selected North East.");
            rate=9000;
            tot_rate=rate*t;
            break;
        case 4:
            printf("\nYou have selected Goa.");
            rate=5000;
            tot_rate=rate*t;
            break;
        case 5:
            printf("\nYou have selected Leh Ladakh.");
            rate=3500;
            tot_rate=rate*t;
            break;
        case 6:
            printf("\nYou have selected Jammu & Kashmir.");
            rate=2500;
            tot_rate=rate*t;
            break;
    }
    int r1,r2,local,total;
    printf("\nDo you want cab services for local(1) or destination(2)?\n");
    scanf("%d",&local);
    switch(local)
    {
    case 1:
        printf("\nCab services only include from airport to hotel and back.");
        r1=350+350*(t%4);
        r2=0;
        break;
    case 2:
        printf("\nCab services include ride from airport to hotel and back along with sightseeing.");
        r1=350+350*(t%4);
        r2=10000+10000*(t%4);
        break;
    }
    total=tot_rate+r1+r2;
    return total;
}
