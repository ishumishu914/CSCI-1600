#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
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
}

int main() 
{
  int size = 10000;
  int nums[10000];

  srand(time(NULL));

  for(int i=0; i<size; i++) 
  {
    nums[i]= rand();
    time_t start, end;
    time(&start);
    sortNums(nums, size);
    time(&end);
    
    cout << "Time: " << end - start << setprecision(5) << " sec." << endl;  
  }
  return 0;
}