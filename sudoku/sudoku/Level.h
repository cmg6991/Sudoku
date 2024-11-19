#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define UP 0 //키입력을 위한 정의
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void menu_init(); //초기화 작업
void levelMenu(); //레벨 메뉴판 그리는 함수
void gotoxyLevel(int x, int y); 
int keyControlLevel(); //키입력을 해 움직이게 해주는 함수
int level(); //화살표로 선택할 수 있게 하는 위치조정함수
int levelDraw(); //다음 단계로 넘어가는 함수