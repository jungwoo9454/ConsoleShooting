//�̱��� ���� - ������ ����
// ���α׷� ������ ��ü�� 1��, ���� ��𼭵� ���� ����
// �޸� ��뷮 ����

class Singleton	//���ø�
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
	Singleton(const Singleton&) = delete; //���� ������X
	Singleton& operator=(const Singleton&) = delete;	//���� ������X
};