#include "stdafx.h"
#include "Scene.h"
//Ʋ���׸�ã�� ��������3
bool isCorrect3[4] = { false, };
int hp3 = 3;
int timeLimit3 = 200;
bool ispaused3 = false;
bool hint3 = false;
bool hintmode3 = false;
int mouseX3;
int mouseY3;

void Stage_3::OnDestory() //�� �Ѿ�� �� ��ư�� ü�»��� �ʱ�ȭ
{
	hintmode3 = false;
	hint3 = false;
	timeLimit3 = 200;
	hp3 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect3[0] = false;
	isCorrect3[1] = false;
	isCorrect3[2] = false;
	isCorrect3[3] = false;
}


void Stage_3::Draw(HDC hMemDC)
{
	ObjPool->stage_3.Draw(hMemDC);
	if (ispaused3 == false)
	{
		if (isCorrect3[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn9.pos.x + 7, ObjPool->asbtn9.pos.y + 17);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect3[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn10.pos.x, ObjPool->asbtn10.pos.y + 15);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect3[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn11.pos.x + 20, ObjPool->asbtn11.pos.y);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect3[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn12.pos.x, ObjPool->asbtn12.pos.y + 20);// ������ ���� �� �������� Oǥ��
		}
		if (hint3 == true) // ��Ʈ �̹����� ���콺Ŀ�� ��ǥ��
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX3, mouseY3);
		}
		//��Ʈ�� ���

		ObjPool->heart1.Draw(hMemDC);//������������������������������������
		ObjPool->heart2.Draw(hMemDC);//                 ��Ʈ �̹���
		ObjPool->heart3.Draw(hMemDC);//������������������������������������
		ObjPool->light1.Draw(hMemDC);//������������������������������������
		ObjPool->light2.Draw(hMemDC);//                 ���� �̹���
		ObjPool->light3.Draw(hMemDC);//                 ��
		ObjPool->light4.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn9.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn10.Draw(hMemDC);//                 ���� ��ư
		ObjPool->asbtn11.Draw(hMemDC);//                 ��
		ObjPool->asbtn12.Draw(hMemDC);//������������������������������������
		ObjPool->timer.Draw(hMemDC);// Ÿ�̸� �̹���
		ObjPool->stop.Draw(hMemDC);// �Ͻ����� �̹���
		ObjPool->hint.Draw(hMemDC);// ��Ʈ(������) �̹���
		//��ư ���

		//�ؽ�Ʈ(GDI) ���
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit3);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB�� ����
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //�޸𸮵�, x, y, �۲� ũ��
	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);
	}

}

bool Stage_3::isCorrectCheck3()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect3[i] == false) return false;
	return true;
}


void Stage_3::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0:
		if (hp3 == 0 || timeLimit3 == 0) {//��Ʈ 3���� �� �������ų� �ð��� �� �Ǹ�
			Stage_3::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//���ӿ��� ȭ������ �̵�
		}
		if (isCorrectCheck3())//�����ư 4���� �� ���߸�
		{
			Stage_3::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//�������� Ŭ���� ȭ������ �̵�
			ObjPool->StageBtn_3.bIsOn = true;
			ObjPool->iscleared[2] = true;

		}
		break;
	case 1: //1�ʸ���
		if (ispaused3 == false)
		{
			timeLimit3--;
		}
		break;
	}


}

void Stage_3::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ispaused3 == false)
	{
		
		if (ObjPool->stop.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			ispaused3 = true;
		}
		else if (ObjPool->asbtn9.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect3[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn10.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect3[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn11.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect3[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn12.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect3[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y)) {
			hintmode3 = true;
		}

		else if (ObjPool->stage_3.isClick(x, y)) {//Stage_3��� �޹���� Ŭ���ϸ�
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp3 == 3) {
				ObjPool->heart1.bIsOn = true;
				hp3--;
			}
			else if (hp3 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp3--;
			}
			else if (hp3 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp3--;
			}
		}
	}
	else
	{
		ispaused3 = false;
	}
}


void Stage_3::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_3::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode3 == true)
	{
		mouseX3 = x;
		mouseY3 = y;
		if (ObjPool->asbtn9.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect3[0] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint3 = false;
			}
			else	hint3 = true;

		}
		else if (ObjPool->asbtn10.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect3[1] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint3 = false;
			}
			else	hint3 = true;
		}
		else if (ObjPool->asbtn11.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect3[2] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint3 = false;
			}
			else	hint3 = true;
		}
		else if (ObjPool->asbtn12.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect3[3] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint3 = false;
			}
			else	hint3 = true;
		}

		else
		{
			hint3 = false;
		}
	}
}

void Stage_3::OnKeyborad()
{

}