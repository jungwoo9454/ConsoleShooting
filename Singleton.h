//싱글톤 패턴 - 디자인 패턴
// 프로그램 내에서 객체가 1개, 언제 어디서든 접근 가능
// 메모리 사용량 높음

class Singleton	//템플릿
{
public:
	int n;

	static Singleton* GetIns()
	{
		if (instance == nullptr)
			instance = new Singleton();
		return instance;
	}
private:
	static Singleton* instance;

	Singleton() {
		n = 0;
	};
	~Singleton() {};
	Singleton(const Singleton&) = delete; //복사 생성자X
	Singleton& operator=(const Singleton&) = delete;	//대입 연산자X
};