### :apple: Splay Tree

- 기본적으로 BST이면서, AVL-TREE , RED-BLACK 과 같은 균형트리처럼 search,insert,delete 연산을
  o(log n) 시간에 처리한다.

- 특징은 균형을 이루기 위한 추가적인 정보를 필요로 하지 않는다.

- 매 연산마다 트리의 구조를 재구성한다,

- self-reconstructing, self-adjusting, self-organizing tree 로 부른다.

---

### :greenapple: 트리를 재구성하는 원칙

- 검색 혹은 삽입되는 노드가 루트가 되도록 재구성

- 삭제되는 노드에 대해서는 이 노드에 인접한 노드(부모노드)를 루트가 되도록 재구성

- 특정노드를 회전시켜 루트까지 올리는 작업을 "splaying" 이라고 함

---

기본적으로 회전은 연속적인 회전이 필요하고 조정된 트리가 균형잡힌 모양이 되지 않을 수 있다.

1. Zig step (x의 부모노드가 루트인 경우 한번 회전을 통해 x를 루트노드로 만들 수 있다.)

![image](https://user-images.githubusercontent.com/46587806/110331450-7ac7d900-8062-11eb-8069-6308bdca4368.png)

2. Zig-Zag step (x의 부모노드가 루트가 아니고 x와 x의 부모노드가 서로 다른 방향의 자식인 경우)

![image](https://user-images.githubusercontent.com/46587806/110331712-ce3a2700-8062-11eb-875b-bae05b6213ab.png)

3. Zig-Zig step (x와 x의 부모노드가 모두 같은 방향의 자식인 경우)

## ![image](https://user-images.githubusercontent.com/46587806/110331846-f590f400-8062-11eb-9317-0da8c8e73bd4.png)

---

splay 작업은 BST에 적용되는 검색, 삽입, 삭제 연산을 수행한 이후 매번 노드적용

- search (원소가 있으면 그원소를 기준으로 splay 없으면 마지막으로 접근한 노드를 기준으로 splay)

- insert (원소를 추가한 이후 그 노드를 중심으로 splay 적용)

- delete (delete 된 노드의 부모노드를 중심으로 splay 적용)

worst O(n) , 전체 연산 - O(m log n)

---

### :bulb: Dynamic Order Statistic

- k번째로 작은 데이터를 말함 -> O(n) 시간에 가능

- 균형트리에 데이터를 저장하면 O(lg n) 시간에 가능

- RBT의 추가, 제거를 통해서도 O(lg n) 시간에 가능

- 전체 데이터에서 크기가 몇 번째인지 순위를 O(lg n) 시간에 찾을 수 있다.

### :tada: Order-Statistic Tree(OST)

- Dynamic order statistic를 처리하기 위한 자료구조

- 기본적으로 RBT로 만든다.

- RBT에서 필드로 SIZE를 가진다.

- 노드 X의 SIZE = X->LEFT->SIZE + X->RIGHT->SIZE + 1

특정 순위의 원소가 무엇인지를 구하는 함수

```
OSselect(x, k)
    r = x->left->size+1;
    if( r== k)
        return x;
    else if( r > k )
        return OSselect(x->left , k);
    else
        return OSselect(x->right , k-r);

```

데이터의 순위를 구하는 함수

```
OSrank(T , x)
    r = x->left->size + 1;
    y = x;

    while(y != T.root)
        if(y == y->p->right)
            y +=y->p->right->size +1;

        y = y-> p;

    return r;

```

insert , delete 과정에서 size 계산 (보류)
