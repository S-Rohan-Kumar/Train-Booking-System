#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

struct info
{
    char name[100];
    int age;
    char gender;
    char *seat_no;
};

int topay(int class)
{
    if (class == 1)
        return 985;
    else if (class == 2)
        return 725;
    else
        return 275;
};

int seat_ava(int class, int booked)
{
    if (booked == 0 && class == 0)
    {
        return 20;
    }
};
int ac(int class, int booked)
{
    if (class == 1)
        return 20 - booked;
    else
        return 20;
}

int sl(int class, int booked)
{
    if (class == 2)
        return 20 - booked;
    else
        return 20;
}

int ss(int class, int booked)
{
    if (class == 3)
        return 20 - booked;
    else
        return 20;
}

int pay(int value, int class)
{
    if (class == 1)
        return value * 1025;
    else if (class == 2)
        return value * 825;
    else
        return value * 325;
};

struct userdate
{
    int year;
    int month;
    int day;
};

struct info p[10];

int age(struct info *p, int i)
{
    printf("Enter the age: ");
    scanf("%d", &p[i].age);
    if (p[i].age <= 0 || p[i].age > 100)
    {
        printf(">>Invalid age entered. Please enter a valid age.\n");
        age(p, i);
    }
    else
        return p[i].age;
}
char gen(struct info *p, int i)
{
    printf("Enter gender (M for male and F for female): ");
    scanf(" %c", &p[i].gender);
    if (p[i].gender == 'M' || p[i].gender == 'F')
    {
        return p[i].gender;
    }
    else
    {
        printf(">>Invalid gender entered. Please enter 'M' or 'F'.\n");
        gen(p, i);
    }
}

