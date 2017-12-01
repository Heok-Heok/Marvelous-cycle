#include <stdio.h>
 #include <string.h>
 #include <process.h>
#include <stdlib.h>

void PrintHexDigit(unsigned sum);//16진수 숫자 문자로 출력
void ConvertBinToHexInt(char *nums,unsigned u);//2진수를 16진수로 변환(정수부)
void ConvertBinToHexFlo(char *under,unsigned u);//2진수를 16진수로 변환(실수부)
void ConvertBinToHex(char *nums);//2진수를 16진수로 변환하여 출력

unsigned HexToDecimal(char hexdigit);//16진수 문자를 10진수로 변환

void ConvertHexToBinSub(char *nums,unsigned u);//16진수를 2진수로 변환-부호없는 정수만
void ConvertHexToBin(char *nums);//16진수를 2진수로 변환-소수점과 부호 포함



void main()
 {
    int i, j;
    char c;
     char nums[100];
     for(i = 0; i<180; i++)
     {
       for (j = 0; j<33; j++)
       {
         c = getchar();
         if( c == '\n')
         {
           nums[j] = '\0';
           break;
         }
         else
         {
           nums[j] = c;
         }

       }
       ConvertBinToHex(nums);
       printf("\n");
     }

}

void PrintHexDigit(unsigned sum)
 {
     if((sum>=0)&&(sum<9))
     {
          putchar(sum + '0');
     }
     else
     {
          putchar(sum + 'a' - 10);
     }
 }



void ConvertBinToHexInt(char *nums,unsigned u)
 {
     unsigned sum = 0;
     while(u)
     {
          sum = 0;
          do
          {
               sum = sum<<1;
               if(*nums == '1')
               {
                    sum +=  1;
               }
               else if(*nums != '0')
              {
                 printf("변환할 수 없는 수가 있네요\n");
                 exit(0);
              }
              u--;
              nums++;
       }while(u%4);
       PrintHexDigit(sum);
     }
 }



void ConvertBinToHexFlo(char *under,unsigned u)
 {
     unsigned sum = 0;
     unsigned cnt = 0;
     while(u)
     {
         cnt = 3;
         sum = 0;
         do
         {
             if(*(under+u-1) == '1')
            {
                 sum +=  1<<cnt;
            }
            else if(*(under+u-1) != '0')
           {
              printf("변환할 수 없는 수가 있네요\n");
              exit(0);
           }
           u--;
           cnt--;

       }while(u%4);
       PrintHexDigit(sum);
     }

}


 void ConvertBinToHex(char *nums)
 {
     unsigned u1 = 0; //정수부 자리수
    unsigned u2 = 0; //소수부 자리수
    char *under=0;   //소수부 시작 위치

    int sign = 0; //양의 수면 0, 음의 수면 1

    unsigned lcnt = 0;



    if(*nums == '-')//첫 부호가 -라면
    {
          sign = 1; //계산 결과
         nums++; //부호 뒤부터 수이므로
         putchar('-');
     }


    under = strstr(nums,".");
     if(under) //소수점을 만났다면
    {
         under++; //.다음 위치를 가르키게 한다.
         u1 = strlen(under);
         u2 = -1;
     }
     u2 += strlen(nums) - u1;

    ConvertBinToHexInt(nums,u2);
     if(under)
     {
         putchar('.');
         ConvertBinToHexFlo(under,u1);
     }

 }
