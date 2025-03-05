


#define MAX_ARRAY_SIZE 25

// �������� ��������� �������
void InputMatrixSize(int* n, int* m);

// �������� ���'�� �� �������
int** AllocateMatrix(int n, int m);

// ���������� ������� ���������� ���������� � ������
void FillMatrix(int** C, int n, int m);

// ��������� �������
void PrintMatrix(int** C, int n, int m, const char* message);

// ���������� ����� ������� ������� ���������
void SortRows(int** C, int n, int m);

// �������� �������� ������ �����
bool ValidateIntegerInput(int* value);
