#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
#include<windows.h>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")
#define MAX_COUNT 10
void textcolor(int color_number);
int main() 
{ 
	
   //1. 맨 처음에 영어 단어 10개를 배열에 입력 시킵니다. 
   char word[MAX_COUNT][32] = {"person", "world", 
      "favorite", "administrator", 
      "strong", "address", 
      "smart", "phone", 
   "computer", "program"}; 
   char c; 
   int select, len; 
   int check[32], i, cnt; 
   while(1) 
   { 
	   system("color e0");
      //2.게임을 시작하면 10개의 단어중 컴퓨터가 임의로 하나의 단어를 선택해 
      select = rand() % 10;
      len = strlen(word[select]); 
      for(i=0;i < 32;i++) 
      check[i] = 0; 
      while(1) 
      { 
         //그 단어의 글자수 만큼 ' _ ' 를 출력합니다. 
         for(i=0;i < len;i++) 
         { 
            // 그 중에 단어가 있으면 그 단어만 출력하고 나머지는 _ 를 출력합니다. 
            if(check[i] == 0) 
            printf("_ ");  
            else//4.다음 글자를 입력받을 때부터는 맞춘 단어는 계속 출력시킵니다.
			
            printf("%c ",word[select][i]); 
         } 
         printf("\n"); 
         //3. 그후 글자 하나씩 입력받아 
         c = getch(); 
         for(i=0;i < len;i++) 
         { 
            if(word[select][i] == c)//입력한 문자와 같은 문자라면 
            check[i] = 1;//맞춘 문자 위치를 체크 
         } 
         //다 맞쳤는지 검사 
         cnt = 0; 
         for(i=0;i < len;i++) 
         { 
            if(check[i] == 1) 
            cnt++; 
         } 
         if(cnt == len)//글자수랑 같으면 다 맞춤 
         break; 
      } 
      printf("%s\n", word[select]); 
      //5.단어를 맞췄으면 계속 할지 안할지 묻습니다. 
      do 
      {  
   sndPlaySoundA("C:\\Users\\thdgks\\Desktop\\ppang.wav",SND_ASYNC|SND_NODEFAULT);
         printf("계속하시겠습니까?(y/n)\n단, 노래가 끝난 후에 시작해주세요.\n"); 
         c = getch(); 
      } while (!(c == 'y' || c == 'n')); 
      if(c == 'n') 
      break; 
   } 
   return 0; 
}

void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
