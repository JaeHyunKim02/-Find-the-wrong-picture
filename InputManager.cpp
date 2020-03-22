#include "stdafx.h"
#include "InputManager.h"
#include "Scene.h"

int InputManager::OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	SetTimer(hWnd, 0, 100, NULL); //0.1초마다 호출하는 타이머
	SetTimer(hWnd, 1, 1000, NULL); //1초마다 호출하는 타이머
	return 1;
}

int InputManager::OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (ObjPool->System.GetScene())	//옵젝풀에서 씬을 불러옴
	{
	case SCENE_TITLE:	//씬이 타이틀 이라면
		Title::OnTimer(hWnd, wParam);	//타이틀 타이머로 보냄
		break;
	case SCENE_INGAME:	//씬이 인게임 이라면
		Ingame::OnTimer(hWnd, wParam);	//인게임 타이머로 보냄
		break;
	case SCENE_CREDIT:	//씬이 크레딧 이라면
		Credit::OnTimer(hWnd, wParam);	//크레딧 타이머로 보냄
		break;
	case SCENE_STAGE_1:	//씬이 스테이지1 이라면
		Stage_1::OnTimer(hWnd, wParam);	//스테이지1 타이머로 보냄
		break;
	case SCENE_STAGE_2:	//씬이 스테이지2 이라면
		Stage_2::OnTimer(hWnd, wParam);	//스테이지2 타이머로 보냄
		break;
	case SCENE_STAGE_3:	//씬이 스테이지3 이라면
		Stage_3::OnTimer(hWnd, wParam);	//스테이지3 타이머로 보냄
		break;
	case SCENE_STAGE_4:	//씬이 스테이지4 이라면
		Stage_4::OnTimer(hWnd, wParam);	//스테이지4 타이머로 보냄
		break;
	case SCENE_STAGE_5:	//씬이 스테이지5 이라면
		Stage_5::OnTimer(hWnd, wParam);	//스테이지5 타이머로 보냄
		break;
	case SCENE_STAGE_6:	//씬이 스테이지6 이라면
		Stage_6::OnTimer(hWnd, wParam);	//스테이지6 타이머로 보냄
		break;
	case SCENE_FINAL://씬이 파이널이라면
		Final::OnTimer(hWnd, wParam);//파이널 타이머로 보냄
		break;
	case SCENE_CLEAR://씬이 클리어라면
		Clear::OnTimer(hWnd, wParam);//클리어 타이머로 보냄
		break;
	case SCENE_GAMEOVER://씬이 게임오버라면
		Game_Over::OnTimer(hWnd, wParam);//게임오버 타이머로 보냄
		break;

	}
	return 1;
}

int InputManager::OnMouseLButton(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (ObjPool->System.GetScene())	//설명 생략
	{
	case SCENE_TITLE:
		Title::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));	//마우스의 위치 값을 가진 lParam을 앞단어, 뒷단어로 분해해서 x,y가 됨 (?비트연산)
		break;
	case SCENE_INGAME:
		Ingame::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_CREDIT:
		Credit::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_1:
		Stage_1::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_2:
		Stage_2::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_3:
		Stage_3::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_4:
		Stage_4::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_5:
		Stage_5::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_6:
		Stage_6::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_FINAL:
		Final::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_CLEAR:
		Clear::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_GAMEOVER:
		Game_Over::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;

	}
	return 1;
}

int InputManager::OnMouseRButton(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (ObjPool->System.GetScene()) //설명 생략
	{
	case SCENE_TITLE:
		Title::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_INGAME:
		Ingame::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_CREDIT:
		Credit::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_1:
		Stage_1::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_2:
		Stage_2::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_3:
		Stage_3::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_4:
		Stage_4::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_5:
		Stage_5::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_6:
		Stage_6::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_FINAL:
		Final::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_CLEAR:
		Clear::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_GAMEOVER:
		Game_Over::OnMouseRButton(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;

	}
	return 1;
}

int InputManager::OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (ObjPool->System.GetScene()) //설명 생략
	{
	case SCENE_TITLE:
		Title::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_INGAME:
		Ingame::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_CREDIT:
		Credit::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_1:
		Stage_1::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_2:
		Stage_2::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_3:
		Stage_3::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_4:
		Stage_4::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_5:
		Stage_5::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_STAGE_6:
		Stage_6::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_FINAL:
		Final::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_CLEAR:
		Clear::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	case SCENE_GAMEOVER:
		Game_Over::OnMouseMove(hWnd, LOWORD(lParam), HIWORD(lParam));
		break;
	}
	return 1;
}

int InputManager::OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 1;
}

// Not Message
void InputManager::InputUpdate()		//메세지가 아닌 다른 인풋의 처리 (ex. 키보드)
{
	if (GetAsyncKeyState(VK_ESCAPE))	//키보드 입력이 VK_ESCAPE(=ESC)라면 프로그램 종료
	{
		exit(0);
	}


	switch (ObjPool->System.GetScene()) //설명 생략
	{
	case SCENE_TITLE:
		Title::OnKeyborad();
		break;
	case SCENE_INGAME:
		Ingame::OnKeyborad();
		break;
	case SCENE_CREDIT:
		Credit::OnKeyborad();
		break;
	case SCENE_STAGE_1:
		Stage_1::OnKeyborad();
		break;
	case SCENE_STAGE_2:
		Stage_2::OnKeyborad();
		break;
	case SCENE_STAGE_3:
		Stage_3::OnKeyborad();
		break;
	case SCENE_STAGE_4:
		Stage_4::OnKeyborad();
		break;
	case SCENE_STAGE_5:
		Stage_5::OnKeyborad();
		break;
	case SCENE_STAGE_6:
		Stage_6::OnKeyborad();
		break;
	case SCENE_FINAL:
		Final::OnKeyborad();
		break;
	case SCENE_CLEAR:
		Clear::OnKeyborad();
		break;
	case SCENE_GAMEOVER:
		Game_Over::OnKeyborad();
		break;

	}
}

// Proc
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)	//콜백에서 메세지 받으면 각각 함수로 전송
{
	switch (message)
	{
	case WM_CREATE:
		return InputManager::OnCreate(hWnd, wParam, lParam);
	case WM_TIMER:
		return InputManager::OnTimer(hWnd, wParam, lParam);
	case WM_LBUTTONUP:
		return InputManager::OnMouseLButton(hWnd, wParam, lParam);
	case WM_RBUTTONUP:
		return InputManager::OnMouseRButton(hWnd, wParam, lParam);
	case WM_MOUSEMOVE:
		return InputManager::OnMouseMove(hWnd, wParam, lParam);
	case WM_DESTROY:
		return InputManager::OnDestroy(hWnd, wParam, lParam);
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}