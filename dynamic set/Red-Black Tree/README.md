### :green_apple: Red-Black Tree

- 연산의 속도가 O(log n)이 되도록 균형 있게 만들어진 tree

- BST의 성질을 만족한다.
- 트리의 각 노드는 Red or Black 중 한가지 색을 가진다.
- null로 표시된 노드는 Black 색을 가진다.
- 어떤 노드가 Red 이면 노드의 두 Child는 black 이다.
- 어떤 노드로부터 이 노드의 모든 단말노드 까지의 경로는 모두 같은 개수의 Black 노드를 가진다.
- 루트는 black 이다.

---

:grape: Rotation

leftRotate(9)

![image](https://user-images.githubusercontent.com/46587806/109628197-d1767400-7b85-11eb-8130-6a39759ea5bd.png) => ![image](https://user-images.githubusercontent.com/46587806/109628324-f834aa80-7b85-11eb-8e79-6d0e8a7fe9ad.png)

---

:doughnut: insertion

- x를 삽입하고 x의 색을 red로둔다.

- x의 부모가 red인 트리를 조정해야 한다.

- case 1 x의 부모와 형제노드가 레드인 경우
  (부모와 형제를 black 할아버지를 red로 변경 => 할아버지는 새로운 x)

- case 2 x의 부모의 형제노드가 black이고 x가 부모의 오른쪽 자식인경우 leftRotate() 후에 case 3

- case 3 x의 부모의 형제노드가 black이고 x가 부모노드의 왼쪽 자식인 경우
  (x의 할아버지에서 rightRotate() 후에 노드의 색을 바꾼다.)

---

:apple: 예시
![Red-Black tree lotation](https://user-images.githubusercontent.com/46587806/109907527-ce929500-7ce5-11eb-9db5-84ffe0b760ea.jpg)

---

### :apple: 레드블랙 삭제

- 기본적으로 BST에서 노드를 제거하는 방법과 동일하다.

- 제거된 노드가 red인 경우에는 RBT의 모든 성질을 만족한다.

- 제거된 노드가 black인 경우에는 RBT의 리프까지 블랙노드의 개수가 같다는 성질을 만족하지 못하므로 RBT를 회전시켜 tree의 구조를 변경한다.

여기서 제거될 노드를 y라고 하고 x가 y의 자식이라고 하면,

1. x 가 red 경우 -> x를 black으로 변경후 종료
2. x 가 black 경우 -> x가 2중 black을 가진다 (이 경우 x부터 root 사이의 경로에 존재하는 red 색의 노드를 이전 시켜서 x를 기본 black으로 바꾸어 만족하게 해야한다. )

지금부터는 더블블랙을 가진 x가 여러 상황에 RBT를 만족하기 위한 방법을 설명한다.

1. x의 형제노드 w의 색이 red인 경우 (x의 부모는 black)

```
w를 black으로, x의 부모를 red로 바꾼 다음 w를 기준으로 leftRotate()를 수행한 후 x의 형제노드를
new w 라고 설정한다.
```

![image](https://user-images.githubusercontent.com/46587806/110324973-1143cc80-805a-11eb-8e54-b19e45cf0332.png)

2. x가 더블블랙이고 w의 left, right child 모두 black인 경우

```
w의 색을 red로 바꾸고 x가 가지고 있던 여분의 black을 x의 부모노드로 옮긴다.
```

![image](https://user-images.githubusercontent.com/46587806/110325281-78618100-805a-11eb-9fa9-160ef6bb7d16.png)

이경우 B(x의 부모) 노드가 어떤 색을 가지는지에 따라 두가지 경우가 발생한다.

2-1. B가 red인 경우

```
더블블랙인 x를 하나 B로 주어 B의 색깔을 black으로 바꾼다.
```

![image](https://user-images.githubusercontent.com/46587806/110325720-03db1200-805b-11eb-8dbb-802275cf5612.png)

2-2. B가 black인 경우

```
B가 x로부터 블랙하나를 전달 받아 더블블랙이되고 B를 x로 두고 계속 loop를 수행
```

3과 4는 w의 색이 black이며 w의 자식노드중 적어도 한개의 자식노드가 red인 경우를 처리한다.

3. w의 오른쪽 child가 black인 경우 (왼쪽 child는 red이다.)

```
왼족 자식으로 rightRotate()를 한 후에 x의 형제를 black 그 right child를 red로 변경한다.
```

![image](https://user-images.githubusercontent.com/46587806/110327136-ef981480-805c-11eb-9d2c-ae8493f64452.png)

4. w의 오른족 child가 red인 경우 (왼쪽 child는 red or black 일 수 있다.)

```
x의 부모를 중심으로 왼쪽회전한 후, x가 가지고 있던 여분의 black을 위로 전달
```

![image](https://user-images.githubusercontent.com/46587806/110327078-d8f1bd80-805c-11eb-8d7b-00c24a55e004.png)
