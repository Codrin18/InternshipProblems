#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
// A comparison function which is used by sort() in printLargest() 
int myCompare(string X, string Y) 
{ 
    // first append Y at the end of X 
    string XY = X.append(Y); 
  
    // then append X at the end of Y 
    string YX = Y.append(X); 
  
    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1: 0; 
} 
  
// The main function that prints the arrangement with the largest value. 
// The function accepts a vector of strings 
void printLargest(vector<string> arr) 
{ 
    // Sort the numbers using library sort funtion. The function uses 
    // our comparison function myCompare() to compare two strings. 
    sort(arr.begin(), arr.end(), myCompare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
    cout <<endl;
}

int main()
{
	vector <string> arr;
	arr.push_back("3");
	arr.push_back("30");
	arr.push_back("34");
	arr.push_back("5");
	arr.push_back("9");
	printLargest(arr);
	return 0;
}