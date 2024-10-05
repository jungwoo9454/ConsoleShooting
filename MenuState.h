
// 업캐스팅 - 부모 -> 자식
// 다운 캐스팅 - 자식 -> 부모
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