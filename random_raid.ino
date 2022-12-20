// 準備
// オンライン
// 手持ちボックス：自動で送る
// 直前にポケポータルを開いてユニオンサークルを開き、ポケポータルを閉じる。その後バックに選択を合わせてメニューを閉じる。

// ライブラリを読み込むためのコード
#include <NintendoSwitchControlLibrary.h>

// ボタンを連打するループの時間（分）
const int MINUTE_TO_PUSH_BUTTON = 6;

// １ループ中にAを連打する回数
const int NUMBER_OF_PRESS_BUTTON_A = 4;

// ループ内でボタンを押した後に開ける時間（ミリ秒）
const int MSECOND_IN_ONE_ACTION = 800;

// 1分間にループする回数
const int NUMBER_OF_LOOP_IN_ONE_MINUTE = 60000 / (MSECOND_IN_ONE_ACTION * (NUMBER_OF_PRESS_BUTTON_A + 1));


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

  // ランダムレイド選択
  pushHat(Hat::LEFT, 800);
  pushHat(Hat::DOWN, 800);

  // MINUTE_TO_PUSH_BUTTON分間連打
  for(int i = 0; i< NUMBER_OF_LOOP_IN_ONE_MINUTE * MINUTE_TO_PUSH_BUTTON; i++) {
    pushButton(Button::A, MSECOND_IN_ONE_ACTION, NUMBER_OF_PRESS_BUTTON_A);
    pushButton(Button::R, MSECOND_IN_ONE_ACTION);
  }
}

void loop() {
  // ボタンを押した状態だと反応しないので待つ
  delay(2000);
  
  // メニュー開きポケポータル開く
  pushButton(Button::X, 600);
  pushButton(Button::A, 6000);

  // レイドバトル開く。２回目はDOWNいらない
  pushButton(Button::A, 8000);

  // ランダムレイド選択
  pushHat(Hat::LEFT, 800);
  pushHat(Hat::DOWN, 800);

  // MINUTE_TO_PUSH_BUTTON分間連打
  for(int i = 0; i< NUMBER_OF_LOOP_IN_ONE_MINUTE * MINUTE_TO_PUSH_BUTTON; i++) {
    pushButton(Button::A, MSECOND_IN_ONE_ACTION, NUMBER_OF_PRESS_BUTTON_A);
    pushButton(Button::R, MSECOND_IN_ONE_ACTION);
  }
  
}