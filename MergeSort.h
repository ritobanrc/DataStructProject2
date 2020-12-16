#include <cstdlib>
#include <time.h>
#include <iostream>
#include <chrono>

// Utility functions used in all sorts
template <typename T>
void swap(int* arr, size_t a, size_t b);

// Merge Sort functions
template <typename T>
void mergeSort(T* arr, size_t size);
template <typename T>
void mergeSort(T* arr, int low, int high);

template <typename T>
void merge(T* arr, int low, int mid, int high);

template <typename T>
void swap(T* arr, size_t a, size_t b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}


template <typename T>
void mergeSort(T* arr, size_t size) {
    mergeSort(arr, 0, size - 1);
}

template <typename T>
void mergeSort(T* arr, int low, int high) {
    if (low < high) {
        int mid = (low + high - 1) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

template <typename T>
void merge(T* arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    T left[n1], right[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[i + low];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0;
    int current = low;

    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[current] = left[i];
            i++;
        } else {
            arr[current] = right[j];
            j++;
        }
        current++;
    }

    while (i < n1) {
        arr[current] = left[i];
        current++;
        i++;
    }

    while (j < n2) {
        arr[current] = right[j];
        current++;
        j++;
    }
}
