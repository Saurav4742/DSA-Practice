// Multiply Large Numbers represented as Strings

// Given two positive numbers as strings. The numbers may be very large (may not fit in long long int), the task is to find product of these two numbers.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

string multiply(string num1, string num2){
    int len1=num1.size();
    int len2=num2.size();

    if(len1 ==0 || len2 == 0)
        return "0";

    vector<int> result(len1 + len2,0);  //keep the result in vector in reverse order

    int i_n1 = 0;  //yr dono indexes result ka position find karega
    int i_n2 = 0;

    for (int i = len1-1;i>=0;i--) { //go from right to left in num1
        int carry = 0;
        int n1 = num1[i]-'0';

        i_n2 =0;  //shift position to left in num2

        for (int j = len2-1;j>=0;j--) {
            
            int n2 = num2[j]-'0';  //take current digit of second number

            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            carry = sum/10; //carry for next iteration

            result[i_n1 + i_n2] = sum %10; //store result;
            i_n2++;
        }

        //store carry in next cell
        if (carry > 0)    
            result[i_n1 + i_n2] += carry;

        i_n1++;  //shift position to left after every multiplication of a digit in num1
    }

    //ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;

    //if all were '0's means either both or one of num1 or num2 were '0'
    if (i == -1)
    return "0";

    string s ="";   //generate the result string

    while (i>=0)
        s += std::to_string(result[i--]);
    
    cout << "Result: ";
    return s;
}

int32_t main(){

    string str1,str2;
    cout<< "enter the 1st number: ";
    cin >> str1;
    cout<<"enter the 2nd number: ";
    cin>>str2;

    if((str1.at(0) == '-' || str2.at(0) == '-') && (str1.at(0) != '-' || str2.at(0) != '-'))
    cout << "-";

    if(str1.at(0) == '-')
        str1 = str1.substr(1);

    if (str2.at(0) == '-')
        str2 = str2.substr(1);

    cout <<multiply(str1,str2);
        return 0;
}

// Input : num1 = 4154  
//         num2 = 51454
// Output : 213739916