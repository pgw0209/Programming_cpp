#include <bangtal>
#include "SpongeBob.h"

using namespace bangtal;



int isPlaying = 0;
float highScore = 0;

ScenePtr scene1, scene2, scene3, start1, over, scene4;
ObjectPtr bob1, bob2, plank[2], plank2[2], startb, overb, restart, overb1, restart1;
ObjectPtr bread, ch, let, patty, cafe, page;
ObjectPtr board, bread2, bread1, ch1, let1, patty1;
ObjectPtr bread3,  ch2, let2, patty2, recipe;

int bobX = 50, bobY = 150;
int plankY = 600;
int p1 = 850, p2 = 700;
int p3 = 300, p4 = 800;
int breadX = 500, chX = 900, letX = 400, pattyX = 800;
int pick1 = 0, pick2 = 0, pick3 = 0, pick4 = 0;

int burger = 0;


int sponge = 0; // 스폰지밥 상태
int enter1 = 0; // 배경 전환

void keyboardCallback(KeyCode x, KeyState) {
	auto laugh = Sound::create("Audios/웃음.mp3");;

	if (isPlaying == 1) {
		if (x == 82) { // 왼쪽
			bobX -= 50;
			if (bobX <= 0) {
				bobX = 0;
			}

			bob1->locate(scene1, bobX, bobY);
			bob2->locate(scene2, bobX, bobY);
			if (sponge == 0) {
				bob1->setImage("Images/bob4.png");
				bob2->setImage("Images/bob4.png");
				sponge = 1;
			}
			else {
				bob1->setImage("Images/bob3.png");
				bob2->setImage("Images/bob3.png");
				sponge = 0;
			}

		}
		else if (x == 83) { // 오른쪽
			bobX += 50;
			if (bobX >= 1200) {
				if (enter1 == 1) {
					bobX = 1200;
				}
				else {
					scene2->enter();
					enter1 = 1;
					bobX = 70;
				}
			}

			if (bobX >= 450 && pick1 == 0) {
				bread->pick();
				laugh->play();
				bread->hide();
				pick1 = 1;
			}
			if (bobX >= 850 && pick2 == 0) {
				ch->pick();
				laugh->play();
				ch->hide();
				pick2 = 1;
			}
			if (bobX >= 350 && pick3 == 0 && enter1 ==1) {
				let->pick();
				laugh->play();
				let->hide();
				pick3 = 1;
			}
			if (bobX >= 750 && pick4 == 0 && enter1 == 1) {
				patty->pick();
				laugh->play();
				patty->hide();
				pick4 = 1;
			}
			if (bobX >= 700 && enter1 == 1) {
				page->show();
			}
			bob1->locate(scene1, bobX, bobY);
			bob2->locate(scene2, bobX, bobY);
			if (sponge == 0) {
				bob1->setImage("Images/bob1.png");
				bob2->setImage("Images/bob1.png");
				sponge = 1;
			}
			else {
				bob1->setImage("Images/bob.png");
				bob2->setImage("Images/bob.png");
				sponge = 0;
			}
		}

	}

}



