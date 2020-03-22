#include "stdafx.h"
#include "Scene.h"
//���������� �����ϴ� â
bool Ingame::endingCheck()
{
	for (int i = 0; i < 6; i++)
		if (ObjPool->iscleared[i] == false) return false;
	return true;
}



void Ingame::OnDestroy()
{

}

void Ingame::Draw(HDC hMemDC)
{
	ObjPool->stagechooseBg.Draw(hMemDC, 0, 0);
	ObjPool->StageBtn_1.Draw(hMemDC);//������ 1~6 ���� ��ư
	ObjPool->StageBtn_2.Draw(hMemDC);
	ObjPool->StageBtn_3.Draw(hMemDC);
	ObjPool->StageBtn_4.Draw(hMemDC);
	ObjPool->StageBtn_5.Draw(hMemDC);
	ObjPool->StageBtn_6.Draw(hMemDC);
	ObjPool->mainBtn.Draw(hMemDC);
	if (endingCheck())
	{
		ObjPool->end.Draw(hMemDC);
	}
}

void Ingame::OnTimer(HWND hWnd, int timer)
{
	//switch (timer)
	//{
	//case 0: //0.1�ʸ��� ȣ��Ǵ� Ÿ�̸�
	//	
	//}
}

void Ingame::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->StageBtn_1.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_STAGE_1);	//ù��° ����������
	}
	if (ObjPool->StageBtn_2.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_STAGE_2);	//�ι�° ����������
	}
	if (ObjPool->StageBtn_3.isClick(x, y))	//��ư�� Ŭ ������ ��
	{
		ObjPool->System.SetScene(SCENE_STAGE_3);	//����° ����������
	}
	if (ObjPool->StageBtn_4.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_STAGE_4);	//�׹�° ����������
	}
	if (ObjPool->StageBtn_5.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_STAGE_5);	//�ټ���° ����������
	}
	if (ObjPool->StageBtn_6.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_STAGE_6);	//������° ����������
	}
	if (ObjPool->mainBtn.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_TITLE);	//��������
	}
	if (ObjPool->end.isClick(x, y) && endingCheck())	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_FINAL);	//��� ���������� ������ �� ���� â����
	}
}

void Ingame::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Ingame::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
}

void Ingame::OnKeyborad()
{

}