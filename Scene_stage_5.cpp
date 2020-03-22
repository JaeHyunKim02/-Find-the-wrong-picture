#include "stdafx.h"
#include "Scene.h"
//Ʋ���׸�ã�� ��������5
bool isCorrect5[4] = { false, };
int hp5 = 3;
int timeLimit5 = 200;
bool ispaused5 = false;
bool hint5 = false;
bool hintmode5 = false;
int mouseX5;
int mouseY5;


void Stage_5::OnDestory() //�� �Ѿ�� �� ��ư�� ü�»��� �ʱ�ȭ
{
	hintmode5 = false;
	hint5 = false;
	timeLimit5 = 200;
	hp5 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect5[0] = false;
	isCorrect5[1] = false;
	isCorrect5[2] = false;
	isCorrect5[3] = false;
	
}
void Stage_5::Draw(HDC hMemDC)
{
	ObjPool->stage_5.Draw(hMemDC);//�׽�Ʈ���� ����ٰ� �������� 5���� ����� �����ϸ� ��
	if (ispaused5 == false)
	{
		if (isCorrect5[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn17.pos.x + 30, ObjPool->asbtn17.pos.y + 10);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect5[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn18.pos.x + 10, ObjPool->asbtn18.pos.y);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect5[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn19.pos.x + 15, ObjPool->asbtn19.pos.y + 20);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect5[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn20.pos.x + 10, ObjPool->asbtn20.pos.y); // ������ ���� �� �������� Oǥ��
		}
		if (hint5 == true) // ��Ʈ �̹����� ���콺Ŀ�� ��ǥ��
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX5, mouseY5);
		}
		//��Ʈ�� ���

		ObjPool->heart1.Draw(hMemDC);//������������������������������������
		ObjPool->heart2.Draw(hMemDC);//                 ��Ʈ �̹���
		ObjPool->heart3.Draw(hMemDC);//������������������������������������
		ObjPool->light1.Draw(hMemDC);//������������������������������������
		ObjPool->light2.Draw(hMemDC);//                 ���� �̹���
		ObjPool->light3.Draw(hMemDC);//                 ��
		ObjPool->light4.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn17.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn18.Draw(hMemDC);//                 ���� ��ư;
		ObjPool->asbtn19.Draw(hMemDC);//                 ��
		ObjPool->asbtn20.Draw(hMemDC);//������������������������������������
		ObjPool->timer.Draw(hMemDC);// Ÿ�̸� �̹���
		ObjPool->stop.Draw(hMemDC);// �Ͻ����� �̹���
		ObjPool->hint.Draw(hMemDC);// ��Ʈ(������) �̹���

		//�ؽ�Ʈ(GDI) ���
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit5);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB�� ����
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //�޸𸮵�, x, y, �۲� 
	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);
	}
}

bool Stage_5::isCorrectCheck5()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect5[i] == false) return false;
	return true;
}


void Stage_5::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0:
		if (hp5 == 0 || timeLimit5 == 0) {//��Ʈ 3���� �� �������ų� �ð��� �� �Ǹ�
			Stage_5::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//���ӿ��� ȭ������ �̵�
		}
		if (isCorrectCheck5())//�����ư 4���� �� ���߸�
		{
			Stage_5::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//�������� Ŭ���� ȭ������ �̵�
			ObjPool->StageBtn_5.bIsOn = true;
			ObjPool->iscleared[4] = true;
		}
		break;
	case 1:
		if (ispaused5 == false)
		{
			timeLimit5--;
		}
		break;
	}
}

void Stage_5::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ispaused5 == false)
	{
		
		if (ObjPool->stop.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			ispaused5 = true;
		}
		else if (ObjPool->asbtn17.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect5[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn18.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect5[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn19.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect5[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn20.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect5[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y))
		{
			hintmode5 = true;
		}

		else if (ObjPool->stage_5.isClick(x, y)) {//Stage_4��� �޹���� Ŭ���ϸ�
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp5 == 3) {
				ObjPool->heart1.bIsOn = true;
				hp5--;
			}
			else if (hp5 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp5--;
			}
			else if (hp5 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp5--;
			}
		}
	}
	else
	{
		ispaused5 = false;
	}
}

void Stage_5::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_5::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode5 == true)
	{
		mouseX5 = x;
		mouseY5 = y;
		if (ObjPool->asbtn17.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect5[0] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint5 = false;
			}
			else	hint5 = true;
		}
		else if (ObjPool->asbtn18.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect5[1] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint5 = false;
			}
			else	hint5 = true;
		}
		else if (ObjPool->asbtn19.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect5[2] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint5 = false;
			}
			else	hint5 = true;
		}
		else if (ObjPool->asbtn20.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect5[3] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint5 = false;
			}
			else	hint5 = true;
		}

		else
		{
			hint5 = false;
		}
	}
}

void Stage_5::OnKeyborad()
{

}