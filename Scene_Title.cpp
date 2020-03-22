#include "stdafx.h"
#include "Scene.h"
//�������� ����ȭ������ ���� ��ư, ũ������ư, ������ ������ ��ư�� �����ϴ� ��
bool isSoundPlay = 0;

void Title::OnDestroy()
{

}

void Title::Draw(HDC hMemDC)
{

	ObjPool->titleBg.Draw(hMemDC, 0, 0);
	//��Ʈ�� ���

	ObjPool->startBtn.Draw(hMemDC);
	//��ư ���
	ObjPool->exitBtn.Draw(hMemDC);
	ObjPool->helpBtn.Draw(hMemDC);
	ObjPool->creditBtn.Draw(hMemDC);
	ObjPool->SoundBtn.Draw(hMemDC);
	
}

void Title::OnTimer(HWND hWnd, int timer)
{

}

void Title::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->startBtn.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_INGAME);	//�������� ���� ȭ������
	}
	if (ObjPool->creditBtn.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_CREDIT);	//ũ��������
	}
	if (ObjPool->helpBtn.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_HELP);	//����â����
	}
	if (ObjPool->exitBtn.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		exit(0); //���� ����
	}
	if (ObjPool->SoundBtn.isClick(x, y))	//��ư�� Ŭ������ ��
	{


		if (isSoundPlay == 0) {
			ObjPool->SoundBtn.bIsOn = true;
			//mciSendString(L"play Sound\\BGM.wav REPEAT", NULL, 0, 0);
			mciSendString(L"play Sound\\BGM.wav", NULL, 0, 0);
			//sndPlaySound(L"Sound\\BGM.wav", SND_NO); // ������ �� BGM������ ���ִ°�
			isSoundPlay = 1;
			//mciSendString(L"play Sound\\BGM.wav", NULL, 0, NULL);
			
		}
		else if (isSoundPlay == 1) {
			ObjPool->SoundBtn.bIsOn = false;
			mciSendString(L"pause Sound\\BGM.wav", NULL, 0, 0);
			//sndPlaySound(NULL, SND_NOSTOP);
			isSoundPlay = 0;
		}
	}
}

void Title::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Title::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->startBtn.isOver(x, y);	//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
	ObjPool->exitBtn.isOver(x, y);	//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
	ObjPool->helpBtn.isOver(x, y);	//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
	ObjPool->creditBtn.isOver(x, y);//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
}

void Title::OnKeyborad()
{

}