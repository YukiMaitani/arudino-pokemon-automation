// 準備
// 準備
// オンライン
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

  // メニュー開きポケポータル開く
  pushButton(Button::X, 600);
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