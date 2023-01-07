#include <iostream>
using namespace std;

void swapper(int&a, int &b)
{
  int temp;

  temp = a;
  a = b;
  b = temp;
}

void sortNums(int nums[], int size)
{
  for (int j=0; j < size-1; j++)
  {
    for (int i = 0; i < size-j-1; i++)
    {
      if (nums[i] > nums[i+1])
      {
        swapper(nums[i], nums[i+1]);
      }
    }
  }      
  cout << "\nThe array of integers sorted in ascending order is: " << endl;

  for (int i=0; i < size; i++)
  {
    cout << nums[i] << " "; 
  }
}

int main() 
{
  int nums[5];

  cout << "Enter 5 integers: " << endl;
  for(int i=0; i<5;i++)
  {
    cin >> nums[i];
  }
  
  int size = sizeof(nums)/sizeof(nums[0]);
  sortNums(nums, size);

  return 0;
}