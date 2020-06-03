
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <iomanip>

using namespace std;

void IncludeTypes(map<string, bool> &m);

void Ident(ifstream &fin, map<string, vector<int>> &identifiers);

int main()
{
	ifstream fin("main.cpp");
	//Список идентификаторов: ключ - имя идентификатора, массив - содержит номера строк где идентификатор встречается
	map<string, vector<int>> identifiers;

	//Просматривает файл из fin и записывает идентификаторы в identifiers
	Ident(fin, identifiers);

	ofstream fout("identifiers.txt");

	//Запись в файл
	int n = 0;
	map<string, vector<int>>::iterator p = identifiers.begin();
	if (p == identifiers.end())
		fout << "Code don't have identifiers";
	else
		while (p != identifiers.end()) {
			n++;
			fout << setw(3) << n << "." << p->first << " => Number = ";
			fout << p->second.size() << " => Lines: ";
			vector<int>::iterator pi = p->second.begin();
			while (pi != p->second.end()) {
				fout << *pi;
				pi++;
				if (pi != p->second.end())
					fout << ", ";
				else
					fout << ";";
			}
			fout << "\n\n";
			p++;
		}
}

void IncludeTypes(map<string, bool> &m) {
	m.insert(make_pair("unsigned", true));
	m.insert(make_pair("const", true));
	m.insert(make_pair("char", true));
	m.insert(make_pair("short", true));
	m.insert(make_pair("int", true));
	m.insert(make_pair("long", true));
	m.insert(make_pair("float", true));
	m.insert(make_pair("double", true));
	m.insert(make_pair("bool", true));
	/////////////////////////////////////
	m.insert(make_pair("bitset", true));
	m.insert(make_pair("deque", true));
	m.insert(make_pair("list", true));
	m.insert(make_pair("map", true));
	m.insert(make_pair("multimap", true));
	m.insert(make_pair("multiset", true));
	m.insert(make_pair("priority-queue", true));
	m.insert(make_pair("queue", true));
	m.insert(make_pair("set", true));
	m.insert(make_pair("stack", true));
	m.insert(make_pair("string", true));
	m.insert(make_pair("vector", true));
	m.insert(make_pair("iostream", true));
	m.insert(make_pair("istream", true));
	m.insert(make_pair("ostream", true));
	m.insert(make_pair("fstream", true));
	m.insert(make_pair("ifstream", true));
	m.insert(make_pair("ofstream", true));
}

