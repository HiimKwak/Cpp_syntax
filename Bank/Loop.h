#pragma once
class Loop
{
	struct KeyState
	{
		bool isKeyDown = false;
		bool wasKeyDown = false;
	};
public:
	Loop();
	~Loop();

	void Run();
	void Quit();

	bool GetPressedKey(int keyCode);
private:
	void ProcessInput();

private:
	bool isQuit = false;
	KeyState keyStates[255] = { };
};

