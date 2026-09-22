#include<stdio.h>

int cmps(char s1[], char s2[]);

int main() 
{
    char name1[50];
    char name2[50];
    char name3[50];

    printf("Candidate 1: ");
    scanf("%49s", name1);

    printf("Candidate 2: ");
    scanf("%49s", name2);

    printf("Candidate 3: ");
    scanf("%49s", name3);
    
    int voters;
    printf("voters: ");
    scanf("%i",&voters);
    printf("\n");

    int v_1=0, v_2=0, v_3=0;
    char vote[50];
    for(int i=0; i<voters; i++)
    {
        printf("vote: ");
        scanf("%49s",vote);
        if(1 == cmps(vote, name1))
        {
            v_1++;
        }
        else if(1 == cmps(vote, name2))
        {
            v_2++;
        }
        else if(1 == cmps(vote, name3))
        {
            v_3++;
        }
        else
        {
            printf("INVALID VOTE");
        }
    }
    int winner=1;
    if(v_2>v_3)
    {
        if(v_2>v_1)
        {
            winner=2;
        }
        else if(v_2==v_1)
        {
            winner=4;
        }
    }
    else if(v_2<v_3)
    {
        if(v_3>v_1)
        {
            winner=3;
        }
        else if(v_3==v_1)
        {
            winner=5;
        }
    }
    else
    {
        if(v_1<v_2)
        {
            winner=6;
        }
        else if(v_1==v_2)
        {
            winner=7;
        }
    }
    switch(winner)
    {
        case 1:printf("winner is %s",name1);
              break;
        case 2:printf("winner is %s",name2);
              break;
        case 3:printf("winner is %s",name3);
              break;
        case 4:printf("winner is tied between %s and %s",name1, name2);
              break;
        case 5:printf("winner is tied between %s and %s",name1, name3);
              break;
        case 6:printf("winner is tied between %s and %s",name2, name3);
              break;
        case 7:printf("winner is tied between %s, %s and %s",name1, name2, name3);
              break;
    }
    return 0;
}



int cmps(char s1[], char s2[])
{
    for(int i = 0; ; i++)
    {
        if(s1[i] != s2[i])
        {
            return 0;
        }

        if(s1[i] == '\0')
        {
            return 1;
        }
    }
}