class GameState : public CState
{
public:
	GameState();
	~GameState();

	void Start() override;
	void Update() override;
	void Draw() override;
	void Exit() override;
};