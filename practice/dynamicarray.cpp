#include <iostream>
using namespace std;
typedef int* IntPtr;

int main() 
{
    IntPtr p1;
    int size;
    //const int min = 1;
    //const int max = 5;
    
    cout << "Enter the size: " << endl;
    cin >> size;
    p1 = new int[size];    
    
    cout << "Enter the integers between 1-5: " << endl;
    
    for(int i=0; i<size;i++)
    {
        cin >> p1[i];
    }
    
    for (int i =1; i<size; i++)
    {
        int count = 0;
        for (int j=0; j< size; j++)
        {
            if(p1[j] == i)
            {
                count++;
            }
        }
        if (count >0)
        {
            if (count == 1)
            {
                cout << i << " -> " << count << " time" << endl;  
            }
            else
            {
                cout << i << " -> " << count << " times" << endl; 
            }
            
        }
    }

    delete [] p1;
    return 0;
}