#include "stdafx.h"
#include "DrawManager.h"
#include "Scene.h"

void DrawManager::Initialize()
{

}

void DrawManager::Drawing(HWND hwnd)	//그리기 단계 (더블버퍼링 적용됨)
{
	hWnd = hwnd;

	hdc = GetDC(hWnd);					//전면 DC
	hMemDC = CreateCompatibleDC(hdc);	//후면 DC

	hBit = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(hMemDC, hBit);

	switch (ObjPool->System.GetScene())	//그릴 씬 체크
	{ 
	case SCENE_TITLE:
		Title::Draw(hMemDC);	//후면DC 전송
		break;
	case SCENE_INGAME://인게임
		Ingame::Draw(hMemDC);
		break;
	case SCENE_CREDIT://크레딧
		Credit::Draw(hMemDC);
		break;
	case SCENE_STAGE_1://스테이지1
		Stage_1::Draw(hMemDC);
		break;
	case SCENE_STAGE_2://스테이지2
		Stage_2::Draw(hMemDC);
		break;
	case SCENE_STAGE_3://스테이지3
		Stage_3::Draw(hMemDC);
		break;
	case SCENE_STAGE_4://스테이지4
		Stage_4::Draw(hMemDC);
		break;
	case SCENE_STAGE_5://스테이지5
		Stage_5::Draw(hMemDC);
		break;
	case SCENE_STAGE_6://스테이지6
		Stage_6::Draw(hMemDC);
		break;
	case SCENE_FINAL://끝났을 때
		Final::Draw(hMemDC);
		break;
	case SCENE_CLEAR://6개의 스테이지를 깼을 때
		Clear::Draw(hMemDC);
		break;
	case SCENE_GAMEOVER://체력이 다 닳아 끝났을 때
		Game_Over::Draw(hMemDC);
		break;
	}

	BitBlt(hdc, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, hMemDC, 0, 0, SRCCOPY);	//씬 그리기에서 그림이 그려진 후면DC를 화면에 보여질 전면DC로 복사

	DeleteObject(hBit);
	DeleteDC(hMemDC);
	DeleteDC(hdc);
	ReleaseDC(hWnd, hdc);	//초기화!
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