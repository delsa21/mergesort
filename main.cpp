#include <iostream>
#include <vector>

//MERGE SORT

using namespace std;

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& array) {
    int leftSize = leftArray.size();
    int rightSize = rightArray.size();

    int i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize) {
        if (leftArray[l] < rightArray[r]) {
            array[i] = leftArray[l];
            l++;
        } else {
            array[i] = rightArray[r];
            r++;
        }
        i++;
    }

    // Copiar los elementos restantes de leftArray, si los hay
    while (l < leftSize) {
        array[i] = leftArray[l];
        l++;
        i++;
    }

    // Copiar los elementos restantes de rightArray, si los hay
    while (r < rightSize) {
        array[i] = rightArray[r];
        r++;
        i++;
    }
}

void mergeSort(vector<int>& array) {
    int n = array.size();
    if (n <= 1) return;

    int center = n / 2;

    vector<int> leftArray(center);
    vector<int> rightArray(n - center);

    for (int i = 0; i < n; i++) {
        if (i < center) {
            leftArray[i] = array[i];
        } else {
            rightArray[i - center] = array[i];
        }
    }

    // Llamada recursiva
    mergeSort(leftArray);
    mergeSort(rightArray);

    // Combina las mitades
    merge(leftArray, rightArray, array);
}

int main() {
    vector<int> array = {12, 3, 7, 9, 14, 6, 11, 2};

    mergeSort(array);

    for (int num : array) {
        cout << num << ",";
    }

    return 0;
}
