#include<stdio.h>
#include<stdlib.h>
char crypto(char c,char key){
    return (c^key);
}
int main(){
    FILE *in,*out;
    char ch,key=0xf;
    if((in=fopen("file1.txt","r"))==NULL){
        printf("error\n");
        exit(0);
    }
    if((out=fopen("file3.txt","w"))==NULL){
        printf("error\n");
        exit(0);
    }
    ch=fgetc(in);
    while(ch!=EOF){
        fputs(crypto(ch,key),out);
        putchar(ch);
        ch==fgetc(in);
    }
    fclose(in);
    fclose(out);
    return 0;
}