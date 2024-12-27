#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
char stack[1000];
int top = -1;
void push(char x){
    if(top==999){
        return;
    }
    else{
        stack[++top] = x;
    }
}
char pop(){
    if(top==-1){
        return;
    }
    else{
        return stack[top--];
    }
}
bool isempty(){
    return top==-1;
}
bool isvalid(char *s){
    int i = 0;
    while(s[i]!='\0'){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            push(s[i]);
        }
        else if(s[i]==')'||s[i]=='}'|| s[i]==']'){
            if(isempty()){
                return false;
            }
            else{
                char x = pop();
                if(s[i]=='(' && x!=')' || 
                   s[i]=='{' && x!='}' || 
                   s[i]=='[' && x!=']'){
                    return false;
                }
            }
        }
        i++;
    }
    return isempty();
}
int main(){
    printf("enter the string:");
    char s[1000];
    scanf("%s",s);
    if(isvalid(s)){
        printf("valid\n");
    }
    else{
        printf("invalid\n");
    }
    return 0;
}
