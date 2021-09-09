using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Olaf Zielinski
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  int a=0; int b=0; int r=0; //index for a,b,c
  
  while(a < A.size() && b < B.size()){ // keep doing until they cross
    if(A[a] < B[b]){ //put the right int in the place, either from A or B
      R[r] = A[a];
      a++; //if it was a, move index
    } else {
      R[r] = B[b];
      b++; } //if it was b, move index
    cout << "comparison" << endl;
    r++; // be careful -- R comes in as an empty vector
  }
  
  if(a < A.size()){ // if there are any leftover values,
    for(; a<A.size(); a++, r++){
      R[r] = A[a]; //put them into the new list
    }
  }else{ //same for values from second array
    for(; b<B.size(); b++, r++){
      R[r]=B[b];
    }
  }
}

int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3
  L3.resize(2*N);
  combine(L1, L2, L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main
