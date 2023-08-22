#include <iostream> //input output stream
using namespace std;
#include <stdlib.h>  // for importing rand() fun
#include <ctime> // for importing time () fun
#include <cmath> // for importing built in fun such ( max,min,pow,sqrt,tan....)

// function definition:(should be out the main function)
//? if we need to put the deffintion after main, it should to write just the first line here and then all def aftter main
// type of return--- name of fun (prameter1,prameter2) {  }
int sum(int g ,int p) //! if the fun dose not return the type =void 
{
    return g+p ;
} 


int main()
{
cout<<"hello world."<<endl;
cout<<"Iam alaa.\n";
cout<<"Iam 19.\n"<<"\tin DSAI.\n";

//this is one line comment
/*this is 
multpile line comment*/
//? blue comment
//! red coment
//todo orange coment

int x =234;
cout<< x <<endl;
cout<< "x is equal " <<x <<endl;

string name="alaa";
cout << name <<endl;

double y= 3.2; // can be 14 digit after dot
cout << y <<endl;

float z= 5.3; // can be 7 digit after dot
cout << z <<endl;

char A='a';  // JUST ONE CHRACTER  IN SINGEL QOTATION 
cout << A <<endl;

bool fail=true; // it print 1 and 0 if false
cout << fail <<endl;

/* and =&& ,or=||
*/


int d;
cout<<"prompet massege\n";
cin>>d; // character input

// x++ means print x then increase it by 1 (postfix)
// ++x means increase x by 1 (prefix)
// x+=a means increase x by a
// the same for decrement -- 


int a =10;
if(a==10)   
{// if it just one line it can be without {} but it required if multipleline
    cout<<"a=10"<<endl;
}
else if(a==11)
{
    cout<<"a=11\n";
}
else
{
    cout<<"somthing else\n";
}

/*
 can write if  statment  like that:
 (a==10)?cout<<"a=10\n":cout<<"a==somthing else"
*/

int r=10;
switch(r)
{
    case 3 :   // mean if r=3
        cout<<"r=10\n";
        break; // the end of the code implement in this case 

    case 10 :  // mean if r=10
        cout<<"r=11\n";
        break;

    default:  // mean else
        cout<<"r=12\n";
        break;

}


for (int w=1; w<12;++w)
{
    cout<< w << endl;
}


int t=1;
while(t<=12) // if condition true implement 
{
    cout<<t<<endl;
    ++t;
}

int f =1;
do
{ // implement  this once and then  if condition true repeat
    cout<< f <<endl;
    ++f;
}while(f <=12) ;


cout<< sum(3,3)<<" this is the sum"<<endl;

cout<<rand()<<" this is long random num\n";
//! num % a = number less than a for sure
// if we need short random num that is lees than a  ,ues %
cout<<rand()%7<<" this is short random num less than 7\n";

// rand () it return the same random nums every run
// to change them write before it srand(time(0)) 
//? time() is function that calclute the secounds from 1970 (from ctime library)

// if  we need to genreat random num between a:b such b>a (a=start , b=end)
// ues this rule:: start + rand()%(end-start)
srand (time(0));
cout<< 30+rand()%( 60-30) <<" this is random number 30:60 \n" ; //print random number between 30:60
//! if we need the end to apper just add 1 :: start + rand()%(end-start+1)



// build in function:
// max(a,b) \ min(a,b) \ pow(a,b) =a**b \ sqrt(a) \ ceil(4.1)=5 \ floor(2.9)=2 \ fabs (-1)=1 
// sin() \ cos() \ tan () \ exp(a)=e**a \ fmod (2.2 ,3.4) 
//? all of them from cmath library

//! % operator dosent work with float so insted we ues fmod (2.2 ,3.4) fun

// if there is two fun with the same name the compiler differ them by th prameeter 
// if they are have same num of prameter and type  it  genreat error
// so if dont need error should make the parameter deffernt (it could by add new int prameter just ues for diff)
// void print() is differnt than void print(int a) and it dosent make error

//! recursion: that the fun call itself 
/* int fact(int n)    // fact mean a!
{
    if  (n==1)
       { return 1;}
    else
    return n* fact(n-1)
  }  */



//? three way to make array  ( first index is zero and its value = x[0]) :

//! 1-   datatype --- name of array [zise] ={ element1 , element2 , ....} ;
            int arr1[4]={1,2,3,4};
            // it make error if we but  between the { } more than the size
            int arr2[4]={0}; 
            // that mean generat array with size 4 all element =0
            int arr3[4]={1,2}; 
            // if we enter num of values less than size it dosent make error,and the remain ones become 0

//! 2-   datatype --- name of array [] ={ element1 , element2 , ....} ;
            int arr4[]={1,2,3,4};
            // it didnt make error if we enter out of range index ,instead it return random num 

//! 3-   datatype --- name of array [zise]  ;
            int arr5[a];
            // it genrate random array with size a



// we can print 1D array just with for loop (return each value alone by it index)
// modfying value in array by it index:
    arr1[0]=23;
// if  we need to make the values in array an able yo change just add const at begining of deffnition
// that mean any trail to change element make error
    const int arr6[4]={0}; 




//? how to calculate the len of array:
cout << sizeof(arr1)/sizeof(arr1[0])<<" the len of arr1\n"; //for all datatype

cout << sizeof(arr2)/sizeof(int)<<" the len of arr2\n"; // just for int

string names[]={"ahmad","adel"};
cout << sizeof(names)/sizeof(string)<<" the len of  name array \n"; // just for string





//? 2D array  :

//! 1-   datatype --- name of array [num of rows] [num of columns] ={ element1 , element2 , ....} ;
            int arr2D1[2][3]={1,2,3,4,5,6}; // c order (row first)
            int arr2D2[2][3]={{1,2,3},{4,5,6}};
            // it make error if we but  between the { } more than the size

            int arr2D3[3][4]={0}; 
            // that mean generat array with size 3,4 all element =0
            int arr2D4[2][4]={1,2}; 
            // if we enter num of values less than size it dosent make error,and the remain ones become 0

            // int arr2D4[][]={1,2,3,4}; it  make error, need to specify the size of at least the first dimensionif
            //it  make error, if we enter out of range index 


// we can print 2D array just with nestad for loop (the first for row index ,the secound for column index)
// modfying value in 2D array by it index:
    arr2D1[0][1]=23;
// if  we need to make the values in array an able yo change just add const at begining of deffnition
// that mean any trail to change element make error
    const int arr2D6[2][4]={0}; 



//? POINTER : the var that store the place of another var ( cant stor it in normal var, it give error)

cout<< &x <<endl; // to get the place of var x
//? datatype of var  *   name of pointer = & name of var
int * p= &x ; // that mean creat pointer contain place of var x 
//! the datatype of pointer must be the same to the var
cout << p << *p <<endl; // that mean print the pointer (P/place of x) and then its value (*P/value of x) 
// can change the value of x by its pointer 
*p=7;

//! the array is pointer so if trying to print it ,it return place of first element  &arr1[0] == x 
cout<< & arr1[0] <<endl; // return the place of arr1 [0] datatype (pointer)
cout<< arr1 <<endl; // return the place of arr1 [0] datatype (int)
cout<< * arr1 <<endl; // return the value of arr1 [0]

cout<< & arr1[1] <<endl; // return int equal the place of arr1 [1]
cout<< arr1 +1 <<endl; // return int equal the place of arr1 [1] and so on...
cout<< * (arr1+1) <<endl; // return the value of arr1 [1]

//!  & arr1[0] == arr1 make error becues the differnce in data type  so it cant comper but the value of them is the same
int * pointer= NULL ;  // this made pointer without var that is equal nan
            

//? CALL BY VALUE

/*   i make as comment beceues it should be out the main fun and here make error
void set (int k)
{
    k=0
    cout<<"in the set fun " << a <<endl;
}*/

int k =10;
cout<<"before set fun " << k <<endl;
//set(k);   
//! here it be call by value such k in set fun is diffrent var than k here and have different place
cout<<"after set fun " << k <<endl;

//? CALL BY REFERENCE

/*void set (int *k)
{
    *m=0
    cout<<"in the set fun " << *m <<endl;
}*/

int m =10;
cout<<"before set fun " << m <<endl;
//set(&m);   
//! here it be call by reference such m in set fun is the same var  m here and have same place and same value
cout<<"after set fun " << m <<endl;



return 0;

} 


