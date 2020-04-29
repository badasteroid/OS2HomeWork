#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>

int copyFile(FILE *sourcefp, char *sourcename, int mask /*0 non executable, other  executable*/){
	FILE * destfp = fopen(sourcename, "w");
	int samefiles=0;
	char c;
	/*if(existsInDir(sourcename, mask)){
		strcat(sourcename,"1");
		sourcefp = fopen(sourcename, "r");
	}
	else{
		sourcefp = fopen(sourcename,"r");
	}
	int flag=0;
	if(sourcefp){
		while(c=fgetc(sourcefp)!=EOF)
			flag=fputc(c, destfp);
	}
	if(mask){
		int mask=0777; //da rivedere
		chmod(destfp, mask);
	}
	return flag;*/
}

void isExecutable(const char *fname){
	char *tname ="~/Documents/homework/OS2HomeWork/a.txt";
	struct stat statfile;
	if(stat(tname, &statfile)<0){
		printf("fuck\n");
		perror("\nerror: \n");
	}
	else{
		printf( (statfile.st_mode & S_IXUSR) ? "x" : "-");
		
	}
	
	
}

//int existsInDir(
 
int main (int argc, char **argv){
	
	FILE *test;
	char tname[] ="a.txt";
	struct stat statfile;
	if(stat(tname, &statfile)<0){
		printf("fuck\n");
		perror("\nerror: \n");
	}
	else{
		printf( (statfile.st_mode & S_IXUSR) ? "x" : "-");
		
	}
	isExecutable(tname);
	return 0;
}
