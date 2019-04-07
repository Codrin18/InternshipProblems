#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* The function assumes that there are  
   at least two elements in array. The  
   function returns a negative value if the 
   array is sorted in decreasing order and   
   returns 0 if elements are equal */
int maxDiff(int arr[], int arr_size) 
{ 
     // Maximum difference found so far 
     int max_diff = arr[1] - arr[0]; 
       
     // Minimum number visited so far  
     int min_element = arr[0]; 
     for(int i = 1; i < arr_size; i++) 
     {      
       if (arr[i] - min_element > max_diff)                              
       max_diff = arr[i] - min_element; 
         
       if (arr[i] < min_element) 
       min_element = arr[i];                      
     } 
       
     return max_diff; 
}

int main()
{
	int arr[] = {2, 3, 10, 2, 4, 8, 1};

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxDiff(arr,n) << endl;

	return 0;
}