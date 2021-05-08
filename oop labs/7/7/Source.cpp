// TODO
//2) Создайте иерархию классов для представления исключений файловых операций.Например:
//
//
//файловые исключения
//class FileException
//{
//	HANDLE hfile[30];	дескриптор файла
//	char filename[256];	имя файла
//public:
//	FileException(char* fname);
//	FileException(HANDLE hf);
//	virtual char* Message() = 0;
//};
////ошибка при создании файла
//class CreateException : public FileException {/*...*/ };
////ошибка открытия файла
//class OpenException : public FileException {/*...*/ };
//ошибка чтения
//class ReadException : public FileException {/*...*/ };
////ошибка записи
//class WriteException : public FileException {/*...*/ };
//
//В производных классах необходимо определить конструкторы и переопределить функцию Message(), которая должна возвращать информацию о произошедшей ошибке.
//
//Разработайте класс
//class File
//{
//	HANDLE CreateFile(char*);создание нового файла (R/W)
//	HANDLE OpenFile(char*);  открытие существующего файла (R/W)
////чтение данных из файла
//	void ReadFile(HANDLE hf, void* buf, int count);
//	//запись данных в файл
//	void WriteFile(HANDLE hf, void* buf, int count);
//};
//
//Каждая функция должна отслеживать исключительные ситуации при выполнении операций и генерировать исключение соответствующего типа.
//
//В функции main поместите в блоки try...catch () вызовы функций класса File.