#include "stdafx.h"
#include "DrawManager.h"
#include "Scene.h"

void DrawManager::Initialize()
{

}

void DrawManager::Drawing(HWND hwnd)	//�׸��� �ܰ� (������۸� �����)
{
	hWnd = hwnd;

	hdc = GetDC(hWnd);					//���� DC
	hMemDC = CreateCompatibleDC(hdc);	//�ĸ� DC

	hBit = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(hMemDC, hBit);

	switch (ObjPool->System.GetScene())	//�׸� �� üũ
	{ 
	case SCENE_TITLE:
		Title::Draw(hMemDC);	//�ĸ�DC ����
		break;
	case SCENE_INGAME://�ΰ���
		Ingame::Draw(hMemDC);
		break;
	case SCENE_CREDIT://ũ����
		Credit::Draw(hMemDC);
		break;
	case SCENE_STAGE_1://��������1
		Stage_1::Draw(hMemDC);
		break;
	case SCENE_STAGE_2://��������2
		Stage_2::Draw(hMemDC);
		break;
	case SCENE_STAGE_3://��������3
		Stage_3::Draw(hMemDC);
		break;
	case SCENE_STAGE_4://��������4
		Stage_4::Draw(hMemDC);
		break;
	case SCENE_STAGE_5://��������5
		Stage_5::Draw(hMemDC);
		break;
	case SCENE_STAGE_6://��������6
		Stage_6::Draw(hMemDC);
		break;
	case SCENE_FINAL://������ ��
		Final::Draw(hMemDC);
		break;
	case SCENE_CLEAR://6���� ���������� ���� ��
		Clear::Draw(hMemDC);
		break;
	case SCENE_GAMEOVER://ü���� �� ��� ������ ��
		Game_Over::Draw(hMemDC);
		break;
	}

	BitBlt(hdc, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, hMemDC, 0, 0, SRCCOPY);	//�� �׸��⿡�� �׸��� �׷��� �ĸ�DC�� ȭ�鿡 ������ ����DC�� ����

	DeleteObject(hBit);
	DeleteDC(hMemDC);
	DeleteDC(hdc);
	ReleaseDC(hWnd, hdc);	//�ʱ�ȭ!
}

void DrawManager::Terminate()
{
	if (hBit != nullptr)
		DeleteObject(hBit);
	if (hMemDC != nullptr)
		DeleteDC(hMemDC);
	if (hdc != nullptr)
		DeleteDC(hdc);
}