// 準備
// オンライン
// 手持ちボックス：自動で送る
// メニューがバックにカーソル
// ポケポータルがユニオンサールにカーソル

// ライブラリを読み込むためのコード
#include <NintendoSwitchControlLibrary.h>

// ループ内でAボタンを押した後に開ける時間（ミリ秒）
const double MSECOND_IN_BUTTON_A_ACTION = 400;

// ループ内でXボタンを押した後に開ける時間（ミリ秒）
const int MSECOND_IN_BUTTON_X_ACTION = 3000;

// １ループ内でAボタンを押す時間（分）
const double MINUTE_TO_PUSH_BUTTON_A = 0.8;

// MINUTE_TO_PUSH_BUTTON_A分間にループする回数
const int NUMBER_OF_LOOP_IN_MINUTE = 60000 * MINUTE_TO_PUSH_BUTTON_A / MSECOND_IN_BUTTON_A_ACTION;

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
  for(int i = 0; i < NUMBER_OF_LOOP_IN_MINUTE ;i++) {
    pushButton(Button::A, MSECOND_IN_BUTTON_A_ACTION);
  }

  // メニューを開いて閉じる動作かつレイド更新。
  pushButton(Button::X, MSECOND_IN_BUTTON_X_ACTION);
  pushButton(Button::X, MSECOND_IN_BUTTON_X_ACTION);

  // 「ランダムレイド選択
  tiltLeftStick(Stick::MAX, Stick::NEUTRAL, 100);
  tiltLeftStick(Stick::NEUTRAL, Stick::MAX, 100);
  
  // 「レイドに参加できませんでした」用
  pushButton(Button::A, MSECOND_IN_BUTTON_A_ACTION);

  // メニューを開く
  pushButton(Button::X, MSECOND_IN_BUTTON_X_ACTION);
}