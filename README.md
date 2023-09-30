This C++ project appears to be focused on implementing and comparing the performance of different sorting algorithms, specifically Quicksort (both with the midpoint and median-of-three pivot selection strategies) and Insertion Sort. 

-  main.cpp:
This is the main program file that orchestrates the sorting algorithm comparisons. It includes the main function, which performs the following tasks:
    - Initializes three arrays (tester1, tester2, and tester3) with random integer values.
    - Measures the runtime of Quicksort with the midpoint pivot selection strategy for sorting tester1.
    - Measures the runtime of Quicksort with the median-of-three pivot selection strategy for sorting tester2.
    - Measures the runtime of Insertion Sort for sorting tester3.
    - Outputs the runtime of each sorting algorithm in milliseconds.
      
-  genRandInt:
A helper function that generates a random integer within a given range.

-  fillArrays:
A function that initializes three arrays with random integer values.

-  Quicksort_midpoint and midpoint_Partition:
Functions that implement the Quicksort algorithm with the midpoint pivot selection strategy. Quicksort_midpoint is a recursive function that sorts a given array by partitioning it around a midpoint pivot element. midpoint_Partition is a helper function that performs the partitioning step of Quicksort with the midpoint pivot strategy.

-  Quicksort_medianOfThree and medianOfThree_Partition:
Functions that implement the Quicksort algorithm with the median-of-three pivot selection strategy. Quicksort_medianOfThree is a recursive function that sorts a given array by partitioning it around a pivot element selected using the median-of-three strategy. medianOfThree_Partition is a helper function that performs the partitioning step of Quicksort with the median-of-three pivot strategy.

-  InsertionSort:
A function that implements the Insertion Sort algorithm to sort an array.

The project's primary focus is on comparing the runtime performance of three sorting algorithms: Quicksort with midpoint pivot selection, Quicksort with median-of-three pivot selection, and Insertion Sort. You generate random arrays of integers and measure the time it takes for each algorithm to sort these arrays. This comparison can help you understand the relative efficiency of these sorting algorithms for different input data.
