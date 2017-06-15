//Enrique Penaloza, Algorithm Analysis Code Portion
//Used DataStructures Book from last semester:
//  www.cs.colorado.edu/~main/chapter13/merge.cxx
//merge and mergeSort carr varaibles of size_t for universal purpose.

#include <iostream>
#include <cstdlib>
#include <string>
void merge(int data[], size_t n1, size_t n2)
/*Precondition: 'data' is an array (or subarray) with at least n1 + n2 elements.
 * The first n1 elements (from data[0] to data[n1-1]) are sorted from smallest to largest, and
 * the last n2(from data[n1 to data[n1+n2 -1] are also sorted from smallest to largest.
 * 
 * Postcondition: The first n1 + n2 elements of data have been rearranged to be sorted from smallest to largest.
 */
{
    int *temp;              //Points to dynamic array to hold the sorted elements.
    size_t copied = 0;      //Number of elements copied from data to temp.
    size_t copied1 = 0;     //Number copied from the first half of data.
    size_t copied2= 0;      //Number copied from the second half of data.
    size_t i;               //Array index to copy from temp back into data.
    
    //Allocate memory for the temporary dynamic array.
    temp= new int[n1+n2];
    
    //Merge elements, copying from two halves of data to the temporary array.
    while((copied1 < n1) && (copied2 < n2))
    {
        if(data[copied1]< (data +n1)[copied2])
            temp[copied++] = data[copied1++];           //Copy from first half.
        else
            temp[copied++] = (data + n1)[copied2++];    //Copy from second half.
    }
    
    //Copy any remaining entries in the left and right subarrays.
    while(copied1 < n1)
        temp[copied++] = data[copied1++];
    while(copied2 < n2)
        temp[copied++] = (data+n1)[copied2++];
    
    //Copy from temp back to the data array
    for(i=0; i< n1+n2; ++i)
    {
        data[i] = temp[i];
    }
    
    //Release temp's memory.
    delete [] temp;
}

void mergeSort(int data[], size_t n)
/* Precondition: data is an array with at least n components.
 *  Needs to have available dynamic memory or sorting algorithm will fail.
 * Postcondition: The elements of data have been rearranged so that data[0] <= data[1] <= ... <data[n-1]
 */
{
    size_t n1;  //Size of the first subarray
    size_t n2;  //Size of the second subarray
    
    if(n > 1)
    {
        //Compute the sizs of the subarray
        n1= n/2;
        n2 = n-n1;
        
        //The two subarrays are sorted with recursive calls.
        mergeSort(data, n1);            //Sort from data[0] through data[n1-1]
        mergeSort((data + n1), n2);     //Sort from data[n1] to the end
        
        //Merge the two sorted halves.
        merge(data, n1, n2);
    }
}