int main(void) {

	auto count = 0;

	setKeyboardCallback(keyboardCallback);

	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

	bobX = 70;
	
	auto bX = 150;
	auto pX = 100, pY = 150;

	scene1 = Scene::create("scene1", "images/scene1.jpg");
	scene2 = Scene::create("scene2", "images/scene2.jpg");
	scene3 = Scene::create("scene3", "images/주방.jpg");
	start1 = Scene::create("start", "images/시작.png");
	scene4 = Scene::create("성공", "images/성공.png");

	startb = Object::create("images/시작버튼.png", start1, 500, 25);

	over = Scene::create("gameover", "images/실패.png");
	overb = Object::create("images/끝.png", over, 1000, 30);
	restart = Object::create("images/재시작.png", over, 1000, 150);

	overb1 = Object::create("images/끝.png", scene4, 1000, 30);

	cafe = Object::create("images/집게리아.png", scene2, 800, bobY + 30);
	bob1 = Object::create("images/bob.png", scene1, bobX, bobY);
	bob2 = Object::create("images/bob.png", scene2, bobX, bobY);
	cafe->setScale(2.0f);

	bread = Object::create("images/빵.png", scene1, breadX, bobY);
	ch = Object::create("images/치즈.png", scene1, chX, bobY);
	let = Object::create("images/상추.png", scene2, letX, bobY);
	patty = Object::create("images/패티.png", scene2, pattyX, bobY);
	page = Object::create("images/안내.png", scene2, 1000, 400);
	page->hide();


	board = Object::create("images/doma.png", scene3, 300, 200);
	bread2 = Object::create("images/빵2.png", scene3, 480, 250);
	patty1 = Object::create("images/패티1.png", scene3, 480, 300);
	ch1 = Object::create("images/치즈1.png", scene3, 480, 310);
	let1 = Object::create("images/상추1.png", scene3, 480, 320);
	bread1 = Object::create("images/빵1.png", scene3, 480, 370);
	
	patty1->hide();
	ch1->hide();
	let1->hide();
	bread1->hide();
	bread2->hide();


	patty2 = Object::create("images/패티1.png", scene3, 120, 330);
	ch2 = Object::create("images/치즈1.png", scene3, 40, 250);
	let2 = Object::create("images/상추1.png", scene3, 1020, 330);
	bread3 = Object::create("images/빵1.png", scene3, 1100, 250);
	
	patty2->setScale(0.5f);
	ch2->setScale(0.5f);
	let2->setScale(0.5f);
	bread3->setScale(0.5f);

	recipe = Object::create("images/레시피.png", scene3, 20, 450);
	auto life = Object::create("images/life3.png", scene1, 0, 650);
	auto life2 = Object::create("images/life3.png", scene2, 0, 650);

	auto xx = Sound::create("Audios/쾅.mp3");
	auto xxx = Sound::create("Audios/화.mp3");
	auto oo = Sound::create("Audios/웃음.mp3");
	auto ooo = Sound::create("Audios/성공.mp3");

	auto clear = Sound::create("Audios/엔딩.mp3");
	auto stage2 = Sound::create("Audios/요리.mp3");
	auto start = Sound::create("Audios/시작.mp3");
	auto click = Sound::create("Audios/딸깍.mp3");
	auto end = Sound::create("Audios/실패.mp3");



	
	plank[0] = Object::create("Images/plank.png", scene1, p3, p1);
	plank[1] = Object::create("Images/plank.png", scene1, p4, p2);
	plank[0]->setScale(0.8f);
	plank[1]->setScale(0.8f);

	plank2[0] = Object::create("Images/plank.png", scene2, p3, p1);
	plank2[1] = Object::create("Images/plank.png", scene2, p4, p2);
	plank2[0]->setScale(0.8f);
	plank2[1]->setScale(0.8f);

	
	auto b = 0;
	auto heart = 3;
	auto timer = Timer::create(0.01f);
	timer->setOnTimerCallback([&](TimerPtr t)->bool {
		p1 -= 7;
		plank[0]->locate(scene1, p3, p1);
		plank2[0]->locate(scene2, p3, p1);
		p2 -= 8;
		plank[1]->locate(scene1, p4, p2);
		plank2[1]->locate(scene2, p4, p2);


		if (p1 <= 10) {
			p1 = 700;
		}
		if (p2 <= 10) {
			p2 = 650;
		}

			if (((bobX > p3 - pX) && (bobX < p3 + pX)) && ((bobY > p1 - pY) && (bobY < p1 + pY))) { // 첫 번째 플랑크톤에 부딪힌 경우
				if (heart == 3) {
					heart = 2;
					xx->play();
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
					p1 = 700;
				}
				else if (heart == 2) {
					heart = 1;
					xx->play();
					life->setImage("Images/life1.png");
					life2->setImage("Images/life1.png");
					p1 = 700;
				}
				else if (heart == 1) {
					heart = 0;
					xx->play();
					over->enter();
					start->stop();
					end->play();
					p1 = 700;
				}
			}

			if (((bobX > p4 - pX) && (bobX < p4 + pX)) && ((bobY > p2 - pY) && (bobY < p2 + pY))) { // 두 번째 플랑크톤에 부딪힌 경우
				if (heart == 3) {
					heart = 2;
					xx->play();
					life->setImage("Images/life2.png");
					life2->setImage("Images/life2.png");
					p2 = 650;
				}
				else if (heart == 2) {
					heart = 1;
					xx->play();
					life->setImage("Images/life1.png");
					life2->setImage("Images/life1.png");
					p2 = 650;
				}
				else if (heart == 1) {
					heart = 0;
					over->enter();
					start->stop();
					end->play();
					p2 = 650;
				}
			}
		
		

		count++;
		if (count < 3000000) {
			t->set(0.01f);
			t->start();
		}

		return true;
		});

	cafe->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (bobX >= 800 && enter1 == 1) {
			click->play();
			scene3->enter();
			start->stop();
			stage2->play();
		}
		return true;
		});


	// 2단계 집게버거 만들기
	bread3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (burger == 0) {
			bread2->show();
			ooo->play();
			burger++;
		}
		else if (burger == 4) {
			bread1->show();
			scene4->enter();
			stage2->stop();
			clear->play();
		}else
			xxx->play();
		return true;
		});

	patty2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (burger == 1) {
			patty1->show();
			ooo->play();
			burger++;
		}
		else
			xxx->play();
		return true;
		});

	ch2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (burger == 2) {
			ch1->show();
			ooo->play();
			burger++;
		}
		else
			xxx->play();
		return true;
		});

	let2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (burger == 3) {
			let1->show();
			ooo->play();
			burger++;
		}
		else
			xxx->play();
		return true;
		});

	start->play();

	startb->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		isPlaying = 1;
		bobX = 70;
		bobY = 150;
		timer->start();
		click->play();
		hideTimer();
		startGame(scene1);
		return true;
		});

	overb->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		click->play();
		endGame();
		return true;
		});

	overb1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		click->play();
		endGame();
		return true;
		});

	restart->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		life->setImage("Images/life3.png");
		life2->setImage("Images/life3.png");
		heart = 3;
		end->stop();
		start->play();
		start1->enter();
		bobX = 50;
		bob1->locate(scene1, bobX, bobY);
		bob2->locate(scene2, bobX, bobY);
		burger = 0;
		enter1 = 0;

		return true;
		});

	


	startGame(start1);
}