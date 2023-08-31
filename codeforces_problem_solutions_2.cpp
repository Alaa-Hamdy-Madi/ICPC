#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <cstdio>
#include <math.h>


void Insomnia_cure(){
    int k=0;
    int arr[5]={0};
    for (int i=0;i<5;i++){
        cin>>arr[i];        
        }
    int arr2[arr[4]]={0};
    for (int j=0;j<arr[4];j++){
        for(int h=0;h<4;h++){
            if(j+1>=arr[h] && (j+1)%arr[h]==0){
                arr2[j]++;
            }

        }
    }
    for (int i=0;i<arr[4];i++){
        if (arr2[i]!=0)  {
            k++;
        }     
        }
    cout<<k;
}
bool isprime(long long x) {
	int i;
	for(i=2;i<=sqrt((double)x);i++)
	{
		if(x%i==0) return false;
	}
	return true;
}
void t_prime(){
	int N;
     int i;
	__int64 X,x;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%I64d",&x);
		X = sqrt((double)x);
		
		if(x>1 && X*X== x && isprime(X))printf("YES\n");
		else printf("NO\n");
	} 
}
void Nearly_Lucky_Number(){
    std::string x;
    std::cin>>x;
    int h=0;
    for (int i=0;i<x.length();i++){
        if (x[i]=='7' || x[i]=='4' ){ 
            h++;  
        }
        
    }
    if (h==7 || h==4){
        std::cout<<"YES";
    }
    else{
        std::cout<<"NO";
    }
    
    
    
}
string Football(){
    string x;
    int f=1;
    cin>>x;
    for (int i=0;i<x.length();i++){
       if (x[i]==x[i+1]){
        f++;
       }
      else{
        if (f>=7){
            return "YES";
        }
        else{f=1;}
      }
    
}
    return "NO";
}
void illy(){
    string s="",k="",f;
    cin>> f ;
    if (stoi (f)<0){
        int  d=f.length();
        for (int i=0;i<d;i++){
            if (i!=d-1){
                s=s+f[i];
            }
            if (i!=d-2){
                k=k+f[i];
            }
        }

        
        int n=stoi (s);
        int n2=stoi (k);
        if (n>n2){
            
            cout<<n<<endl;
            

        }
        else{
            cout<<n2<<endl;

        }
        
    }
    else {
        cout<<f;
}
}
void Raising_Bacteria(){
    int x, ans = 0;
    cin >> x;
    
    while( x>1){
           if( x%2==0){
               x /= 2;
           }
           else {
                x--;
                ans++;
           }
    }
    
    cout << ans + 1 << endl;
    
    //system("pause");
}


int main()
{
   //Insomnia_cure();
   //t_prime();
   //Nearly_Lucky_Number();
   //Football();
   //illy();
   //Raising_Bacteria();
    int a,b;
    cin>>a>>b;
    int s=0;
    while (b>a){
        if (b%2 !=0){
             b+=1;
        }
        
        else {
            b=b/2;
        }
        s=s+1;   
    }
    s=s+(a-b);
    cout<<s;
    return 0;

}


 
