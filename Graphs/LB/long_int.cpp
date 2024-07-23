// C++ program to obtain the maximum 
// value stored in unsigned long long int 
#include <climits> 
#include <iostream> 
using namespace std; 

// Driver Code 
int main() 
{ 

	// From the constant of climits 
	// header file 
	 long int valueFromLimits = ULONG_MAX; 

	cout << "Value from climits "
		<< "constant: "; 
	cout << valueFromLimits << "\n"; 

	// Using the wrap around property 
	// of data types 

	// Initialize a variable with value 0 
	unsigned  long int value = 0; 

	// Subtract 1 from value since an 
	// unsigned data type cannot store 
	// negative number, the value will 
	// wrap around and stores maximum 
	// value stored in it 
	value = value - 1; 
	cout << "Value using the wrap"
		<< " around property: "
		<< value << "\n"; 

	return 0; 
} 
