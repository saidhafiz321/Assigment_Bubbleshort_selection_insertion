#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void swap(int &x, int &y) {
int temp = x;
x = y;
y = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
     for (int j = 0; j < n-i-1; j++) {
         if (arr[j] > arr[j+1]) {
              swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
int key, j;
for (int i = 1; i < n; i++) {
key = arr[i];
j = i-1;
while (j >= 0 && arr[j] > key) {
arr[j+1] = arr[j];
j--;
}
arr[j+1] = key;
}
}

void selectionSort(int arr[], int n) {
int minIndex;
for (int i = 0; i < n-1; i++) {
minIndex = i;
for (int j = i+1; j < n; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}
swap(arr[minIndex], arr[i]);
}
}

int main() {
int n = 10000;
int arr[n];
int choice;
clock_t start, end;
double timeTaken;
 
srand(time(0));
for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
}
random_shuffle(arr, arr + n);

cout << "Data sebelum diurutkan: ";
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
cout << endl;

cout << "Pilih metode pengurutan: " << endl;
cout << "1. Bubble Sort" << endl;
cout << "2. Insertion Sort" << endl;
cout << "3. Selection Sort" << endl;
cout << "Masukkan pilihan: ";
cin >> choice;

start = clock();
switch (choice) {
    case 1:
        bubbleSort(arr, n);
        break;
    case 2:
        insertionSort(arr, n);
        break;
    case 3:
        selectionSort(arr, n);
        break;
    default:
        cout << "Pilihan salah" << endl;
        return 0;
}
end = clock();
timeTaken = double(end - start) / CLOCKS_PER_SEC;

cout << "Data setelah diurutkan: ";
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
cout << endl;
cout << "Waktu yang dibutuhkan: " << timeTaken << " detik" << endl;

return 0;
}