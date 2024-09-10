// Convert Infix expression to Postfix expression.

// Input: A + B * C + D
// Output: ABC*+D+

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int


int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

char associativity(char c) {
    if (c == '^')
        return 'R'; //right associative
        return 'L'; // Default to left-associative
}

void infixtopostfix(char s[]){
    char result[1000];
    int resultIndex = 0;
    int len = strlen(s);
    char stack[1000];
    int stackIndex = -1;

    for (int i = 0 ; i<len ; i++) {
        char c = s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) {
            result[resultIndex++] = c;
        }
        else if (c == '(') {
            stack[++stackIndex] = c;
        }
        else if (c==')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                result[resultIndex++] = stack[stackIndex--];
            }
            stackIndex--; // pop '('
        }
        else {
                while (stackIndex >= 0 && (prec(s[i]) < prec(stack[stackIndex]) ||
                    prec(s[i]) == prec(stack[stackIndex]) && associativity(s[i]) == 'L')) {
                    result[resultIndex++] = stack[stackIndex--];
                }
            stack[++stackIndex] = c;
        }
    }
        // Pop all the remaining elements from the stack

        while (stackIndex >= 0) {
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0';
    printf("%s\n", result);
}

int32_t main(){


char exp[] = "a+b*(c^d-e)^(f+g*h)-i";

infixtopostfix(exp);
    return 0;
}
