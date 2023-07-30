#include<string.h>
#include<stdio.h>
int main()
{
    char toberead[100], str[10];
    printf("Enter any 2 string:");
    gets(toberead);
    int x = strlen(toberead);
    toberead[x] = ' ';
    toberead[x+1] = '\0';
    gets(str);
    int i=0;
    char word[10];
    int wptr = 0;
    int found = 0;
    for(i = 0 ; toberead[i]!='\0' ; i++)
    {
        if(toberead[i] == ' ')
        {
            word[wptr] = '\0';
            wptr = 0;
            if(strcmp(word, str)==0)
                found ++;
        }
        else
            word[wptr++] = toberead[i];

    }
    if(found == 0)
        printf("Not found");
    else
        printf("Found %d times", found);

}
