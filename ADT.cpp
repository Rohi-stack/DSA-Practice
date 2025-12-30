#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
  
struct Array
{
    int *A;
    int size;
    int length;
};
void display(int arr[],
             int size,
             int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    Array arr;
    arr.size = 12;
    arr.length = 5;
    arr.A = new int[arr.size]{2, 4, 6, 8, 10};
    // append 65 in an array
    arr.A[arr.length] = 65;
    arr.length++;

    // print all elements of the array
    display(arr.A, arr.size, arr.length);
    std::cout << std::endl;
    int temp;
    // delete an element at index 2
    for (int i = 0; i < arr.length; i++)
    {
        // temp=arr.A[i+1];
        arr.A[i] = arr.A[i + 1];
    }

    arr.length--;
    display(arr.A, arr.size, arr.length);
    std::cout << std::endl;

    // Insert an element(4,15)
    int index = 2;
    int element = 15;
    // temp = 0;
    temp = arr.length;
    for (int i = index; i < arr.length; i++)
    {

        arr.A[temp] = arr.A[temp-1];
        temp--;
    }
    arr.length++;
    arr.A[index] = element;
    display(arr.A, arr.size, arr.length);
    std::cout << std::endl;



    //linear search for an element(15)
    int key = 15;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)    
        {
            std::cout << "Element " << key << " found at index " << i << std::endl;
            break;
        }
        else
        {
            if (i == arr.length - 1)
            {
                std::cout << "Element " << key << " not found in the array" << std::endl;
            }
        }
    }

    // binary search for an element(65)
    key = 65;
    int low = 0;
    int high = arr.length - 1;
    int mid;

    // sort the array before binary search

    for (int i = 0; i < arr.length - 1; i++)
    {
        for (int j = 0; j < arr.length - i - 1; j++)
        {
            if (arr.A[j] > arr.A[j + 1])
            {
                temp = arr.A[j];
                arr.A[j] = arr.A[j + 1];
                arr.A[j + 1] = temp;
            }
        }
    }

    while (low <= high)
    {
        mid = ((low + high) / 2);
        mid = floor(mid);
        if (arr.A[mid] == key)
        {
            std::cout << "Element " << key << " found at index " << mid << std::endl;
            break;
        }
        else if (arr.A[mid] < key)  
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

        if (low>high)
        {
            std::cout << "Element " << key << " not found in the array" << std::endl;
        }
    
    }  
    cout<<"Sorted array: "; 
    display(arr.A, arr.size, arr.length);
    std::cout << std::endl;



    // reverse the array
    int i=0;
    int j=arr.length-1;
    while (i<j)
    {
        temp=arr.A[i];
        arr.A[i]=arr.A[j];
        arr.A[j]=temp;
        i++;
        j--;
    }
    cout<<"Reversed array: ";
    display(arr.A, arr.size, arr.length);
    std::cout << std::endl;


    //left rotate the array by 2 times
    int rotate_by=2;
    for (int r = 0; r < rotate_by; r++)
    {
        int first=arr.A[0]; 
        for (int i = 0; i < arr.length-1; i++)
        {
            arr.A[i]=arr.A[i+1];
        }
        arr.A[arr.length-1]=first;
    }

    cout<<"Array after left rotating by "<<rotate_by<<" times: ";
    display(arr.A, arr.size, arr.length);
    std::cout << std::endl;

    //insert an element in sorted array
    //assuming the array is sorted in ascending order
    std::sort(arr.A, arr.A + arr.length); // sorting the array first
    int sorted_element=5;

    temp=arr.length;
        {
            while (arr.A[temp-1]>sorted_element)
            {
                arr.A[temp]=arr.A[temp-1];
                temp--;
            }
            arr.A[temp]=sorted_element;
            arr.length++;

        }

    cout<<"Array after inserting "<<sorted_element<<" in sorted array: ";
    display(arr.A, arr.size, arr.length);
    std::cout << std::endl;

    // move all negative numbers to left side of the array
    
    int a[]={-6,-8,0,-9};
    // append it to array arr
    for (int i = 0; i < 4; i++)
    {
        arr.A[arr.length]=a[i];
        arr.length++;
    }

    cout<<"Array before moving negative numbers to left: ";
    display(arr.A, arr.size, arr.length);

    std::cout << std::endl; 
    // move all negative numbers to left side of the array
    int left=0;
    int right=arr.length-1;
    while (left<right)
    {
        while (arr.A[left]<0) left++;
        while (arr.A[right]>=0) right--;
        if (left<right){
            temp=arr.A[left];
            arr.A[left]=arr.A[right];
            arr.A[right]=temp;
        }
    }

    cout<<"Array after moving negative numbers to left: ";
    display(arr.A, arr.size, arr.length);
    std::cout << std::endl;

    int q[] = {3, 5, 7,9, 11,13};
    int m = 3; // size of q
    int n = arr.length; // size of arr
    int* merged = new int[m + n];

    // merge arr and q into merged
    std::sort(arr.A, arr.A + arr.length); // sorting the array first
    i = 0, j = 0;
    int k = 0;
    while (i < n && j < m) {
        if (arr.A[i] < q[j]) {
            merged[k++] = arr.A[i++];
        } else {
            merged[k++] = q[j++];
        }
    }   
    while (i < n) {
        merged[k++] = arr.A[i++];
    }
    while (j < m) {
        merged[k++] = q[j++];
    }

    cout<<"Merged array: ";
    display(merged, m + n, m + n);
    std::cout << std::endl;

    delete []merged;
    // deallocate memory
    delete[] arr.A;

    // Finding a Pair of Elements with sum K
    int sumK = 14;
    bool found = false;
    for (int i = 0; i < arr.length; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.A[i] + arr.A[j] == sumK)
            {
                cout<<"Pair found: ("<<arr.A[i]<<", "<<arr.A[j]<<") with sum "<<sumK<<endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (!found)
    {
        cout<<"No pair found with sum "<<sumK<<endl;
    }

    // Finding Max and Min in a single Scan
    int maxElement=arr.A[0];
    int minElement=arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i]>maxElement)
        {
            maxElement=arr.A[i];
        }
        if (arr.A[i]<minElement)
        {
            minElement=arr.A[i];
        }
    }
    cout<<"Maximum element in the array: "<<maxElement<<endl;
    cout<<"Minimum element in the array: "<<minElement<<endl;


    cout<<"********************************************"<<endl;


    //set operations using arrays
    Array setA;
    setA.size=10;
    setA.length=5;
    setA.A=new int[setA.size]{2,4,6,8,10};      
    Array setB;
    setB.size=10;
    setB.length=4;
    setB.A=new int[setB.size]{3,6,9,12};

    // union of setA and setB
    Array unionSet;
    unionSet.size=setA.size+setB.size;
    unionSet.A = new int[unionSet.size];
    int p=0,q1=0;
    while (p<setA.length && q1<setB.length)
    {   
        if (setA.A[p]<setB.A[q1])
        {
            unionSet.A[unionSet.length++] = setA.A[p++];
        }
        else if (setB.A[q1]<setA.A[p])
        {
            unionSet.A[unionSet.length++] = setB.A[q1++];
        }
        else
        {
            unionSet.A[unionSet.length++]=setA.A[p++];
            q1++;  // we did 
        }
    }
    while (p<setA.length)
    {
        unionSet.A[unionSet.length++]=setA.A[p++];
    }
    while (q1<setB.length)
    {
        unionSet.A[unionSet.length++]=setB.A[q1++];
    }   

    cout<<"Union of setA and setB: ";
    display(unionSet.A, unionSet.size, unionSet.length);
    std::cout << std::endl;

    // other approach can be like 
    // copy element from A(check if A[i]==B[j], if so dont copy) and B to unionSet
    // but that would be less efficient as it would take O(n^2) time in worst case


    delete[] unionSet.A;

    // intersection of setA and setB
    Array intersectionSet;
    intersectionSet.size=(setA.size<setB.size)?setA.size:setB.size;
    intersectionSet.A=new int[intersectionSet.size];        
    p=0; q1=0;
    while (p<setA.length && q1<setB.length)
    {   
        if (setA.A[p]<setB.A[q1])
        {
            p++;
        }
        else if (setB.A[q1]<setA.A[p])
        {
            q1++;       
        }
        else
        {
            intersectionSet.A[intersectionSet.length++]=setA.A[p++];
            q1++;
        }
    }   
    cout<<"Intersection of setA and setB: ";
    display(intersectionSet.A, intersectionSet.size, intersectionSet.length);
    std::cout << std::endl;
    delete[] intersectionSet.A;


    // difference of setA and setB (setA - setB)
    Array differenceSet;
    differenceSet.size=setA.size;           
    differenceSet.A=new int[differenceSet.size];

    p=0; q1=0;
    while (p<setA.length && q1<setB.length)     
    {   
        if (setA.A[p]<setB.A[q1])
        {
            differenceSet.A[differenceSet.length++]=setA.A[p++];
        }
        else if (setB.A[q1]<setA.A[p])
        {
            q1++;       
        }
        else
        {
            p++;
            q1++;
        }
    }   
    while (p<setA.length)
    {
        differenceSet.A[differenceSet.length++]=setA.A[p++];
    }   
    cout<<"Difference of setA and setB (setA - setB): ";
    display(differenceSet.A, differenceSet.size, differenceSet.length);
    std::cout << std::endl;
    delete[] differenceSet.A;

    // symmetric difference of setA and setB
    Array symDifferenceSet;
    symDifferenceSet.size=setA.size+setB.size;           
    symDifferenceSet.A=new int[symDifferenceSet.size];  
    p=0; q1=0;
    while (p<setA.length && q1<setB.length)     
    {   
        if (setA.A[p]<setB.A[q1])
        {
            symDifferenceSet.A[symDifferenceSet.length++]=setA.A[p++];      
        }
        else if (setB.A[q1]<setA.A[p])
        {   
            symDifferenceSet.A[symDifferenceSet.length++]=setB.A[q1++];       
        }
        else
        {
            p++;
            q1++;
        }
    }   
    while (p<setA.length)
    {   
        symDifferenceSet.A[symDifferenceSet.length++]=setA.A[p++];
    }   
    while (q1<setB.length)
    {   
        symDifferenceSet.A[symDifferenceSet.length++]=setB.A[q1++];       
    }
    cout<<"Symmetric Difference of setA and setB: ";
    display(symDifferenceSet.A, symDifferenceSet.size, symDifferenceSet.length);
    std::cout << std::endl;
    delete[] symDifferenceSet.A;

    // set membership test for an element in setA
    int memberElement=6;
    bool isMember=false;            
    for (int i = 0; i < setA.length; i++)
    {
        if (setA.A[i]==memberElement)
        {
            isMember=true;
            break;
        }
    }
    if (isMember)
    {
        cout<<"Element "<<memberElement<<" is a member of setA"<<endl;
    }
    else
    {   
        cout<<"Element "<<memberElement<<" is not a member of setA"<<endl;
    }


    // deallocate memory
    delete[] setA.A;
    delete[] setB.A;

    return 0;
}
