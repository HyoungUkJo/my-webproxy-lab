/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"

int main(void) {
  // 버퍼의 정보를 읽을 포인터와 버퍼의 끝을 찍을 포인터
  // 문자열 처리를 위한 포인터
  char *buf, *p;
  // 내가 받을 인자값과 변경해야할 컨텐트 초기화
  char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
  int n1=0, n2=0;

  if((buf = getenv("QUERY_STRING")) != NULL){
    p = strchr(buf,'&'); // p가 &의 위치를 가리킨다.
    *p = '\0'; // 포인터가 가리키는 값을 \0 즉 문자열의 끝으로 설정한다.
    strcpy(arg1, buf);  // \0까지 arg1에 저장
    strcpy(arg2, p+1);  // \0이후는 arg2에 저장
    n1 = atoi(arg1);  // arg를 케릭터 형에서 int형으로 형변환 하겠다. 더하기 하기 위해
    n2 = atoi(arg2);
  }

  sprintf(content, "QUREY_STRING=%s", buf);
  sprintf(content, "Welcome to add.com: ");
  sprintf(content, "%s THE Internet addition portal. \r\n <p>", content);
  sprintf(content, "%s The answer is : %d + %d = %d\r\n<p>", content, n1, n2, n1+n2);
  sprintf(content, "%s Thanks for visiting! \r\n", content);

  printf("Connection: close\r\n");
  printf("Content-length: %d\r\n", (int)strlen(content));
  printf("Content-type: text/html\r\n\r\n");
  printf("%s", content);
  fflush(stdout);  


  exit(0);
}
/* $end adder */ 
