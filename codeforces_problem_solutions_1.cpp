#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
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
string Mishka_and_Game()
{
    int n; cin>>n;
    int a;int b;
    int Mishka=0;
    int Chris=0;
    for (int i =0; i<n; i++)
    {
        cin>>a>>b;
        if (a>b)
        {Mishka++;}
        else if(b>a)
        {Chris++;}
    }

    if(Chris>Mishka)
    {return "Chris";}
    else if (Mishka >Chris)
    {return"Mishka";}
    else
    {return"Friendship is magic!^^";}
}
string Dragons()
{
    int s;int n;
    cin>>s >> n;
    vector <int> arrx(n,0);
    vector <int> arry(n,0);
    for (int i=0; i<n;i++)
    {
        cin >>arrx.at(i);
        cin >>arry.at(i);
    }
    while (!arrx.empty())
    {
        auto min = std::min_element(arrx.begin(), arrx.end());
        int min_index = distance(arrx.begin(), min); 
        if (s > *min)
        {
            arrx.erase(min);
            s=s+arry.at( min_index);
            arry.erase(arry.begin() + min_index); 
        }
        else
        {
            return "NO";
        }
    }
    return "YES";
}
/*int Olya_and_Game_with_Arrays()
{
    int test_cases; cin>>test_cases;

    for (int i=0; i<test_cases; i++)
    {
        int number_of_arrays; cin>>number_of_arrays;

        for (int j=0; j<number_of_arrays; j++)
        {
            int number_of_elements; cin >>number_of_elements;
            vector <int> arr(4,50);
            for (int h=0; h<number_of_elements; h++)
            {
                cout<<"fghj";
            }
        }
    }
}*/
string  I_Wanna_Be_the_Guy()
{
    int n; cin>>n;
    int x; cin>>x;
    vector<int> arrx(x,0);
    for(int i=0 ; i<x; i++ )
    {
        cin>>arrx.at(i);
    }

    int y; cin>>y;
    vector<int> arry(y,0);
    for(int i=0 ; i<y; i++ )
    {
        cin>>arry.at(i);
    }

    arrx.insert (arrx.end(),arry.begin(),arry.end());

    for(int i=1 ; i<=n; i++ )
    {
        if (!std::count(arrx.begin(), arrx.end(), i))
        {return "Oh, my keyboard!";}
    }
    return "I become the guy.";
    

}
int Buy_a_Shovel()
{
    int k;int r;
    cin>>k>>r;
    int i=1;
    while (true)
    {
        if(i*k%10==0 || i*k%10==r )
        {
            return i++;
        }
        i++;
    }
}
long long Xenia_and_Ringroad()
{
    int n; int m;
    cin>>n>>m;
    long long num;
    long long time;
    long long pos=1;
    for(int i=0 ; i<m ;i++)
    {
        cin>>num;
        if(i==0)
        { 
            time=num-1;
            pos=num;
        }
        else if (num<pos) 
        {
            time+=((n-pos)+num);
            pos=num;
        }
        else
        {
            time+=(num-pos);
            pos=num;
        }
    }
    return time;
}
void t_primes()
{
    int n; cin>>n;
    int t;
    int divisors=0;
    for (int i=0; i<n;i++)
    {
        cin>>t;
        for (int j=1; j<=sqrt(t) ;j++)
        {
            if( t==j*j)
            divisors++;
            else if(t%j==0)
            divisors+=2;
            if (divisors>3)
            {
                cout<<"NO"<<endl;
                break;
            }
            else if (divisors==3)
            { 
                cout<<"YES"<<endl;
                break;
            }
        }
        if (divisors<3)
        cout<<"NO"<<endl;
        
        divisors=0;
 
    }
 
}
int Insomnia_cure()
{
    vector <int> arr1 (4,0);
    
    for (int i=0; i<4;i++)
    {
        cin>>arr1.at(i);
    }
    
    int d;
    cin >>d;
    vector <int> arr (d,0);
    for (int i=0; i<4;i++)
   { 
       for (int j=arr1.at(i)-1; j<d;j+=arr1.at(i))
        {
            arr.at(j)=1;
        }
   }
   
    return d-(std::count(arr.begin(), arr.end(), 0));
}
int IQ_test()
{
    int n; cin>>n;
    vector <int> arr(n,0);
    int d;
    for(int i=0 ;i<n; i++)
    {
        cin>>d;
        if (d%2==0)
        {
            arr.at(i)=0;
        }
        else
        {
            arr.at(i)=1; 
        }
    }
    
    if (std::count(arr.begin(), arr.end(), 0)==1)
    {
        return  (std::find(arr.begin(), arr.end(), 0)- arr.begin())+1;
    }
    else 
    {
        return  (std::find(arr.begin(), arr.end(), 1)- arr.begin())+1;
    }
   
}
double Vanya_and_Lanterns()
{
    int n ,l;
    cin>>n>>l;
    vector <int> arr(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>arr.at(i);
    }
    sort(arr.begin(), arr.end());
    int max_diff=0;

    for(int i=0; i<n-1; i++)
    {
        max_diff= max (max_diff, arr.at(i+1)-arr.at(i));
    }
    double min_light_radius = max( max_diff / 2.0, max(double(arr[0]), double(l - arr[n - 1])));
    return min_light_radius;
}
int BerSU_Ball()
{
    int n,m; 
    cin>>n;
    vector<int> arrn(n,0);
    for(int i=0 ; i<n;i++)
    {
        cin>>arrn.at(i);
    }

    cin>>m;
    vector<int> arrm(m,0);
    for(int i=0 ; i<m;i++)
    {
        cin>>arrm.at(i);
    }

    int count=0;

    sort(arrn.begin(), arrn.end());
    sort(arrm.begin(), arrm.end());
   
    for (int i : arrm)
    {
        if (std::count(arrn.begin(), arrn.end(), i-1))
        {
            arrn.erase(std::find(arrn.begin(), arrn.end(), i-1));
            count++;
        }
        else  if (std::count(arrn.begin(), arrn.end(), i))
        {
            arrn.erase(std::find(arrn.begin(), arrn.end(), i));
            count++;
        }
        else  if (std::count(arrn.begin(), arrn.end(), i+1))
        {
            arrn.erase(std::find(arrn.begin(), arrn.end(), i+1));
            count++;
        }
    }
    return count;
}
void Worms()
{
    int n,m;
    cin>>n;
    vector <int> arrn(n,0);
    for (int i=0; i<n;i++)
    {
        cin>>arrn.at(i);
    }

    cin>>m;
    vector <int> arrm(m,0);
    for (int i=0; i<m;i++)
    {
        cin>>arrm.at(i);
    }

    vector<double> sum( arrn.size() );
    partial_sum( arrn.begin(), arrn.end(), sum.begin() );
    for (int i :arrm)
    {
        auto pos= std::lower_bound(sum.begin(), sum.end(), i);
        cout<< (pos - sum.begin())+1<<endl;
    }
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
    //cout<<Lucky_Division();
    //cout<<Amusing_Joke();
    //cout<<Hit_the_Lottery();
    //cout<<Mishka_and_Game();
    //cout <<Dragons();
    //cout << Olya_and_Game_with_Arrays();
    //cout <<I_Wanna_Be_the_Guy();
    //cout <<Buy_a_Shovel();
    //cout <<Xenia_and_Ringroad();
    //t_primes();
    //cout<<Insomnia_cure();
    //cout<<IQ_test();
    //cout<<Vanya_and_Lanterns();
    //cout <<BerSU_Ball();
    //Worms();
    return 0;
}

