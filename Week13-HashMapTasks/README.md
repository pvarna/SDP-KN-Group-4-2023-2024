# Хеш таблици

### Задача 1
Напишете програма, която прочита трибуквен код на международно летище от потребителя и връща неговото разположение. Данните се вземат от текстовия файл `AirportCodes.txt`, който съдържа няколко хиляди летища по света.

### Задача 2
Напишете програма, която прочита трицифрен телефонен код в САЩ и връща в кой щат е кодът и обратно, при даден щат връща кои са телефонните кодове в този щат. Данните се вземат от текстовия файл `AreaCodes.txt`.

### Задача 3
Напишере функция, която проверява дали има цикъл в едносвързан списък.

### Задача 4
Напишете програма, която може да въвежда промо кодове за онлайн магазин за храна. За вход на програмата ще получите броя на промо кодовете и след това за всеки промо-код ще получите следните данни на един ред:
`<процент-отстъпка> <промо-код> <брой-храни> [<храна-1>, <храна-2>...]`

Имената не съдържат интервали - интервали се използват за разделители между
елементите. Приемете, че входът ще е коректен.

Вашата програма трябва да може да отговаря на заявки по име на храна - кои са промо-кодовете, които може да се приложат за нея. Това трябва да стане със сложност не по-голяма от `O(K)`, където `K` е броят храни. Ако няма такива купони, изведете `no-promo`. Ще получите броя заявки и после ще се въведат толкова на брой имена на храни.

Всички числа, които се въвеждат са цели, всички имена са по къси от 30 символа и нямат празни символи в тях.

**Пример:**
```
4
5 food-promo 4 cesar-salad beef-burger fries chicken-sandwich
7 meet-promo 4 beef-burger chicken-sandwich pork-steak minced-pork
10 new-items 3 cesar-salad fries salmon-sushi
3 chicken 2 chicken-sandwich chicken-soup1

3
chicken-soup
изход> 3% chicken
beef-burger
изход> 7% meet-promo 5% food-promo
cheese-burger
изход> no-promo
```

### Задача 5
Напишете прграма, която прочита текстов файл и дава възможност за проверка колко пъти дадена дума се среща във файла
