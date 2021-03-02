### :green_apple: Binary Search Tree

---

:data:

- key : 원소의 순서를 정하기 위한 자료
- left : left_child or NULL
- right : right_child or NULL
- p : pointer to a parent node (부모를 가리키는 포인터)

---

:zap:

- key[left_SubTree(X)] < key[X] < key[right_SubTree(X)]

---

BTS에서 정렬된 순서로 출력하는 함수
InOrder (left_child_tree -> oneself -> right_child_tree)로 순회

---

:apple: search

```
TreeSearch(x , k)
    if(x == null or k == x-> key)
        return x;

    if(k <  x-> key)
        return TreeSearch(x->left , k);
    else
        return TreeSearch(x->right , k);
```

:banana: Min ~~ Max

```
TreeMaximum(x)
    while (x -> right != null)
        x = x->right;

    return x;
```

:melon: Successor(x) ~~ Predecessor

- x의 키값 보다 큰 원소중 가장 작은 키값을 찾는 함수

- right_sub_tree 존재 하면 x의 right_sub_tree 에서 가장 작은 노드

- right_sub_tree 가 없으면 x의 조상노드 이면서 그 조상 노드의 left_child가 x의 조상노드 인 경우

```
TreeSuccessor(x)
    if(x-> right != null)
        return TreeMinimum(x-> right);

    y = x->p // x의 부모

    while( y != null && y-> right == x){

        x = y;
        y = x-> p;
    }
    return y;
```

:candy: insert

```
TreeInsert(T , z)
    y = null;
    x = T.root;

    while( x != null){
        y = x;

        if(z->key < y ->key)
            x = x->left;
        else
            x = x->right;
    }

    z->p =y;

    if(y == null){ //첫노드 삽입시
        T.root = z;
    }
    else if(z-> key < y->key)
        y->left = z;
    else
        y->right = z;
```

:grapes: Delete

- x의 child가 없는 경우 (단순 제거)
- x가 1개의 child를 가지는 경우 (child를 x의 자식으로 대체)
- x가 2개의 child를 가지는 경우 (successor를 이용하여 자리를 바꾸고 case1 , case 2 적용)

```
TreeDelete(T, z)
    if(z->left == null || z->right == null)
        y = z;
    else
        y = TreeSuccessor(z);

    if(y->left != null)
        x = y->left;
    else
        x = y->right;

    if(x !=null)
        x->p = y->p;

    if(y->p == null)
        s.root = x;
    else if(y == y->p-> left)
        y->p->left = x;
    else
        y->p->right =x;

    if( y != z)
        z-> key = y->key;

    return y;
```

:peach: 시간복잡도

- 모든 함수는 트리의 높이에 따라 O(h)시간복잡도를 가진다.
- 원소의 개수가 n이면 BST 높이는 최악의 경우 (N+1)
- 위 연산의 시간복잡도는 O(N) 이다.
