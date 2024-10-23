#include <iostream>
#include <iomanip>
using namespace std;

void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int FindFirstZeroColumn(int** a, const int rowCount, const int colCount);
int CalculateRowCharacteristic(int* row, const int colCount);
void SortRowsByCharacteristic(int** a, const int rowCount, const int colCount);
void SwapRows(int** a, int row1, int row2);

int main() {
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

  
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);

    Print(a, rowCount, colCount);

    int firstZeroCol = FindFirstZeroColumn(a, rowCount, colCount);
    if (firstZeroCol != -1)
        cout << "First column with a zero element: " << firstZeroCol + 1 << endl;
    else
        cout << "No columns with zero elements." << endl;

    SortRowsByCharacteristic(a, rowCount, colCount);

    cout << "Matrix after sorting rows by decreasing characteristics:" << endl;
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int FindFirstZeroColumn(int** a, const int rowCount, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        for (int i = 0; i < rowCount; i++) {
            if (a[i][j] == 0)
                return j;
        }
    }
    return -1; 
}

int CalculateRowCharacteristic(int* row, const int colCount) {
    int sum = 0;
    for (int j = 0; j < colCount; j++) {
        if (row[j] < 0 && row[j] % 2 == 0) {
            sum += row[j];
        }
    }
    return sum;
}

void SortRowsByCharacteristic(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount - 1; i++) {
        for (int j = 0; j < rowCount - i - 1; j++) {
            int characteristic1 = CalculateRowCharacteristic(a[j], colCount);
            int characteristic2 = CalculateRowCharacteristic(a[j + 1], colCount);
            if (characteristic1 < characteristic2) {
                SwapRows(a, j, j + 1);
            }
        }
    }
}

void SwapRows(int** a, int row1, int row2) {
    int* temp = a[row1];
    a[row1] = a[row2];
    a[row2] = temp;
}
