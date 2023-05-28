#include<stdio.h>
#include<string.h>

int palindrome(char str[])
{
    int n=strlen(str);
    for (int i = 0; i < n; i++)
    {
        if (str[i]!=str[n-i-1])
            return 0;
    }
    return 1;
    
};

void main()
{
    char a[100];

    printf("Enter string : ");
    scanf("%s",a);
    int res=palindrome(a);
    if (res==1)
        printf("\nThe string is palindrome.");
    else
        printf("\nThe string is not a palindrome.");
}