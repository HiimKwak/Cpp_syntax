#include <iostream>

int main()
{
	FILE* file = nullptr;
	fopen_s(&file, "Test.txt", "rb");

	if (file == nullptr)
	{
		__debugbreak();
		std::cout << "Failed to read file.\n";
	}

	// const char* message = "프로그램에서 작성한 문자열 값입니다.";
	// fputs(message, file);

	/*char data[256] = { };
	while (true)
	{
		if (fgets(data, 256, file) == nullptr)
		{
			break;
		}

		std::cout << data;
	}*/

	// 파일 크기 계산
	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);

	std::cout << "FileSize: " << fileSize << std::endl;

	// 파일 크기 계산 후 다시 처음부터 읽으려면 FP를 되돌려야 함
	//fseek(file, 0, SEEK_SET);
	rewind(file);

	//char buffer[1024] = {};
	char* buffer = new char[fileSize + 1];
	size_t readSize = fread(buffer, sizeof(char), fileSize + 1, file);

	std::cout << "readSize: " << readSize << std::endl;
	std::cout << buffer;

	delete[] buffer;

	fclose(file);
}