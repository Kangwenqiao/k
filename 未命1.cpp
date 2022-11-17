#include <stdio.h>
int main(){
    char ch[5][20];
    int i=0;
    while(i<4){
        scanf("%s",ch[i]);
        printf("%c%c",ch[i][0],ch[i][1]);
        i++;
    }
    printf("\n");
    return 0;
}

