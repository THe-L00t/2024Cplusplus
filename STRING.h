// ----------------------------------------------------------
// 헤더에서는 클래스를 선언한다. 
//
//-----------------------------------------------------------
#pragma once

class STRING {
private:
	size_t num{};
	char* p{};

public:
	STRING() = default;
	STRING(const char* s);
	STRING(size_t);		//+연산을 위해 새로 작성 
	~STRING();
		//복사생성자와 복사할당 연산자를 코딩해야 한다. 왜냐? RAII클래스 이기 때문에 
	STRING( const STRING& );
	STRING& operator=(const STRING&);

	//연산자 오버로딩 
	STRING operator+(const char*) const;	//자기 자신과 하는 연산만 하지 않기에 레퍼런스 출력이 아님
	//자기 자신이 변하진 않음 고로 const 붙임
	friend std::ostream& operator<<(std::ostream& cout, STRING& output);


	char* get() const;
	size_t size() const;


};