#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 //스페이스바

void menu_init() //초기화 작업
{
	system("mode con cols = 56 lines =20 | title sudoku");
}
void levelMenu() //타이틀 출력
{
	system("cls");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("          ____________SELECT LEVEL__________\n");
	printf("         |                                  |\n");
	printf("         |                                  |\n");
	printf("         |               초보               |\n"); 
	printf("         |                                  |\n");
	printf("         |                                  |\n");
	printf("         |               하수               |\n"); 
	printf("         |                                  |\n");
	printf("         |                                  |\n");
	printf("         |               중수               |\n");
	printf("         |                                  |\n");
	printf("         |                                  |\n");
	printf("         |               고수               |\n");
	printf("         |                                  |\n");
	printf("         |                                  |\n");
	printf("         |             초초초고수           |\n");
	printf("         |                                  |\n");
	printf("         |__________________________________|\n");

}

void gotoxyLevel(int x, int y) //커서
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int keyControlLevel() //키입력함수
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		return LEFT;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		return RIGHT;
	else if (GetAsyncKeyState(VK_UP) & 0x8000)
		return UP;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		return DOWN;
	else if (GetAsyncKeyState(' ') & 0x8000)
		return SUBMIT;
	else
		return 5;
}

int level() //화살표를 움직이게 하는함수
{
	int x = 20;
	int y = 6;
	gotoxy(x, y);
	printf(">");
	while (1)
	{
		Sleep(50);
		int n = keyControl();
		int i = y + 2;
		switch (n) {
		case UP: {
			if (y > 6) {
				gotoxy(x, y);
				printf(" ");
				gotoxy(x, y-3);
				y -= 3;
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 18) {
				gotoxy(x , y);
				printf(" ");
				gotoxy(x , y+3);
				y += 3;
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 6;
		}
		}
	}
}
int levelDraw() //메인함수
{
	menu_init();
	levelMenu();

	srand(time(NULL)); //판을 랜덤으로 불러들어오게 하는 함수
	const char* filenames[][2] = {
		{"first.txt", "firstanswer.txt"},
		{"first1.txt", "first1answer.txt"},
		{"first2.txt", "first2answer.txt"},
		{"first3.txt", "first3answer.txt"},
	};
	const int num_files = 4;
	
	const char* secondfiles[][2] = {
		{"second.txt", "secondanswer.txt"},
		{"second2.txt", "second2answer.txt"},
		{"second3.txt", "second3answer.txt"},
	};
	const int second_files = 3;

	const char* mediumfiles[][2] = {
		{"medium.txt", "mediumanswer.txt"},
		{"medium1.txt", "medium1answer.txt"},
		{"medium2.txt", "medium2answer.txt"},
	};
	const int medium_files = 3;

	const char* difficultfiles[][2] = {
		{"difficult.txt", "difficultanswer.txt"},
		{"difficult1.txt", "difficult1answer.txt"},
		{"difficult2.txt", "difficult2answer.txt"},
	};
	const int difficult_files = 3;

	const char* veryfiles[][2] = {
		{"veryverydifficult.txt", "veryverydifficultanswer.txt"},
		{"very1.txt", "very1answer.txt"},
		{"very2.txt", "very2answer.txt"},
	};
	const int very_files = 3;


	while (1)
	{
		int select = level();
		if (select == 0)
		{
			int file = rand() % num_files;
			sudoku(filenames[file][0], filenames[file][1]);
		}
		else if (select == 3)
		{
			int second = rand() % second_files;
			sudoku(secondfiles[second][0], secondfiles[second][1]);
		}
		else if (select == 6)
		{
			int medium = rand() % medium_files;
			sudoku(mediumfiles[medium][0], mediumfiles[medium][1]);
		}
		else if (select == 9)
		{
			int difficult = rand() % difficult_files;
			sudoku(difficultfiles[difficult][0], difficultfiles[difficult][1]);
		}
		else if (select == 12)
		{
			int very = rand() % very_files;
			sudoku(veryfiles[very][0], veryfiles[very][1]);
		}
	}
}