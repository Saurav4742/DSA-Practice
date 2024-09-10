// Sentence Palindrome (Palindrome after removing spaces, dots, .. etc)


// Write a program to check if a sentence is a palindrome or not. You can ignore white spaces and other characters to consider sentences as a palindrome.


// Input : str = "Too hot to hoot."
// Output : Sentence is palindrome.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

bool SentencePalindrome( string& str){
    int l = 0, h = str.length() - 1;

    // lower case string
    for(int i= 0;i<=h;i++)
        str[i] = tolower(str[i]);

    // compare character until they are equal
    while (l <= h ) {

        // if there ia another symbol in left of sentence
        if (!(str[l] >='a' && str[l] <= 'z'))
            l++;

        // another symbol in right of sentence
        else if (!(str[h] >= 'a' && str[h] <='z'))
            h--;

        // If characters are equal
        else if (str[l] == str[h])
            l++,h--;

        // if character is not equal
        else 
            return false;
    }
    return true;
}

int32_t main(){

    string str;
    cout<< "enter the Sentence: " ;
    cin >> str;

    if (SentencePalindrome(str))
        cout << "Sentenceis palindrome";
    else {
        cout << "Sentence is not palindrome";
    }
    return 0;
}