void Ident(ifstream &fin, map<string, vector<int>> &identifiers) {
	//Список типов и объявление в нём известых типов
	map<string, bool> types;
	IncludeTypes(types);

	//Хранит номер текущей строки
	int line = 0;
	//Хранит текущую строку
	string s;
	int type_declared = 0;/*
	1 - возможно объявить идентификатор, если будет использована ","
	2 - тип объявлен, можно определить идентификатор
	0 - объявить нельзя
	*/
	bool comment = false;
	bool new_struct = false;
	bool ignore_next_word = false;
	int roundBrackets = 0; //()
	int triangleBrackets = 0; //<>
	bool quotes1 = false; //''
	bool quotes2 = false; //""

	bool can_be_ident = false;
	string can_be_ident_word;
	int can_be_ident_line;

	while (!fin.eof())
	{
		line++;
		getline(fin, s);

		int l = s.length();
		//Просматривает строку кода
		for (int i = 0; i < l; i++) {
			if (s[i] == '\\') {
				i++;
				continue;
			}
			//Проверка на кавычки, если нашлась одна, 
			//то весь последующий код игнорируется до следующей кавычки такого же вида
			if (s[i] == '\'' && !quotes2)
				if (quotes1)
					quotes1 = false;
				else
					quotes1 = true;
			if (s[i] == '"' && !quotes1)
				if (quotes2)
					quotes2 = false;
				else
					quotes2 = true;

			if (!quotes1 && !quotes2) {
				//Игрнорирует код между /* */
				if (s[i] == '/' && s[i + 1] == '*')
					comment = true;
				if (s[i] == '*' && s[i + 1] == '/')
					comment = false;

				if (!comment) {
					//Игнорирует дальнейший код в просматриваемой строке
					if (s[i] == '/' && s[i + 1] == '/')
						break;
					if (s[i] == '#')
						break;

					//Если был объявлен тип, то код в <> игнорируются
					if (s[i] == '<' && type_declared == 2)
						triangleBrackets++;
					if (s[i] == '>' && type_declared == 2 && triangleBrackets)
						triangleBrackets--;

					if (!triangleBrackets) {
						//Если был объявлен тип, то следующее после : (в частности после ::) ключевое слово будет проигнорированно
						if (s[i] == ':' && type_declared == 2)
							ignore_next_word = true;

						//Выделение ключевого слова в коде
						if ('A' <= s[i] && s[i] <= 'Z' || 'a' <= s[i] && s[i] <= 'z' || s[i] == '_') {
							string word("");
							//Выделение самого слова и занесение его в word
							while (true) {
								word += s[i];
								if ('A' <= s[i + 1] && s[i + 1] <= 'Z' ||
									'a' <= s[i + 1] && s[i + 1] <= 'z' ||
									'0' <= s[i + 1] && s[i + 1] <= '9' ||
									s[i + 1] == '_')
									i++;
								else
									break;
							}

							//Слово игнорируется
							if (ignore_next_word) {
								ignore_next_word = false;
								continue;
							}

							//Если слово == struct или class,
							//то следующее за ним словом будет новым типом, который занеяётся в types
							if (word == "struct" || word == "class") {
								new_struct = true;
								continue;
							}
							if (new_struct) {
								types.insert(make_pair(word, true));
								new_struct = false;
								continue;
							}

							//Проверяется наличие word в списке возможных типов
							map<string, bool>::iterator pt;
							pt = types.find(word);
							if (pt != types.end()) {
								//Пропуск последующих пробелов
								while (s[i + 1] == ' ') {
									i++;
									if (i + 1 >= l) {
										getline(fin, s);
										line++;
										i = -1;
										l = s.length();
									}
								}
								//Если следующий символ "(", то word - является частью приведения к типу word, значит возможный идентификатор - не функция, он добавляется в список(ниже написано, что это)
								if (s[i + 1] == '(' && can_be_ident)
									identifiers.insert(make_pair(can_be_ident_word, vector<int>(1, can_be_ident_line)));
								//Если это другой символ или возможного идентификатора нет, то word является объявлением типа
								else
									type_declared = 2;
								can_be_ident = false;
								continue;
							}

							//Если первыми в скобках после возможного идентификатора слово не является типом,
							//значит это идентификатор с конструктором, он заносится в список идентификаторов 
							if (can_be_ident) {
								identifiers.insert(make_pair(can_be_ident_word, vector<int>(1, can_be_ident_line)));
							}

							//Поиск word в списке идентификаторов, если оно там есть, то добавление в массив номера строки
							map<string, vector<int>>::iterator p;
							p = identifiers.find(word);
							if (p != identifiers.end()) {
								p->second.push_back(line);
								continue;
							}

							//Если тип объявлен, то word возможно новый идетификатор
							if (type_declared == 2) {
								//Пропуск пробелов
								while (s[i + 1] == ' ') {
									i++;
									if (i + 1 >= l) {
										getline(fin, s);
										line++;
										i = -1;
										l = s.length();
									}
								}
								//Если после после word стоит "(", то это либо функция, либо новый идентификатор.
								//Чтобы опреденлить что это, данные word запоминаются.
								//Идентификатор это или функция - определяет, то что написано первым полсе (:
								//Если это объявление новой переменной - то это функия
								//Нет - значит can_be_ident_word - идентификатор, а (  часть конструктора
								if (s[i + 1] == '(') {
									roundBrackets++;
									i++;
									can_be_ident = true;
									can_be_ident_word = word;
									can_be_ident_line = line;
									type_declared = 1;
									continue;
								}
								//Если скобки нет,то word новый идентификатор
								identifiers.insert(make_pair(word, vector<int>(1, line)));
								type_declared = 1;
								continue;
							}
						}

						//Если первыми в скобках после возможного идентификатора есть цифры,
						//значит это идентификатор с конструктором, он заносится в список идентификаторов 
						if (can_be_ident && '0' <= s[i] && s[i] <= '9') {
							identifiers.insert(make_pair(can_be_ident_word, vector<int>(1, can_be_ident_line)));
							can_be_ident = false;
						}

						//Если в скобках после возможного идентификатора ничего нет
						//значит это функция, она не записывается в список идентификаторов
						if (can_be_ident && s[i] == ')')
							can_be_ident = false;

						//roundBrackets равно 0, когда все круглые скобки после идентификатора закрыты
						if (s[i] == '(' && roundBrackets)
							roundBrackets++;
						if (s[i] == ')' && roundBrackets)
							roundBrackets--;

						//Если после одного объявленого идентификатора стоит ",", то можно объявить ещё один
						if (type_declared == 1 && s[i] == ',' && roundBrackets == 0)
							type_declared = 2;

						//После ; и { дентификатор нельзя объявить
						if (s[i] == ';' || s[i] == '{')
							type_declared = 0;
					}
				}
			}

			//Если первыми в скобках после возможного идентификатора есть кавычки,
			//значит это идентификатор с конструктором, он заносится в список идентификаторов 
			if (can_be_ident && (s[i] == '\'' || s[i] == '"')) {
				identifiers.insert(make_pair(can_be_ident_word, vector<int>(1, can_be_ident_line)));
				can_be_ident = false;
			}
		}
	}
}
