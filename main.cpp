// Win32APIGameBase.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "System.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow) //뭔가 이상한게 굉장히 많지만. 이게 일단 main함수라고 생각하면 편해.
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//Api System

	//시작하기 앞서 숙지해두면 좋은 것들
	//1. 이 프레임워크는 파일분할이 적용되어 있어. 실행의 흐름을 읽고 싶다면, 함수에 커서를 올린 후 F12를 적극적으로 활용해보렴.
	//2. 모르는 문법들이 가득 나오는게 당연한거야. 나도 이 프레임워크를 완벽히 이해하진 못해. 게임 개발에 필요한 부분부터 조금씩 손대어 나가봐.
	//3. 이해한 내용이 있으면 너만의 주석을 달아 표시해둬. 주석은 코드를 이해했다는 기쁨의 표식이기도 하거든.

	ApiSystem* System = new ApiSystem;


	System->Initialize();	//초기화
	System->Run();			//실행
	System->Terminate();	//종료

	delete System;

	return 0;
}
