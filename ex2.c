#include<stdio.h>

int main()
{
//	display a prompt for the file name
	int number_count = 0;
	char filename[20];
	puts("Please provide filename:\n");
	scanf("%[^\n]s", filename);
	printf("Filename: %s", filename);
	FILE *in_file = fopen(filename, "r");
	char num = getc(in_file);
	int interger_array[100];
	while(num != EOF) {
		putchar(num);
		num = getc(in_file);
		if (num != '\n')
			interger_array[number_count] = atoi(num);
		number_count++;
	}
	//fclose();

//	read in the file name
//	try to open the file
//	if the file fails to open
//		print an error message on the screen and exit
//	fi
//	while we can read an int from the file
//		insert the int into the array
//	elihw
//	close the file
//	makeheap()
//	for i = 1 to 5
//		print the ith element of the heap
//	rof
//End main
}

