# Spreadsheet


**<big>Представяне на данните</big>**

Данните на една таблица ще записваме в текстов файл по следния начин:
- Всеки ред във файла представя отделен ред в таблицата.
- Всеки ред във файла съдържа данни, разделени със запетаи. Тези данни се интерпретират като стойностите в клетките на реда.
- Всеки ред в таблицата може да съдържа различен брой клетки. Затова и всеки ред във файла може да съдържа различен брой елементи, разделени със запетаи.
- Празен ред във файла представя празен ред в таблицата (т.е. ред, в който всички клетки са празни).
- Между две запетаи във файла може да няма никакви данни. По този начин се представя празна клетка.
- Между данните и запетаите може да има произволен брой празни символи (whitespace).

Така за една таблица може да има различни представяния. Например таблицата:


![image](https://github.com/monsicode/Spreadsheet/assets/96687353/2bf2c03d-5e8d-4cef-8049-45ff8f625ad2)

може да се представи по следните начини (възможни са и други представяния):

![image](https://github.com/monsicode/Spreadsheet/assets/96687353/837b9024-de92-483b-a642-4e078ddfc51e)


**Типове данни в таблицата**

Всяка клетка в таблицата може да съдържа различни типове данни:
- **Цяло число** – поредица от цифри без никакви други символи между тях. В началото на числото може да има знак '+' или '-'. Например: `123`, `-123`, `+123`.
- **Дробно число** – поредица от цифри, следвана от символ за точка и след нея друга поредица от цифри. В началото на числото може да има знак '+' или '-'. Например: `123.456`, `-123.456`, `+123.456`.
- **Символен низ** – поредица от произволни символи, оградени в кавички (quotation marks). Подобно на низовете в C++, включването на символа за кавичка в даден низ, трябва да се представи като `\"`, а включването на обратна наклонена черта се представя като `\\`. Например: `"Hello world!"`, `"C:\\temp\\"`, `"\"This is a quotation\""`.
- **Формула** – формулата винаги започва със символ за равенство `=`. В нея могат да участват следните операции: събиране `+`, изваждане `-`, умножение `*`, деление `/` и степенуване `^`. Във формулата могат да участват числа или препратки към клетки в таблицата (например `R1C2` за клетката в първия ред и втората колона). Ако във формулата участва препратка към клетка, на това място в изчислението се използва стойността, съхранена в дадената клетка. Повече информация за формулите е дадена по-долу.

## Нужна функционалност

След като приложението отвори даден файл, то трябва да може да извършва следните операции, в допълнение на общите операции (open, close, save, save as и exit):
- **Извеждане на таблицата на екрана (`print`)**: Данните в колоните трябва да се подравнят, а между отделните колони трябва да се поставят символи за отвесна черта (`|`).
- **Редактиране на клетки (`edit`)**: Потребителят трябва да може да променя стойностите на отделните клетки чрез въвеждане на ред и колона на клетката, както и нова стойност. В случай на въведени неправилни данни програмата не трябва да променя нищо в таблицата и да изведе съобщение за грешка.
- **Изчисляване на формули (`calculate`)**: Програмата трябва да може да оценява и изчислява формули, съдържащи числа и препратки към клетки в таблицата, спазвайки правилата за аритметичните операции и обработката на грешки като деление на нула или невалидни изрази.

Тези функционалности трябва да бъдат ясно документирани и достъпни за потребителя на програмата.


![image](https://github.com/monsicode/Spreadsheet/assets/96687353/89795d8f-3219-4d42-b45b-83aeb0c88565)

Ако при зареждането на данните се открие грешка (напр. некоректен формат), трябва да се изведе подходящо съобщение за грешка и изпълнението на програмата да се прекрати. Съобщението трябва да подскаже на потребителя какво не е наред във входните данни. Например:
- Ако липсва запетая трябва да се изведе на кой ред и след кой символ липсва запетаята;
- Aко съдържанието на дадена клетка е от неизвестен тип, трябва да се изведе на кой ред и коя колона е клетката и какво точно е некоректното съдържание. Например нека предположим, че на ред 2, колона 5, потребителят е въвел 123.123.123. Приложението ви може да изведе например следното съобщение: “Error: row 2, col 5, 123.123.123 is unknown data type”. 



## Извеждане на таблицата на екрана

При извеждане на заредената таблица (командата print), данните в колоните трябва да се подравняват. Между отделните колони трябва да се поставят символи за отвесна черта (`|`).

![image](https://github.com/monsicode/Spreadsheet/assets/96687353/44bad259-094f-445a-bd72-5e62c134ddfb)


## Редактиране на клетки

Командата `edit` трябва да има подходящи параметри и да позволява на потребителя да променя стойностите на отделните клетки в таблицата. Това става като се посочат редът и колоната на клетката, която потребителят иска да промени, както и новата стойност, която да се запише в нея. Потребителят може да въведе данни от произволен тип от следните: цели и дробни числа, низове в кавички, както и формули.

Ако потребителят въведе неправилни данни, програмата не трябва да променя нищо в таблицата, а само да изведе на екрана съобщение за грешка. Изпълнението на програмата не трябва да се прекратява при неправилни данни.

### Формули

Номерата на редовете и клетките в таблицата започват от 1. Препратка към ред и колона в таблицата се записва по следния начин: `R<ред>C<колона>`. Например, клетката в ред 10 и колона 5 се представя като `R10C5`.

В дадена формула могат да участват:

- **Литерали**: цели или дробни числа.
- **Препратки към други клетки** от произволни типове.

  ### Правила за изчисляване на стойностите в формули

При изчислението на стойността на дадена клетка важат следните правила:

1. **Само числа в формула**: Ако в дадената формула участват само числа, изчислението се извършва по традиционните правила на аритметиката, спазвайки приоритета на операциите. Например, формулата `2 + 3 * 4` ще се изчисли като `14`, тъй като умножението има по-висък приоритет от събирането.

2. **Деление на две цели числа**: Като специален случай, ако формулата съдържа деление на две цели числа, резултатът може да бъде дробно число. Например, формулата `1 / 2` ще се изчисли като `0.5`.

3. **Участие на низове в формула**: Ако в дадената формула участва низ, който коректно представя цяло или дробно число според предходното описание, той се преобразува до стойността на числото. Например, низът `"123"` ще се преобразува до числото `123`. Всички други низове, които не представляват валидно число, се конвертират до нула при изчисляването на формулата.

Например:
![image](https://github.com/monsicode/Spreadsheet/assets/96687353/b99a4217-905a-4fb3-afe8-4fdb8f952471)


