#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int Tram()
{
    int n;
    cin >> n;

    int capacity = 0;
    int current_passengers = 0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        current_passengers -= a;  // Passengers exiting
        current_passengers += b;  // Passengers entering

        capacity = max(capacity, current_passengers);  // Update the capacity
    }

   return capacity ;
}
string Translation()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    
    if (s.size() != t.size())
    {
        return "NO"; 
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[s.size() - 1 - i])
            {
                return "NO"; 
            }
        }
        return "YES";
    }
}
string Queue_at_the_School()
{
    int n, t;
    cin >> n >> t;
    
    string s;
    cin >> s;
    
    for (int i = 0; i < t; i++) 
    {
        for (int j = 0; j < n - 1; j++) 
        {
            if (s[j] == 'B' && s[j + 1] == 'G') 
            {
                swap(s[j], s[j + 1]);
                j++; 
            }
        }
    }
    
   
    return s;
}
int  Magnets()
{
    int n;
    cin>>n;

    string arr[n];
    for ( int i =0; i<n; i++)
    {
        string position;
        cin>>position;
        arr[i]=position;
    }
    int count=0;
    for ( int i =0; i<n-1; i++)
    {
        if (arr[i]!=arr[i+1])
        {
            count++;
        }
    }
    return count+1;

}
int Vanya_and_Fence()
{
    int a,b;
    cin>>a>>b;
    int total=0;
    for (int i = 0; i < a; ++i) {
        int height;
        cin >> height;
        total++;
        if(height>b)
        {
            total++;
        }
    }
    return total;
}
int Beautiful_Year()
{
    string year;
    cin>>year;
    bool flag =true;
    int years=stoi(year);
    years++;
    year=to_string(years);
    while (flag)
    {
        for (int i=0; i<year.size();i++)
        {
            for (int j=0; j<year.size();j++)
            {
                if(i!=j && year[i]==year[j])
                {
                    flag=false;
                }
            }
        }

        if (!flag)
        {
            years++;
            year=to_string(years);
            flag =true;
        }
        else
        {
            return years;
        }
    }
    return 0;
}
int Games()
{
    int n;
    cin>>n;
    int home ;int guest;
    int home_uniform[n]={0};
    int guest_uniform[n]={0};
    int count=0;
    for (int i=0; i<n; i++)
    {
        cin>>home>>guest ;
        home_uniform[i]=home;
        guest_uniform[i]=guest;
    }
    for (int j=0; j<n; j++)
    {
        for (int h=0; h<n; h++)
        {
            if (home_uniform[j]==guest_uniform[h])
            {
                count++;
            }
        }
    }
    return count;
}
int Puzzles()
{
    int n, m;
    cin >> n >> m;
 
    vector<int> puzzles(m);
    for (int i = 0; i < m; ++i) {
        cin >> puzzles[i];
    }
 
    sort(puzzles.begin(), puzzles.end());
 
    int minDifference = puzzles[n - 1] - puzzles[0];
    for (int i = 0; i <= m - n; ++i) {
        minDifference = min(minDifference, puzzles[i + n - 1] - puzzles[i]);
    }
    return minDifference;
}
bool is_lucky(string num)// it's not a problem , its just for the next problem 
{
    bool flag =true;
    for (int i =0; i<num.size(); i++)
    {
        int decimal = num[i] - '0';
        if ( decimal!=4 && decimal!=7 )
        {
            flag =false;
        }
    }
    return flag;
}
string Lucky_Division() 
{
    int num ;
    cin>>num;
    if (is_lucky(to_string (num)))
    { 
        return "YES";
    }
    else
    {
        int i=0;
        while (i< num)
        {
            if( is_lucky(to_string (i)) && num%i==0)
            {
                return "YES";
            }
            i++;
        }
        return "NO";
    }
}
string Amusing_Joke()
{
    string line_1;  string line_2;  string line_3;
    cin>>line_1; cin>>line_2;   cin>>line_3;
    line_1=line_1+line_2;
    for(int i=0; i< line_1 .size(); i++)
    {
        int pos=line_3.find(line_1[i]);
        if (pos != std::string::npos)
        {
            line_3.erase(pos, 1);
        }
        else
        {
            return "NO";
        }
    }
    if (line_3.empty())
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}
int Hit_the_Lottery()
{
    int n ; cin >>n;
    int arr[5]={100,20,10,5,1};
    int count=0;
    int i=0;
    while (i<5 && n>0)
    {
        while (n>=arr[i] && n>0)
        {
            n-=arr[i];
            count++;
        }
        i++;
    }
    return count;
}
string Registration_system()
{

}




int main()
{
    //cout << Tram();
    //cout << Translation();
    //cout << Queue_at_the_School();
    //cout<< Magnets();
    //cout<<Vanya_and_Fence();
    //cout <<Beautiful_Year();
    //cout<< Games();
    //cout<<Puzzles();
    cout<<Lucky_Division();
    //cout<<Amusing_Joke();
    //cout<<Hit_the_Lottery();
    return 0;
}

