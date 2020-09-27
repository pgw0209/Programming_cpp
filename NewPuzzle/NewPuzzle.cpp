#include <bangtal.h>
#include <cstdio>
#include <iostream>
#include <ctime>

using namespace bangtal;
using namespace std;

int main() {

    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);


    srand((unsigned int)time(NULL));
    time_t start_time;
    time_t start_time2;

    auto sound = Sound::create("Audios/bgm.mp3");
    sound->play();
	auto scene1 = Scene::create("1단계", "Images/back1.png");
    auto scene2 = Scene::create("2단계", "Images/back2.png");

    auto timer = Timer::create(0.1);
    auto timer2 = Timer::create(0.1);

	ObjectPtr board[9];
    ObjectPtr board2[9];
    ObjectPtr init[9];
    ObjectPtr init2[9];

    int x3 = 350, x2 = 557, x1 = 764;
    int y1 = 85, y2 = 292, y3 = 499;
    int blank = 8;
    int blank2 = 8;


    board[0] = Object::create("Images/1.jpg", scene1, x3, y3);
    board[1] = Object::create("Images/2.jpg", scene1, x2, y3);
    board[2] = Object::create("Images/3.jpg", scene1, x1, y3);

    board[3] = Object::create("Images/4.jpg", scene1, x3, y2);
    board[4] = Object::create("Images/5.jpg", scene1, x2, y2);
    board[5] = Object::create("Images/6.jpg", scene1, x1, y2);

    board[6] = Object::create("Images/7.jpg", scene1, x3, y1);
    board[7] = Object::create("Images/8.jpg", scene1, x2, y1);
    board[8] = Object::create("Images/9.jpg", scene1, x1, y1);
    
    auto start = Object::create("images/start.png", scene1, 590, 70);
    auto second = Object::create("images/2단계.png", scene1, 590, 270);
    second->hide();
    start->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        
        start->hide();
        board[8]->setImage("Images/white.jpg");
        timer->start();
        start_time = time(NULL);
        return true;
        });
    second->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        second->hide();
        scene2->enter();
        return true;
        });

    for (int i = 0; i < 9; i++) {
        board[i]->setScale(0.5f);
        init[i] = board[i];
    }
    for (int j = 0; j < 9; j++) {
        board[j]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int k;
            for (k = 0; k < 9; k++) {
                if (board[k] == object)
                    break;
            }
            if ((k % 3 > 0 && k - 1 == blank)||
               (k % 3 < 2 && k + 1 ==blank) ||
               (k > 2 && k - 3 == blank) ||
               (k < 6 && k + 3 == blank)){
                board[k]->locate(scene1, 350 + (blank % 3) * 207, 499 - (blank / 3) * 207);
                board[blank]->locate(scene1, 350 + (k % 3) * 207, 499 - (k / 3) * 207);
                board[k] = board[blank];
                board[blank] = object;
                blank = k;
                
                int a;
                for (a = 0; a < 9; a++) {
                    if (board[a] != init[a]) break;
                }
                if (a == 9) {
                    auto end_time = time(NULL);
                    string buf = to_string((int)(difftime(end_time, start_time))) + "초걸렸습니다! 1단계 성공!";
                    showMessage(buf.c_str());
                    second->show();
                }
            }
            return true;
            });
    }

    auto count = 0;
 
    timer->setOnTimerCallback([&](TimerPtr t)->bool {

        int j = 0;

        do {
            switch (rand() % 4) {
            case 0: j = blank - 1; break;
            case 1: j = blank + 1; break;
            case 2: j = blank - 3; break;
            case 3: j = blank + 3; break;
            }
        } while (j < 0 || j > 8 || !((j % 3 > 0 && j - 1 == blank) ||
                (j % 3 < 2 && j + 1 == blank) ||
                (j > 2 && j - 3 == blank) ||
                (j < 6 && j + 3 == blank)));
            
                board[j]->locate(scene1, 350 + (blank % 3) * 207, 499 - (blank / 3) * 207);
                board[blank]->locate(scene1, 350 + (j % 3) * 207, 499 - (j / 3) * 207);

                auto object = board[j];
                board[j] = board[blank];
                board[blank] = object;
                blank = j;
            
        

        count++;
        if (count < 30) {
            t->set(0.1f);
            t->start();
        }
        return true;

        });
    


    ////////////////////////////////////////////////////////////////////////

    int x3_ = 311, x2_ = 506, x1_ = 701;
    int y1_ = 93, y2_ = 288, y3_ = 483;

    board2[0] = Object::create("Images/1_.jpg", scene2, x3_, y3_);
    board2[1] = Object::create("Images/2_.jpg", scene2, x2_, y3_);
    board2[2] = Object::create("Images/3_.jpg", scene2, x1_, y3_);

    board2[3] = Object::create("Images/4_.jpg", scene2, x3_, y2_);
    board2[4] = Object::create("Images/5_.jpg", scene2, x2_, y2_);
    board2[5] = Object::create("Images/6_.jpg", scene2, x1_, y2_);

    board2[6] = Object::create("Images/7_.jpg", scene2, x3_, y1_);
    board2[7] = Object::create("Images/8_.jpg", scene2, x2_, y1_);
    board2[8] = Object::create("Images/9_.jpg", scene2, x1_, y1_);

    auto start2 = Object::create("images/start.png", scene2, 590, 70);


    start2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        start2->hide();
        board2[8]->setImage("Images/white.jpg");
        timer2->start();
        start_time2 = time(NULL);
        return true;
        });
    for (int b = 0; b < 9; b++) {
        board2[b]->setScale(0.47f);
        init2[b] = board2[b];
    }
    for (int j = 0; j < 9; j++) {
        board2[j]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int k;
            for (k = 0; k < 9; k++) {
                if (board2[k] == object)
                    break;
            }
            if ((k % 3 > 0 && k - 1 == blank2) ||
                (k % 3 < 2 && k + 1 == blank2) ||
                (k > 2 && k - 3 == blank2) ||
                (k < 6 && k + 3 == blank2)) {
                board2[k]->locate(scene2, 311 + (blank2 % 3) * 195, 483 - (blank2 / 3) * 195);
                board2[blank2]->locate(scene2, 311 + (k % 3) * 195, 483 - (k / 3) * 195);
                board2[k] = board2[blank2];
                board2[blank2] = object;
                blank2 = k;

                int a;
                for (a = 0; a < 9; a++) {
                    if (board2[a] != init2[a]) break;
                }
                if (a == 9) {
                    auto end_time2 = time(NULL);
                    string buf2 = to_string((int)(difftime(end_time2, start_time2))) + "초걸렸습니다! 퍼즐맞추기 대성공!!";
                    showMessage(buf2.c_str());
                    
                }
            }
            return true;
            });
    }

    auto count2 = 0;

    timer2->setOnTimerCallback([&](TimerPtr t)->bool {

        int j = 0;

        do {
            switch (rand() % 4) {
            case 0: j = blank2 - 1; break;
            case 1: j = blank2 + 1; break;
            case 2: j = blank2 - 3; break;
            case 3: j = blank2 + 3; break;
            }
        } while (j < 0 || j > 8 || !((j % 3 > 0 && j - 1 == blank2) ||
            (j % 3 < 2 && j + 1 == blank2) ||
            (j > 2 && j - 3 == blank2) ||
            (j < 6 && j + 3 == blank2)));

        board2[j]->locate(scene2, 311 + (blank2 % 3) * 195, 483 - (blank2 / 3) * 195);
        board2[blank2]->locate(scene2, 311 + (j % 3) * 195, 483 - (j / 3) * 195);

        auto object = board2[j];
        board2[j] = board2[blank2];
        board2[blank2] = object;
        blank2 = j;



        count2++;
        if (count2 < 50) {
            t->set(0.1f);
            t->start();
        }
        return true;

        });

	startGame(scene1);
	return 0;
}