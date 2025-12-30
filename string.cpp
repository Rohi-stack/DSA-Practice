#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    // length of string
    const char * name ="Singh 03-conditionals-loops";     // read only we can't write them 
    int i=0;
    // name.touppercase();
    while(name[i]!='\0'){
        i++;
    }
    cout<<"Length of string is: "<<i<<endl;

    // copy string
    const char * source ="Hello, World!";
    char destination[50];
    i=0;
    while(source[i]!='\0'){
        destination[i]=source[i];
        i++;
    }
    destination[i]='\0'; // null character at end of string if we don't add it garbage values will be printed and will be treated as part of string
    cout<<"Copied string is: "<<destination<<endl;
    cout<<typeid(destination).name()<<endl; //A50_c means array of 50 characters     
    
    // toUpperCase
    int len=i;
    for (int i = 0; i < len; i++)
    {
        if(destination[i]>='a' && destination[i]<='z'){
            destination[i]-=32;
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        cout<<destination[i];
    }
    cout<<endl;
    //toLowerCase

    len=i;
    for (int i = 0; i < len; i++)
    {
        if(destination[i]<='Z' && destination[i]>='A'){
            destination[i]+=32;
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        cout<<destination[i];
    }
    cout<<endl;
    
    return 0;
}
