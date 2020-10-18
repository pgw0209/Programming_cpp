#include <bangtal>

using namespace bangtal;

auto Message() {
	showMessage("수수께끼를 맞히면 선물로 뭘 줄까? 영어로 대답해봐");
}
auto Message2() {
	showMessage("총 몇 개의 선물을 모아야 될까?");
}
auto Message3() {
	showMessage("이 게임의 주인공을 영어로 말하면?");
}
auto Message4() {
	showMessage("피해야 하는 동물의 수는?");
}
auto Message5() {
	showMessage("피해야 하는 동물을 영어로 말하면?");
}



int main() {
	//setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	// 장면을 생성한다.
	auto scene1 = Scene::create("바다", "images/배경1.png");
	auto scene2 = Scene::create("바다", "images/배경2.png");
	auto scene3 = Scene::create("실패", "images/gameover.png");
	auto scene4 = Scene::create("클리어", "images/gameclear.png");


	ObjectPtr shark[4];
	

	auto m1 = Sound::create("audios/m1.mp3");
	auto clear = Sound::create("audios/clear.mp3");
	clear->play();

	auto diverX = 0;
	auto diverY = 0;

	auto diver = Object::create("images/diver.png", scene1, diverX, diverY);
	auto diver2 = Object::create("images/diver.png", scene2, diverX, diverY, false);



	auto leftButton = Object::create("images/left.png", scene1, 510, 25, false);
	auto rightButton = Object::create("images/right.png", scene1, 690, 25, false);
	auto topButton = Object::create("images/top.png", scene1, 600, 113, false);
	auto bottomButton = Object::create("images/bottom.png", scene1, 600, 30, false);

	auto leftButton2 = Object::create("images/left.png", scene2, 510, 25);
	auto rightButton2 = Object::create("images/right.png", scene2, 690, 25);
	auto topButton2 = Object::create("images/top.png", scene2, 600, 113);
	auto bottomButton2 = Object::create("images/bottom.png", scene2, 600, 30);

	auto life = Object::create("images/life3.png", scene1, 0, 650);
	auto life2 = Object::create("images/life3.png", scene2, 0, 650);


	auto turtleX = 150;
	auto turtleY = 150;
	auto sharkX = 115;
	auto sharkY = 115;

	auto x1 = 300, y1 = 300, y2 = 350, x2 = 900;
	auto x3 = 250, y3 = 30;
	auto s1 = 1200, s2 = 150;
	auto s3 = 30, s4 = 500;

	auto pearl = Object::create("images/pearl.png", scene1, x1, y1, false);
	auto pearl2 = Object::create("images/pearl.png", scene1, x2, y2, false);
	auto pearl3 = Object::create("images/pearl.png", scene2, x1, y1, false);
	auto pearl4 = Object::create("images/pearl.png", scene2, x2, y2, false);
	auto pearl5 = Object::create("images/pearl.png", scene2, x3, y3, false);
	auto pnum = 0;

	auto turtle = Object::create("images/turtle.png", scene1, x1, y1);
	auto turtle2 = Object::create("images/turtle.png", scene1, x2, y2);
	auto turtle3 = Object::create("images/turtle.png", scene2, x1, y1);
	auto turtle4 = Object::create("images/turtle.png", scene2, x2, y2);
	auto turtle5 = Object::create("images/turtle.png", scene2, x3, y3);



	shark[0] = Object::create("Images/상어1.png", scene1, s1, s2);
	shark[0]->setScale(0.25f);
	shark[1] = Object::create("Images/상어1.png", scene1, s3, s4);
	shark[1]->setScale(0.25f);
	shark[2] = Object::create("Images/상어1.png", scene1, s1, s2);
	shark[2]->setScale(0.25f);
	shark[3] = Object::create("Images/상어1.png", scene1, s3, s4);
	shark[3]->setScale(0.25f);

	auto story = Object::create("images/story.png", scene1, 0, 0);
	auto startButton = Object::create("images/start.png", scene1, 590, 70);
	auto endButton = Object::create("images/end.png", scene1, 590, 20);
	auto restartButton = Object::create("images/restart.png", scene3, 590, 70);

	life->setScale(0.6f);
	life2->setScale(0.6f);
	restartButton->setScale(1.2f);

	auto count = 0;
	auto blank = 1;
	auto a = 0;
	auto b = 0;



	auto heart = 3; 
	auto timer = Timer::create(0.01f); 
	timer->setOnTimerCallback([&](TimerPtr t)->bool {
		int j = 0;

		if ((s1> 0)&&(s1<1270)&&(b==0)) {
			s1 += 10;
			shark[j]->locate(scene1, s1, s2);
			shark[j]->setImage("Images/상어1.png");
			if (((diverX > s1 - sharkX) && (diverX < s1 + sharkX)) && ((diverY > s2 - sharkY) && (diverY < s2 + sharkY))) {
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life1.png");
				}else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s1 > 1200) {
				b = 1;
			}

		}
		else if((b==1)){
			b = 1;
			s1 -= 5;
			shark[j]->setImage("Images/상어.png");
			shark[j]->locate(scene1, s1, s2);
			if (((diverX > s1 - sharkX) && (diverX < s1 + sharkX)) && ((diverY > s2 - sharkY) && (diverY < s2 + sharkY))) {
				s1 = 1100;
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s1 < 5) {
				b = 0;
			}
		}
		else {
			s1 += 5;
			shark[j]->setImage("Images/상어1.png");
			shark[j]->locate(scene1, s1, s2);
			if (((diverX > s1 - sharkX) && (diverX < s1 + sharkX)) && ((diverY > s2 - sharkY) && (diverY < s2 + sharkY))) {
				s1 = 1100;
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s1 > 1200) {
				b = 1;
			}
		}
		

		if ((s3 > 0) && (s3 < 1270) && (a == 0)) {
			s3 += 5;
			shark[1]->locate(scene1, s3, s4);
			shark[1]->setImage("Images/상어1.png");
			if (((diverX > s3 - sharkX) && (diverX < s3 + sharkX)) && ((diverY > s4 - sharkY) && (diverY < s4 + sharkY))) {
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s3 > 1200) {
				a = 1;
			}

		}
		else if ((a == 1)) {
			a = 1;
			s3 -= 5;
			shark[1]->setImage("Images/상어.png");
			shark[1]->locate(scene1, s3, s4);
			if (((diverX > s3 - sharkX) && (diverX < s3 + sharkX)) && ((diverY > s4 - sharkY) && (diverY < s4 + sharkY))) {
				s3 = 1100;
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s3 < 5) {
				a = 0;
			}
		}
		else {
			s3 += 5;
			shark[1]->setImage("Images/상어1.png");
			shark[1]->locate(scene1, s3, s4);
			if (((diverX > s3 - sharkX) && (diverX < s3 + sharkX)) && ((diverY > s4 - sharkY) && (diverY < s4 + sharkY))) {
				s3 = 1100;
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s3 > 1200) {
				a = 1;
			}
		}


		if ((s1 > 0) && (s1 < 1270) && (b == 0)) {
			s1 += 5;
			shark[2]->locate(scene2, s1, s2);
			shark[2]->setImage("Images/상어1.png");
			if (((diverX > s1 - sharkX) && (diverX < s1 + sharkX)) && ((diverY > s2 - sharkY) && (diverY < s2 + sharkY))) {
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life1.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s1 > 1200) {
				b = 1;
			}

		}
		else if ((b == 1)) {
			b = 1;
			s1 -= 5;
			shark[2]->setImage("Images/상어.png");
			shark[2]->locate(scene2, s1, s2);
			if (((diverX > s1 - sharkX) && (diverX < s1 + sharkX)) && ((diverY > s2 - sharkY) && (diverY < s2 + sharkY))) {
				s1 = 1100;
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s1 < 5) {
				b = 0;
			}
		}
		else {
			s1 += 5;
			shark[2]->setImage("Images/상어1.png");
			shark[2]->locate(scene2, s1, s2);
			if (((diverX > s1 - sharkX) && (diverX < s1 + sharkX)) && ((diverY > s2 - sharkY) && (diverY < s2 + sharkY))) {
				s1 = 1100;
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s1 > 1200) {
				b = 1;
			}
		}

		if ((s3 > 0) && (s3 < 1270) && (a == 0)) {
			s3 += 5;
			shark[3]->locate(scene2, s3, s4);
			shark[3]->setImage("Images/상어1.png");
			if (((diverX > s3 - sharkX) && (diverX < s3 + sharkX)) && ((diverY > s4 - sharkY) && (diverY < s4 + sharkY))) {
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s3 > 1200) {
				a = 1;
			}

		}
		else if ((a == 1)) {
			a = 1;
			s3 -= 5;
			shark[3]->setImage("Images/상어.png");
			shark[3]->locate(scene2, s3, s4);
			if (((diverX > s3 - sharkX) && (diverX < s3 + sharkX)) && ((diverY > s4 - sharkY) && (diverY < s4 + sharkY))) {
				s3 = 1100;
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s3 < 5) {
				a = 0;
			}
		}
		else {
			s3 += 5;
			shark[3]->setImage("Images/상어1.png");
			shark[3]->locate(scene2, s3, s4);
			if (((diverX > s3 - sharkX) && (diverX < s3 + sharkX)) && ((diverY > s4 - sharkY) && (diverY < s4 + sharkY))) {
				s3 = 1100;
				if (heart == 3) {
					heart = 2;
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 2) {
					heart = 1;
					life->setImage("Images/life1.png");
					life2->setImage("Images/life2.png");
				}
				else if (heart == 1) {
					heart = 0;
					scene3->enter();
				}
			}
			if (s3 > 1200) {
				a = 1;
			}
		}
		count++;
		if (count < 3000000) {
			t->set(0.01f);
			t->start();
		}
		return true;
		});


	restartButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		timer->start();
		startButton->hide();
		endButton->hide();
		heart = 3;
		diverX = 0;
		diverY = 0;
		diver->locate(scene1, diverX, diverY);
		pearl->locate(scene1, x1, y1);
		pearl2->locate(scene1, x2, y2);

		diver->show();
		diver2->show();
		diver2->locate(scene2, diverX, diverY);
		life->setImage("Images/life3.png");
		life2->setImage("Images/life3.png");

		leftButton->show();
		rightButton->show();
		topButton->show();
		bottomButton->show();


		diverX = 0;
		diverY = 0;
		diver->locate(scene1, diverX, diverY);
		diver2->locate(scene2, diverX, diverY);

		return true;
		});


	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		story->hide();
		timer->start();
		startButton->hide();
		endButton->hide();
		
		leftButton->show();
		rightButton->show();
		topButton->show();
		bottomButton->show();


		diverX = 0;
		diver->locate(scene1, diverX, diverY);
		return true;
		});

	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();
		return true;
		});


	///////////////////////////////////////////////////////////////////////


	leftButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		diverX -= 25;
		diver->locate(scene1, diverX, diverY);
		diver->setImage("Images/diver2.png");
		if (((diverX > x1 - turtleX) && (diverX < x1 + turtleX)) && ((diverY > y1 - turtleY) && (diverY < y1 + turtleY))) {
			Message();
			showKeypad("pearl", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle->hide();
				x1 = -500, y1 = -500;
				turtle->locate(scene1, x1, y1);
				pearl->show();
				pearl->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();

						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x2 - turtleX) && (diverX < x2 + turtleX)) && ((diverY > y2 - turtleY) && (diverY < y2 + turtleY))) {
			Message2();
			showKeypad("5", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle2->hide();
				x2 = -500, y2 = -500;
				turtle2->locate(scene1, x2, y2);
				pearl2->show();
				pearl2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl2->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		
		return true;
		});

	rightButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		diverX += 25;
		diver->locate(scene1, diverX, diverY);
		diver->setImage("Images/diver.png");
		if (((diverX > x1 - turtleX) && (diverX < x1 + turtleX)) && ((diverY > y1 - turtleY) && (diverY < y1 + turtleY))) {
			Message();
			showKeypad("pearl", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle->hide();
				x1 = -500, y1 = -500;
				turtle->locate(scene1, x1, y1);
				pearl->show();
				pearl->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();

						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x2 - turtleX) && (diverX < x2 + turtleX)) && ((diverY > y2 - turtleY) && (diverY < y2 + turtleY))) {
			Message2();
			showKeypad("5", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle2->hide();
				x2 = -500, y2 = -500;
				turtle2->locate(scene1, x2, y2);
				pearl2->show();
				pearl2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl2->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();

						clear->play();
					}
					return true;
					});
				return true;
				});
		}

		return true;
		});

	topButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		diverY += 25;
		diver->locate(scene1, diverX, diverY);

		if (diverY > 650) { // 화면 가로 길이
			scene2->enter();
			shark[0]->locate(scene1, -500, -500);
			shark[1]->locate(scene1, -500, -500);
			diver->hide();
			diver2->show();
			diverY = -50;
			diver2->locate(scene2, diverX, diverY);
		}

		if (((diverX > x1 - turtleX) && (diverX < x1 + turtleX)) && ((diverY > y1 - turtleY) && (diverY < y1 + turtleY))) {
			Message();
			showKeypad("pearl", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle->hide();
				x1 = -500, y1 = -500;
				turtle->locate(scene1, x1, y1);
				pearl->show();
				pearl->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();

						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x2 - turtleX) && (diverX < x2 + turtleX)) && ((diverY > y2 - turtleY) && (diverY < y2 + turtleY))) {
			Message2();
			showKeypad("5", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle2->hide();
				x2 = -500, y2 = -500;
				turtle2->locate(scene1, x2, y2);
				pearl2->show();
				pearl2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl2->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}

		
		return true;
		});




	bottomButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		diverY -= 25;
		diver->locate(scene1, diverX, diverY);

		if (((diverX > x1 - turtleX) && (diverX < x1 + turtleX)) && ((diverY > y1 - turtleY) && (diverY < y1 + turtleY))) {
			Message();
			showKeypad("pearl", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle->hide();
				x1 = -500, y1 = -500;
				turtle->locate(scene1, x1, y1);
				pearl->show();
				pearl->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x2 - turtleX) && (diverX < x2 + turtleX)) && ((diverY > y2 - turtleY) && (diverY < y2 + turtleY))) {
			Message2();
			showKeypad("5", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle2->hide();
				x2 = -500, y2 = -500;
				turtle2->locate(scene1, x2, y2);
				pearl2->show();
				pearl2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl2->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}

		return true;
		});

	///////////////////////////////////////////////////////////////////

	leftButton2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		diverX -= 25;
		diver2->locate(scene2, diverX, diverY);
		diver2->setImage("Images/diver2.png");
		if (((diverX > x1 - turtleX) && (diverX < x1 + turtleX)) && ((diverY > y1 - turtleY) && (diverY < y1 + turtleY))) {
			Message3();
			showKeypad("diver", turtle3);
			turtle3->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle3->hide();
				x1 = -500, y1 = -500;
				turtle3->locate(scene2, x1, y1);
				pearl3->show();
				pearl3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl3->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x2 - turtleX) && (diverX < x2 + turtleX)) && ((diverY > y2 - turtleY) && (diverY < y2 + turtleY))) {
			Message4();
			showKeypad("4", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle4->hide();
				x2 = -500, y2 = -500;
				turtle4->locate(scene2, x2, y2);
				pearl4->show();
				pearl4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl4->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x3 - turtleX) && (diverX < x3 + turtleX)) && ((diverY > y3 - turtleY) && (diverY < y3 + turtleY))) {
			Message5();
			showKeypad("shark", turtle5);
			turtle5->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle5->hide();
				x3 = -500, y3 = -500;
				turtle5->locate(scene2, x3, y3);
				pearl5->show();
				pearl5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl5->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}

		return true;
		});

	rightButton2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		diverX += 25;
		diver2->locate(scene2, diverX, diverY);
		diver2->setImage("Images/diver.png");
		if (((diverX > x1 - turtleX) && (diverX < x1 + turtleX)) && ((diverY > y1 - turtleY) && (diverY < y1 + turtleY))) {
			Message3();
			showKeypad("diver", turtle3);
			turtle3->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle3->hide();
				x1 = -500, y1 = -500;
				turtle3->locate(scene2, x1, y1);
				pearl3->show();
				pearl3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl3->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x2 - turtleX) && (diverX < x2 + turtleX)) && ((diverY > y2 - turtleY) && (diverY < y2 + turtleY))) {
			Message4();
			showKeypad("4", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle4->hide();
				x2 = -500, y2 = -500;
				turtle4->locate(scene2, x2, y2);
				pearl4->show();
				pearl4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl4->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x3 - turtleX) && (diverX < x3 + turtleX)) && ((diverY > y3 - turtleY) && (diverY < y3 + turtleY))) {
			Message5();
			showKeypad("shark", turtle5);
			turtle5->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle5->hide();
				x3 = -500, y3 = -500;
				turtle5->locate(scene2, x3, y3);
				pearl5->show();
				pearl5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl5->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		return true;
		});


	topButton2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		diverY += 25;
		diver2->locate(scene2, diverX, diverY);
		if (((diverX > x1 - turtleX) && (diverX < x1 + turtleX)) && ((diverY > y1 - turtleY) && (diverY < y1 + turtleY))) {
			Message3();
			showKeypad("diver", turtle3);
			turtle3->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle3->hide();
				x1 = -500, y1 = -500;
				turtle3->locate(scene2, x1, y1);
				pearl3->show();
				pearl3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl3->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x2 - turtleX) && (diverX < x2 + turtleX)) && ((diverY > y2 - turtleY) && (diverY < y2 + turtleY))) {
			Message4();
			showKeypad("4", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle4->hide();
				x2 = -500, y2 = -500;
				turtle4->locate(scene2, x2, y2);
				pearl4->show();
				pearl4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl4->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x3 - turtleX) && (diverX < x3 + turtleX)) && ((diverY > y3 - turtleY) && (diverY < y3 + turtleY))) {
			Message5();
			showKeypad("shark", turtle5);
			turtle5->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle5->hide();
				x3 = -500, y3 = -500;
				turtle5->locate(scene2, x3, y3);
				pearl5->show();
				pearl5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl5->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}

		return true;
		});

	bottomButton2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		diverY -= 25;
		diver2->locate(scene2, diverX, diverY);

		if (diverY < -70) { // 화면 가로 길이
			scene1->enter();
			diver->show();
			diverY = 650;
			diver->locate(scene1, diverX, diverY);
		}
		if (((diverX > x1 - turtleX) && (diverX < x1 + turtleX)) && ((diverY > y1 - turtleY) && (diverY < y1 + turtleY))) {
			Message3();
			showKeypad("diver", turtle3);
			turtle3->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle3->hide();
				x1 = -500, y1 = -500;
				turtle3->locate(scene2, x1, y1);
				pearl3->show();
				pearl3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl3->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x2 - turtleX) && (diverX < x2 + turtleX)) && ((diverY > y2 - turtleY) && (diverY < y2 + turtleY))) {
			Message4();
			showKeypad("4", turtle);
			turtle->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle4->hide();
				x2 = -500, y2 = -500;
				turtle4->locate(scene2, x2, y2);
				pearl4->show();
				pearl4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl4->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		if (((diverX > x3 - turtleX) && (diverX < x3 + turtleX)) && ((diverY > y3 - turtleY) && (diverY < y3 + turtleY))) {
			Message5();
			showKeypad("shark", turtle5);
			turtle5->setOnKeypadCallback([&](ObjectPtr object)->bool {
				turtle5->hide();
				x3 = -500, y3 = -500;
				turtle5->locate(scene2, x3, y3);
				pearl5->show();
				pearl5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
					pearl5->pick();
					pnum++;
					if (pnum == 5) {
						scene4->enter();
						clear->play();
					}
					return true;
					});
				return true;
				});
		}
		return true;
		});


	// 게임을 시작한다.
	startGame(scene1);

	return 0;
}

