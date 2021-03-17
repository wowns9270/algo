### :apple: Range Tree

- 직선상의 n개의 실수가 주어지고 폐구간 [x, y]에 포함되는 모든 원소에 관해 계산하는 문제.

1. 모든 점을 reporting 하는 문제
2. 점의 개수 만을 계산하는 문제

- insert , delete , query 등을 효율적으로 처리하는 자료구조

---

![image](https://user-images.githubusercontent.com/46587806/111421564-90a75f00-8730-11eb-95a4-7bf48c0ef715.png)

---

range [l , r] 의 모든 점들을 구하기 위해서는

1. l , r 을 각각 최종적으로 도달한 단말노드를 t_l , t_r라고 한다.

2. l , r 을 하면서 처음으로 갈라지는 노드를 v_split이라고 한다.

3. v_split에서 t_l노드를 향해 갈 때 왼쪽으로 내려갈 경우
   오른쪽 서브트리의 단말노드를 모두 report 한다.

4. v_split에서 t_r노드를 향해 갈 때 오른쪽으로 내려갈 경우
   왼쪽 서브트리의 단말노드를 모두 report 한다.

![image](https://user-images.githubusercontent.com/46587806/111422706-71113600-8732-11eb-83d1-1b1b60f14ac4.png)

### :orange: Range Counting Query

- 개수를 빠르게 구하는 트리

![image](https://user-images.githubusercontent.com/46587806/111423124-280db180-8733-11eb-99d4-5e0edd11517d.png)

이렇게 하면 range tree는 쿼리를 구하는데
O(log n + k) 이고 range counting tree는 O(log n)
여기서 k 는 원소를 report 하는데 걸리는 시간.

---

### :note: 2차원 range tree

- 2차원 평면 상의 주어진 범위에서의 점을 구하는 문제
- 점이 동적으로 insert delete 될 수 있다.

![image](https://user-images.githubusercontent.com/46587806/111423571-db76a600-8733-11eb-9a28-37f1bc3aeb50.png)

- x를 기준으로 1차원 range tree를 만든 다음 각 노드마다
  y를 루트로 하는 range tree를 구성한다.

![image](https://user-images.githubusercontent.com/46587806/111424413-12998700-8735-11eb-8db8-7f49ed7083d5.png)

---

![image](https://user-images.githubusercontent.com/46587806/111424728-7fad1c80-8735-11eb-8533-f2b81e3d0766.png)
