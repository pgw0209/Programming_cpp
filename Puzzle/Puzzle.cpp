#include <bangtal.h>
#include <windows.h>
#include <time.h>
using namespace bangtal;

struct Puzzle {
    int centerX, centerY;
};


int main()
{
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
    auto scene1 = Scene::create("퍼즐", "Images/back1.png");
    auto scene2 = Object::create("Images/back1.png", scene1, 45, 30);
    scene2->setScale(0.465f);

    auto scene3 = Scene::create("퍼즐", "Images/scene2.png");
    auto scene4 = Object::create("Images/scene2.png", scene3, 45, 30);
    scene4->setScale(0.493f);

    int x3 = 370, x2 = 563, x1 = 756;
    int y1 = 104, y2 = 297, y3 = 490;
    int px = x1, py = y1; // 초기 하얀색 칸의 위치
    int psize = 193;
    int end = 0;


    auto timer1 = Timer::create(60);


    showTimer(timer1);
    

    Puzzle puzzle[9]{

        {x3, y3},
        {x2, y3},
        {x1, y3},


        {x3, y2},
        {x2, y2},
        {x1, y2},

        {x3, y1},
        {x2, y1},
        {x1, y1},

    };

    ObjectPtr p[12];
    p[0] = Object::create("Images/1.jpg", scene1, puzzle[0].centerX, puzzle[0].centerY);
    p[1] = Object::create("Images/2.jpg", scene1, puzzle[1].centerX, puzzle[1].centerY);
    p[2] = Object::create("Images/3.jpg", scene1, puzzle[2].centerX, puzzle[2].centerY);

    p[3] = Object::create("Images/4.jpg", scene1, puzzle[3].centerX, puzzle[3].centerY);
    p[4] = Object::create("Images/5.jpg", scene1, puzzle[4].centerX, puzzle[4].centerY);
    p[5] = Object::create("Images/6.jpg", scene1, puzzle[5].centerX, puzzle[5].centerY);

    p[6] = Object::create("Images/7.jpg", scene1, puzzle[6].centerX, puzzle[6].centerY);
    p[7] = Object::create("Images/8.jpg", scene1, puzzle[7].centerX, puzzle[7].centerY);
    p[8] = Object::create("Images/9.jpg", scene1, puzzle[8].centerX, puzzle[8].centerY);


    for (int i = 0; i < 9; i++) {
        p[i]->setScale(0.465f);
    }


    int rand_n1 = rand() % 2;
    int rand_n2 = rand() % 2;
    int rand_n3 = rand() % 4;
    int rand_n4 = rand() % 3;
    int rand_n5 = rand() % 2;


    auto start = Object::create("images/start.png", scene1, 590, 70);
    start->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        timer1->start();
        start->hide();
        p[8]->setImage("Images/white.jpg");
        if (rand_n1 == 0) { // 북
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + psize);
            p[5]->locate(scene1, puzzle[5].centerX, puzzle[5].centerY - psize);
            puzzle[8].centerY += psize;
            puzzle[5].centerY -= psize;
            if (rand_n2 == 0) { // 북
                p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + psize);
                p[2]->locate(scene1, puzzle[2].centerX, puzzle[2].centerY - psize);
                puzzle[8].centerY += psize;
                puzzle[2].centerY -= psize;
                if ((rand_n3 == 0) || (rand_n3 == 1) || (rand_n3 == 2) || (rand_n3 == 3)) { // 서
                    p[8]->locate(scene1, puzzle[8].centerX - psize, puzzle[8].centerY);
                    p[1]->locate(scene1, puzzle[1].centerX + psize, puzzle[1].centerY);
                    puzzle[8].centerX -= psize;
                    puzzle[1].centerX += psize;
                    if ((rand_n4 == 0) || (rand_n4 == 1)) { // 서
                        p[8]->locate(scene1, puzzle[8].centerX - psize, puzzle[8].centerY);
                        p[0]->locate(scene1, puzzle[0].centerX + psize, puzzle[0].centerY);
                        puzzle[8].centerX -= psize;
                        puzzle[0].centerX += psize;
                        if ((rand_n5 == 0) || (rand_n5 == 1)) { // 남
                            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - psize);
                            p[3]->locate(scene1, puzzle[3].centerX, puzzle[3].centerY + psize);
                            puzzle[8].centerY -= psize;
                            puzzle[3].centerY += psize;
                        }
                    }
                    else if (rand_n4 == 2) { // 남
                        p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - psize);
                        p[4]->locate(scene1, puzzle[4].centerX, puzzle[4].centerY + psize);
                        puzzle[8].centerY -= psize;
                        puzzle[4].centerY += psize;
                    }
                }
            }
            else if (rand_n2 == 1) { // 서
                p[8]->locate(scene1, puzzle[8].centerX - psize, puzzle[8].centerY);
                p[4]->locate(scene1, puzzle[4].centerX + psize, puzzle[4].centerY);
                puzzle[8].centerX -= psize;
                puzzle[4].centerX += psize;
                if (rand_n3 == 0) { // 북
                    p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + psize);
                    p[1]->locate(scene1, puzzle[1].centerX, puzzle[1].centerY - psize);
                    puzzle[8].centerY += psize;
                    puzzle[1].centerY -= psize;
                    if ((rand_n4 == 0) || (rand_n4 == 1) || (rand_n4 == 2)) { // 남
                        p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - psize);
                        p[3]->locate(scene1, puzzle[3].centerX, puzzle[3].centerY + psize);
                        puzzle[8].centerY -= psize;
                        puzzle[3].centerY += psize;
                    }
                }
                else if ((rand_n3 == 1) || (rand_n3 == 3)) { // 서
                    p[8]->locate(scene1, puzzle[8].centerX - psize, puzzle[8].centerY);
                    p[3]->locate(scene1, puzzle[3].centerX + psize, puzzle[3].centerY);
                    puzzle[8].centerX -= psize;
                    puzzle[3].centerX += psize;
                    if ((rand_n4 == 0) || (rand_n4 == 1)) { // 남
                        p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - psize);
                        p[6]->locate(scene1, puzzle[6].centerX, puzzle[6].centerY + psize);
                        puzzle[8].centerY -= psize;
                        puzzle[6].centerY += psize;
                    }
                    else if (rand_n4 == 2) { // 북
                        p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + psize);
                        p[0]->locate(scene1, puzzle[0].centerX, puzzle[0].centerY - psize);
                        puzzle[8].centerY += psize;
                        puzzle[0].centerY -= psize;
                    }
                }
                else if (rand_n3 == 2) { // 남
                    p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - psize);
                    p[7]->locate(scene1, puzzle[7].centerX, puzzle[7].centerY + psize);
                    puzzle[8].centerY -= psize;
                    puzzle[7].centerY += psize;
                    if ((rand_n4 == 0) || (rand_n4 == 1) || (rand_n4 == 2)) { // 서
                        p[8]->locate(scene1, puzzle[8].centerX - psize, puzzle[8].centerY);
                        p[6]->locate(scene1, puzzle[6].centerX + psize, puzzle[6].centerY);
                        puzzle[8].centerX -= psize;
                        puzzle[6].centerX += psize;
                    }
                }
            }
        }
        else if (rand_n1 == 1) { // 서
            p[8]->locate(scene1, puzzle[8].centerX - psize, puzzle[8].centerY);
            p[7]->locate(scene1, puzzle[7].centerX + psize, puzzle[7].centerY);
            puzzle[8].centerX -= psize;
            puzzle[7].centerX += psize;
            if (rand_n2 == 0) { // 북
                p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + psize);
                p[4]->locate(scene1, puzzle[4].centerX, puzzle[4].centerY - psize);
                puzzle[8].centerY += psize;
                puzzle[4].centerY -= psize;
                if (rand_n3 == 0) { // 북
                    p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + psize);
                    p[1]->locate(scene1, puzzle[1].centerX, puzzle[1].centerY - psize);
                    puzzle[8].centerY += psize;
                    puzzle[1].centerY -= psize;
                    if ((rand_n4 == 0) || (rand_n4 == 1) || (rand_n4 == 2)) {
                        p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + psize);
                        p[0]->locate(scene1, puzzle[0].centerX, puzzle[0].centerY - psize);
                        puzzle[8].centerY += psize;
                        puzzle[0].centerY -= psize;
                    }

                }
                else if ((rand_n3 == 1) || (rand_n3 == 3)) { // 서
                    p[8]->locate(scene1, puzzle[8].centerX - psize, puzzle[8].centerY);
                    p[3]->locate(scene1, puzzle[3].centerX + psize, puzzle[3].centerY);
                    puzzle[8].centerX -= psize;
                    puzzle[3].centerX += psize;
                }
                else if (rand_n3 == 2) { // 동
                    p[8]->locate(scene1, puzzle[8].centerX + psize, puzzle[8].centerY);
                    p[5]->locate(scene1, puzzle[5].centerX - psize, puzzle[5].centerY);
                    puzzle[8].centerX += psize;
                    puzzle[5].centerX -= psize;
                }
            }
            else if (rand_n2 == 1) { // 서
                p[8]->locate(scene1, puzzle[8].centerX - psize, puzzle[8].centerY);
                p[6]->locate(scene1, puzzle[6].centerX + psize, puzzle[6].centerY);
                puzzle[8].centerX -= psize;
                puzzle[6].centerX += psize;
                if ((rand_n3 == 0) || (rand_n3 == 1) || (rand_n3 == 2) || (rand_n3 == 3)) { // 북
                    p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + psize);
                    p[3]->locate(scene1, puzzle[3].centerX, puzzle[3].centerY - psize);
                    puzzle[8].centerY += psize;
                    puzzle[3].centerY -= psize;
                }
            }
        }

        end = 1;
        return true;
        });


    p[0]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if ((puzzle[0].centerX == puzzle[8].centerX - 193) && (puzzle[0].centerY == puzzle[8].centerY)) {
            p[0]->locate(scene1, puzzle[0].centerX + 193, puzzle[0].centerY);
            p[8]->locate(scene1, puzzle[8].centerX - 193, puzzle[8].centerY);
            puzzle[8].centerX -= 193;
            puzzle[0].centerX += 193;
        }
        else if ((puzzle[0].centerX == puzzle[8].centerX + 193) && (puzzle[0].centerY == puzzle[8].centerY)) {
            p[0]->locate(scene1, puzzle[0].centerX - 193, puzzle[0].centerY);
            p[8]->locate(scene1, puzzle[8].centerX + 193, puzzle[8].centerY);
            puzzle[8].centerX += 193;
            puzzle[0].centerX -= 193;
        }
        else if ((puzzle[0].centerY == puzzle[8].centerY + 193) && (puzzle[0].centerX == puzzle[8].centerX)) {
            p[0]->locate(scene1, puzzle[0].centerX, puzzle[0].centerY - 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + 193);
            puzzle[8].centerY += 193;
            puzzle[0].centerY -= 193;
        }
        else if ((puzzle[0].centerY == puzzle[8].centerY - 193) && (puzzle[0].centerX == puzzle[8].centerX)) {
            p[0]->locate(scene1, puzzle[0].centerX, puzzle[0].centerY + 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - 193);
            puzzle[8].centerY -= 193;
            puzzle[0].centerY += 193;
        }
        if (puzzle[0].centerX == x3 && puzzle[0].centerY == y3 &&
            puzzle[1].centerX == x2 && puzzle[1].centerY == y3 &&
            puzzle[2].centerX == x1 && puzzle[2].centerY == y3 &&
            puzzle[3].centerX == x3 && puzzle[3].centerY == y2 &&
            puzzle[4].centerX == x2 && puzzle[4].centerY == y2 &&
            puzzle[5].centerX == x1 && puzzle[5].centerY == y2 &&
            puzzle[6].centerX == x3 && puzzle[6].centerY == y1 &&
            puzzle[7].centerX == x2 && puzzle[7].centerY == y1 &&
            puzzle[8].centerX == x1 && puzzle[8].centerY == y1 &&
            end == 1) {
            showMessage("퍼즐맞추기 성공");
            timer1->stop();
        }
        return true;
        });

    p[1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if ((puzzle[1].centerX == puzzle[8].centerX - 193) && (puzzle[1].centerY == puzzle[8].centerY)) {
            p[1]->locate(scene1, puzzle[1].centerX + 193, puzzle[1].centerY);
            p[8]->locate(scene1, puzzle[8].centerX - 193, puzzle[8].centerY);
            puzzle[8].centerX -= 193;
            puzzle[1].centerX += 193;
        }
        else if ((puzzle[1].centerX == puzzle[8].centerX + 193) && (puzzle[1].centerY == puzzle[8].centerY)) {
            p[1]->locate(scene1, puzzle[1].centerX - 193, puzzle[1].centerY);
            p[8]->locate(scene1, puzzle[8].centerX + 193, puzzle[8].centerY);
            puzzle[8].centerX += 193;
            puzzle[1].centerX -= 193;
        }
        else if ((puzzle[1].centerY == puzzle[8].centerY + 193) && (puzzle[1].centerX == puzzle[8].centerX)) {
            p[1]->locate(scene1, puzzle[1].centerX, puzzle[1].centerY - 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + 193);
            puzzle[8].centerY += 193;
            puzzle[1].centerY -= 193;
        }
        else if ((puzzle[1].centerY == puzzle[8].centerY - 193) && (puzzle[1].centerX == puzzle[8].centerX)) {
            p[1]->locate(scene1, puzzle[1].centerX, puzzle[1].centerY + 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - 193);
            puzzle[8].centerY -= 193;
            puzzle[1].centerY += 193;
        }
        if (puzzle[0].centerX == x3 && puzzle[0].centerY == y3 &&
            puzzle[1].centerX == x2 && puzzle[1].centerY == y3 &&
            puzzle[2].centerX == x1 && puzzle[2].centerY == y3 &&
            puzzle[3].centerX == x3 && puzzle[3].centerY == y2 &&
            puzzle[4].centerX == x2 && puzzle[4].centerY == y2 &&
            puzzle[5].centerX == x1 && puzzle[5].centerY == y2 &&
            puzzle[6].centerX == x3 && puzzle[6].centerY == y1 &&
            puzzle[7].centerX == x2 && puzzle[7].centerY == y1 &&
            puzzle[8].centerX == x1 && puzzle[8].centerY == y1 &&
            end == 1) {
            showMessage("퍼즐 맞추기 성공");
            timer1->stop();
        }
        return true;
        });

    p[2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if ((puzzle[2].centerX == puzzle[8].centerX - 193) && (puzzle[2].centerY == puzzle[8].centerY)) {
            p[2]->locate(scene1, puzzle[2].centerX + 193, puzzle[2].centerY);
            p[8]->locate(scene1, puzzle[8].centerX - 193, puzzle[8].centerY);
            puzzle[8].centerX -= 193;
            puzzle[2].centerX += 193;
        }
        else if ((puzzle[2].centerX == puzzle[8].centerX + 193) && (puzzle[2].centerY == puzzle[8].centerY)) {
            p[2]->locate(scene1, puzzle[2].centerX - 193, puzzle[2].centerY);
            p[8]->locate(scene1, puzzle[8].centerX + 193, puzzle[8].centerY);
            puzzle[8].centerX += 193;
            puzzle[2].centerX -= 193;
        }
        else if ((puzzle[2].centerY == puzzle[8].centerY + 193) && (puzzle[2].centerX == puzzle[8].centerX)) {
            p[2]->locate(scene1, puzzle[2].centerX, puzzle[2].centerY - 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + 193);
            puzzle[8].centerY += 193;
            puzzle[2].centerY -= 193;
        }
        else if ((puzzle[2].centerY == puzzle[8].centerY - 193) && (puzzle[2].centerX == puzzle[8].centerX)) {
            p[2]->locate(scene1, puzzle[2].centerX, puzzle[2].centerY + 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - 193);
            puzzle[8].centerY -= 193;
            puzzle[2].centerY += 193;
        }
        if (puzzle[0].centerX == x3 && puzzle[0].centerY == y3 &&
            puzzle[1].centerX == x2 && puzzle[1].centerY == y3 &&
            puzzle[2].centerX == x1 && puzzle[2].centerY == y3 &&
            puzzle[3].centerX == x3 && puzzle[3].centerY == y2 &&
            puzzle[4].centerX == x2 && puzzle[4].centerY == y2 &&
            puzzle[5].centerX == x1 && puzzle[5].centerY == y2 &&
            puzzle[6].centerX == x3 && puzzle[6].centerY == y1 &&
            puzzle[7].centerX == x2 && puzzle[7].centerY == y1 &&
            puzzle[8].centerX == x1 && puzzle[8].centerY == y1 &&
            end == 1) {
            showMessage("퍼즐 맞추기 성공");
            timer1->stop();
        }
        return true;
        });

    p[3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if ((puzzle[3].centerX == puzzle[8].centerX - 193) && (puzzle[3].centerY == puzzle[8].centerY)) {
            p[3]->locate(scene1, puzzle[3].centerX + 193, puzzle[3].centerY);
            p[8]->locate(scene1, puzzle[8].centerX - 193, puzzle[8].centerY);
            puzzle[8].centerX -= 193;
            puzzle[3].centerX += 193;
        }
        else if ((puzzle[3].centerX == puzzle[8].centerX + 193) && (puzzle[3].centerY == puzzle[8].centerY)) {
            p[3]->locate(scene1, puzzle[3].centerX - 193, puzzle[3].centerY);
            p[8]->locate(scene1, puzzle[8].centerX + 193, puzzle[8].centerY);
            puzzle[8].centerX += 193;
            puzzle[3].centerX -= 193;
        }
        else if ((puzzle[3].centerY == puzzle[8].centerY + 193) && (puzzle[3].centerX == puzzle[8].centerX)) {
            p[3]->locate(scene1, puzzle[3].centerX, puzzle[3].centerY - 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + 193);
            puzzle[8].centerY += 193;
            puzzle[3].centerY -= 193;
        }
        else if ((puzzle[3].centerY == puzzle[8].centerY - 193) && (puzzle[3].centerX == puzzle[8].centerX)) {
            p[3]->locate(scene1, puzzle[3].centerX, puzzle[3].centerY + 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - 193);
            puzzle[8].centerY -= 193;
            puzzle[3].centerY += 193;
        }
        if (puzzle[0].centerX == x3 && puzzle[0].centerY == y3 &&
            puzzle[1].centerX == x2 && puzzle[1].centerY == y3 &&
            puzzle[2].centerX == x1 && puzzle[2].centerY == y3 &&
            puzzle[3].centerX == x3 && puzzle[3].centerY == y2 &&
            puzzle[4].centerX == x2 && puzzle[4].centerY == y2 &&
            puzzle[5].centerX == x1 && puzzle[5].centerY == y2 &&
            puzzle[6].centerX == x3 && puzzle[6].centerY == y1 &&
            puzzle[7].centerX == x2 && puzzle[7].centerY == y1 &&
            puzzle[8].centerX == x1 && puzzle[8].centerY == y1 &&
            end == 1) {
            showMessage("퍼즐 맞추기 성공");
            timer1->stop();
        }
        return true;
        });

    p[4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if ((puzzle[4].centerX == puzzle[8].centerX - 193) && (puzzle[4].centerY == puzzle[8].centerY)) {
            p[4]->locate(scene1, puzzle[4].centerX + 193, puzzle[4].centerY);
            p[8]->locate(scene1, puzzle[8].centerX - 193, puzzle[8].centerY);
            puzzle[8].centerX -= 193;
            puzzle[4].centerX += 193;
        }
        else if ((puzzle[4].centerX == puzzle[8].centerX + 193) && (puzzle[4].centerY == puzzle[8].centerY)) {
            p[4]->locate(scene1, puzzle[4].centerX - 193, puzzle[4].centerY);
            p[8]->locate(scene1, puzzle[8].centerX + 193, puzzle[8].centerY);
            puzzle[8].centerX += 193;
            puzzle[4].centerX -= 193;
        }
        else if ((puzzle[4].centerY == puzzle[8].centerY + 193) && (puzzle[4].centerX == puzzle[8].centerX)) {
            p[4]->locate(scene1, puzzle[4].centerX, puzzle[4].centerY - 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + 193);
            puzzle[8].centerY += 193;
            puzzle[4].centerY -= 193;
        }
        else if ((puzzle[4].centerY == puzzle[8].centerY - 193) && (puzzle[4].centerX == puzzle[8].centerX)) {
            p[4]->locate(scene1, puzzle[4].centerX, puzzle[4].centerY + 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - 193);
            puzzle[8].centerY -= 193;
            puzzle[4].centerY += 193;
        }
        if (puzzle[0].centerX == x3 && puzzle[0].centerY == y3 &&
            puzzle[1].centerX == x2 && puzzle[1].centerY == y3 &&
            puzzle[2].centerX == x1 && puzzle[2].centerY == y3 &&
            puzzle[3].centerX == x3 && puzzle[3].centerY == y2 &&
            puzzle[4].centerX == x2 && puzzle[4].centerY == y2 &&
            puzzle[5].centerX == x1 && puzzle[5].centerY == y2 &&
            puzzle[6].centerX == x3 && puzzle[6].centerY == y1 &&
            puzzle[7].centerX == x2 && puzzle[7].centerY == y1 &&
            puzzle[8].centerX == x1 && puzzle[8].centerY == y1 &&
            end == 1) {
            showMessage("퍼즐 맞추기 성공");
            timer1->stop();
        }
        return true;
        });

    p[5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if ((puzzle[5].centerX == puzzle[8].centerX - 193) && (puzzle[5].centerY == puzzle[8].centerY)) {
            p[5]->locate(scene1, puzzle[5].centerX + 193, puzzle[5].centerY);
            p[8]->locate(scene1, puzzle[8].centerX - 193, puzzle[8].centerY);
            puzzle[8].centerX -= 193;
            puzzle[5].centerX += 193;
        }
        else if ((puzzle[5].centerX == puzzle[8].centerX + 193) && (puzzle[5].centerY == puzzle[8].centerY)) {
            p[5]->locate(scene1, puzzle[5].centerX - 193, puzzle[5].centerY);
            p[8]->locate(scene1, puzzle[8].centerX + 193, puzzle[8].centerY);
            puzzle[8].centerX += 193;
            puzzle[5].centerX -= 193;
        }
        else if ((puzzle[5].centerY == puzzle[8].centerY + 193) && (puzzle[5].centerX == puzzle[8].centerX)) {
            p[5]->locate(scene1, puzzle[5].centerX, puzzle[5].centerY - 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + 193);
            puzzle[8].centerY += 193;
            puzzle[5].centerY -= 193;
        }
        else if ((puzzle[5].centerY == puzzle[8].centerY - 193) && (puzzle[5].centerX == puzzle[8].centerX)) {
            p[5]->locate(scene1, puzzle[5].centerX, puzzle[5].centerY + 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - 193);
            puzzle[8].centerY -= 193;
            puzzle[5].centerY += 193;
        }
        if (puzzle[0].centerX == x3 && puzzle[0].centerY == y3 &&
            puzzle[1].centerX == x2 && puzzle[1].centerY == y3 &&
            puzzle[2].centerX == x1 && puzzle[2].centerY == y3 &&
            puzzle[3].centerX == x3 && puzzle[3].centerY == y2 &&
            puzzle[4].centerX == x2 && puzzle[4].centerY == y2 &&
            puzzle[5].centerX == x1 && puzzle[5].centerY == y2 &&
            puzzle[6].centerX == x3 && puzzle[6].centerY == y1 &&
            puzzle[7].centerX == x2 && puzzle[7].centerY == y1 &&
            puzzle[8].centerX == x1 && puzzle[8].centerY == y1 &&
            end == 1) {
            showMessage("퍼즐 맞추기 성공");
            timer1->stop();
        }
        return true;
        });

    p[6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if ((puzzle[6].centerX == puzzle[8].centerX - 193) && (puzzle[6].centerY == puzzle[8].centerY)) {
            p[6]->locate(scene1, puzzle[6].centerX + 193, puzzle[6].centerY);
            p[8]->locate(scene1, puzzle[8].centerX - 193, puzzle[8].centerY);
            puzzle[8].centerX -= 193;
            puzzle[6].centerX += 193;
        }
        else if ((puzzle[6].centerX == puzzle[8].centerX + 193) && (puzzle[6].centerY == puzzle[8].centerY)) {
            p[6]->locate(scene1, puzzle[6].centerX - 193, puzzle[6].centerY);
            p[8]->locate(scene1, puzzle[8].centerX + 193, puzzle[8].centerY);
            puzzle[8].centerX += 193;
            puzzle[6].centerX -= 193;
        }
        else if ((puzzle[6].centerY == puzzle[8].centerY + 193) && (puzzle[6].centerX == puzzle[8].centerX)) {
            p[6]->locate(scene1, puzzle[6].centerX, puzzle[6].centerY - 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + 193);
            puzzle[8].centerY += 193;
            puzzle[6].centerY -= 193;
        }
        else if ((puzzle[6].centerY == puzzle[8].centerY - 193) && (puzzle[6].centerX == puzzle[8].centerX)) {
            p[6]->locate(scene1, puzzle[6].centerX, puzzle[6].centerY + 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - 193);
            puzzle[8].centerY -= 193;
            puzzle[6].centerY += 193;
        }
        if (puzzle[0].centerX == x3 && puzzle[0].centerY == y3 &&
            puzzle[1].centerX == x2 && puzzle[1].centerY == y3 &&
            puzzle[2].centerX == x1 && puzzle[2].centerY == y3 &&
            puzzle[3].centerX == x3 && puzzle[3].centerY == y2 &&
            puzzle[4].centerX == x2 && puzzle[4].centerY == y2 &&
            puzzle[5].centerX == x1 && puzzle[5].centerY == y2 &&
            puzzle[6].centerX == x3 && puzzle[6].centerY == y1 &&
            puzzle[7].centerX == x2 && puzzle[7].centerY == y1 &&
            puzzle[8].centerX == x1 && puzzle[8].centerY == y1 &&
            end == 1) {
            showMessage("퍼즐 맞추기 성공");
            timer1->stop();
        }
        return true;
        });

    p[7]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if ((puzzle[7].centerX == puzzle[8].centerX - 193) && (puzzle[7].centerY == puzzle[8].centerY)) {
            p[7]->locate(scene1, puzzle[7].centerX + 193, puzzle[7].centerY);
            p[8]->locate(scene1, puzzle[8].centerX - 193, puzzle[8].centerY);
            puzzle[8].centerX -= 193;
            puzzle[7].centerX += 193;
        }
        else if ((puzzle[7].centerX == puzzle[8].centerX + 193) && (puzzle[7].centerY == puzzle[8].centerY)) {
            p[7]->locate(scene1, puzzle[7].centerX - 193, puzzle[7].centerY);
            p[8]->locate(scene1, puzzle[8].centerX + 193, puzzle[8].centerY);
            puzzle[8].centerX += 193;
            puzzle[7].centerX -= 193;
        }
        else if ((puzzle[7].centerY == puzzle[8].centerY + 193) && (puzzle[7].centerX == puzzle[8].centerX)) {
            p[7]->locate(scene1, puzzle[7].centerX, puzzle[7].centerY - 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY + 193);
            puzzle[8].centerY += 193;
            puzzle[7].centerY -= 193;
        }
        else if ((puzzle[7].centerY == puzzle[8].centerY - 193) && (puzzle[7].centerX == puzzle[8].centerX)) {
            p[7]->locate(scene1, puzzle[7].centerX, puzzle[7].centerY + 193);
            p[8]->locate(scene1, puzzle[8].centerX, puzzle[8].centerY - 193);
            puzzle[8].centerY -= 193;
            puzzle[7].centerY += 193;
        }
        if (puzzle[0].centerX == x3 && puzzle[0].centerY == y3 &&
            puzzle[1].centerX == x2 && puzzle[1].centerY == y3 &&
            puzzle[2].centerX == x1 && puzzle[2].centerY == y3 &&
            puzzle[3].centerX == x3 && puzzle[3].centerY == y2 &&
            puzzle[4].centerX == x2 && puzzle[4].centerY == y2 &&
            puzzle[5].centerX == x1 && puzzle[5].centerY == y2 &&
            puzzle[6].centerX == x3 && puzzle[6].centerY == y1 &&
            puzzle[7].centerX == x2 && puzzle[7].centerY == y1 &&
            puzzle[8].centerX == x1 && puzzle[8].centerY == y1 &&
            end == 1) {
            showMessage("퍼즐 맞추기 성공");
            timer1->stop();
        }
        return true;
        });




    startGame(scene1);
}

