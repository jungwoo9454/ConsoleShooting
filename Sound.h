
class Sound
{
public:
	Sound();
	~Sound();

	void LoadSoundFile(std::string path, bool loop);
	void Playsound();
	void StopSound();
	void Update();
	static FMOD::System* system;
private:
	FMOD::Sound* sound;			//���� ����
	FMOD::Channel* channel;		//���� ���� ���(����Ŀ)
};