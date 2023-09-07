#include <iostream>
#include <string> 
#include <vector>
#include <cmath> 
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


void Ternary_String()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        string str; cin>>str;
        //int m= floor (str.length()/2);
        //string substring = str.substr(m-1, 3); 
        
    }
}
void Pashmak_and_Garden()
{
    int x1,y1,x2,y2 ; scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    if(x1==x2)
    {   printf("%d ",x1 +(y2-y1));
        printf("%d ",y1  );
        printf("%d ",x2 +(y2-y1));
        printf("%d",y2  );
    }
    else if(y1==y2)
    {
        printf("%d ",x1 );
        printf("%d ",y1 +(x2-x1) );
        printf("%d ",x2 );
        printf("%d",y2 +(x2-x1) );
    }
    else if(abs(x2-x1)!=abs(y2-y1))
    {
        printf("%d ",-1 );
    }
    else
    {
        printf("%d ",x1 );
        printf("%d ",y2  );
        printf("%d ",x2 );
        printf("%d",y1  );
    }
}
void DZY_Loves_Chessboard()
{
    int n,m; scanf("%d %d",&n,&m);
    vector<vector<char>> arr(n, vector<char>(m));
    char current_color = 'B';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char cell;
            std::cin >> cell;

            if (cell == '.')
            {
                if ((i + j) % 2 == 0)
                    arr[i][j] = 'B';
                else
                    arr[i][j] = 'W';
            }
            else
            {
                arr[i][j] = '-';
            }
        }
    }

   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}
void Not_Equal_on_a_Segment()
{
    int n,m,l,r,x,pos; scanf("%d %d",&n,&m);
    vector <int> arr (n,0);
    
    for (int i=0; i<n;i++)
    {
        cin>>arr.at (i);
    }
    while (m--)
    {
        scanf("%d %d %d",&l,&r,&x);
        pos=-1;
        for (int i=l-1; i<r;i++)
        {
            if (arr[i]!=x)
            {
                pos=max(pos,i+1);
            }
        }
        printf("%d\n",pos);
    }

}

std::unordered_map<char, std::vector<int>> freq(const std::string& word)
{
    std::unordered_map<char, std::vector<int>> charIndices;

    for (int i = 0; i < word.size(); i++) {
        charIndices[word[i]].push_back(i);
    }

    return charIndices;
}


void q__5()
{
    string word;
    cin>>word;
    unordered_map<char, vector<int>> frequencyMap = freq(word);
    unordered_map<char, vector<int>> frequency_odd_Map ;
    int odd=0,swap=0;

    
    for (const auto& pair : frequencyMap)
    {
        if((pair.second).size()%2==1)
        {
            odd++;
            frequency_odd_Map[pair.first]=pair.second;
        }
    }

    if (word.size()%2==0 && odd!=0)
    {
        cout<<"impossible";
        return;
    }
    else if(word.size()%2==1 && odd!=1)
    {
        cout<<"impossible";
        return;
    }
    else
    {

        for( int i=0;i< word.size()/2;i++ )
        {
            if (word[i]!=word[ word.size()-i])
            {
                int max_index = frequencyMap[word[i]].back();
                swap+= (word.size()-i)-max_index;
                char removedChar = word[max_index];
                word.erase(max_index, 1);
                word.insert(word.size()-i, 1, removedChar);
                cout<<word<<"\n";
                frequencyMap= freq( word);
            }
        }
        cout<<word;
        cout<<swap<<"\n";

         for (const auto& pair : frequency_odd_Map)
         {
            cout<<(pair.first).first<<"\n";
            cout<<(pair.first).second<<"\n";
         }
        return;


    }      
}
 


int main ()
{
   // Ternary_String();
   //DZY_Loves_Chessboard ();
   // XXXXX();
   //Not_Equal_on_a_Segment();
    int cases;
    cin>>cases;
    while(cases--)
    {
        q__5();
    }
    return 0;
}