#include <iostream>
#include <cmath>

using namespace std;

int CountZeros(double* arr, int size) {
    int zeroCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            zeroCount++;
        }
    }
    return zeroCount;
}

int FindMinIndex(double* arr, int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

double SumAfterMin(double* arr, int size, int minIndex) {
    double sum = 0;
    for (int i = minIndex + 1; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void SortOddElements(double* arr, int size) {
    double* oddArr = new double[size];
    int oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (static_cast<int>(arr[i]) % 2 != 0 && floor(arr[i]) == arr[i]) {
            oddArr[oddCount++] = arr[i];
        }
    }

    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = 0; j < oddCount - i - 1; j++) {
            if (fabs(oddArr[j]) > fabs(oddArr[j + 1])) {
                swap(oddArr[j], oddArr[j + 1]);
            }
        }
    }

    for (int i = 0, j = 0; i < size && j < oddCount; i++) {
        if (static_cast<int>(arr[i]) % 2 != 0 && floor(arr[i]) == arr[i]) {
            arr[i] = oddArr[j++];
        }
    }

    delete[] oddArr;
}

void PrintArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    double* arr = new double[n];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Initial array: ";
    PrintArray(arr, n);

    // 1.1. Підрахунок кількості елементів, рівних нулю
    int zeroCount = CountZeros(arr, n);
    cout << "Number of zero elements: " << zeroCount << endl;

    // 1.2. Сума елементів після мінімального елемента
    int minIndex = FindMinIndex(arr, n);
    double sumAfterMin = SumAfterMin(arr, n, minIndex);
    cout << "Sum of elements after minimum: " << sumAfterMin << endl;

    // 2. Впорядкування непарних елементів за зростанням модулів
    SortOddElements(arr, n);

    cout << "Modified array: ";
    PrintArray(arr, n);

    delete[] arr;

    return 0;
}
