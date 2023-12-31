# Двоично дърво за търсене.

### Задача 1
Добавете методи, които връщат елементите на BST в `std::vector`:
 - `inorder`
 - `preorder`
 - `postorder`

### Задача 2
Добавете метод `size`, който връща броя на елементите в BST.

### Задача 3
Добавете метод `height`, който връща височината на BST.

### Задача 4
Добавете метод `isBalanced`, който проверява дали едно BST е балансирано. Едно BST е балансирано, ако:
 - е празно
 - лявото му и дясното му поддърво са балансирани и разликата между височините на лявото и дясното поддърво е 0 или 1

### Задача 5
Добавете метод `isPerfectlyBalanced`, който проверява дали едно BST е перфектно балансирано. Едно BST е перфектно балансирано, ако:
 - е празно
 - лявото му и дясното му поддърво са перфектно балансирани и разликата между броя елементи на лявото и дясното поддърво е 0 или 1

### Задача 6
Добавете методи `min` и `max`, които намират съответно най-малкия и най-големия елемент на BST.

### Задача 7
Добавете метод `leaves`, който връща листата на BST.

### Задача 8
Добавете метод `atLevel`, приемащ естествено число `n` и връща елементите на ниво `n` в BST.

### Задача 9
Добавете метод `map`, приемащ растяща унарна функция `f` и я прилага върху всеки елемент на BST.

```c++
struct Box 
{
   int data;
   Box* left;
   Box* right;

   Box(int data, Box* left = nullptr, Box* right = nullptr) 
    : data(data), left(left), right(right) {} 
};
```

### Задача 10
Реализирайте фунцкия `Box* toTree(const int* sortedData, std::size_t size)`, която получава сортиран в нарастващ ред масив `sortedData`, съдържащ `size` на брой числа. Създава балансирано по тегло (перфектно балансирано) двоично наредено дърво, в което са записани елементите на масива. Елементите на дървото да се заделят с `new`. Връща като резултат корена на дървото. Ако на функцията се подаде празен масив, да връща като резултат `nullptr`. Сложността да бъде не повече от `O(size)`.