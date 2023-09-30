#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;
const int NUMBERS_SIZE = 5000;

int genRandInt(int low, int high); //generate a random integer within the given range of low to high
void fillArrays(int arr1[], int arr2[],int arr3[]); //declares 3 arrays
void Quicksort_midpoint(int numbers[], int i , int k); //implements the Quicksort algorithm to sort the elements in the numbers array
int midpoint_Partition(int numbers[], int i, int k); //partition the numbers array around a pivot element (midpoint) and return the index of the pivot element after partitioning
void Quicksort_medianOfThree(int numbers[], int i, int k); //implements Quicksort again
int medianOfThree_Partition(int numbers[], int i, int k); //partition the numbers array around a pivot element (median of three elements) and return the index of the pivot element after partitioning
void InsertionSort(int numbers[], int numbersSize); //implements the Insertion Sort algorithm to sort the elements in the numbers array

int main() {

    //allocate memory to store a sequence of integers
    int tester1[NUMBERS_SIZE];
    int tester2[NUMBERS_SIZE];
    int tester3[NUMBERS_SIZE];

    fillArrays(tester1, tester2, tester3);
    
    
    clock_t Start = clock(); //records the current clock time at the start
    Quicksort_midpoint(tester1, 0, NUMBERS_SIZE - 1); //sort the elements in the tester1 array using the Quicksort algorithm 
    clock_t End = clock(); // records the current clock time after the execution
    int quicksortElapsedTime = (End - Start)/CLOCKS_PER_MS; //calculates the elapsed time for the execution in milliseconds
    cout << "Quicksort (midpoint) runtime: " << quicksortElapsedTime << " ms" << endl;

    clock_t medianStart = clock(); //records the current clock time at the start 
    Quicksort_medianOfThree(tester2, 0, NUMBERS_SIZE - 1); // sort the elements in the tester2 array using the Quicksort algorithm 
    clock_t medianEnd = clock(); //records the current clock time after the execution
    int medianElapsedTime = (medianEnd - medianStart)/CLOCKS_PER_MS; //calculates the elapsed time in milliseconds 
    cout << "Quicksort (median of three) runtime: " << medianElapsedTime << " ms" << endl;

    clock_t insertStart = clock();
    InsertionSort(tester3, NUMBERS_SIZE);
    clock_t insertEnd = clock();
    int insertElapsedTime = (insertEnd - insertStart)/CLOCKS_PER_MS;
    cout << "Insertion sort runtime: " << insertElapsedTime << " ms" << endl;

    return 0;
}

//generate random number
int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1); //makes sure result is within desired range
}

//fill arrays arr1, arr2, and arr3 with random integer values
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}


//recursive implementation of the Quicksort algorithm
//divides the input array into smaller partitions and recursively applies the Quicksort algorithm to each partition until the entire array is sorted
void Quicksort_midpoint(int numbers[], int i , int k) {
    if (i < k){
        int q = midpoint_Partition(numbers, i, k);
        Quicksort_midpoint(numbers, i, q);
        Quicksort_midpoint(numbers, q+1, k);
    }
    else{
        return;
    }
}

int midpoint_Partition(int numbers[], int i, int k) {
    int midpoint = i + (k - i)/2; //midpoint of partition
    int pivot = numbers[midpoint];
    
    bool done = false;

    while (!done){
        while (numbers[i] < pivot){ //increments i until it reaches an index where the element is greater than or equal to the pivot value
            i = i + 1;
        }
        while (pivot < numbers[k]){ //decrements k until it reaches an index where the element is less than or equal to the pivot value
            k = k - 1;
        }
        if (i >= k){
            done = true;
        }
        else{ //there are still elements to be swapped
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;

            i = i + 1;
            k = k - 1;  
        }
    }

    return k;
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {
    if (i < k){ //there is more than one element in the current partition and sorting is required
        int q = medianOfThree_Partition(numbers, i, k); //rearrange the elements in such a way that all elements less than or equal to the pivot are placed before the pivot
        Quicksort_medianOfThree(numbers, i, q);
        Quicksort_medianOfThree(numbers, q+1, k);
    }
    else{
        return;
    }
}

int medianOfThree_Partition(int numbers[], int i, int k) {
    int midpoint = i + (k - i)/2;
    int pivot = 0;
    
    bool done = false;

    if (numbers[i] > numbers[midpoint]){ //numbers[i] is larger than at least one of the other two elements
        if (numbers[midpoint] > numbers[k]){
            pivot = numbers[midpoint];
        }
        else if (numbers[i] > numbers[k]){
            pivot = numbers[k];
        }
        else{
            pivot = numbers[i]; //numbers[i] is the median
        }
    }
    else{
        if (numbers[i] > numbers[k]){
            pivot = numbers[i]; //numbers[i] is the median and it set as the pivot
        }
        else if (numbers[midpoint] > numbers[k]){
            pivot = numbers[k]; //otherwise, numbers[k] is the median, and it is assigned as the pivot value.
        }
        else{
            pivot = numbers[midpoint]; //otherwise, numbers[midpoint] is the median and it is assigned as the pivot value
        }
    }

    while (!done){ //repeat of midpointPartition algorithm loop
        while (numbers[i] < pivot){
            i = i + 1;
        }
        while (pivot < numbers[k]){
            k = k - 1;
        }
        if (i >= k){
            done = true;
        }
        else{
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;

            i = i + 1;
            k = k - 1;  
        }
    }
    return k;
}

void InsertionSort(int numbers[], int numbersSize) {
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 1; i < numbersSize; ++i){
        j = i; //position of the element being considered for insertion
        while (j > 0 && numbers[j] < numbers[j - 1]){
            temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp; //swaps the elements at positions j and j - 1
            --j; //decrements j by 1 to move to the previous position
        }
    }
}


