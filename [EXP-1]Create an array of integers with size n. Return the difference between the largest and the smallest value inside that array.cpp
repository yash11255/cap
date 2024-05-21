#include <iostream>
#include <vector>

// Function to calculate the difference between the largest and smallest
// values in an array
int differenceBetweenLargestAndSmallest(const std::vector<int>& arr)
{
    // Initialize variables to store the largest and smallest values
    int largest = arr[0];
    int smallest = arr[0];
    
    // Iterate through the array to find the largest and smallest values
    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    
    // Calculate the difference between the largest and smallest values
    int difference = largest - smallest;
    
    // Return the difference
    return difference;
}

int main()
{
    // Input the size of the array
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    
    // Create a vector of integers with size n and initialize it with user input
    std::vector<int> arr(n);
    
    // Input the elements of the array
    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    
    // Call the function to calculate the difference between the largest and smallest values
    int difference = differenceBetweenLargestAndSmallest(arr);
    
    // Output the difference
    std::cout << "Difference between the largest and smallest values: " << difference << std::endl;
    
    return 0;
}
