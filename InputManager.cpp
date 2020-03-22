#include "stdafx.h"
#include "InputManager.h"
#include "Scene.h"

int InputManager::OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	SetTimer(hWnd, 0, 100, NULL); //0.1�ʸ��� ȣ���ϴ� Ÿ�̸�
	SetTimer(hWnd, 1, 1000, NULL); //1�ʸ��� ȣ���ϴ� Ÿ�̸�
	return 1;
}

int InputManager::OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (ObjPool->System.GetScene())	//����Ǯ���� ���� �ҷ���
	{
	case SCENE_TITLE:	//���� Ÿ��Ʋ �̶��
		Title::OnTimer(hWnd, wParam);	//Ÿ��Ʋ Ÿ�̸ӷ� ����
		break;
	case SCENE_INGAME:	//���� �ΰ��� �̶��
		Ingame::OnTimer(hWnd, wParam);	//�ΰ��� Ÿ�̸ӷ� ����
		break;
	case SCENE_CREDIT:	//���� ũ���� �̶��
		Credit::OnTimer(hWnd, wParam);	//ũ���� Ÿ�̸ӷ� ����
		break;
	case SCENE_STAGE_1:	//���� ��������1 �̶��
		Stage_1::OnTimer(hWnd, wParam);	//��������1 Ÿ�̸ӷ� ����
		break;
	case SCENE_STAGE_2:	//���� ��������2 �̶��
		Stage_2::OnTimer(hWnd, wParam);	//��������2 Ÿ�̸ӷ� ����
		break;
	case SCENE_STAGE_3:	//���� ��������3 �̶��
		Stage_3::OnTimer(hWnd, wParam);	//��������3 Ÿ�̸ӷ� ����
		break;
	case SCENE_STAGE_4:	//���� ��������4 �̶��
		Stage_4::OnTimer(hWnd, wParam);	//��������4 Ÿ�̸ӷ� ����
		break;
	case SCENE_STAGE_5:	//���� ��������5 �̶��
		Stage_5::OnTimer(hWnd, wParam);	//��������5 Ÿ�̸ӷ� ����
		break;
	case SCENE_STAGE_6:	//���� ��������6 �̶��
		Stage_6::OnTimer(hWnd, wParam);	//��������6 Ÿ�̸ӷ� ����
		break;
	case SCENE_FINAL://���� ���̳��̶��
		Final::OnTimer(hWnd, wParam);//���̳� Ÿ�̸ӷ� ����
		break;
	case SCENE_CLEAR://���� Ŭ������
		Clear::OnTimer(hWnd, wParam);//Ŭ���� Ÿ�̸ӷ� ����
		break;
	case SCENE_GAMEOVER://���� ���ӿ������
		Game_Over::OnTimer(hWnd, wParam);//���ӿ��� Ÿ�̸ӷ� ����
		break;

	}
	return 1;
}

int InputManager::OnMouseLButton(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (ObjPool->System.GetScene())	//���� ����
	{
	case SCENE_TITLE:
		Title::OnMouseLButton(hWnd, LOWORD(lParam), HIWORD(lParam));	//���콺�� ��ġ ���� ���� lParam�� �մܾ�, �޴ܾ�� �����ؼ� x,y�� �� (?��Ʈ����)
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
	switch (ObjPool->System.GetScene()) //���� ����
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
	switch (ObjPool->System.GetScene()) //���� ����
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
void InputManager::InputUpdate()		//�޼����� �ƴ� �ٸ� ��ǲ�� ó�� (ex. Ű����)
{
	if (GetAsyncKeyState(VK_ESCAPE))	//Ű���� �Է��� VK_ESCAPE(=ESC)��� ���α׷� ����
	{
		exit(0);
	}


	switch (ObjPool->System.GetScene()) //���� ����
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
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)	//�ݹ鿡�� �޼��� ������ ���� �Լ��� ����
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