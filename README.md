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
