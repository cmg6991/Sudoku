#include <stdio.h>
#include <conio.h>
#include <windows.h>

extern int sdokuboard[9][9]; //스도쿠 판 정의
extern int answerboard[9][9]; //답안지 판 정의

extern int cursorX; //가르키는 커서
extern int cursorY; 
extern int hint; //힌트의 기회는 3으로 정의

void Gotoxy(int x, int y); //커서
void MakeBoard(); //판 그리기 
void ReadBoard(const char* txtfile, const char* answertxt); //파일을 읽어오는함수
void CursorMake(); //판에 숫자 입력하기 위한 커서
void CursorMove(); //커서 키입력
void InsertNumber(); //판에 숫자넣기
int Input(); //숫자를 넣을 수 있도록 -2로 재정의
//void ChangeColor(const char* txtfile, const char* answertxt);
void Hint(); //힌트 보여주는 함수
void checkAnswer(); //답을 체크해서 틀리면 색깔출력하는 함수
void CheckGameOver(); //스도쿠 판을 종료하는 함수
int sudoku(const char* txtfile, const char* answertxt); //메인함수