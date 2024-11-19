#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Level.h"
#include "board.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 //스페이스바

void init() //초기화 작업
{
	system("mode con cols = 56 lines =20 | title sudoku");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
void titleDraw() //타이틀 출력
{
	/*printf("  ________  ___  ___  ________  ________  ___  __    ___  ___\n\n");
	printf(" | \   ____\ | \  \ | \  \ | \   ___ \ | \   __  \ | \  \ | \  \ | \  \ | \  \\n\n");
	printf(" \ \  \___ | \ \  \\\  \ \  \_ | \ \ \  \ | \  \ \  \/  /|\ \  \\\  \\n\n");
	printf("  \ \_____  \ \  \\\  \ \  \ \\ \ \  \\\  \ \   ___  \ \  \\\  \\n\n");
	printf("   \ | ____ | \  \ \  \\\  \ \  \_\\ \ \  \\\  \ \  \\ \  \ \  \\\  \\n\n");
	printf("	____\_\  \ \_______\ \_______\ \_______\ \__\\ \__\ \_______\\n\n");
	printf("   | \_________\ | _______ | \ | _______ | \ | _______ | \ | __ | \ | __ | \ | _______ |\n\n");
	printf("   \| _________ | \n\n");*/
	printf("\n\n\n\n\n\n");
	printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
	printf("| |    _______   | || | _____  _____ | || |  ________    | || |     ____     | || |  ___  ____   | || | _____  _____ | |\n");
	printf("| |   /  ___  |  | || ||_   _ || _  _|| || | |_   ___ `.  | || |   .'    `.   | || | |_  ||_  _|  | || ||_  _||_   _|||\n");
	printf("| |  |  (__ \\_|  | || |  | |    | |  | || |   | |   `. \\ | || |  /  .--.  \\  | || |   | |_/ /    | || |  | |    | |||\n");
	printf("| |   '.___`-.   | || |  | '    ' |  | || |   | |    | | | || |  | |    | |  | || |   |  __'.    | || |  | '    ' |  | |\n");
	printf("| |  |`\____) |   | || |   \ `- - ' /   | || |  _| |___.' / | || |  \\  `- - '  /  | || |  _| | \\ \\_  | || |\\ `--'/||\n");
	printf("| |  |_______.'  | || |    `.__.'    | || | |________.'  | || |   `.____.'   | || | |____ || ____| | || |  `.__.'   ||\n");
	printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
}


void gotoxy(int x, int y) //커서
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
int keyControl() //키입력하는 함수
{
	if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		return LEFT;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		return RIGHT;
	else if (GetAsyncKeyState(VK_UP) & 0x0001)
		return UP;
	else if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		return DOWN;
	else if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		return SUBMIT;
	else
		return 5;
}

int menuDraw() //메뉴를 그리기
{
	int x = 57;
	int y = 20;
	gotoxy(x - 2, y);
	printf("> PLAY!");
	gotoxy(x, y+1);
	printf("HOWTOPLAY");
	gotoxy(x, y+2);
	printf("EXIT");

	while (1)
	{
		Sleep(50);
		int n = keyControl();
		switch (n){
			case UP:{
				if (y > 20){
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
				break;
		}
			case DOWN:{
				if (y < 22){
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
				break;
		}
			case SUBMIT:{
				return y - 20;
			}
		}
	}
}

void infoDraw() //게임정보판
{
	system("cls");
	printf("\n\n\n\n");
	printf("\n\n\n\n\n\n\n");
	printf("                                                   모두가 아는 스도쿠 게임 \n\n");
	printf("                                        스도쿠 잘한다 싶으면 초초초고수를 도전해보세요^0^ \n\n");
	printf("                                         스페이스 바를 누르면 메인 화면으로 이동합니다. \n\n\n");

	while (1)
	{
		if (keyControl() == SUBMIT)
			break;
	}
}


int main()//메인문
{
	init();
	while(1)   
	{
		titleDraw();
		int select = menuDraw();
		if (select == 0)
		{
			levelDraw();
		}
		else if (select == 1)
		{
			infoDraw();
		}
		else if (select == 2)
		{ 
			return 0;
		}
		system("cls");
	}
}