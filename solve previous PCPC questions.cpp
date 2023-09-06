#include <iostream>
using namespace std;
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i, n) for(int i=0; i<int(n); i++)

int bubble_sort(int arr[],int size)
{
   int count=0;
   for (int i =0; i<size; i++) // num of iteration =size-1
   {
        for (int j=0; j< size-i-1 ; j++) // num of compare opreation in each iteration
        { // the size of arr decreases by one for each iteration
            if (arr[j+1]<arr[j])
            {
                swap(arr[j+1],arr[j]);
                count++;
            }
            //after each iteration at least one element bing in his sorted place
            // so in next iteration we dident compaer with it  and decreases the size
        }
   }
   return count;
}
void q_1_2013(){
    int cases,n;
    cin>>cases;
    while(cases--){
        cin>>n;
        int arr[n];
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
     cout<<bubble_sort(arr,n);
    }
}
void q_2_2013(){
    int foo=-1,first=-1;
    string a,b;
    cin>>a;
    cin>>b;
    
    char firstObject=b[0];
    char someObject=b[b.size()-1];
    
    for (int i=0;i<a.size();i++){
        if( a[i]==someObject){
           foo=i; 
        }
      if (first==-1){
        if( a[i]==firstObject){
           first=i;

      } } 
      
    }
    if (foo!=-1 &&first !=-1){
        cout<<first<<' '<<foo<<endl;
      }
    else{
        cout<<-1;
    }
}
void q_3_2013(){
    int n,count=1;
    cin>>n;
    
    while(n!=-1){
        int arr[n];
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        for (int i=0;i<n-1;i++){
            if (arr[i]!=arr[i+1]){
                count++;
                
            }
        }
        cout<<count<<endl;
        cin>>n;
        count=1;}
}
void q_4_2013(){
    int cases,count=0;
    int arr[10]={1,0,0,0,1,0,1,0,2,1};
    string word;
    cin>>cases;
    while(cases--){
        cin>>word;
      
        for(int i=0;i<word.size();i++){
            char d=word[i];
            count+=arr[d-'0'];
           
        }
        cout<<count<<endl;
        count=0;

    }
}
void q_5_2013(){
    int n,x;
    cin>>n;
    
    while(n--){
        int count=0;
        cin>>x;
        int a[x];
        int b[x];
        for (int i=0;i<x;i++) {
            a[i]=i+1;
        }
        std::partial_sum(a,a+x,b);
        for (int i:b)
        {
            count+=(i%1000000007)*6;
        }
        cout<<count<<endl;
    }   
}
bool check(int array[], int n)
{   
    bool flag = 0;

    for(int i = 0; i < n - 1; i++)      
    {         
        if(array[i] != array[i + 1])
            flag = 1;
    }

    return flag;
}
int comp(int x, int y)
{
    return x + y;
}


void xxxx(){
    ios_base::sync_with_stdio(false);
    int cases,num,h,x,sum=0;
    
    cin>>cases;
    while(cases--)
    {
        sum=0;
        cin>>h>>num;
        int arr[h];
        for(int i=0; i<h; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if (sum % num !=0)
        {
            cout<<h<<endl;
        }
        else {
        int total=h;
        int i=0;
        while(i<h)
        {
            if ((sum -arr[i])%num !=0 ||(sum-arr[h-1-i])%num!=0)
            {
                cout<<total-i-1<<endl;
                break;
            }
            else
            {
                i++;
            }
        }
        if (i==h)
            {
                cout<<-1<<endl;
            }
        
        }}

}
void q_1_2020(){
    int cases,num1,num2;
    cin>>cases;
    while(cases--)
    {
        cin>>num1>>num2;
        cout<<num1/num2<<" "<<num1%num2<<"\n";
    }

}
void q_2_2020(){
int cases,v=1;
    cin>>cases;
    string word;
    while(cases--)
    {
        cin>>word;
        for(int i=0; i<word.size(); i++) 
        {
            if (word[i]=='r')
            {
                if(word[i+1]=='n')
                {
                    cout<<"not sure \n";
                    v=0;
                    break;
                }
            }
        }
        if (v==1)
        {
            cout<<"sure \n";
        }
    }
}
void q_3_2020(){
    int cases,n,m;
    cin>>cases;
    while (cases--)
    {
        cin>>n>>m;
        cout<<n-m<<"\n";
    }

}
void q_4_2020(){
   int cases,a,b;
    cin>>cases;
    while(cases--)
    {   int max=-1,min=-1,vmax=-1,vmin=-1;
        cin>>a>>b;
        vector <int> sum1;
        vector <int> arr;
        for (int i=a;i<=b;i++)
        {   arr.push_back(i);
            int x=i,sum=0;
            while (x!=1)
            {
                if (x%2==0)
                {
                    x=x/2;
                    sum++;
                }
                else
                {
                    x=x*3+1;
                    sum++;
                }
            }
            
            sum1.push_back(sum);

        }
        

        
        cout<<arr.at(min_element(sum1.begin(),sum1.end())-sum1.begin())<<" ";
        cout<<arr.at(max_element(sum1.begin(),sum1.end())-sum1.begin())<<" ";



    } 
}
void q_5_2020(){
    int t=0,x,l=0;
    cin>>t;
    
    
    while(t--)
    {
        l=0;
        cin>>x;
        int arr[x];
        for (int i=0;i<x;i++){
            cin>>arr[i];
        }
        
        while (check(arr,x)){
            sort(arr, arr + x);
            for (int j=0;j<x-1;j++){
                arr[j]+=1;
                
            }
            l+=1;
        }
        
        cout<<l<<endl;
        }
 

    }
    vector<int>  freq(string  vec,vector<int> frequencyMap)
    {
        for (int element : vec) {
        frequencyMap[element]++;
        }
        return frequencyMap;
    
    }
    vector<int>  index(string  vec,int i,char a)
    {
        vector <int> indices;
        for (int j=i;i<(vec.size()-i);j++)
        {
            if (vec[j]==a)
            {
                indices.push_back(j);
            }
        }
    }

    int main() {
    /*q_1_2013()
    q_2_2013()
    q_3_2013()
    q_4_2013()
    q_5_2013()
    q_1_2020()
    q_2_2020()
    q_3_2020()
    q_4_2020()
    q_5_2020()*/
        
    ios_base::sync_with_stdio(false);    
    
    return 0;
}