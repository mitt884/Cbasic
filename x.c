#include <stdio.h> 
#include <string.h>

void chuanhoa(char str[]){
    while (str[0] == ' ') strcpy(&str[0], &str[1]);
    
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' ' && str[i+1]==' '){
            strcpy( &str[i], &str[i+1]);
            i--;
        }
    }
    
    while(str[strlen(str) - 1] == ' ')
        strcpy(&str[strlen(str) -1], &str[strlen(str)]);
}

int main(){
    char str[50];

    fgets(str, sizeof(str), stdin);
    chuanhoa(str);

    return 0;
}