#include <DxLib.h>

/// <summary>
/// 2次元ベクトル
/// </summary>
struct Vector2
{
	float x;
	float y;
};

using Position2 = Vector2;

/// <summary>
/// 矩形構造体
/// </summary>
struct Rect
{
	Position2 center;
	// 中心から端までの距離
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
	SetWindowText(L"1916022_津田舜太");
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	// (200,200)の位置に幅100、高さ200の矩形
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


		// 矩形の表示
		DrawBox(rc.Left(), rc.Top(), rc.Right(), rc.Bottom(), 0xffffff, true);

		ScreenFlip();
	}
	DxLib_End();
	return 0;
}