#include <stdio.h>
void reverseArray(int arr[], int start, int end) // Function to rotate the array
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void circularRotate(int arr[], int d, int n) // Function for circular Rotation
{
    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
}
void printArray(int arr[], int size) // Function to print Array
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
/* Driver program to test above functions */
int main()
{
    int n; // Declare Array size
    printf("\nEnter the number of elements ");
    scanf("%d", &n);
    int arr[n]; // Declare an array
    printf("\nEnter the array elements ");
    for (int i = 0; i < n; i++) // Initialize array elements
        scanf("%d", &arr[i]);
    int k; // Declare a variable for number of array rotation
    printf("\nEnter the number of array rotation ");
    scanf("%d", &k);
    circularRotate(arr, k, n); // Call a function for circular rotation
    printf("\nAfter %d array rotation, the resulting array is \n", k);
    printArray(arr, n); // Call a function to print the array
    return 0;
}