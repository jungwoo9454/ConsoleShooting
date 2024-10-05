
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
	FMOD::Sound* sound;			//사운드 파일
	FMOD::Channel* channel;		//사운드 파일 재생(스피커)
};