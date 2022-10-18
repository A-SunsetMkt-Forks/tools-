#ifndef __SIMPLECONFIG_H__
#define __SIMPLECONFIG_H__

class Config {
private:
	std::wstring config_file_name;
	bool SetConfigFile(std::wstring wFileName, HMODULE hModule);
public:
	// EXE�̃f�B���N�g�����Q��
	Config(std::wstring wFileName);
	// DLL�̃f�B���N�g�����Q��
	Config(std::wstring wFileName, HMODULE hDll);
	// �ݒ�̓ǂݎ��
	bool Read(std::wstring wSection, std::wstring wKey, std::wstring &wValue);
	// �ݒ�̍X�V
	bool Update(std::wstring wSection, std::wstring wKey, std::wstring wValue);
};

#endif