**Какво е текстов файл ?**

- "форматиран" файл
- printable characters only (ASCII код >= 32)
- Примери : C++ source code, webpage(HTML)



**Декларация на файлови променливи**

// Добавяме библиотеката <fstream>

- ifstream file_read; (read only)
- ofstream file_write; (write only)
- fstream file_read_write; (read and write, rarely used)



**Отваряне и затваряне, начини на отваряне**

char filename = "hello.txt";

file_read.open(filename);

**Режими на отваряне на файлове - чрез флагове**

- ios::in - режим за четене
- ios::out - режим за писане
- ios::app - указателят за писане отива след последния елемент
- ios::ate - указателите за писане и четене отиват след последния елемент
- ios::trunc - изтриване на съдържанието на файла

ifstream fileStream(filename, ios::in);

ofstream fileStream(filename, ios::out | ios::trunc);

Проверка дали файл е отворен : filestream.isOpen() - true or false

Затваряне на файл : fileStream.close() 



**Засичане край на файл, четене ред по ред**

 ifstream fstr;

 fi.eof() - true or false (eof - end of file)

char line[200] = { '\0'};

while (!fstr.eof()) 

{

fstr.getline(line, 200);

cout << line << '\n';

}



**Четене знак по знак**

ifstream fstr;

char toRead;

while(!fstr.eof())

{

toRead = fstr.get();

}



**Четене на променливи**

ifstream fstr;

int num;

double doubleNum;

while (!fi.eof())

{

fstr>> num;

fstr>>doubleNum;

}





**Указатели за четене и писане**

fstream fstr;

fstr.tellg()  - връща позицията на указателя за четене, съответно при прочетени вече 6 знака функцията ще върне 6

fstr.tellp() - връща позицията на указателя за писане



fstr.seekg(0, ios::beg) - премества указателя за четене на 0 (първия аргумент) позиции от началото(вторият аргумент, който може да бъде ios::beg(началото на файла), ios::curr(сегашната позиция на указателя), ios::end(края на файла))

fstr.seekp(10, ios::curr) - премества указателя за писане на 10 позиции от сегашната му позиция

