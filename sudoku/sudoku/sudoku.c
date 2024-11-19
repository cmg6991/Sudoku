#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <direct.h>

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25
#define SDOKU_BOARD_FILE_PATH "board.txt"
#define ANSWER_SDOKU_BOARD_FILE_PATH "answer.txt"
#define _CRT_SECURE_NO_WARNINGS

int sdokuBoard[81];
int answerBoard[81];

int cursorPositionX;
int cursorPositionY;

void Init()
{
	system("mode con cols = 80 lines =25 | title sudoku");

	CONSOLE_CURSOR_INFO consoleCursorInfo;

	consoleCursorInfo.bVisible = 0;
	consoleCursorInfo.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);

	char buffer[1024];
	char* dir = buffer;
	strcpy_s(buffer, 1024, "C:/Users/User/Documents");

	buffer[1023] = '\0';

	while (*dir)
	{
 		if (*dir == '/')
		{
			*dir = '\0';
			_mkdir(buffer);
			*dir = '/';
		}
		dir++;
	}
}

void Gotoxy(int x, int y)
{
	COORD position = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void ReadBoard()
{
	int x;
	int y;

	FILE* fp = NULL;

	fp = fopen_s(&fp,"board.txt", "r");

	if (fp == NULL)
	{
		printf("[Error] Not found to file in %s", SDOKU_BOARD_FILE_PATH);
		exit(0);
	}

	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 9; x++)
			sdokuBoard[x + 9 * y] = fgetc(fp) - 48;
		fgetc(fp);
	}
	fclose(fp);

	fp = fopen_s(&fp,"answer.txt", "r");

	if (!fp)
	{
		printf("[Error] Not found to file in %s", ANSWER_SDOKU_BOARD_FILE_PATH);
		exit(0);
	}
	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 9; x++)
			answerBoard[x + 9 * y] = fgetc(fp) - 48;
		fgetc(fp);
	}
	fclose(fp);
}

void DrawBoard()
{
	int x;
	int y;
	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 9; x++)
		{
			Gotoxy((x + 2) * 4, (y + 2) * 2);
			printf("%d", sdokuBoard[x + 9 * y]);

			if (x == 2 || x == 5)
			{
				Gotoxy((x + 2) * 4 +2, (y + 2) * 2);
				printf("|");
			}
			if (y == 2 || y == 5)
			{
				Gotoxy((x + 2) * 4 - 1, (y + 2) * 2 + 1);
				printf("----");
			}
		}
	}
}

void DrawCursor()
{
	Gotoxy((cursorPositionX + 1) * 4, 2);
	printf(" ");
	Gotoxy((cursorPositionX + 2) * 4, 2);
	printf("@");
	Gotoxy((cursorPositionX + 3) * 4, 2);
	printf(" ");

	Gotoxy(4, (cursorPositionY + 1) * 2);
	printf(" ");
	Gotoxy(4, (cursorPositionY + 2) * 2);
	printf("@");
	Gotoxy(4, (cursorPositionY + 3) * 2);
	printf(" ");
}

void CursorMove()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x0001)
	{
		if (cursorPositionX - 1 == -1)
		{
			return;
		}

		cursorPositionX--;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
	{
		if (cursorPositionX + 1 == 9)
		{
			return;
		}

		cursorPositionX++;
	}
	if (GetAsyncKeyState(VK_UP) & 0x0001)
	{
		if (cursorPositionY - 1 == -1)
		{
			return;
		}

		cursorPositionY--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x0001)
	{
		if (cursorPositionY + 1 == 9)
		{
			return;
		}

		cursorPositionY++;
	}
}
int Input()
{
	return _kbhit() ? _getch() : -2;
}

void InsertNumber()
{
	int key = Input();

	if (key == -2)
	{
		return;
	}

	if (key == 8)
	{
		sdokuBoard[cursorPositionX + 9 * cursorPositionY] = 0;
	}

	if (key >= 49 && 57 >= key)
	{
		sdokuBoard[cursorPositionX + 9 * cursorPositionY] = key - 48;
	}
}

void CheckGameOver()
{
	int i;

	for (i = 0; i < 82; i++)
	{
		if (sdokuBoard[i] != answerBoard[i])
		{
			exit(0);
		}
	}

	system("cls");
	Gotoxy(0, 0);
	printf("Game Clear!");
	exit(0);
}
int main(void)
{
	Init();

	ReadBoard();

	while (1)
	{
		if (Input() == 32)
		{
			CheckGameOver();
		}

		DrawBoard();
		DrawCursor();
		CursorMove();
		InsertNumber();

		Sleep(15);
	}

	return 0;
}