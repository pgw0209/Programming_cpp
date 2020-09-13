// 객체지향프로그래밍 2주차 Quiz 제출 
// 20174910 박규원
// 3주차 수정 완료_20200913


/*
scene1 : 룸1
scene2 : 룸2
scene2 : 룸3

door1 : 룸1의 오른쪽 문
door2 : 룸1과 룸2를 연결하는 문
door3 : 룸2의 숨겨진 문
door4 : 룸3의 숨겨진 문

룸1 - 화분을 옮겨 열쇠를 얻는다.
룸2 - 스위치를 통해 패스워드를 찾고, 키패트에 패스워드를 입력하면 숨겨진 door3가 나온다. door3를 클릭하면 문이 열리고 방을 탈출할 수 있다.
룸3 - 리모콘을 찾아 책장을 옮겨 숨겨진 문을 찾는다.
*/

#include <bangtal.h>
using namespace bangtal;

/* bool door1_mouseCallback(ObjectPtr object, int x, int y, MouseAction action) {
	
	endGame(); // 게임을 종료한다.
	return true;
} */

int main() {
	// 1. 장면을 생성한다,
	auto scene1 = Scene::create("룸1", "Images/배경-1.png"); // (장면의 이름, 배경 이미지) 입력
	//ScenePtr scene1 = Scene::create("룸1", "Images/배경-1.png"); // (장면의 이름, 배경 이미지) 입력
	auto scene2 = Scene::create("룸2", "Images/배경-2.png"); // (장면의 이름, 배경 이미지) 입력
	auto scene3 = Scene::create("룸3", "Images/배경-3.png"); // (장면의 이름, 배경 이미지) 입력


	// 5. 열쇠를 만든다.
	auto key = Object::create("Images/열쇠.png", scene1, 600, 150);
	key->setScale(0.2f);

	key->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		key->pick();
		return true;
	});

	// 6. 화분을 만든다.
	auto flowerpot_moved = false;
	auto flowerpot = Object::create("Images/화분.png", scene1, 550, 150); // (배경 이미지, 어떤 장면에 위치하는지, x좌표, y좌표)
	flowerpot->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (flowerpot_moved == false) {
			if (action == MouseAction::MOUSE_DRAG_LEFT) {
				flowerpot->locate(scene1, 450, 150);
				flowerpot_moved = true;
			}
			else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
				flowerpot->locate(scene1, 650, 150);
				flowerpot_moved = true;
			}
		}
		
		return true;
		});


	// 3. 문을 생성한다.
	auto open1 = false;
	auto door1 = Object::create("Images/문-오른쪽-닫힘.png", scene1, 800, 270); // (배경 이미지, 어떤 장면에 위치하는지, x좌표, y좌표)

	// 4. 문을 클릭하면 이동한다.            //람다 함수(lambda function)
	//door1->setOnMouseCallback(door1_mouseCallback);
	door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open1 == true) { //문이 열린 상태
			scene2->enter();
			showMessage("숨겨진 문을 찾아보세요!");
		}
		else if (key->isHanded()) {				 //문이 닫힌 상태
			door1->setImage("Images/문-오른쪽-열림.png");
			open1 = true;
		}
		else {
			showMessage("열쇠가 없어 문을 열지 못합니다.");
		}
		return true;
	}); 

	auto door2 = Object::create("Images/문-왼쪽-열림.png", scene2, 320, 270); // (배경 이미지, 어떤 장면에 위치하는지, x좌표, y좌표)
	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open1 == true) 
			scene1->enter();
		return true;
		});

	auto door3 = Object::create("Images/문-오른쪽-닫힘.png", scene2, 910, 270); // (배경 이미지, 어떤 장면에 위치하는지, x좌표, y좌표)
	door3->hide();

	// 7. 키패드를 만든다.
	auto keypad = Object::create("Images/키패드.png", scene2, 885, 420); // (배경 이미지, 어떤 장면에 위치하는지, x좌표, y좌표)
	keypad->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showKeypad("1", door3); // (암호, 수신할 Object)
		return true;
	});

	auto open3 = false;


	door3->setOnKeypadCallback([&](ObjectPtr object)->bool {
		showMessage("문이 나타났다!");
		door3->show();
		door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (open3 == true) {
				scene3->enter(); // 게임이 종료된다.
			}
			else {
				door3->setImage("Images/문-오른쪽-열림.png");
				open3 = true;
			}
		return true;
		});

		
		return true;
		});

	// 8. 스위치를 만든다.
	auto password = Object::create("Images/암호.png", scene2, 400, 100); // (배경 이미지, 어떤 장면에 위치하는지, x좌표, y좌표)
	password->hide();
	auto lighted = true;
	auto button = Object::create("Images/스위치.png", scene2, 880, 440); // (배경 이미지, 어떤 장면에 위치하는지, x좌표, y좌표)
	button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (lighted == true) {
			scene2->setLight(0.2f);
			password->show();
			lighted = false;
		}
		else {
			scene2->setLight(1);
			password->hide();
			lighted = true;
		}
		return true;
		});

	auto door4 = Object::create("Images/문1.png", scene3, 300, 220);
	auto shelf = Object::create("Images/책장1.png", scene3, 450, 120);
	auto remote = Object::create("Images/리모콘.png", scene3, 590, 190);
	auto book1 = Object::create("Images/책1.png", scene3, 600, 190);
	auto book2 = Object::create("Images/책2.png", scene3, 600, 290);
	auto book3 = Object::create("Images/책3.png", scene3, 600, 380);
	auto book4 = Object::create("Images/책1.png", scene3, 600, 480);
	auto partition = Object::create("Images/파티션2.png", scene3, 180, 200);


	book1->setScale(0.9f);
	book2->setScale(0.9f);
	book3->setScale(0.9f);
	book4->setScale(0.9f);
	remote->setScale(0.03f);
	partition->setScale(0.9f);

	book1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			if (action == MouseAction::MOUSE_DRAG_LEFT) {
				book1->locate(scene3, 600, 190);
			}
			else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
				book1->locate(scene3, 670, 190);
			}
		
		return true;
		});

	book2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT) {
			book2->locate(scene3, 600, 290);
		}
		else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
			book2->locate(scene3, 670, 290);
		}

		return true;
		});

	book3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT) {
			book3->locate(scene3, 600, 380);
		}
		else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
			book3->locate(scene3, 670, 380);
		}

		return true;
		});

	book4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT) {
			book4->locate(scene3, 600, 480);
		}
		else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
			book4->locate(scene3, 670, 480);
		}

		return true;
		});

	remote->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showMessage("리모콘으로 무언가를 동작시킬 수 있을 것 같다.");
		remote->pick();
		return true;
		});



	auto open4 = false;
	door4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (open4 == true) { //문이 열린 상태
			endGame();
		}
		else if (remote->isHanded()) {				 //문이 닫힌 상태
			door4->setImage("Images/문2.png");
			door4->locate(scene3, 300, 200);
			showMessage("딸깍");
			open4 = true;
		}
		return true;
		});

	partition->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		 if (remote->isHanded()) {				 //리모콘이 있는 상태
			partition->locate(scene3, 30, 200);
		}
		 else { //리모콘이 없는 상태
			 showMessage("책장 뒤에 무엇인가 있는 것 같다. 책장을 옮길 방법이 없을까?");
		 }
		return true;
		});


	// 2. 게임을 시작한다.
	startGame(scene1);
	

	return 0;
}