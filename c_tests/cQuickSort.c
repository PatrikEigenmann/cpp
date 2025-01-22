/* *******************************************************************************************
 * cQuickSort.c - The Quick Sort algorithm was created by Tony Hoare in 1959 while he was a
 * visiting student at Moscow State University. He developed the algorithm as part of a
 * machine translation project and later published it in 19611. Tony Hoare is a British
 * computer scientist known for his contributions to computer science, including the
 * development of this efficient sorting algorithm.
 * 
 * The Quick Sort algorithm I have implemented here is similar to the one used in the Unix
 * operating system. It is a comparison-based sorting algorithm that uses a divide-and-conquer
 * strategy to sort an array of elements. The algorithm works by selecting a pivot element from
 * the array and partitioning the other elements into two sub-arrays according to wheter they
 * are less than or greater than the pivot element. The sub-arrays are then recursively sorted.
 * 
 * Compile instructions:
 * gcc/clang cQuickSort.c -o cQuickSort
 * pmake cQuickSort.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Wed 2025-01-22 File created.                                                 Version: 00.01
 * ********************************************************************************************/
#include <stdio.h>

/*
 * This function takes two integer pointers and swaps the values they point to.
 * 
 * @param a -> Pointer to an integer
 * @param b -> Pointer to another integer
 */
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/*
 * This function takes the last element as pivot, places the pivot element at its correct
 * position in sorted array, and places all smaller (smaller than pivot) to left of pivot
 * and all greater elements to right of pivot.
 * 
 * @param arr[] --> Array to be sorted
 * @param low --> Starting index
 * @param high --> Ending index
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/*
 * This is an implemention of the quick sort algorithm by Tony Hoare in 1959.

 * @param arr[] --> Array to be sorted,
 * @param low --> Starting index,
 * @param high --> Ending index
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*
 * This function is printing element after element of an array to the console as a formatted string.
 *
 * @param arr[] --> Array to be printed
 * @param size --> Size of the array
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ---------------------------------------------------------------------------------------------
// main - The main function is the starting point of a C or C++ program, where execution begins.
// This version of the main function allows the program to take command-line arguments when it
// runs. The function typically returns an numbered value to the operating system, often zero
// to signify successful execution.
// ----------------------------------------------------------------------------------------------
int main() {

    // Short program will test the quick sort algorithm
    
    int arr[] = {10, 7, 8, 9, 1, 5};        // Array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]);   // Size of the array

    // Call the quick sort function
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: \n");

    // Call the print array function
    printArray(arr, n);

    // Return 0 to the operating system
    return 0;
}