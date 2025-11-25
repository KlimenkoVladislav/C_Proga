Нахожусь на ветке main

![alt text](img/image.png)

git log выглядит так:

![alt text](img/image-1.png)

Добавился файл sort.c

![alt text](img/image-2.png)

sort.c убралась из списка файлов "Untracked files" и переместилась в список "Changes to be committed"

![alt text](img/image-3.png)

закоммитились 2 файла: README и sort.c

![alt text](img/image-4.png)

Исчезли файлы README (он исчез, просто я сразу добавляю в него информацию для отчёта) и sort.c из списка "Changes not staged for commit"

![alt text](img/image-5.png)

Файл sort.c снова появился в списке "Changes not staged for commit", но с припиской "modified"

![alt text](img/image-6.png)

sort.c снова в "Changes to be committed"

![alt text](img/image-7.png)

sort.c снова в "Changes not staged for commit". При вводе git commit появился новый коммит

![alt text](img/image-8.png)

Запушил

![alt text](img/image-9.png)

Создал новую ветку и переключился на неё. git status показывает в начале, что я нахожусь на другой ветке

![alt text](img/image-10.png)

Проверил, что нахожусь на ветке mybranch. Создал файл file1_Vlad.txt и закоммитил его. Проверил, что ветка указывает на новый коммит

![alt text](img/image-11.png)

Переключился на основную ветку. Исчез коммит, который был в другой ветке

![alt text](img/image-12.png)

Создал файл file2.txt и закоммитил его. Посмотрел, что ветки теперь две

![alt text](img/image-13.png)

Переключился на другую ветку. Файл file2.txt пропал и его коммит тоже

![alt text](img/image-14.png)






Показывает, что изменилось в коде.  git diff --staged пустой. После add стало наоборот

![alt text](img/image-15.png)

git diff показывает изменения в коде, которые я сделал сейчас, а git diff --staged показывает изменения в коде, которые были сделаны в прошлый раз

![alt text](img/image-16.png)

после того, как мы добавили строку printf(“hello git\n”) git status просто показывает, что sort.c 'Changes not staged for commit', после  git restore sort.c sort.c исчез

![alt text](img/image-17.png)

Создал новый файл на ветке main и закоммитил его

![alt text](img/image-18.png)

Создал новую ветку. В git status ничего необычного

![alt text](img/image-19.png)

Когда изменил текст, закоммитил его при использовании git log --oneline --graph --all появилась новая ветка

![alt text](img/image-20.png)

Переключился на main. Команда cat выдала приветствие в нижнем регистре

![alt text](img/image-21.png)

Из-за различной информации в одной и той же строке возник конфликт

![alt text](img/image-22.png)

Удалил ветку

![alt text](img/image-23.png)

Смержил main и mybranch

![alt text](img/image-24.png)