int main()
{
    system("Color 70");
    struct userdate udate;
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    srand(time(NULL));
    char input[11];
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char desti, y;
    char *seats[50] = {"E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "E11", "E12", "E13", "E14", "E15", "E16", "E17", "E18", "E19", "E20", "E21", "E22", "E23", "E24", "E25", "E26", "E27", "E28", "E29", "E30"};
    int time, n, i, option, class, pass;
    int max = 1000000000;
    int min = 100000000;
    int pnr = rand() % (max - min + 1) + min;

    printf("\n\n\n===============================WELCOME===============================\n\n");

    do
    {
        printf("\n\n\n1.Book Train Ticket.\n2.Check your booking status.\n3.Exit\n");
        printf("\nWhat would you like to do: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n\nChoose M-Mysore,H-Hydrabad,C-Chennai,T-Trivandrum\n");
            printf("Enter your destination : ");
            scanf(" %c", &desti);
            y = toupper(desti);

            if (y == 'M' || y == 'H' || y == 'C' || y == 'T')
            {
                printf("Enter Journey date(YYYY-MM-DD): ");
                scanf("%d-%d-%d", &udate.year, &udate.month, &udate.day);
                printf("\n\n>>Entered date: %d-%d-%d\n", udate.year, udate.month, udate.day);

                if ((udate.year % 4 == 0 && udate.year % 100 != 0) || udate.year % 400 == 0)
                    month[1] = 29;

                if ((udate.year > 2023 && udate.year < 2030) && (udate.month >= 0 && udate.month < 13) && (udate.day > 0 && udate.day <= month[udate.month - 1]))
                {
                    int journeyDate = udate.year * 10000 + udate.month * 100 + udate.day;
                    int currentDate = (date.tm_year + 1900) * 10000 + (date.tm_mon + 1) * 100 + date.tm_mday;

                    if (journeyDate >= currentDate)
                    {
                        switch (y)
                        {
                        case 'M':
                            printf("\n>>Trains avaliable for Mysore:-\n\n");
                            printf("1.MYS VANDEBHARAT (20664) - 10 A.M (SBC) to 12 P.M (MYS)\n");
                            printf("2.RAJYA RANI EXP (20660) - 11.30 A.M (SBC) to 2 P.M (MYS)\n");
                            printf("3.WODEYAR EXPRESS (12614) - 3.15 P.M (SBC) to 5.45 P.M (MYS)\n");
                            printf("4.KAVERI EXPRESS (16021) - 4 P.M (SBC) to 6.40 P.M (MYS)\n");
                            printf("\nEnter 1,2,3,4 to choose the respective train: ");
                            scanf("%d", &time);
                            switch (time)
                            {
                            case 1:
                                printf("\n>>You have choosen MYS VANDEBHARAT (20664) - 10 A.M (SBC) to 12 P.M (MYS)\n");
                                break;
                            case 2:
                                printf("\n>>You have choosen RAJYA RANI EXP (20660) - 11.30 A.M (SBC) to 2 P.M (MYS)\n");
                                break;
                            case 3:
                                printf("\n>>You have choosen WODEYAR EXPRESS (12614) - 3.15 P.M (SBC) to 5.45 P.M (MYS)\n");
                                break;
                            case 4:
                                printf("\n>>You have choosen KAVERI EXPRESS (16021) - 4 P.M (SBC) to 6.40 P.M (MYS)\n");
                                break;
                            default:
                                printf("\n>>No train choosen\n");
                                break;
                            }
                            break;
                        case 'T':
                            printf("\n>>Trains avaliable for Trivendrum:-\n\n");
                            printf("1.KANYAKUMARI EXP (16526) - 10 A.M (SBC) to 12 P.M TRIVANDRUM CNTL\n");
                            printf("2.YPR KCVL AC EXP (22677) - 11.30 A.M (SBC) to 2 P.M TRIVANDRUM CNTL\n");
                            printf("3.KCVL GARIBRATH (12257) - 3.15 P.M (SBC) to 5.45 P.M TRIVANDRUM CNTL\n");
                            printf("4.KOCHUVELI EXP (16315) - 4 P.M (SBC) to 6.40 P.M TRIVANDRUM CNTL\n");
                            printf("\nEnter 1,2,3,4 to choose the respective train: ");
                            scanf("%d", &time);
                            switch (time)
                            {
                            case 1:
                                printf("\n>>You have choosen KANYAKUMARI EXP (16526) - 10 A.M (SBC) to 12 P.M TRIVANDRUM CNTL\n");
                                break;
                            case 2:
                                printf("\n>>You have choosen YPR KCVL AC EXP (22677) - 11.30 A.M (SBC) to 2 P.M TRIVANDRUM CNTL\n");
                                break;
                            case 3:
                                printf("\n>>You have choosen KCVL GARIBRATH (12257) - 3.15 P.M (SBC) to 5.45 P.M TRIVANDRUM CNTL\n");
                                break;
                            case 4:
                                printf("\n>>You have choosen KOCHUVELI EXP (16315) - 4 P.M (SBC) to 6.40 P.M TRIVANDRUM CNTL\n");
                                break;
                            default:
                                printf("\n>>No train choosen\n");
                                break;
                            }
                            break;
                        case 'C':
                            printf("\n>>Trains avaliable for Chennai:-\n\n");
                            printf("1.MAS VANDEBHARAT (20608) - 10 A.M (SBC) to 12 P.M MGR CHENNAI CTL\n");
                            printf("2.SANGHAMITRA EXP (12295) - 11.30 A.M (SBC) to 2 P.M MGR CHENNAI CTL\n");
                            printf("3.LALBAGH SF EXP (12608) - 3.15 P.M (SBC) to 5.45 P.M MGR CHENNAI CTL\n");
                            printf("4.CHENNAI EXPRESS (12610) - 4 P.M (SBC) to 6.40 P.M MGR CHENNAI CTL\n");
                            printf("\nEnter 1,2,3,4 to choose the respective train: ");
                            scanf("%d", &time);
                            switch (time)
                            {
                            case 1:
                                printf("\n>>You have choosen MAS VANDEBHARAT (20608) - 10 A.M (SBC) to 12 P.M MGR CHENNAI CTL\n");
                                break;
                            case 2:
                                printf("\n>>You have choosen SANGHAMITRA EXP (12295) - 11.30 A.M (SBC) to 2 P.M MGR CHENNAI CTL\n");
                                break;
                            case 3:
                                printf("\n>>You have choosen LALBAGH SF EXP (12608) - 3.15 P.M (SBC) to 5.45 P.M MGR CHENNAI CTL\n");
                                break;
                            case 4:
                                printf("\n>>You have choosen CHENNAI EXPRESS (12610) - 4 P.M (SBC) to 6.40 P.M MGR CHENNAI CTL\n");
                                break;
                            default:
                                printf("\n>>No train choosen\n");
                                break;
                            }
                            break;
                        case 'H':
                            printf("\n>>Trains avaliable for Hydrabad:-\n\n");
                            printf("1.KCG VANDE BHARAT (20704) - 10 A.M (SBC) to 12 P.M HYDERABAD DECAN\n");
                            printf("2.YPR GKP EXP (15024) - 11.30 A.M (SBC) to 2 P.M HYDERABAD DECAN\n");
                            printf("3.KACHEGUDA EXP (12786) - 3.15 P.M (SBC) to 5.45 P.M HYDERABAD DECAN\n");
                            printf("4.SC GARIB RATH (12736) - 4 P.M (SBC) to 6.40 P.M HYDERABAD DECAN\n");
                            printf("\nEnter 1,2,3,4 to choose the respective train: ");
                            scanf("%d", &time);
                            switch (time)
                            {
                            case 1:
                                printf("\n>>You have choosen KCG VANDE BHARAT (20704) - 10 A.M (SBC) to 12 P.M HYDERABAD DECAN\n");
                                break;
                            case 2:
                                printf("\n>>You have choosen YPR GKP EXP (15024) - 11.30 A.M (SBC) to 2 P.M HYDERABAD DECAN\n");
                                break;
                            case 3:
                                printf("\n>>You have choosen KACHEGUDA EXP (12786) - 3.15 P.M (SBC) to 5.45 P.M HYDERABAD DECAN\n");
                                break;
                            case 4:
                                printf("\n>>You have choosen SC GARIB RATH (12736) - 4 P.M (SBC) to 6.40 P.M HYDERABAD DECAN\n");
                                break;
                            default:
                                printf("No train choosen\n");
                                break;
                            }
                            break;
                        default:
                            printf("\n>>No trains avalaible\n");
                        }
                        if (time > 0 && time < 5)
                        {
                            printf("\n\n>>Select your class\n\n");
                            printf(">>1. AC FIRST CLASS(1A): Seats ava: %d\n>>2. SECOND Sitting(2S): Seats ava: %d\n>>3. Sleeper(SC): Seats ava: %d\n", ac(class, n), ss(class, n), sl(class, n));
                            printf("\n>>Enter your choice: ");
                            scanf(" %d", &class);
                            if (class == 1 || class == 2 || class == 3)
                            {
                                printf("\n\n>>Please mention number of passengers: ");
                                scanf("%d", &n);
                                if (n > 0 && n < 21)
                                {
                                    printf("\n\n--------Please enter passengers details-------------\n\n");
                                    pass = 0;
                                    for (int i = 1; i <= n; i++)
                                    {
                                        printf("Enter name of passenger %d: ", i);
                                        getchar();
                                        fgets(p[i].name, 100, stdin);
                                        {
                                            age(p, i);
                                            p[i].age;
                                        }

                                        {
                                            gen(p, i);
                                            p[i].gender;
                                        }
                                        pass++;
                                    }
                                    if (pass == n)
                                    {
                                        printf("\n\n------------------ Passengers details ---------------------\n\n");
                                        for (int i = 1; i <= n; i++)
                                        {
                                            printf("Passenger %d: %s", i, p[i].name);
                                            printf("   Age : %d\n", p[i].age);
                                            printf("Gender : %c\n", p[i].gender);
                                        }
                                        printf("\n-----------------Payment------------------");
                                        printf("\n\n>> Price of each ticket is : Rupees %d\n", topay(class));
                                        printf(">> Number of passengers: %d", n);
                                        printf("\n>> Total amount to be paid: Rupees %d (Inclusive of all taxes)", pay(n, class));
                                        printf("\n>> Amount Paid : Rupees %d", pay(n, class));

                                        printf("\n\n----------Your seats have been booked----------\n\n");
                                        switch (y)
                                        {
                                        case 'M':
                                            printf("\n>>Destination: Mysore\n");
                                            switch (time)
                                            {
                                            case 1:
                                                printf("\n>>Train:- MYS VANDEBHARAT (20664) - 10 A.M (SBC) to 12 P.M (MYS)\n");
                                                break;
                                            case 2:
                                                printf("\n>>Train:- RAJYA RANI EXP (20660) - 11.30 A.M (SBC) to 2 P.M (MYS)\n");
                                                break;
                                            case 3:
                                                printf("\n>>Train:- WODEYAR EXPRESS (12614) - 3.15 P.M (SBC) to 5.45 P.M (MYS)\n");
                                                break;
                                            case 4:
                                                printf("\n>>Train:- KAVERI EXPRESS (16021) - 4 P.M (SBC) to 6.40 P.M (MYS)\n");
                                                break;
                                            default:
                                                printf("\n>>No train choosen\n");
                                                break;
                                            }
                                            break;
                                        case 'T':
                                            printf("\n>>Destination: Trivandrum\n");
                                            switch (time)
                                            {
                                            case 1:
                                                printf("\n>>Train:- KANYAKUMARI EXP (16526) - 10 A.M (SBC) to 12 P.M TRIVANDRUM CNTL\n");
                                                break;
                                            case 2:
                                                printf("\n>>Train:- YPR KCVL AC EXP (22677) - 11.30 A.M (SBC) to 2 P.M TRIVANDRUM CNTL\n");
                                                break;
                                            case 3:
                                                printf("\n>>Train:- KCVL GARIBRATH (12257) - 3.15 P.M (SBC) to 5.45 P.M TRIVANDRUM CNTL\n");
                                                break;
                                            case 4:
                                                printf("\n>>Train:- KOCHUVELI EXP (16315) - 4 P.M (SBC) to 6.40 P.M TRIVANDRUM CNTL\n");
                                                break;
                                            default:
                                                printf("\n>>No train choosen\n");
                                                break;
                                            }
                                            break;
                                        case 'C':
                                            printf("\n>>Destination: Chennai\n");
                                            switch (time)
                                            {
                                            case 1:
                                                printf("\n>>Train:- MAS VANDEBHARAT (20608) - 10 A.M (SBC) to 12 P.M MGR CHENNAI CTL\n");
                                                break;
                                            case 2:
                                                printf("\n>>Train:- SANGHAMITRA EXP (12295) - 11.30 A.M (SBC) to 2 P.M MGR CHENNAI CTL\n");
                                                break;
                                            case 3:
                                                printf("\n>>Train:- LALBAGH SF EXP (12608) - 3.15 P.M (SBC) to 5.45 P.M MGR CHENNAI CTL\n");
                                                break;
                                            case 4:
                                                printf("\n>>Train:- CHENNAI EXPRESS (12610) - 4 P.M (SBC) to 6.40 P.M MGR CHENNAI CTL\n");
                                                break;
                                            default:
                                                printf("\n>>No train choosen\n");
                                                break;
                                            }
                                            break;
                                        case 'H':
                                            printf("\n>>Destination: Hydrabad\n");
                                            switch (time)
                                            {
                                            case 1:
                                                printf("\n>>Train:- KCG VANDE BHARAT (20704) - 10 A.M (SBC) to 12 P.M HYDERABAD DECAN\n");
                                                break;
                                            case 2:
                                                printf("\n>>Train:- YPR GKP EXP (15024) - 11.30 A.M (SBC) to 2 P.M HYDERABAD DECAN\n");
                                                break;
                                            case 3:
                                                printf("\n>>Train:- KACHEGUDA EXP (12786) - 3.15 P.M (SBC) to 5.45 P.M HYDERABAD DECAN\n");
                                                break;
                                            case 4:
                                                printf("\n>>Train:- SC GARIB RATH (12736) - 4 P.M (SBC) to 6.40 P.M HYDERABAD DECAN\n");
                                                break;
                                            default:
                                                printf("No train choosen\n");
                                                break;
                                            }
                                            break;
                                        default:
                                            printf("\n>>No trains avalaible\n");
                                        }

                                        printf("\n>>Jouney date : %d-%d-%d\n", udate.year, udate.month, udate.day);
                                        printf("\n>>Booking Date: %d-%d-%d\n", date.tm_year + 1900, date.tm_mon + 1, date.tm_mday);
                                        printf("\n>>Quota:  GENERAL(GN)\n");

                                        int initialNo = rand() % 10;
                                        for (i = 1; i <= n; i++)
                                        {
                                            p[i].seat_no = seats[(++initialNo)];
                                        }

                                        switch (class)
                                        {
                                        case 1:
                                            printf("\n>>Class : AC FIRST CLASS(1A)\n");
                                            break;
                                        case 2:
                                            printf("\n>>Class : SECOND Sitting(2S)\n");
                                            break;
                                        case 3:
                                            printf("\n>>Class : Sleeper(SC)\n");
                                            break;
                                        default:
                                            printf("\n>>No class choosen\n");
                                        }
                                        printf("\n>>Your tickets have been generted and your P N R and seat numbers are:- \n");
                                        printf("\nP N R - %d\n\n", pnr);
                                        printf("\n>> Passengers details --------------------------------------\n");
                                        printf("\n\n#   Name\t    Age\t    Gender \tSeat No");
                                        printf("\n\n---------------------------------------------------\n");
                                        for (i = 1; i <= n; i++)
                                        {
                                            printf("\n\n%d %s \t\t    %d \t\t%c\t  %s", i, p[i].name, p[i].age, p[i].gender, p[i].seat_no);
                                            printf("\n\n---------------------------------------------------\n");
                                        }
                                    }
                                    else
                                        printf("\n\n>>Please enter correct passengers detalis\n\n");
                                }
                                else
                                    printf("\n\nPlease enter correct no of passengers\n\n");
                            }

                            else
                            {
                                printf("\n\n>>Please enter correct class\n");
                            }
                        }
                        else
                        {
                            printf("\n--------------Sorry no trains available---------------\n\n\n\n");
                        }
                    }
                    else
                    {
                        printf("\n\nPlease enter correct date\n\n");
                    }
                }
                else
                {
                    printf("\n\n-----------Please enter correct date--------\n\n");
                }
            }
            else
            {
                printf("\n\n--------------Sorry no trains available---------------\n\n\n\n");
            }
            break;

        case 2:
            if (y == 'M' || y == 'H' || y == 'C' || y == 'T')
            {
                if ((udate.year > 2023 && udate.year < 2030) && (udate.month >= 0 && udate.month < 13) && (udate.day > 0 && udate.day <= month[udate.month - 1]))
                {
                    int journeyDate = udate.year * 10000 + udate.month * 100 + udate.day;
                    int currentDate = (date.tm_year + 1900) * 10000 + (date.tm_mon + 1) * 100 + date.tm_mday;
                    if (journeyDate >= currentDate)
                    {
                        if (time > 0 && time < 5)
                        {
                            if (n > 0 && n < 21)
                            {
                                if (pass == n)
                                {
                                    printf("\n\n----------Your seats have been booked----------\n\n");
                                    switch (y)
                                    {
                                    case 'M':
                                        printf("\n>>Destination: Mysore\n");
                                        switch (time)
                                        {
                                        case 1:
                                            printf("\n>>Train:- MYS VANDEBHARAT (20664) - 10 A.M (SBC) to 12 P.M (MYS)\n");
                                            break;
                                        case 2:
                                            printf("\n>>Train:- RAJYA RANI EXP (20660) - 11.30 A.M (SBC) to 2 P.M (MYS)\n");
                                            break;
                                        case 3:
                                            printf("\n>>Train:- WODEYAR EXPRESS (12614) - 3.15 P.M (SBC) to 5.45 P.M (MYS)\n");
                                            break;
                                        case 4:
                                            printf("\n>>Train:- KAVERI EXPRESS (16021) - 4 P.M (SBC) to 6.40 P.M (MYS)\n");
                                            break;
                                        default:
                                            printf("\n>>No train choosen\n");
                                            break;
                                        }
                                        break;
                                    case 'T':
                                        printf("\n>>Destination: Trivandrum\n");
                                        switch (time)
                                        {
                                        case 1:
                                            printf("\n>>Train:- KANYAKUMARI EXP (16526) - 10 A.M (SBC) to 12 P.M TRIVANDRUM CNTL\n");
                                            break;
                                        case 2:
                                            printf("\n>>Train:- YPR KCVL AC EXP (22677) - 11.30 A.M (SBC) to 2 P.M TRIVANDRUM CNTL\n");
                                            break;
                                        case 3:
                                            printf("\n>>Train:- KCVL GARIBRATH (12257) - 3.15 P.M (SBC) to 5.45 P.M TRIVANDRUM CNTL\n");
                                            break;
                                        case 4:
                                            printf("\n>>Train:- KOCHUVELI EXP (16315) - 4 P.M (SBC) to 6.40 P.M TRIVANDRUM CNTL\n");
                                            break;
                                        default:
                                            printf("\n>>No train choosen\n");
                                            break;
                                        }
                                        break;
                                    case 'C':
                                        printf("\n>>Destination: Chennai\n");
                                        switch (time)
                                        {
                                        case 1:
                                            printf("\n>>Train:- MAS VANDEBHARAT (20608) - 10 A.M (SBC) to 12 P.M MGR CHENNAI CTL\n");
                                            break;
                                        case 2:
                                            printf("\n>>Train:- SANGHAMITRA EXP (12295) - 11.30 A.M (SBC) to 2 P.M MGR CHENNAI CTL\n");
                                            break;
                                        case 3:
                                            printf("\n>>Train:- LALBAGH SF EXP (12608) - 3.15 P.M (SBC) to 5.45 P.M MGR CHENNAI CTL\n");
                                            break;
                                        case 4:
                                            printf("\n>>Train:- CHENNAI EXPRESS (12610) - 4 P.M (SBC) to 6.40 P.M MGR CHENNAI CTL\n");
                                            break;
                                        default:
                                            printf("\n>>No train choosen\n");
                                            break;
                                        }
                                        break;
                                    case 'H':
                                        printf("\n>>Destination: Hydrabad\n");
                                        switch (time)
                                        {
                                        case 1:
                                            printf("\n>>Train:- KCG VANDE BHARAT (20704) - 10 A.M (SBC) to 12 P.M HYDERABAD DECAN\n");
                                            break;
                                        case 2:
                                            printf("\n>>Train:- YPR GKP EXP (15024) - 11.30 A.M (SBC) to 2 P.M HYDERABAD DECAN\n");
                                            break;
                                        case 3:
                                            printf("\n>>Train:- KACHEGUDA EXP (12786) - 3.15 P.M (SBC) to 5.45 P.M HYDERABAD DECAN\n");
                                            break;
                                        case 4:
                                            printf("\n>>Train:- SC GARIB RATH (12736) - 4 P.M (SBC) to 6.40 P.M HYDERABAD DECAN\n");
                                            break;
                                        default:
                                            printf("No train choosen\n");
                                            break;
                                        }
                                        break;
                                    default:
                                        printf("\n>>No trains avalaible\n");
                                    }
                                    printf("\n>>Jouney date : %d-%d-%d\n", udate.year, udate.month, udate.day);
                                    printf("\n>>Booking Date: %d-%d-%d\n", date.tm_year + 1900, date.tm_mon + 1, date.tm_mday);
                                    printf("\n>>Quota:  GENERAL(GN)\n");
                                    switch (class)
                                    {
                                    case 1:
                                        printf("\n>>Class : AC FIRST CLASS(1A)\n");
                                        break;
                                    case 2:
                                        printf("\n>>Class : SECOND Sitting(2S)\n");
                                        break;
                                    case 3:
                                        printf("\n>>Class : Sleeper(SC)\n");
                                        break;
                                    default:
                                        printf("\n>>No class choosen\n");
                                    }
                                    printf("\n>>Your tickets have been generted and your P N R and seat numbers are:- \n");
                                    printf("\nP N R - %d\n\n", pnr);
                                    printf("\n>> Passengers details --------------------------------------\n");
                                    printf("\n\n#   Name\t    Age\t    Gender \tSeat No");
                                    printf("\n\n---------------------------------------------------\n");
                                    for (i = 1; i <= n; i++)
                                    {
                                        printf("\n\n%d. %s \t\t    %d \t\t%c\t  %s", i, p[i].name, p[i].age, p[i].gender, p[i].seat_no);
                                        printf("\n\n---------------------------------------------------\n");
                                    }
                                }
                                else
                                    printf("\n\n>>Please Book Ticket First\n\n");
                            }
                            else
                                printf("\n\n>>Please Book Ticket First\n\n");
                        }
                        else
                            printf("\n\n>>Please Book Ticket First\n\n");
                    }
                    else
                        printf("\n\n>>Please Book Ticket First\n\n");
                }
                else
                    printf("\n\n>>Please Book Ticket First\n\n");
            }
            else
                printf("\n\n>>Please Book Ticket First\n\n");
            break;
        case 3:
            printf("\n======================THANK YOU======================\n\n\n");
            break;
        default:
            printf("\n\n>>Please enter correct option\n\n");
        }

    } while (option != 3);

    return 0;
}