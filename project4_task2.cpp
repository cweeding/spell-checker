/*************************************************************************
* Name: Codie Weeding
* StarID: vx3094oa
* Class: CSCI 301
* Section: 054
* File Name: project4_task2.cpp
* File Location: CourseFiles\Fall2019\jhu\CSCI301s54\
*                StudentWorkFolder\vx3094oa\Project4-CodieWeeding
* Due Date: 10/17/2019
* Instructor: Jie Hu Meichsner
*
* Description: Program reads words from an external file and checks for
*              correct spelling. Prints misspelled words.
*************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayStack.h"

using namespace std;

void getKey(string key[], string docName); // Function prototype

/*************************************************************************
* Function: stackTester()
*
* Description: Uses ADT stack: Array-based implementation to spell check
*              an external set of words
* @Pre: stack pointer
* @Post: none
*************************************************************************/
void stackTester(ArrayStack<string>* stackPtr)
{
  int SIZE = 10;
	string dictionary[SIZE];
	string myreport[SIZE];
  string incorrect[4];
  string docName;
  int count = 0;

  // Reads data from external file and adds to dictionary array
  docName = "dictionary.txt";
  getKey(dictionary, docName);

  // Reads data from external file and adds to myreport array
  cout << "\nEnter the name of the file with words to check: ";
  cin >> docName;
  getKey(myreport, docName);
	
  // Prints dictionary words
  cout << "\nDictionary words:" << endl;
	for (int i = 0; i < 10; i++)
  {
		cout << " " << dictionary[i] << endl;
	}

  // Prints words to check
  cout << "\nmyReport words:" << endl;
	for (int i = 0; i < 10; i++)
  {
		cout << " " << myreport[i] << endl;
	}

  // Assigns stackPtr to myreport array
  for (int i = 0; i < 10; i++)
   {
      bool success = stackPtr->push(myreport[i]);
      if (!success)
        cout << "Failed to push " << myreport[i] << " onto the stack." << endl;
	}

  // Enters while myreport is not emptyy
  while (stackPtr->isEmpty() == 0)
  {
    for (int i = 0; i < 10; i++)
    {
      // Enters if word is found in dictionary
      if (stackPtr->peek() == dictionary[i])
      {
        stackPtr->pop(); // Removes word
        i = 0;
      }
    }

    incorrect[count] = stackPtr->peek(); // Adds incorrect word to array
    stackPtr->pop(); // Removes word
    count++;
  }

  // Prints incorrect words
  int index = count;
  cout << "\nIncorrect words:" << endl;
  for (int i = 0; i < count ; i++)
  {
    cout << " " << incorrect[index-1] << endl;
    index--;
  }
}  // end stackTester

/*************************************************************************
* Function: getKey()
*
* Description: Reads in the correct answers from a file and stores to
*              an array called key
* @Pre: key array
* @Post: key arry is updated in main
*************************************************************************/
void getKey(string key[], string docName)
{
  // Variables
  ifstream inFile;
  int count = 0;

  // Opens the file
  inFile.open(docName.c_str());

  if(inFile)    // Enters if file opens correctly
  {
    // Runs through entire file and assigns values to array
    for (int i = 0; i < 10; i++)
    {
      inFile >> key[i];
    }
  }
  else    // Enters if file does not open correctly and exits program
  {
    cout << "File Error" << endl;
    exit(0);
  }

  // Closes the file
  inFile.close();
}


int main()
{
	ArrayStack<string>* stackPtr = new ArrayStack<string>(); // Assigns stackPtr

	cout << "\nTESTING THE ARRAY-BASED STACK" << endl;
	stackTester(stackPtr); // Calls stackTester function
	
  cout << endl;
  return 0;
}  // end main
