
// ��ĳ���� - �θ� -> �ڽ�
// �ٿ� ĳ���� - �ڽ� -> �θ�
class MenuState : public CState
{
public:
	MenuState();
	~MenuState();

	void Start() override;	
	void Update() override;
	void Draw() override;
	void Exit() override;
};