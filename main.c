#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limit.h>
/*
static void list_dir (const char * dir_name){

	DIR *d;
	
	d = opendir(dir_name);
	
	if (!d){
	
		fprintf(stderr, "cannot open dir '%s': %s\n", dir_name, strerror(errno));
		exit(EXIT_FAILURE);	
	
	}

	while(1){

		struct dirent * entry;
		const char * d_name;
	
		if(!entry)
			break;
		d_name = entry->d_name;	
	
	}

}
*/
int copyFile(FILE *sourcefp, char *sourcename, int mask /*0 non executable, other  executable*/){
	FILE * destfp = fopen(sourcename, "w");
	int samefiles=0;
	if(existsInDir(sourcename, mask)
		strcat(sourcename,"1");
		*sourcefp = fopen(sourcename, "r");
	else{
		*sourcefp = fopen(sourcename,"r");
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
	return flag;
}

*char destFolderManagement(FILE *sourcefp, char *fname){
	*sourcefp = open(
	
}

int existsInDir(
 
int main (int argc, char *argv){
	

}
