//==================================================================================
// Written by Andrew Byerly
// February 18th, 2024
// WolfTracker.cpp
// This program will not prompt the user for input as the intention is that this
// program will primarily be tested using .txt files. *Precondition for File: The 
// must contain 96 lines of data (96 15 minute intervals for each 24 hour cycle).
// Each line of data should come in the following format (hh:mm x y). The program
// itself will then iterate over each line of data storing the data in their
// respective arrays. After storing the data in their respective arrays the program
// will then convert each unique x, y combination into a unique integer value 
// ranging anywhere from [0.. 249,999], storing said value in an array. After
// converting and storing each coordinate into the converted array the program
// will then search for the longest palindrome pattern of integer values (if there
// are multiple patterns with the same length the program will output the one
// that appears first). Using the values obtained from finding the longest
// palindrome in the converted list, the program will output the longest out and
// back sequence in the following form (hh:mm x: x y: y).
// Note: From the description it may not seem readily apparent what this program is
// meant to do so I'd like to provide a quick summation of it's purpose: given a
// dataset containing timestamps, x, and y coordinates, output the longest
// "out-and-back" x and y sequence with timestamps.
//==================================================================================

#include <iostream>
using namespace std;

// start by creating a constant global variable 'DATAPOINTS' that will indicate
// how many datapoints/time intervals we are reading in (this will prove very useful).
const int DATAPOINTS = 96;

//==================================================================================
// isPalindrome()
// This function will take an array of integers 'array' along will a starting and
// ending index 'startIndex', 'endIndex', using these parameters the function will
// return true if the array is a palindrome and false if otherwise.
// Parameters:
//    An array 'array[]' that holds the slice of integers we are looking to test.
//    An integer 'startIndex' that will show where in the array we start the slice.
//    An integer 'endIndex' that will show where in the array we end the slice.
// Return Value:
//    A boolean 'palinStatus' that will evaluate as true if the slice of the array
//    we're examining is a palindrome and false if it isn't.
//==================================================================================
bool isPalindrome(int array[], int startIndex, int endIndex) {

 // creates 'palinStatus' boolean and sets it equal to true by default.
 bool palinStatus = true;
 
 // iterates while 'palinStatus' is true and the 'startIndex' and 'endIndex' haven't
 // converged upon each other. For each iteration it checks if the two opposing 
 // values in the array slice are equal, setting 'palinStatus' to false if they're
 // not. After checking, increment startIndex and decrement endIndex by 1.
 while (palinStatus && startIndex < endIndex) {
  if (array[startIndex] != array[endIndex]) {
   palinStatus = false;
  }
  startIndex++;
  endIndex--;
 }
 
 // returns the 'palinStatus' boolean variable.
 return palinStatus;
}

//==================================================================================
// displayLongestPalindrome()
// This function will take an array of one dimensional coordinates 'oneD' and find
// the longest palindrome pattern within said array. After finding the location
// and length of the largest palindrome, the function will use the arrays 'time',
// 'x', and 'y' to output the timestamps and coordinates of the longest palindrome.
// that occurs first within the data.
// Parameters:
//    An array 'oneD' that holds the one dimensional coordinates.
//    An array 'time' that holds the data timestamps.
//    An array 'x' that holds the x coordinates.
//    An array 'y' that holds the y coordinates.
// Return Value:
//    None, this function is the void type and will return nothing, it's main
//    purpose is to compute the location of the longest palindrome and output the
//    timestamps and coordinates of said palindrome to the console.
//==================================================================================
void displayLongestPalindrome(int oneD[], string time[], int x[], int y[]) {
 
 // creates 'longestLength', 'startIndex', and 'length' integer variables, setting
 // them all equal to 0 by default.
 int longestLength = 0;
 int startIndex = 0;
 int length = 0;
 
 // iterate for each datapoint, nested for loop will iterate over each slice, the
 // length of the slice is determined by how long the longest palindrome is at 
 // any given moment. If the current slice being looked at is a palindrome and is
 // longer than the previous longest palindrome, store it's starting index and
 // length.
 for (int i = 0; i < DATAPOINTS; i++) {
  for (int j = i + longestLength; j < DATAPOINTS; j++) {
   if (isPalindrome(oneD, i, j)) {
    length = j - i + 1;
    if (length > longestLength) {
     longestLength = length;
     startIndex = i;
    }
   }
  }
 }
 
 // iterate over the slice that is considered the longest palindrome found in the
 // array (first takes precedence), from starting index of the palindrome to the 
 // end, output each timestamp, x, and y coordinate that shares that index.
 for (int i = startIndex; i < startIndex + longestLength; i++) {
  cout << time[i] << " x: " << x[i] << " y: " << y[i] << endl;
 }
 
}

//==================================================================================
// coordinateConverter()
// This function will take the arrays of the x and y coordinates represented in the
// data 'x' and 'y' and store their unique one dimensional equivalent in the 'oneD'
// array (they share the same index, making it easy to keep track of what one
// dimensional value represents which x and y combination).
// Parameters:
//    An array 'x' that holds the x coordinates.
//    An array 'y' that holds the y coordinates.
//    An array 'oneD' that will hold the converted value of each x/y combination.
// Return Value:
//    None, this function is the void type and will return nothing, it's main
//    purpose is to convert the data stored in the x and y arrays into a one
//    dimensional equivalent, storing the equivalent in the passed arrays memory.
//==================================================================================
void coordinateConverter(int x[], int y[], int oneD[]) {

 // iterate for each datapoint, convert the two dimensional coordinates into
 // one dimensional coordinates and store their value in the array 'oneD'.
 for (int i = 0; i < DATAPOINTS; i++) {
  oneD[i] = x[i] + 500 * y[i];
 }
 
}

//==================================================================================
// main()
// This function will act as the backbone of the program, taking each function and
// leveraging it in the manner it's intended. It will start by reading in the data
// in each line into their respective arrays, will iterate DATAPOINTS times (So, if
// coming back to this in the future we want to examine data on shorter intervals we
// can increase the global variable DATAPOINTS. After storing the data in their
// respective arrays, the function will invoke the 'coordinateConverter' function,
// converting each datapoint into a unique one dimensional coordinate and storing
// it in the array passed, in this case its the 'oneDArray'. After conversion, the
// function will make a call to the 'displayLongestPalindrome' function, which will
// output the longest palindrome found within the data to the console.
//==================================================================================
int main() {
 
 // creates the arrays needed to store the data for the program and sets their size
 // equal to the constant DATAPOINTS, these array are 'timeArray', 'xArray',
 // 'yArray' and 'oneDArray'.
 string timeArray[DATAPOINTS];
 int xArray[DATAPOINTS];
 int yArray[DATAPOINTS];
 int oneDArray[DATAPOINTS];
 
 // iterate for each datapoint, store the data in their respective arrays.
 for (int i = 0; i < DATAPOINTS; i++) {
  cin >> timeArray[i] >> xArray[i] >> yArray[i];
 }
 
 // convert the x and y coordinates into one dimensional form and store them in
 // the 'oneDArray' array.
 coordinateConverter(xArray, yArray, oneDArray);
 
 // call the 'displayLongestPalindrome' function to output the timestamps and
 // coordinates of the longest palindrome in the data to the console.
 displayLongestPalindrome(oneDArray, timeArray, xArray, yArray);

 return 0;
}