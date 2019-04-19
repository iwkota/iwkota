#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main(void)
{
    ofstream out("kadai09.svg");
    out<<"<svg width=\"5000\" height=\"3000\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    
    int rule_num;
    scanf("%d",&rule_num);
    int rule_array[8];
    for(int i=0;i<8;i++){
        rule_array[i]=rule_num%2;
        rule_num/=2;
    }
    
    int n=200; //step数
    int array_num=2*n+1;
    
    char array_new[array_num];
    char array_old[array_num];
    
    for(int i=0;i<array_num;i++){
        array_new[i]='0';
    }
    array_new[n]='1';
    
    for(int i=1;i<array_num-1;i++){
        if(array_new[i]=='0'){
            printf(" ");
            out<<"<rect x=\""<<100+i<<"\" y=\"100\" width=\"1\" height=\"1\" fill=\"none\"/>"<<endl;
        }
        if(array_new[i]=='1'){
            printf("*");
            out<<"<rect x=\""<<100+i<<"\" y=\"100\" width=\"1\" height=\"1\" fill=\"black\"/>"<<endl;
        }
    }
    printf("\n");
    
    for(int k=1;k<n;k++){
        strcpy(array_old,array_new);
        
        array_old[0]=array_old[array_num-2];
        array_old[array_num-1]=array_old[1];
        
        for(int i=1;i<array_num-1;i++){
            int rule=0;
            if(array_old[i-1]=='1'){
                rule+=4;
            }
            if(array_old[i]=='1'){
                rule+=2;
            }
            if(array_old[i+1]=='1'){
                rule+=1;
            }
            if(rule_array[rule]==1){
                array_new[i]='1';
            }
            if(rule_array[rule]==0){
                array_new[i]='0';
            }
        }
        
        for(int i=1;i<array_num-1;i++){
            if(array_new[i]=='0'){
                printf(" ");
                out<<"<rect x=\""<<100+i<<"\" y=\""<<100+k<<"\" width=\"1\" height=\"1\" fill=\"none\"/>"<<endl;
            }
            if(array_new[i]=='1'){
                printf("*");
                out<<"<rect x=\""<<100+i<<"\" y=\""<<100+k<<"\" width=\"1\" height=\"1\" fill=\"black\"/>"<<endl;
            }
        }
        printf("\n");
    }
    
    out<<"</svg>"<<endl;
}
