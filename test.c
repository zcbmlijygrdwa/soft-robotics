#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define SWAP(a,b)({a^=b;b^=a;a^=b;})

void reverse (char *s, int i, int j)
{
    while(i<j)
    {
        SWAP(s[i],s[j]); 
        i++;
        j--;
    }
}
void reverseWords(char *s) {
    int p1 = 0;
    int p2 = 0;
    int len = strlen(s);
    while(p2<len)
    {
        while(p2<len&&s[p2]==' ')
        {
            p2++;
        }
        
        p1 = p2;
        
        while(p2<len&&s[p2]!=' ')
        {
            p2++;
        }
        
        reverse(s,p1,p2-1);
    }
    reverse(s,0,len-1);
  
    //remove spaces
    p1 = 0;
    p2 = 0;
    while(p2<len)
    {
        while(s[p2]!=' ')
        {
            s[p1] = s[p2];
            p1++;
            p2++;
        }
        s[p1++] = ' ';
        while(s[p2]==' ')
        {
            p2++;
        }
    }
    s[p1-1] = '\0';
}
int main() {

    //char s[] = "the sky is blue";
    char* s = (char*)calloc(16,sizeof(char));
    s = strcpy(s,"the sky is blue");
    
    //printf("s: %s\n", s);
    reverseWords(s);
    printf("your code: %s\n", s);

    return 0;
}
