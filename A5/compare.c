#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int compare(const char *a,const char *c)
{
    int i=0;
    char tmpa[256];
    for(i=0;a[i]!='\0';i++)
    {
        tmpa[i] = toupper(a[i]);
    }
    char *z =&tmpa;
    char tmpb[256];
    for(i=0;c[i]!='\0';i++)
    {
        tmpb[i] = toupper(c[i]);
    }
    char *x =&tmpb;
    for( ; *z == *x; ++z, ++x )
    if ( *x == '\0' )
    return 0;
    return *z - *x;
}
int main()
{
    char a[]= "HelLo woRld";
    char c[]= "HelLo wOrLd";
    if (compare(a,c)==0)
    {
        printf("Strings are equal");
    }
    else
    {
        printf("Strings aren't equal");
    }
    getchar();
    return 0;
}
