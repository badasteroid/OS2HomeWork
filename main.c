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

void isExecutable(FILE *sourcefp,const char *fname){
	sourcefp = fopen(fname, "r");
	struct stat *statfile;
	char mode;
	if(stat(fname, statfile)==0){
		mode_t perm = statfile->st_mode;
		mode = (perm & S_IXUSR) ? 'x' : '-';
		printf("%s is %c\n", fname, mode);
	}
	printf("fuck");
}

//int existsInDir(
 
int main (int argc, char *argv){
	
	FILE *test;
	char *tname ="/a.txt";
	isExecutable(test, tname);
	return 0;
}
