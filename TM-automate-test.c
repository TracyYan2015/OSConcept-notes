#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nlist.h"

#define RIGHT 'r'
#define LEFT 'l'
#define EMPTY 'n'

typedef char State;
typedef char Code; // 带上符

/* hashtable structure to store transition relationship */
struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* state has the form of q0, q1, etc */
/* for q0 returns A, q1 returns B, etc */
char state_transform(const State* state)
{
	return 'A' + state[1] - '0';
}

/* reversal function of state_transform */
void state_rtransform(State *state, char cap_state)
{
	*state = 'q';
	*(state + 1) = '0'+cap_state-'A';
	*(state + 2) = '\0';
}

/* transform the input from command */
void get_input(int argc, char *args[], char codes[])
{
	int idx = 0;
	for (int i = 1; i < argc; ++i, idx++)
	{
		Code *p_code = *(args+i);
		size_t len = strlen(p_code);
		if(len > 1)
		{
			/* transform the state*/
			codes[idx] = state_transform(p_code);
		}
		else if(len == 1)
		{
			/* copy the code(带上符) into codes */
			codes[idx] = p_code[0];
		}
		else
		{
			printf("invalid input from command. \n");
			exit(1);
		}
	}
	codes[idx] = '\0';
}

void _parse(Code codes[], int codes_cnt, State cur_state, Code cur_code)
{

}

void parse(Code codes[], int codes_cnt, int state_idx)
{
	State cur_state = codes[state_idx];
	Code cur_code = codes[state_idx + 1];

	char *result = malloc(sizeof(char) * 2);
	// transition_map(cur_state, cur_code, result);
}

void get_transition_input(FILE *fp)
{
	char buffer[10];
	while(fgets(buffer, 10, fp) != NULL)
	{
		// printf("%s", buffer);
		char key[4];
		char value[5];
		memcpy(key, buffer, 3);
		key[3]='\0';
		memcpy(value, buffer+4, 4);
		value[4] = '\0';

		/* push the key-value pair into nlist */
		install(key, value);
	}
}

void file_input_test(FILE *fp)
{
	if(fp == NULL)
	{
		printf("cannot open file for automata transition input\n");
		exit(1);
	}
	char buffer[10];
	while(fgets(buffer, 10, fp) != NULL)
	{
		printf("%s", buffer);
	}
}

int main(int argc, char *args[])
{
	printf("%d\n", argc);
	for (int i = 0; i < argc; ++i)
	{
		printf("%s\n", args[i]);
	}
	
	/* 带上符数组 */
	char *codes = malloc(sizeof(char) * (argc-1) + 1);
	get_input(argc, args, codes);
	printf("%s\n", codes);

	FILE *fp;
	fp = fopen("./automata-transition-data.txt", "r");
	if(fp == NULL)
	{
		printf("cannot open file for automata transition input\n");
		exit(1);
	}

	/* load transition rules into hashtab */
	get_transition_input(fp);

	run();

	exit(0);
}