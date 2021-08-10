#include<stdio.h>
#include<string.h>
int main(){
	FILE *fp;
	char ch;
	fp=fopen("file1.txt","w");
	ch=getchar();
	while(ch!='\n'){
		fputc(ch,fp);
		ch=getchar();
	}
	fclose(fp);
	return 0;
}