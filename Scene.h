#include "stdafx.h"

//namespace �� ���� �Լ� �̸������� ������ �ٸ��� �Ͽ� ������ �� �ֵ��� ����
namespace Ingame {
	void OnDestroy(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool endingCheck();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();

}

namespace Title {
	void OnDestroy(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Help {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Credit {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Stage_1 {

	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool isCorrectCheck1();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}
namespace Stage_2 {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool isCorrectCheck2();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}
namespace Stage_3 {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool isCorrectCheck3();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}
namespace Stage_4 {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool isCorrectCheck4();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();

}
namespace Stage_5 {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool isCorrectCheck5();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}
namespace Stage_6 {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool isCorrectCheck6();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Clear {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool isCorrectCheck7();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Final {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool isCorrectCheck8();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Game_Over {
	void OnDestory(); //�� �ҷ������� ���� ���� �� �� ȣ��Ǵ� �Լ�
	void Draw(HDC hMemDC);
	bool isCorrectCheck9();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}