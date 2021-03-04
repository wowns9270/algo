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
