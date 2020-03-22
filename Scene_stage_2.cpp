#include "stdafx.h"
#include "Scene.h"
//Ʋ���׸�ã�� ��������2
bool isCorrect2[4] = { false, };
int hp2 = 3;
int timeLimit2 = 200;
bool ispaused2 = false;
bool hint2 = false;
bool hintmode2 = false;
int mouseX2;
int mouseY2;


void Stage_2::OnDestory() //�� �Ѿ�� �� ��ư�� ü�»��� �ʱ�ȭ
{

	hintmode2 = false;
	hint2 = false;
	timeLimit2 = 200;
	hp2 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect2[0] = false;
	isCorrect2[1] = false;
	isCorrect2[2] = false;
	isCorrect2[3] = false;
	
}


void Stage_2::Draw(HDC hMemDC)
{
	if (ispaused2 == false)
	{
		ObjPool->stage_2.Draw(hMemDC);//�׽�Ʈ���� ����ٰ� �������� 2���� ����� �����ϸ� ��
		if (isCorrect2[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn5.pos.x + 25, ObjPool->asbtn5.pos.y + 10);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect2[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn6.pos.x + 5, ObjPool->asbtn6.pos.y + 25);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect2[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn7.pos.x + 25, ObjPool->asbtn7.pos.y + 20);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect2[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn8.pos.x + 20, ObjPool->asbtn8.pos.y + 27); // ������ ���� �� �������� Oǥ��
		}
		if (hint2 == true) // ��Ʈ �̹����� ���콺Ŀ�� ��ǥ��
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX2, mouseY2);
		}
		//��Ʈ�� ���

		ObjPool->heart1.Draw(hMemDC);//������������������������������������
		ObjPool->heart2.Draw(hMemDC);//                 ��Ʈ �̹���
		ObjPool->heart3.Draw(hMemDC);//������������������������������������
		ObjPool->light1.Draw(hMemDC);//������������������������������������
		ObjPool->light2.Draw(hMemDC);//                 ���� �̹���
		ObjPool->light3.Draw(hMemDC);//                 ��
		ObjPool->light4.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn5.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn6.Draw(hMemDC);//                 ���� ��ư
		ObjPool->asbtn7.Draw(hMemDC);//                 ��
		ObjPool->asbtn8.Draw(hMemDC);//������������������������������������
		ObjPool->timer.Draw(hMemDC);// Ÿ�̸� �̹���
		ObjPool->stop.Draw(hMemDC);// �Ͻ����� �̹���
		ObjPool->hint.Draw(hMemDC);// ��Ʈ(������) �̹���

		//�ؽ�Ʈ(GDI) ���
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit2);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB�� ����
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //�޸𸮵�, x, y, �۲� ũ��
	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);
	}
}

bool Stage_2::isCorrectCheck2()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect2[i] == false) return false;
	return true;
}


void Stage_2::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0:
		if (hp2 == 0|| timeLimit2==0) {//��Ʈ 3���� �� �������ų� �ð��� �� �Ǹ�
			Stage_2::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//���ӿ��� ȭ������ �̵�
		}
		if (isCorrectCheck2())//�����ư 4���� �� ���߸�
		{
			Stage_2::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//�������� Ŭ���� ȭ������ �̵�
			ObjPool->StageBtn_2.bIsOn = true;
			ObjPool->iscleared[1] = true;
		}
		break;
	case 1: //1�ʸ���
		if (ispaused2 == false)
		{
			timeLimit2--;
		}
		break;
	}
}

void Stage_2::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ispaused2 == false)
	{
		
		if (ObjPool->stop.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			ispaused2 = true;
		}
		else if (ObjPool->asbtn5.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect2[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn6.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect2[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn7.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect2[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn8.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect2[3] = true;
			ObjPool->light4.bIsOn = true;
		}
		else if (ObjPool->hint.isClick(x, y))
		{
			hintmode2 = true;
		}

		else if (ObjPool->stage_2.isClick(x, y)) {//Stage_4��� �޹���� Ŭ���ϸ�
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp2 == 3) {
				ObjPool->heart1.bIsOn = true;
				hp2--;
			}
			else if (hp2 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp2--;
			}
			else if (hp2 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp2--;
			}
		}
	}
	else
	{
		ispaused2 = false;
	}
}

void Stage_2::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_2::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode2 == true)
	{
		mouseX2 = x;
		mouseY2 = y;
		if (ObjPool->asbtn5.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect2[0] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint2 = false;
			}
			else	hint2 = true;
		}
		else if (ObjPool->asbtn6.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect2[1] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint2 = false;
			}
			else	hint2 = true;

		}
		else if (ObjPool->asbtn7.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect2[2] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint2 = false;
			}
			else	hint2 = true;

		}
		else if (ObjPool->asbtn8.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect2[3] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint2 = false;
			}
			else	hint2 = true;

		}

		else
		{
			hint2 = false;
		}
	}
}

void Stage_2::OnKeyborad()
{

}