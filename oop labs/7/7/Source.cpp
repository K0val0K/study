// TODO
//2) �������� �������� ������� ��� ������������� ���������� �������� ��������.��������:
//
//
//�������� ����������
//class FileException
//{
//	HANDLE hfile[30];	���������� �����
//	char filename[256];	��� �����
//public:
//	FileException(char* fname);
//	FileException(HANDLE hf);
//	virtual char* Message() = 0;
//};
////������ ��� �������� �����
//class CreateException : public FileException {/*...*/ };
////������ �������� �����
//class OpenException : public FileException {/*...*/ };
//������ ������
//class ReadException : public FileException {/*...*/ };
////������ ������
//class WriteException : public FileException {/*...*/ };
//
//� ����������� ������� ���������� ���������� ������������ � �������������� ������� Message(), ������� ������ ���������� ���������� � ������������ ������.
//
//������������ �����
//class File
//{
//	HANDLE CreateFile(char*);�������� ������ ����� (R/W)
//	HANDLE OpenFile(char*);  �������� ������������� ����� (R/W)
////������ ������ �� �����
//	void ReadFile(HANDLE hf, void* buf, int count);
//	//������ ������ � ����
//	void WriteFile(HANDLE hf, void* buf, int count);
//};
//
//������ ������� ������ ����������� �������������� �������� ��� ���������� �������� � ������������ ���������� ���������������� ����.
//
//� ������� main ��������� � ����� try...catch () ������ ������� ������ File.