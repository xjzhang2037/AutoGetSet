#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Auto Getter and Setter Program  */
/* @author Xin Zhang               */

/* Function Prototypes */
void defaultMsg();

/* Usage [flags] -[type] [arg1] [arg2] ... [argn] */
int main(int argc , char* argv[]){
	char type[81];		/* Type of argument */
	int idx;		/* Variable for loops */
	int wMod = 0;
	int wGet = 0;
	int wSet = 0;

	if( argc < 4 )	/* It will only be a valid command if there are at least 4 arguments */
		defaultMsg();

	/* The argv[1] should be flags. If so, set properly */
	if( argv[1][0] == '-' ){
		for( idx = 1 ; idx < strlen(argv[1]) ; idx++ ){
			switch( argv[1][idx] ){
				case 'm' : wMod = 1;	break;
				case 'g' : wGet = 1;	break;
				case 's' : wSet = 1;	break;
				default  : printf("Improper Usage\n");
				           defaultMsg();
		}}
	} else {
		printf("Improper Usage\n");
		defaultMsg();
	}

	for( idx = 2 ; 	idx < argc ; idx++ ){

		if( argv[idx][0] == '-' ){
			strncpy( type , argv[idx] + sizeof(char) , 80 ); /* We don't want the dash. */
			continue;
		}

		if( wMod )
			printf("\n/** Modifies %s with the argument passed in **/\nvoid mod_%s( %s mod ){ \n\t%s += mod;\n}\n",argv[idx],argv[idx],type,argv[idx]);
		if( wSet )
			printf("\n/** Sets %s with the argument passed in **/\nvoid set_%s( %s set ){ \n\t%s = set;\n}\n",argv[idx],argv[idx],type,argv[idx]);
		if( wGet )
			printf("\n/** Gets %s **/\n%s get_%s(){ \n\t return %s;\n}\n",argv[idx],type,argv[idx],argv[idx]);
	}

    return 0;
}

void defaultMsg(){
		printf("Automatically prints getters / setters / modifiers for arguments to the terminal.\nUsage: mkgset -[flags] -[type] [arg1] [arg2] ... [argn]\nWhere type is the object to return or set as char[80].\n\nFlags:\n\tm : Makes a modifier for the argument. arg += mod\n\tg : Makes a getter for the argument\n\ts : Makes a setter for the argument. Note: You will have to replace return type manually.\n");
		exit(1);
}
