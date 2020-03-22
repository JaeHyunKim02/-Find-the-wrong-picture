#include "stdafx.h"

//namespace 는 같은 함수 이름이지만 성씨를 다르게 하여 구별할 수 있도록 구분
namespace Ingame {
	void OnDestroy(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool endingCheck();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();

}

namespace Title {
	void OnDestroy(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Help {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Credit {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Stage_1 {

	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool isCorrectCheck1();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}
namespace Stage_2 {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool isCorrectCheck2();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}
namespace Stage_3 {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool isCorrectCheck3();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}
namespace Stage_4 {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool isCorrectCheck4();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();

}
namespace Stage_5 {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool isCorrectCheck5();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}
namespace Stage_6 {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool isCorrectCheck6();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Clear {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool isCorrectCheck7();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Final {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool isCorrectCheck8();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}

namespace Game_Over {
	void OnDestory(); //씬 불러왔을때 제일 먼저 한 번 호출되는 함수
	void Draw(HDC hMemDC);
	bool isCorrectCheck9();
	void OnTimer(HWND hWnd, int timer);
	void OnMouseLButton(HWND hWnd, int x, int y);
	void OnMouseRButton(HWND hWnd, int x, int y);
	void OnMouseMove(HWND hWnd, int x, int y);
	void OnKeyborad();
}