


#define MAX_ARRAY_SIZE 25

// Введення розмірності матриці
void InputMatrixSize(int* n, int* m);

// Виділення пам'яті під матрицю
int** AllocateMatrix(int n, int m);

// Заповнення матриці унікальними значеннями в рядках
void FillMatrix(int** C, int n, int m);

// Виведення матриці
void PrintMatrix(int** C, int n, int m, const char* message);

// Сортування рядків матриці методом бульбашки
void SortRows(int** C, int n, int m);

// Перевірка введення цілого числа
bool ValidateIntegerInput(int* value);
