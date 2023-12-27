/*
 ============================================================================
 Name        : Struct_to_TXT_file.c
 Author      : Goran Vujnovic
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char Title[20];
	char Author[20];
	char Topic[20];
	int id_book;

}Books;


void main(void)
{
	const int numberBooks = 2;

	Books Library[numberBooks];


	FILE *fp = fopen("output_file.txt", "w");

	if(fp == NULL)
	{
		printf("Unable to open file for writing!\n");
	}

	else
	{
		strcpy(Library[0].Title, "House of lights");
		strcpy(Library[0].Author, "Donato Karizi");
		strcpy(Library[0].Topic, "Triller");
		Library[0].id_book = 2021;

		strcpy(Library[1].Title, "Dust");
		strcpy(Library[1].Author, "Hugh Howey");
		strcpy(Library[1].Topic, "Science Fiction");
		Library[1].id_book = 10085;

		 int i = 0;

		 while(i < numberBooks)
		 {
			printf("Book_%d - Title: %s \t\n", i + 1, Library[i].Title);
			printf("Book_%d - Author: %s \t\n",i + 1, Library[i].Author);
			printf("Book_%d - Topic: %s \t\n", i + 1,  Library[i].Topic);
			printf("Book_%d - ID: %d \t\n", i + 1, Library[i].id_book);
			printf("================================\n");

			fprintf(fp, "Book_%d - Title: %s \t\n", i + 1, Library[i].Title);
			fprintf(fp, "Book_%d - Author: %s \t\n", i + 1,  Library[i].Author);
			fprintf(fp, "Book_%d - Topic: %s \t\n", i + 1,  Library[i].Topic);
			fprintf(fp, "Book_%d - ID: %d \t\n", i + 1, Library[i].id_book);
			fprintf(fp, "================================\n" );

			i++;
		 }

		fclose(fp);
	}

}
