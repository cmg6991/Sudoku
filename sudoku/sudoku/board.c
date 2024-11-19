#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <direct.h>
#include <stdbool.h>


int sdokuboard[9][9];
int answerboard[9][9];

int cursorX;
int cursorY;
int hint=3;

void Gotoxy(int x, int y)
{
	COORD position = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void ReadBoard(const char* txtfile, const char* answertxt) //스도쿠 판 불러오는 함수
{
	int x;
	int y;

	FILE* fp = NULL;

	fp = fopen(txtfile, "r");

	if (fp == NULL)
	{
		printf("[Error] Not found to file in %s", txtfile);
		exit(0);
	}

	for (x = 0; x < 9; x++)
	{
		for (y = 0; y < 9; y++)
		{
			sdokuboard[y][x] = fgetc(fp) - 48;
		}
		fgetc(fp);
	}
	fclose(fp);

	fp = fopen(answertxt, "r");

	if (!fp)
	{
		printf("[Error] Not found to file in %s", txtfile);
		exit(0);
	}
	for (x = 0; x < 9; x++)
	{
		for (y = 0; y < 9; y++)
		{
			answerboard[y][x] = fgetc(fp) - 48;
		}
		fgetc(fp);
	}
	fclose(fp);
}

void MakeBoard() //판만들기
{
	//system("cls");
	int x, y;
	for (x = 0; x < 9; x++) 
	{
		for (y = 0; y < 9; y++)
		{
			Gotoxy((x + 4) * 3, (y + 2) * 2);
			printf("%d", sdokuboard[x][y]);

			if (x == 2 || x == 5)
				printf("\033[0;32m||\033[0m");
			if (y == 2 || y == 5) 
			{
				Gotoxy((x + 2) * 4-1, (y + 2)*2+1);
				printf("\033[0;32m----\033[0m");
			}	
		}
	}
}

void CursorMake() //판에 숫자 입력하기 위한 커서
{
	Gotoxy((cursorX + 3) * 3, 3);
	printf(" ");
	Gotoxy((cursorX + 4) * 3, 3);
	printf("&");
	Gotoxy((cursorX + 5) * 3, 3);
	printf(" ");

	Gotoxy(10, (cursorY + 1) * 2);
	printf(" ");
	Gotoxy(10, (cursorY + 2) * 2);
	printf("&");
	Gotoxy(10, (cursorY + 3) * 2);
	printf(" ");
}

void CursorMove() //커서 키입력
{
	if (GetAsyncKeyState(VK_LEFT) & 0x0001)
	{
		if (cursorX - 1 == -1)
		{
			return;
		}

		cursorX--;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
	{
		if (cursorX + 1 == 9)
		{
			return;
		}

		cursorX++;
	}
	if (GetAsyncKeyState(VK_UP) & 0x0001)
	{
		if (cursorY - 1 == -1)
		{
			return;
		}

		cursorY--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x0001)
	{
		if (cursorY + 1 == 9)
		{
			return;
		}
		 
		cursorY++;
	}

	if (GetAsyncKeyState(VK_SHIFT) & 0x0001)
	{
		if (hint > 0 && sdokuboard[cursorX][cursorY] != answerboard[cursorX][cursorY])
		{
			sdokuboard[cursorX][cursorY] = answerboard[cursorX][cursorY];
			hint--;
		}
		if (hint > 0)
		{
			Gotoxy(50, 5);
			printf("%d번 남았습니다.\n", hint);
		}
		else
		{
			Gotoxy(50,5);
			printf("힌트를 다 써버렸네요...\n");
			printf("                                                     안타깝습니다..\n");
		}
	}
}
void InsertNumber() //판에 숫자를 들어가게 하기 위한 함수
{
	if (sdokuboard[cursorX][cursorY] == answerboard[cursorX][cursorY])
		return;

	int key = sdokuboard[cursorX][cursorY];

	if (GetAsyncKeyState(0x31) & 0x8000) {
		key = 1;
	}
	// 2
	else if (GetAsyncKeyState(0x32) & 0x8000) {
		key = 2;
	}
	// 3
	else if (GetAsyncKeyState(0x33) & 0x8000) {
		key = 3;
	}
	// 4
	else if (GetAsyncKeyState(0x34) & 0x8000) {
		key = 4;
	}
	// 5
	else if (GetAsyncKeyState(0x35) & 0x8000) {
		key = 5;
	}
	// 6
	else if (GetAsyncKeyState(0x36) & 0x8000) {
		key = 6;
	}
	// 7
	else if (GetAsyncKeyState(0x37) & 0x8000) {
		key = 7;
	}
	// 8
	else if (GetAsyncKeyState(0x38) & 0x8000) {
		key = 8;
	}
	// 9
	else if (GetAsyncKeyState(0x39) & 0x8000) {
		key = 9;
	}

	sdokuboard[cursorX][cursorY] = key;
}

int Input() //-2로 정의
{
	return _kbhit() ? _getch() : -2;
}
void CheckGameOver() //스도쿠판을 종료하는 함수
{
	int x,y;

	for (x = 0; x < 9; x++)
	{
		for (y = 0; y < 9; y++)
		{
			if (sdokuboard[x][y] != answerboard[x][y])
			{
				return;
			}
		}
		
	}
		system("cls");
		Gotoxy(0, 0);
		printf("  _____ __ __    __    __    ___  _____ _____\n");
		printf(" / ___/|  T  T / ] / ] / _] / ___// ___/\n");
		printf("(\\_ |  |  | /  /  /  /  /[_(\\_   (\\_   \\ \n");
		printf(" \\__  T|  |  |/  /  /  / Y   _]  \\__  T\\__  T\n");
		printf(" / \\  || : / \\_ / \\_ | [_ / \\ |/  \\|\n");
		printf(" \\ |  l    \\               \\ || T\\ | \\ |\n");
		printf("  \\___j \\__, _j\\____j\\____jl_____j\\___j \\___j\n");
		Sleep(3000);
		exit(0);
}


void Hint() //힌트를 알려주는 함수
{
	Gotoxy(55,10);
	printf("shift를  누르면 3번의 힌트 기회가 있습니다.\n");
	Gotoxy(55, 11);
	printf("       __    __  ______  __    __  ________\n");
	Gotoxy(55, 12);
	printf("/  |  /  |/      |/  \\  /  |/        |\n");
	Gotoxy(55, 13);
	printf("$$ | $$ | $$$$$$ / $$  \\ $$ | $$$$$$$$ /\n");
	Gotoxy(55, 14);
	printf("$$ | __$$ | $$ |   $$  \\ $$|    $$   |\n");
	Gotoxy(55, 15);
	printf("$$    $$ | $$ |   $$ $$   $$|    $$   |\n");
	Gotoxy(55, 16);
	printf("$$$$$$$$ | $$ |   $$  $$  $$|    $$   |\n");
	Gotoxy(55, 17);
	printf("$$ | $$ | _$$ | _ $$ | $$ $$ |    $$   |\n");
	Gotoxy(55, 18);
	printf("$$ | $$ |/ $$ |   $$ |  $ $$ |    $$   |\n");
	printf("\n\n");
}

void checkAnswer() //답을 체크해서 색깔출력하는 함수
{
	Gotoxy(cursorX*3+12, cursorY*2+4);
	if (sdokuboard[cursorX][cursorY] != answerboard[cursorX][cursorY])
		printf("\033[31m%d\033[0m ", sdokuboard[cursorX][cursorY]);
	else
		printf("%d ", sdokuboard[cursorX][cursorY]);
}

int sudoku(const char* txtfile,const char* answertxt)
{
	ReadBoard(txtfile,answertxt);
	system("cls");

	while (1)
	{
		MakeBoard();
		if (Input() == 32)
		{
			CheckGameOver();
		}
		Hint();
		CursorMake();
		CursorMove();
		InsertNumber();
		checkAnswer();
		Sleep(7);
	}
}