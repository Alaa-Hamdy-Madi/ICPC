#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void swap(int *x,int*y)
{
    int temp= *y;
    *y= *x;
    *x= temp;
}

void print_arr(int arr[],int size)
{
    for (int i=0; i<size; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void bubble_sort(int arr[],int size)
{
   for (int i =0; i<size; i++) // num of iteration =size-1
   {
        for (int j=0; j< size-i-1 ; j++) // num of compare opreation in each iteration
        { // the size of arr decreases by one for each iteration
            if (arr[j+1]<arr[j])
            {
                swap(arr[j+1],arr[j]);
            }
            //after each iteration at least one element bing in his sorted place
            // so in next iteration we dident compaer with it  and decreases the size
        }
   }
}

void insertion_sort(int arr[],int size)
{
    for (int j=1; j<size; j++) // num of iteration =size-1
    {
        int i=0;
        while( arr[j] > arr[i] ) 
        // compaer until find the right place in sorted part 
        // from index 0 to the end of sorted part
        {
            i++;
        }
        int m=arr[j] ;

        for (int k=0; k<j-i-1;k++) //shifting all element in sorted part
        {
            arr[j-k]=arr[j-k-1];
        }
        arr[i]=m ;
    }

}

int linear_search(int arr[],int size,int x)
{
    int i=0;
    while (i< size && x != arr[i])
    {
        i++;
    }
    /*if (i < size) 
        return i;
    else
        return -1;*/
    return (i < size) ? i : -1;

    
}

int binary_search(int arr[],int size,int x)
{
    int i= 0;
    int j= size-1;
    while (i<j)
    {
        int m= floor((i+j)/2);
        if(x > arr[m])
            i=m+1;
        else
            j=m;
    }
    return (x==arr[i]) ? i : -1;
}


void generateSubsequences(const std::vector<int>& input, std::vector<int>& current, int index, std::vector<std::vector<int>>& subsequences) {
    // Base case: when we reach the end of the input vector
    if (index == input.size()) {
        // Store the current subsequence in the result vector
        subsequences.push_back(current);
        return;
    }

    // Exclude the current element from the subsequence
    generateSubsequences(input, current, index + 1, subsequences);

    // Include the current element in the subsequence
    current.push_back(input[index]);
    generateSubsequences(input, current, index + 1, subsequences);

    // Backtrack by removing the last element to explore other possibilities
    current.pop_back();
}


int main ()
{
    int arr[4]={7,2,5,1};
    print_arr(arr,4);
    insertion_sort (arr,4);
    print_arr(arr,4);
    cout << linear_search(arr,4,5)<<endl;
    cout << binary_search(arr,4,5)<<endl;


    vector<int> input = {1, 2, 3};
    vector<int> current;
    vector<vector<int>> subsequences;

    generateSubsequences(input, current, 0, subsequences);

    cout << "All generated subsequences:" <<endl;
    for (const vector<int>& subsequence : subsequences) {
        for (int num : subsequence) {
            cout << num << " ";
        }
        cout << endl;
    }

}
