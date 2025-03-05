
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>

bool ValidateIntegerInput(int* value)
{
	char buffer[800];
	if (!fgets(buffer, sizeof(buffer), stdin))
	{
		return false;
	}
	char* endptr;
	long num = strtol(buffer, &endptr, 10); 
	if (*endptr != '\n' && *endptr != '\0') 
	{
		return false;
	}
	if (num < INT_MIN || num > INT_MAX)
	{
		return false;
	}
	*value = (int)num;
	return true;
}

void InputMatrixSize(int* n, int* m)
{
	bool validInput = false;
	while (!validInput)
	{
		printf("Введіть кількість рядків n: ");
		while (!ValidateIntegerInput(n) || *n <= 0)
		{
			printf("Некоректне значення, введіть ціле число більше 0.\n");
			printf("Введіть кількість рядків n: ");
		}

		printf("Введіть кількість стовпців m: ");
		while (!ValidateIntegerInput(m) || *m <= 0)
		{
			printf("Некоректне значення, введіть ціле число більше 0.\n");
			printf("Введіть кількість стовпців m: ");
		}

		if (*n * *m >= MAX_ARRAY_SIZE)
		{
			int choice;
			printf("Розмірність масиву перевищує %d! Продовжити? (1 - так, 2 - змінити): ", MAX_ARRAY_SIZE);
			while (!ValidateIntegerInput(&choice) || (choice != 1 && choice != 2))
			{
				printf("Некоректне значення, введіть 1 або 2.\n");
			}
			if (choice == 1)
				validInput = true;
		}
		else
		{
			validInput = true;
		}
	}
	printf("\nВи ввели розмірність масиву %d на %d\n", *n, *m);
}


int** AllocateMatrix(int n, int m)
{
	int** C = (int**)malloc(n * sizeof(int*));
	if (!C)
	{
		printf("Помилка виділення пам'яті\n");
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		C[i] = (int*)malloc(m * sizeof(int));
		if (!C[i])
		{
			printf("Помилка виділення пам'яті\n");
			for (int i = 0; i < n; i++)
			{
				free(C[i]);
			}
			free(C);
			exit(1);
		}
	}
	return C;
}

void FillMatrix(int** C, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (1)
			{
				printf("Введіть елемент масиву C[%d][%d]: ", i + 1, j + 1);
				int inputElement;
				if (!ValidateIntegerInput(&inputElement))
				{
					printf("Некоректне значення, введіть ціле число.\n");
				}
				else
				{
					bool isUnique = true;
					for (int q = 0; q < j; q++)
					{
						if (C[i][q] == inputElement)
						{
							isUnique = false;
							break;
						}
					}
					if (isUnique)
					{
						C[i][j] = inputElement;
						break;
					}
					else
					{
						printf("Елемент %d вже існує в цьому рядку. Введіть інший.\n", inputElement);
					}
				}
			}
		}
	}
}

void PrintMatrix(int** C, int n, int m, const char* message)
{
	printf("%s\n", message);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf(" %6d ", C[i][j]);
		}
		printf("\n");
	}
}

void SortRows(int** C, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			for (int k = 0; k < m - j - 1; k++)
			{
				if (C[i][k] > C[i][k + 1])
				{
					int temp = C[i][k];
					C[i][k] = C[i][k + 1];
					C[i][k + 1] = temp;
				}
			}
		}
	}
}