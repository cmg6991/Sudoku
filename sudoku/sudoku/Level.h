#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define UP 0 //Ű�Է��� ���� ����
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void menu_init(); //�ʱ�ȭ �۾�
void levelMenu(); //���� �޴��� �׸��� �Լ�
void gotoxyLevel(int x, int y); 
int keyControlLevel(); //Ű�Է��� �� �����̰� ���ִ� �Լ�
int level(); //ȭ��ǥ�� ������ �� �ְ� �ϴ� ��ġ�����Լ�
int levelDraw(); //���� �ܰ�� �Ѿ�� �Լ