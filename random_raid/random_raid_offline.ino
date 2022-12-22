// 準備
// オフライン
// 手持ちボックス：自動で送る
// メニューがバックにカーソル
// ポケポータルがユニオンサールにカーソル

// ライブラリを読み込むためのコード
#include <NintendoSwitchControlLibrary.h>

// 1ループ内でAXを押す回数
const int NUMBER_OF_PUSH_BUTTON_AX = 3;

// ループ内でボタンを押した後に開ける時間（ミリ秒）
const int MSECOND_IN_ONE_ACTION = 500;

void setup() {
  // Switchがマイコンを認識するまでは信号を受け付けないため、適当な処理をさせておく
  pushButton(Button::B, 500, 5);

  // メニューを開きオンラインにする
  pushButton(Button::X, 600);
  pushButton(Button::L, 10000);
  pushButton(Button::A, 600);

  // ポケポータル開く
  pushHat(Hat::DOWN, 600);
  pushHat(Hat::DOWN, 600);
  pushHat(Hat::DOWN, 600);
  pushButton(Button::A, 6000);

  // レイドバトル開く
  pushHat(Hat::DOWN, 600);
  pushButton(Button::A, 8000);

}

void loop() {
  for(int i = 0; i < NUMBER_OF_PUSH_BUTTON_AX ;i++) {
    pushButton(Button::A, MSECOND_IN_ONE_ACTION);
    pushButton(Button::X, MSECOND_IN_ONE_ACTION);
  }
  pushButton(Button::R, MSECOND_IN_ONE_ACTION);
}