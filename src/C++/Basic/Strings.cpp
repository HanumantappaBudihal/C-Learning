#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialization by rae string
    string string1("First string");
    cout << " String 1 : "<< string1 << endl;

    //initialization by another string
    string string2(string1);
    cout << " String 2 : "<< string2 << endl;

    //initialization by character with number of occurrence
    string string3(5, '#');
    cout << " String 3 : "<< string3 << endl;

    //initialization by part of another string
    string string4(string1, 2, 10);
    cout << " String 4 : "<< string4 << endl;
    
    //initilization by part of another string
    string string5(string2.begin(),string2.begin()+5);
    cout<< " String 5 : "<< string5;

    //  assignment operator 
    string str6 = string4; 
  
    // clear function deletes all character from string 
    string4.clear(); 
  
    //  both size() and length() return length of string and 
    //  they work as synonyms 
    int len = str6.length(); // Same as "len = str6.size();" 
  
    cout << "Length of string is : " << len << endl; 
  
    // a particular character can be accessed using at / 
    // [] operator 
    char ch = str6.at(2); //  Same as "ch = str6[2];" 
  
  
    cout << "third character of string is : " << ch << endl; 
  
    //  front return first character and back returns last character 
    //  of string 
  
    char ch_f = str6.front();  // Same as "ch_f = str6[0];" 
    char ch_b = str6.back();   // Same as below 
                               // "ch_b = str6[str6.length() - 1];" 
  
    cout << "First char is : " << ch_f << ", Last char is : "
         << ch_b << endl; 
  
    // c_str returns null terminated char array version of string 
    const char* charstr = str6.c_str(); 
    printf("%s\n", charstr); 
  
    // append add the argument string at the end 
    str6.append(" extension"); 
    //  same as str6 += " extension" 
  
    // another version of append, which appends part of other 
    // string 
    string4.append(str6, 0, 6);  // at 0th position 6 character 
  
    cout << str6 << endl; 
    cout << string4 << endl; 
  
    //  find returns index where pattern is found. 
    //  If pattern is not there it returns predefined 
    //  constant npos whose value is -1 
  
    if (str6.find(string4) != string::npos) 
        cout << "str4 found in str6 at " << str6.find(string4) 
             << " pos" << endl; 
    else
        cout << "str4 not found in str6" << endl; 
  
    //  substr(a, b) function returns a substring of b length 
    //  starting from index a 
    cout << str6.substr(7, 3) << endl; 
  
    //  if second argument is not passed, string till end is 
    // taken as substring 
    cout << str6.substr(7) << endl; 
  
    //  erase(a, b) deletes b characters at index a 
    str6.erase(7, 4); 
    cout << str6 << endl; 
  
    //  iterator version of erase 
    str6.erase(str6.begin() + 5, str6.end() - 3); 
    cout << str6 << endl; 
  
    str6 = "This is a examples"; 
  
    //  replace(a, b, str)  replaces b characters from a index by str 
    str6.replace(2, 5, "ese are test Hanumanth"); 
  
    cout << str6 << endl; 
  
    return 0; 
}