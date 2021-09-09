#include<iostream>
using namespace std;

// You may not change my code in any manner.  0 pts if you do.
// Simply add your code for **

//----------------------------------------
//CS311 HW2P2 Partition
//Name: Olaf Zielinski
//Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r)
{
  int left = f; // pointer from the left
  int right = r; // pointer from the right 
  int i, tmp; //index of the integer and temporary var to store swapped item
  int partition=left+1;

  //    if right OK, move right
  //    if both are bad, swap
 
  // return the partition point where
  // those smaller than pivot are before what is returned
  // ** there is a special cases and a regular case

  // loop for finding out of place pairs and swap them
  // until the left and right cross
  for(i=left+1;i<=right;i++){ 

    if(a[i]<pivot){  

      if(i!=partition){ 
	//if bad, swap
	tmp=a[partition];
	a[partition]=a[i];
	a[i]=tmp;
      }
     
      partition++; //to move to next element
    }

  }

  a[left]=a[partition-1];  
  a[partition-1]=pivot;
  i=0;
  if(a[0]==pivot) return 1; //that's the special case

  while(a[i]!=pivot)i++; //find the index of the pivot 
  return i; // and return it
}

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums[0], nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

}
