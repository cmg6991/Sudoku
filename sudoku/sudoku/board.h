#include <stdio.h>
#include <conio.h>
#include <windows.h>

extern int sdokuboard[9][9]; //������ �� ����
extern int answerboard[9][9]; //����� �� ����

extern int cursorX; //����Ű�� Ŀ��
extern int cursorY; 
extern int hint; //��Ʈ�� ��ȸ�� 3���� ����

void Gotoxy(int x, int y); //Ŀ��
void MakeBoard(); //�� �׸��� 
void ReadBoard(const char* txtfile, const char* answertxt); //������ �о�����Լ�
void CursorMake(); //�ǿ� ���� �Է��ϱ� ���� Ŀ��
void CursorMove(); //Ŀ�� Ű�Է�
void InsertNumber(); //�ǿ� ���ڳֱ�
int Input(); //���ڸ� ���� �� �ֵ��� -2�� ������
//void ChangeColor(const char* txtfile, const char* answertxt);
void Hint(); //��Ʈ �����ִ� �Լ�
void checkAnswer(); //���� üũ�ؼ� Ʋ���� ��������ϴ� �Լ�
void CheckGameOver(); //������ ���� �����ϴ� �Լ�
int sudoku(const char* txtfile, const char* answertxt); //�����Լ