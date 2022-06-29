#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_DATA_VALUE 50
#define DATA_NUM_PER_LINE 10

void makeData(int*, int);
void printData(int*, int);
void sumofFactor(int*, int);

int main()
{
	while(1) {
	int* pArr = NULL;
	int data_num;
	srand((unsigned int)time(NULL));
	scanf("%d", &data_num);
	pArr = (int*)calloc(data_num, sizeof(int));
	makeData(pArr, data_num);
	printData(pArr, data_num);
	sumofFactor(pArr, data_num);
	free(pArr);
	
	}
	return 0;	
}

void makeData(int* pArr, int data_num)
{
	int n, i;
	int* flag = (int*)calloc(MAX_DATA_VALUE, sizeof(int));

	for (i = 0; i < data_num; i++)
	{
		n = rand() % MAX_DATA_VALUE + 1;
		while (flag[n - 1] == 1)
			n = rand() % ((MAX_DATA_VALUE + 1) - 2) + 2;   // Already used number
		flag[n - 1] = 1;
		*(pArr + i) = n;
	}
	free(flag);
}

void printData(int* pArr, int data_num)
{
	int i, count;
	printf("***** Random int data List (%d) *****\n", data_num);
	for (i = 0, count = 0; i < data_num; i++)
	{
		printf("%4d", *(pArr + i));
		count++;
		if (count % DATA_NUM_PER_LINE == 0)
			printf("\n");
	}
	printf("\n");
}

void sumofFactor(int* pArr, int data_num)
{
	int num, sum = 0, count = 0, lastNum;
	int i;
	for (i = 0; i < data_num; i++)
	{
		lastNum = pArr[i];
		num = 1;
		sum = 0;
		count = 0;
		while (num <= lastNum)
		{
			if (lastNum % num == 0)
			{
				sum += num;
				count++;
			}
			num += 1;
		}
		if (count != 2)
			printf("The sum of the factors of %d is %d\n", lastNum, sum);
		else
			printf("The number %d is prime number\n", lastNum);
	}
}
