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

    // counting vowel and consonents in a string called destination

    i=0;
    int vowel=0;
    int consonet=0;
    while (i<len)
    {
        if (destination[i]>=97 and destination[i]<=122)
        {
           if(destination[i]=='a'||destination[i]=='e'||destination[i]=='i'||destination[i]=='o'||destination[i]=='u')
                    vowel++;
            else
               consonet++;
        }
        
        if (destination[i]>=65 and destination[i]<=90)
        {

           if(destination[i]=='a'-32||destination[i]=='e'-32||destination[i]=='i'-32||destination[i]=='o'-32||destination[i]=='u'-32)
                    vowel++;
            else
               consonet++;
        }

        i++;
        
    }
    
    cout<<destination<<" having length: "<<len<<endl;

    cout<<"vowel:"<<vowel<<" and "<<"consonents: "<<consonet<<endl;

    // valid String

    for (int i = 0; i < len; i++)
    {
        if((destination[i]>=65 && destination[i]<<90 )||(destination[i]>=65+32 && destination[i]<<90+32))
            cout<<destination[i]<<" :Valid String"<<endl;

        else
            cout<<destination[i]<<" :InValid String"<<endl;

    }
    
    
    //reverse a String

    i=0;
    int j=len-1;
    char temp;
    while (j>i)
    {
        temp=destination[i];
        destination[i]=destination[j];
        destination[j]=temp;
        i++;
        j--;
    }
    cout<<"Reversed: ";
    cout<<destination<<endl;
    
    i=0;
    j=len-1;
    while (j>i)
    {
       
        temp=destination[i];
        destination[i]=destination[j];
        destination[j]=temp;
        i++;
        j--;
    }
    cout<<destination<<endl;

    return 0;
}
