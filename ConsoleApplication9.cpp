


#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <windows.h>
#include "functions.h"


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n, m;
	InputMatrixSize(&n, &m);
	int** C = AllocateMatrix(n, m);
	FillMatrix(C, n, m);
	PrintMatrix(C, n, m, "\nВведений масив:");
	SortRows(C, n, m);
	PrintMatrix(C, n, m, "\nВідсортований масив:");

	// Звільнення пам'яті
	for (int i = 0; i < n; i++)
	{
		free(C[i]);
	}
	free(C);
	return 0;
}

