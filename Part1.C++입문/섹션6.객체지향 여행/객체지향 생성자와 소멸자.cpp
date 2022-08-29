#include <iostream>
using namespace std;

class Knight
{
public:
	//[0]암시적 생성자 : 생성자를 명시적으로 만들지않으면, [기본생성자]가 컴파일러에 의해 자동으로 만들어짐 (빈껍데기가 만들어짐)
	//[1]생성자: 생성과 동시에 호출.//강사는 인자없는 버전이 기본생성자 라는데, 디폴트값 해줘도 되더라.
	Knight(int hp = 100, int attack = 10)
	{
		cout << "Knight생성자 호출" << endl;
		this->_hp = hp;
		this->_attack = attack;
		this->_posY = 0;
		this->_posX = 0;
	}//생성자는 오버로딩이 가능하다.

	//[2]복사생성자 (자신의 클래스 참조타입을 인자로 받음) //얘도 암시적복사생성자가 있는데, 이경우 모든데이터를 똑같이 복사함.
	//(인자의 데이터를 토대로 새로운 객체를 생성함)
	Knight(const Knight& knight)
	{
		this->_hp = knight._hp;
		this->_attack = knight._attack;
		this->_posY = knight._posY;
		this->_posX = knight._posX;
	}
	//[3]기타생성자 
	Knight(int hp, int attack, int posY, int posX)
	{
		_hp = hp;
		_attack = attack;
		_posX = posY;
		_posY = posX;
	}
	//기타생성자 중 '입자를 1개만' 받는 생성자를 [타입 변환 생성자]라 하는데, 얘는 특이한 용도가 있다.넣어준 인자를 알아서 쓸만한타입으로 바꿔서 이용함
	// 암시적 형변환이란 : 컴파일러가 알아서 형변환을 시키는걸 말한다.
	// int num=1;
	// float f1 = num; //암시적형변환의 예시 : 컴파일러가 알아서 num형변환을해서 float로 넣는다.
	// float f2 = (float)num; //명시적형변환의 예시
	// 컴파일러가 알아서 바꿔주니까 편할거같은데, 이로인해 혼동과 버그가 생겨나기도 한다.
	// 
	// 그래서 암시적으로 바꾸지말라고, 명시적인 용도로만 쓰라고 하는게 explicit (고급문법이긴함)
	explicit Knight(int hp)
	{
		_hp = 100;
		_attack = 10;
		_posY = 0;
		_posX = 0;

	}

	//소멸자
	~Knight()
	{
		cout << "~Knight기본소멸자 호출" << endl;
	}

public:
	//멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	void Die() //바로 여기서 기능구현도 가능.
	{
		this->_hp = 0; //this는 포인터더라.
		_hp = 0; //어셈블리상 위와 완전히 같음
		cout << "Die" << endl;
	}

public:
	//멤버 변수
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x) //Knight클래스의 함수라는 것을 알리기 위해 '::'필요
{
	_posY = y;
	_posX = x;
}

void Knight::Attack()
{
	cout << "Attack" << endl;

}

int main()
{
	Knight k1; //c#과 달리 new 필요없음. 그저 int a; 하듯 만들면됨
	k1._hp = 200;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	Knight k2(k1);

	//놀랍게도 다음 k3와k4의 생성로직은 서로 다르다. 오히려 k2와 k3의 로직이 비슷.
	Knight k3 = k1; //k3는 생성과 동시에 복사생성자가 호출되고
	Knight k4; //k4는 기본생성자 후에, k1복사가 이루어진다.
	k4 = k1;

	k1.Move(2, 2);
	k1.Die();
	k1.Attack();

	return 0;
}
