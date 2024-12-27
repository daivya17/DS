#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 1000
char stack[max];
int top=-1;
void push(char x){
    if(top==max-1){
        printf("stack full\n");
        return;
    }
    stack[++top]=x;
}
char pop(){
    if(top==-1){
        printf("stack empty\n");
        return -1;
    }
    return stack[top--];
}
int precedence(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 2;
    }
    else if(x=='^'){
        return 3;
    }
    else{
        return 0;
    }
}
int isop(char x){
    return (x=='+'||x=='-'||x=='*'||x=='/'||x=='^');
}
void infixtopostfix(char *exp){
    char postfix[max];
    int i=0;
    char *ptr = exp;
    while(*ptr!='\0'){
        if(isalpha(*ptr)){
            postfix[i++] = *ptr;
        }
        if(*ptr=='('){
            push(*ptr);
        }
        if(*ptr==')'){
            while(stack[top]!='('){
                postfix[i++]=pop();
            }
            pop();
        }
        if(isop(*ptr)){
            while(precedence(stack[top])>=precedence(*ptr)){
                postfix[i++]=pop();
            }
            push(*ptr);
        }
        ptr++;
    }
    while(top!=-1){
        postfix[i++]=pop();
    }
    postfix[i]='\0';
    printf("Postfix:%s",postfix);
}
int main(){
    char exp[max];
    printf("enter expression:");
    scanf("%s",exp);
    infixtopostfix(exp);
    return 0;
}
