#include "stdafx.h"
#include "Scene.h"
//Ʋ���׸�ã�� ��������4
bool isCorrect4[4] = { false, };
int hp4 = 3;
int timeLimit4 = 200;
bool ispaused4 = false;
bool hint4 = false;
bool hintmode4 = false;
int mouseX4;
int mouseY4;


void Stage_4::OnDestory() //�� �Ѿ�� �� ��ư�� ü�»��� �ʱ�ȭ
{
	hintmode4 = false;
	hint4 = false;
	timeLimit4 = 200;
	hp4 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect4[0] = false;
	isCorrect4[1] = false;
	isCorrect4[2] = false;
	isCorrect4[3] = false;
	
}

void Stage_4::Draw(HDC hMemDC)
{
	ObjPool->stage_4.Draw(hMemDC);
	if (ispaused4 == false)
	{
		if (isCorrect4[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn13.pos.x + 10, ObjPool->asbtn13.pos.y);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect4[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn14.pos.x + 20, ObjPool->asbtn14.pos.y);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect4[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn15.pos.x + 10, ObjPool->asbtn15.pos.y + 5);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect4[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn16.pos.x + 10, ObjPool->asbtn16.pos.y + 17); // ������ ���� �� �������� Oǥ��
		}
		//��Ʈ�� ���

		ObjPool->heart1.Draw(hMemDC);//������������������������������������
		ObjPool->heart2.Draw(hMemDC);//                 ��Ʈ �̹���
		ObjPool->heart3.Draw(hMemDC);//������������������������������������
		ObjPool->light1.Draw(hMemDC);//������������������������������������
		ObjPool->light2.Draw(hMemDC);//                 ���� �̹���
		ObjPool->light3.Draw(hMemDC);//                 ��
		ObjPool->light4.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn13.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn14.Draw(hMemDC);//                 ���� ��ư
		ObjPool->asbtn15.Draw(hMemDC);//                 ��
		ObjPool->asbtn16.Draw(hMemDC);//������������������������������������
		ObjPool->timer.Draw(hMemDC);// Ÿ�̸� �̹���
		ObjPool->stop.Draw(hMemDC);// �Ͻ����� �̹���
		ObjPool->hint.Draw(hMemDC);// ��Ʈ(������) �̹���

		if (hint4 == true) // ��Ʈ �̹����� ���콺Ŀ�� ��ǥ��
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX4, mouseY4);
		}
		//��ư ���

		//�ؽ�Ʈ(GDI) ���
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit4);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB�� ����
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //�޸𸮵�, x, y, �۲� ũ��

	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);
	}

}

bool Stage_4::isCorrectCheck4()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect4[i] == false) return false;
	return true;
}


void Stage_4::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0:
		if (hp4 == 0 || timeLimit4 == 0) {//��Ʈ 3���� �� �������ų� �ð��� �� �Ǹ�
			Stage_4::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//���ӿ��� ȭ������ �̵�
		}
		if (isCorrectCheck4())//�����ư 4���� �� ���߸�
		{
			Stage_4::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//�������� Ŭ���� ȭ������ �̵�
			ObjPool->StageBtn_4.bIsOn = true;
			ObjPool->iscleared[3] = true;
		}
		break;
	case 1: //1�ʸ���
		if (ispaused4 == false)
		{
			timeLimit4--;
		}
		break;
	}


}

void Stage_4::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ispaused4 == false)
	{
		
		if (ObjPool->stop.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			ispaused4 = true;
		}
		else if (ObjPool->asbtn13.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect4[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn14.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect4[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn15.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect4[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn16.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect4[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y))
		{
			hintmode4 = true;
		}

		else if (ObjPool->stage_4.isClick(x, y)) {//Stage_4��� �޹���� Ŭ���ϸ�
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp4 == 3) {
				ObjPool->heart1.bIsOn = true;
				hp4--;
			}
			else if (hp4 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp4--;
			}
			else if (hp4 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp4--;
			}
		}
	}
	else
	{
		ispaused4 = false;
	}

}


void Stage_4::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_4::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode4 == true)
	mouseX4 = x;
	mouseY4 = y;
	if (ObjPool->asbtn13.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
	{
		if (isCorrect4[0] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
			hint4 = false;
		}
		else	hint4 = true;
	}
	else if (ObjPool->asbtn14.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
	{
		if (isCorrect4[1] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
			hint4 = false;
		}
		else	hint4 = true;
	}
	else if (ObjPool->asbtn15.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
	{
		if (isCorrect4[2] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
			hint4 = false;
		}
		else	hint4 = true;
	}
	else if (ObjPool->asbtn16.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
	{
		if (isCorrect4[3] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
			hint4 = false;
		}
		else	hint4 = true;
	}

	else
	{
		hint4 = false;
	}
}

void Stage_4::OnKeyborad()
{

}