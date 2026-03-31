# Тестовое задание
Для работы использовалась Visual Studio 2017 с аддоном `qtvsaddin`. Компилятор MSVC 2017

Стек:
- Qt 5.11
- libpqxx
- libpq
- pqcrypt (для щифрования паролей в бд. `CREATE EXTENSION pgcrypto`)

Библиотеки были установлены через команду `.\vcpkg.exe install libpq:x64-windows` и `.\vcpkg.exe install libpqxx:x64-windows`

Название БД -- стандартное postgres, пароль 123456. Параметры можно в `connectionString` сменить

Команда для создания:
```sql
CREATE TABLE students (
	Id SERIAL PRIMARY KEY,
	Fio VARCHAR(50),
	Gr VARCHAR(50),
	Login VARCHAR(50),
	Pass CHAR(100)
)
```

Команда для наполенения
```sql
INSERT INTO students VALUES 
(1, 'Иванов Иван Иванович', 'Gr1', 'Vnya12', crypt('password1', gen_salt('md5'))),
(2, 'Петров Пётр Петрович', 'Gr2', 'Petya34', crypt('password2', gen_salt('md5'))),
(3, 'Сидоров Сидор Сидорович', 'Gr1', 'Sidor56', crypt('password3', gen_salt('md5'))),
(4, 'Кузнецова Анна Сергеевна', 'Gr3', 'Anna78', crypt('password4', gen_salt('md5'))),
(5, 'Васильев Алексей Николаевич', 'Gr2', 'Alex90', crypt('password5', gen_salt('md5'))),
(6, 'Морозова Екатерина Ивановна', 'Gr3', 'Katya12', crypt('password6', gen_salt('md5'))),
(7, 'Новиков Дмитрий Владимирович', 'Gr1', 'Dmitry34', crypt('password7', gen_salt('md5'))),
(8, 'Фёдорова Мария Алексеевна', 'Gr2', 'Maria56', crypt('password8', gen_salt('md5'))),
(9, 'Смирнов Николай Петрович', 'Gr3', 'Nikolay78', crypt('password9', gen_salt('md5'))),
(10, 'Гусева Ольга Сергеевна', 'Gr1', 'Olga90', crypt('password10', gen_salt('md5')));
```
