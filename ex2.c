#include<stdio.h>
#include<stdlib.h>

void sift_down(int*, int, int);
void make_heap(int*, int);
int number_count = 0;
int int_array[100];

int main()
{
//	display a prompt for the file name
	char filename[20];
	puts("Please provide filename:");
	scanf("%[^\n]s", filename);
	printf("Filename entered: %s\n", filename);

//	open file with check
	FILE * in_file = fopen(filename, "r");
	if (in_file == NULL) {
		puts("Error opening file!");
		exit(EXIT_FAILURE);
	}

//	read file to array and close file
	while(fscanf(in_file, "%d\n", &int_array[number_count]) != EOF)
		number_count++;
	fclose(in_file);

	// making heap with min-heap property
	make_heap(int_array, number_count);

	for (int i = 0; i < 5; i++)
		printf("Number on line %i: %d\n", i+1, int_array[i]);

	return 0;
}
// END MAIN

void sift_down(int * arr, int n, int i)
{
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
	int temp = arr[i];
	arr[i] = arr[largest];
	arr[largest] = temp;
        sift_down(arr, n, largest);
    }
}

void make_heap(int * integer_array, int count)
{
    for (int i = count/2 - 1; i >= 0; i--)
        sift_down(integer_array, count, i);

    /*
    for (int i = count-1; i > 0; i--) {
	int temp = integer_array[0];
	integer_array[0] = integer_array[i];
	integer_array[i] = temp;
        sift_down(integer_array, i, 0);
    }
    */
}
// Reference: code hints on sifting heap from https://ide.geeksforgeeks.org/rFO7Lm
