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
	~STRING();
		//복사생성자와 복사할당 연산자를 코딩해야 한다. 왜냐? RAII클래스 이기 때문에 
	STRING( const STRING& );
	STRING& operator=(const STRING&);

	size_t size() const;

};