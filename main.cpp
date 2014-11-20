//
//  main.cpp
//  divides
//
//  Created by taiyun228 on 2014/6/18.
//  Copyright (c) 2014年 Wang Taiyun. All rights reserved.
//
#include <iostream>
#include <math.h>
using namespace std;
void sub(int *dividend ,int *divisor,int *answer,int size1)
{
   // cout<<size1<<" "<<size2;
    for(int k = 0 ; k < size1 ; k++)
        answer[k] = dividend[k] - divisor[k];
    for(int i = 0; i < size1 ; i++)// size1 has noted it
    {
                if(answer[i] < 0)
                {
                    answer[i+1]--;
                   // answer[i+1] = 0;
                    answer[i] += 10;
                }
        
    }
    
 /*  for(int ss = 0; ss < size1; ss++)
   {
        cout<<answer[ss];
   }

cout<<endl;
    */
}
/*void mul(int *multiplier,int *multiplicand,int *answer,int size1,int size2)
{
    int lenth = size1+size2;
    for(int i = 0; i < lenth; i++)
        answer[i] = 0;
    for(int i = 0; i < lenth; i++)
        for(int j = 0; j < lenth; j++)
            if(i + j < lenth)
                answer[i+j] += multiplier[i] * multiplicand[j];
    for(int i = 0; i < lenth; i++)
    {
        {
            answer[i+1] += answer[i] / 10;
            answer[i] %= 10;
        }
        cout<<answer[i];
    }
    
    
}
 */
void mul(int *a, int b, int *c,int size1)
{
    for(int i = 0; i < size1; i++)
        c[i] = a[i] * b;
    for(int i = 0; i < size1; i++)
    {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
        //cout<<c[i];
    }
   
    /* for(int ii = 0 ; ii < size1; ii++)
     cout<<c[ii];
     cout<<endl;
*/
   
}

bool largerthan(int *a,int *b,int size1)
{
    for(int i = size1-1; i >= 0; i--)
    {
        if(a[i] > b[i])
            return true;
    }
    return false;
}
bool equalto(int *a ,int *b,int size1)
{
    for(int i = size1-1; i >= 0; i--)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
    
   
    
}
void div(int *dividend,int *divider,int *answer,int size1,int div_lenth)
{
    //cout<<div_lenth<<endl;
    
    int *t = new int[100];//store the divider mul pow
    for( int j= div_lenth; j >= 0; j--)//digit
    {
        mul(divider,pow(10,j),t,size1);
       /* for(int ii = 0; ii < size1; ii++)//pleas exe to find bug
        {
            cout<<t[ii];
        }
        cout<<endl;
        */
      //  sub(dividend,t,answer,size1);
        if(largerthan( dividend, t,size1)==true)//digit is not same but divider is larger
        {
            
            for(int k = 9; k > 1; k--)
            {
                mul(t,k,t,size1);
                if( equalto(t,answer,size1)==true )//digit is same
                {
                    sub(answer,t,answer,size1);
                    break;
                }
            }
        }
        for(int ii = 0 ; ii < size1; ii++)
            cout<<answer[ii];
        cout<<endl;
        

    }
}
int main(int argc, const char * argv[])
{
    char input1[100],input2[100];
    int a_lenth[100], b_lenth[100];
    int *answer = new int[100];
    cin>>input1;
    cin>>input2;
    int size1 = (unsigned)strlen(input1);
    int size2 = (unsigned)strlen(input2);
    int temp1 = size1 - 1;
    int temp2 = size2 - 1;
    int div_lenth = size1 -size2;
    for(int i = 0; i < size1; i++)
    {
        if(input1[i] == '\0')
        break;
        else
        {
            a_lenth[temp1] = input1[i] - '0';
            temp1--;
        }
    }
    for(int j = 0; j < size2; j++)
    {
        if(input2[j] == '\0')
        break;
        else
        {
            b_lenth[temp2] = input2[j] - '0';
            temp2--;
        }
    }
    cout<<endl;
    div(a_lenth,b_lenth,answer,size1,div_lenth);// is thi pt
    
}







