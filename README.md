# Мои решения заданий и мой конспект по изучению книги "The C Programming language"

## Ссылки на источники для изучения
[The C Programming Language](https://kremlin.cc/k&r.pdf) - PDF версия книги.

[cc4e](https://www.cc4e.com/book) - Сайт курса изучения C, основываясь на книге, с комментариями Dr.Chuck.

[YouTube freeCodeCamp](https://www.youtube.com/watch?v=j-_s8f5K30I&t=260s&ab_channel=freeCodeCamp.org) - Видео по курсу cc4e от Dr.Chuck.

## Конспект

### Оглавление

[Глава 2](#chapter-2) \
&nbsp;&nbsp;&nbsp;&nbsp;[2.1 Имена переменных](#variable-names)<br />
&nbsp;&nbsp;&nbsp;&nbsp;[2.2 Типы данных и их размеры](#data-types-and-sizes)<br />
&nbsp;&nbsp;&nbsp;&nbsp;[2.3 Константы](#constants)<br />
	
### <a id="chapter-2"></a>Глава 2 - Типы данных, операторы и выражения.

#### <a id="variable-names"></a>2.1 Имена переменных.
Особенности именования переменных и констант:
- Имя может состоять из цифр, букв и символа нижнего подчеркивания "_".
- Имя должно начинаться с буквы. Нижнее подчеркивания считается буквой "_".
- Переменные в верхнем и нижнем регистре считаются разными переменными. test != TEST != Test... Есть негласное правило - использовать верхний регистр для констант, а нижний для переменных.
- Для имени переменной нельзя использовать "зарезервированные слова" - *if*, *else*, *float*, *int*...
- В старых версиях языка C только первые восемь символов в имени переменной имели значение. Остальные игнорировались. Сейчас минимум 30 символов играют роль.

#### <a id="data-types-and-sizes"></a>2.2 Типы данных и их размеры.

В языке C существует всего несколько базовых типов данных:
- *char* - один байт, способный содержать один символ.
- *int* - целое число. В диапазоне **-2 147 483 648** до **2 147 483 647**.
- *float* - число с плавающей точкой одинарной точности. Примерно 7 десятичных знаков.
- *double* - число с плавающей точкой двойной точности. Примерно 16 десятичных знаков.

Кроме того, для целых чисел (*int*) также применимы классификаторы, со следующим синтаксисом объявления:
- *short int x* - находится в интервале от **-32 767** до **32 767**.
- *long int x* - находится в интервале от **-2 147 483 648** до **2 147 483 647**.
- *unsigned int x* - как обычный *int*, но беззнаковый (всегда положительный). 
По этому может находиться в интервале от **0** до **4 294 967 295**.

#### <a id="constants"></a>2.3 Константы.

Константы объявляются с помощью ключевого выражения *#define*. Пример:

&nbsp;&nbsp;&nbsp;&nbsp;*#define MAXLINE	1000*

Такое выражение вычисляется во время компиляции, а не исполнения программы.


**Числовые константы:**
- Могут представлять целое число *int*.
- Могут представлять *float* и *double*. При чем константы с плавающей точкой это всегда *double*.
- Могут быть записаны в [**экспоненциальной записи**](https://ru.wikipedia.org/wiki/%D0%AD%D0%BA%D1%81%D0%BF%D0%BE%D0%BD%D0%B5%D0%BD%D1%86%D0%B8%D0%B0%D0%BB%D1%8C%D0%BD%D0%B0%D1%8F_%D0%B7%D0%B0%D0%BF%D0%B8%D1%81%D1%8C).
- Могут представлять длинные числа с записью вида *123L*.
- Могут быть записаны в виде числа восьмеричной (octal) или шестнадцатиричной (hex) системы счисления. Для записи octal в начале числа должен находится лидирующий ноль - 0. Для hex в начале лидирующий - 0x. 
Например 31 из десятиричной системы будет выглядеть следующим образом.

&nbsp;&nbsp;&nbsp;&nbsp;037 в octal;
&nbsp;&nbsp;&nbsp;&nbsp;0x1f или 0X1F в hex.

**Символьные константы:**
Символьная константа это один символ записанный в одинарных кавычках, например 'x'. Значение такой константы это числовое представление символ в машинной последовательности символов. 
Например в стандарте кодирования [ASCII](https://ru.wikipedia.org/wiki/ASCII) символ нуля '0' это число 48.

Символьные константы могут участвовать в числовых операциях, как и любые другие числа, но как правило это не используется.

Некоторые не графические символы могут быть представлены в константе в виде записи [управляющей последовательности(escape sequence)](https://ru.wikipedia.org/wiki/%D0%A3%D0%BF%D1%80%D0%B0%D0%B2%D0%BB%D1%8F%D1%8E%D1%89%D0%B0%D1%8F_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D1%8C#:~:text=escape%20sequence)%20%E2%80%94%20%D1%81%D0%BE%D0%B2%D0%BE%D0%BA%D1%83%D0%BF%D0%BD%D0%BE%D1%81%D1%82%D1%8C%20%D0%B8%D0%B4%D1%83%D1%89%D0%B8%D1%85%20%D0%BF%D0%BE%D0%B4%D1%80%D1%8F%D0%B4,%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B5%D0%B9%20%D0%BF%D1%80%D0%B5%D0%B4%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D1%8F%D0%B5%D1%82%20%D1%81%D0%BE%D0%B1%D0%BE%D0%B9%20%D0%BB%D0%BE%D0%B3%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%BE%D0%B5%20%D0%BA%D0%BE%D0%B4%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5.).
Например — \n новая строка; \t табуляция; \0 null; \' одинарная кавычка и т.д.

**Строковые константы:**
Это последовательность из нуля или большего количества символов в двойных кавычках. Пример:

"I am a string" или "" — пустая строка.

Кавычки это не часть строки, а служат только для её разделения. В строках применяются те же управляющие (escape) последовательности, что и в символах. Например для обозначения двойных кавычек используется следующая последовательность символов — \" .
Технически, строка это массив состоящий из символов. Компилятор автоматически размещает пустой символ (\0) в конце каждой строки, чтобы программа могла определить её конец.

Нужно обратить внимание, что символьная и строковая константа с одними символами это не одно и то же.

'x' != "x" 