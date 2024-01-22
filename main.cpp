#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"

const char kWindowTitle[] = "LC1A_06_オオハラアオイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	int windowX = 1280;
	int windowY = 720;
	Novice::Initialize(kWindowTitle, windowX, windowY);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player_ = new Player();
	Enemy* enemys[2];
	for (int oi = 0; oi < 2; oi++) {
		enemys[oi] = new Enemy({ 200.0f * oi , 200.0f + (oi * 300) });
	}
	Collision* collision_ = new Collision(player_);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///------------------///
		/// ↓更新処理ここから
		///------------------///

		player_->Update(keys, preKeys);
		for (int oi = 0; oi < 2; oi++) {
			enemys[oi]->Update();
			collision_->Update(enemys[oi]);
		}
		

		///------------------///
		/// ↑更新処理ここまで
		///------------------///

		///------------------///
		/// ↓描画処理ここから
		///------------------///

		player_->Draw();
		for (int oi = 0; oi < 2; oi++) {
			enemys[oi]->Draw();
		}

		if (keys[DIK_R]) {
			Enemy::SetIsAlive(true);
		}

		///------------------///
		/// ↑描画処理ここまで
		///------------------///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player_;
	delete collision_;
	for (int oi = 0; oi < 2; oi++) {
		delete enemys[oi];
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
