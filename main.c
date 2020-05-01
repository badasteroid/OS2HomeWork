#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>

int copyFile(char *sourcename){
	FILE *sourcefp;
	FILE * destfp = fopen(sourcename, "w");
	int samefiles=0;
	char c;
	if(existsInDir(sourcename, mask)){
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
	if(isExecutable(sourcename)==0){
		int mask=0777; //da rivedere
		chmod(destfp, mask);
	}
	return flag;
}

int isExecutable(const char *fname){
	
	struct stat statfile;
	if(stat(fname, &statfile)<0){
		
		perror("\nerror: \n");
		return -1;
	}
	else{

		if (statfile.st_mode & S_IXUSR){
			return 0;		
		}
		else 
			return 1;	
	}
}

int searchDir(char *startingDir, int depth){
	
	if(startingDir==NULL || *startingDir=='\0')
		return -1;
	struct stat statf;
	struct dirent direntry;
	DIR *directoryname = startingDir;
	
	char *nextElement;
	if(depth>-1){
		while (direntry=opendir(startingDir)){
			--depth;
			if(stat(directoryentry->d_name, &statf)<0){
				return -1;		
			}
			else {
				if(S_ISREG(statf.st_mode))
					searchDir(directoryentry->d_name, depth); 			
				else{
					copyFile(directoryentry->d_name);
				}
			}
		
		}
	}
	return 0;
}
//int existsInDir(
 
int main (int argc, char **argv){
	
	FILE *test;
	char tname[] ="a.txt";
	struct stat statfile;
	
	isExecutable(tname);
	if(argc<2){ //3 per i processi
		printf("\nusage: %s <directory> <N for depth> <P for processes\nN=0 to scan only the current directory", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
		return searchDir(argv[1], atoi(argv[2]));

}
