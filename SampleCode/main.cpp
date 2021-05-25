#include <DxLib.h>

/// <summary>
/// 2�����x�N�g��
/// </summary>
struct Vector2
{
	float x;
	float y;
};

using Position2 = Vector2;

/// <summary>
/// ��`�\����
/// </summary>
struct Rect
{
	Position2 center;
	// ���S����[�܂ł̋���
	float w;
	float h;

	float Left() const
	{
		return center.x - w;
	}

	float Right() const
	{
		return center.x + w;
	}

	float Top() const
	{
		return center.y - h;
	}

	float Bottom() const
	{
		return center.y + h;
	}

	float Width() const
	{
		return w * 2.0f;
	}

	float Height() const
	{
		return h * 2.0f;
	}
};


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	SetWindowText(L"1916022_�Óc�w��");
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	// (200,200)�̈ʒu�ɕ�100�A����200�̋�`
	Rect rc = { 200, 200, 50, 100 };

	char keystate[256];

	while (!ProcessMessage())
	{
		ClsDrawScreen();
		GetHitKeyStateAll(keystate);

		constexpr float speed = 4.0f;
		if (keystate[KEY_INPUT_LEFT])
		{
			rc.center.x -= speed;
		}
		if (keystate[KEY_INPUT_RIGHT])
		{
			rc.center.x += speed;
		}
		if (keystate[KEY_INPUT_DOWN])
		{
			rc.center.y += speed;
		}
		if (keystate[KEY_INPUT_UP])
		{
			rc.center.y -= speed;
		}


		// ��`�̕\��
		DrawBox(rc.Left(), rc.Top(), rc.Right(), rc.Bottom(), 0xffffff, true);

		ScreenFlip();
	}
	DxLib_End();
	return 0;
}