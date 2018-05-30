#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Revers(char *str)
{
      char tmp;
      int i=0;
      int size=0;
      for (size; str[size]!='\0'; size++);

      size--;
      while (i<=size)
      {
            tmp=str[i];
            str[i]=str[size];
            str[size]=tmp;
            size--;
            i++;
      }
}
int main()
{
    printf("Enter your text: ");
    char s[1024];
    gets(s);
    Revers(s);
    printf("%s",s);
    getchar();
    return 0;
}
