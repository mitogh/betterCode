#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string sum(string a, string b){
    int len_a = a.size();
    int len_b = b.size();

    if(!len_a &&  len_b) return b;
    if(!len_b &&  len_a) return a;

    string tmp;
    if(len_b > len_a){
        int t = len_a;
        len_a = len_b;
        len_b = t;
        tmp = a;
        a = b;
        b = tmp;
    }
    tmp = a;
    int j = len_a;
    tmp[j--] = '\0';
    len_a--;
    len_b--;
    
    short carry = 0;
    while(len_a >= 0){
        int sum = 0;
        sum += (int)a[len_a--] - 48;
        if(len_b >= 0) sum += (int)b[len_b--] - 48;

        sum += carry;
        if(sum < 10){
            tmp[j--] = sum + 48;
            carry = 0;
        }else{ 
            tmp[j--] = (sum - 10) + 48;
            carry = 1;
        }
    }
    if(carry) return (char)(carry + 48) + tmp;
    else return tmp;
}

int main(){
    string line, total = "0";
    while(getline(cin, line)){
        total = sum(line, total);
    }
    int i = 0;
    while(total[i] != '\0') printf("%c", total[i++]);
    printf("\n");
    return 0;
}  
