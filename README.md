# 알고리즘 정복하기

* 좋은 개발자가 되기 위해 하루동안 학습한 알고리즘 내용이나 경험들을 기록을 통해 남긴다.
* 다양한 알고리즘을 통해서 탄탄한 기본기를 갖추는 것이 목표이다.
* 여기서의 내용은 알고리즘이여도 되고, 알고리즘을 풀 때 사용한 함수나 문법의 경험, 자료구조도 작성한다.
* 지금은 못하더라도 조급해지지 않고 꾸준히 열심히 하자!

작성하게 된 계기는 [namjunemy](https://github.com/namjunemy/TIL)의 Github를 보고 나도 작성하기로 했다.

# 다짐
* 중요한 것은 모르는 부분을 찾고자 할 때, 추가적인 검색의 비용이 들지 않도록 자세히 기록한다.
* 참고한 자료는 꼭 출처를 남기자.
* 어려워도 포기하지 말고 해보자.

# Algorithm
유한한 단계를 통해 문제를 해결하기 위한 절차나 방법을 말한다. <br>
`슈도코드` 의사코드로 흉내낸 코드 <br>
`순서도` 프로그램이나 작업의 진행흐름을 순서에 따라 여러가지 기호나 문자로 나타낸 지표

**성능 분석** <br><br>
1. `정확성` 얼마나 정확하게 동작하는가?
2. `작업량` 얼마나 적은 연산으로 원하는 결과를 얻어내는가?
3. `메모리사용량` 얼마나 적은 메모리를 사용하는가?
4. `단순성` 얼마나 단순한가?
5. `최적성` 더 이상 개선할 여지 없이 최적화되어있는가?

`시간 복잡도(TimeComplex)` 실제 걸리는 시간을 측정의 지표, 빅-오 표기법 사용 <br>
시간 복잡도를 계산할 때 가장 큰 영향력을 주는 `N`에 대한 항만을 표시한다.

![TimeComplex](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F260F4850559AB6672C45F1) <br>
출처: https://ledgku.tistory.com/33

`공간 복잡도(SpaceComplex)` 얼마나 메모리를 사용했는지에 대한 지표

## 1. 패턴 매칭 알고리즘
본문이 되는 string에서 특정한 string을 찾는 알고리즘 <br>
### 1.1. 무식한 방법(Brute Force)
본문 string을 처음부터 끝까지 차례대로 순회하면서 패턴 내의 문자들을 일일이 비교하면서 확인한다. <br>
본문의 string 길이가 M이고, 찾아야 할 패턴 string 길이가 N이면 <br>
최악의 시간 복잡도는 모든 위치에서 패턴을 비교해야하므로 `O(MN)`이 된다.
### 1.2. KMP 알고리즘
불일치가 발생한 텍스트 string 앞 부분에 어떤 문자가 있었는지 미리 알고 있으므로 불일치가 발생한 앞 부분에 대하여 다시 비교하지 않고 넘어간다. <br>

        0 1 2 3 4 5 6 7 8 9 
    T[] a b c d a b c d f f
    P[] a b c d a b c e f
    
    인덱스 7에서 서로 매칭이 맞지 않기 때문에, 틀린 부분의 앞 부분에서 a b c 가 같음을 이용해서 다시 비교한다.
    
        0 1 2 3 4 5 6 7 8 9 
    T[] a b c d a b c d f f
    P[]         a b c d a b c e f (-> shift됨)
    
### 1.3. 보이어-무어 알고리즘
오른쪽에서 왼쪽으로 비교하는 생각의 전환 <br>
대부분의 상용 소프트웨어에서 채택하고 있는 알고리즘이라고 한다. <br><br>

패턴에 오른쪽 끝에 있는 문자가 불일치하고, 이 문자가 패턴 내에 존재하지 않는 경우 이동거리는 패턴의 길이 만큼 된다.
    
        0 1 2 3 4 5 6 7 8 9
    T[] f d y z w a p p l e
    P[] a p p l e
    
    이 경우 아래와 같이 점프한다.
    
        0 1 2 3 4 5 6 7 8 9
    T[] f d y z w a p p l e
    P[]           a p p l e (패턴의 길이 만큼 이동)
    
패턴에 오른쪽 끝에 있는 문자가 불일치하고, 이 문자가 패턴 내에 존재하는 경우

        0 1 2 3 4 5 6 7 8 9
    T[] f d y w a p p l e l
    P[] a p p l e
    
    이 경우 아래와 같이 점프한다.
    
        0 1 2 3 4 5 6 7 8 9
    T[] f d y w a p p l e l
    P[]         a p p l e
    
    이렇게 점프한 뒤 인덱스 8부터 시작해서 4까지 하나씩 문자를 비교해서 맞는지 확인한다.
### 1.4. 카프-라빈 알고리즘

### 1.5. string 매칭 알고리즘 비교 표
찾고자 하는 string 패턴의 길이를 `M`, 총 string 길이를 `N`이라고 하면 <br>

알고리즘 종류 | 시간 복잡도
---|---
`Bruteforce` | O(MN)
`카프-라빈` | O(N)
`KMP` | O(N)
`보이어-무어` | O(N)보다 빠름, 단 최악의 경우 O(MN)
    
## 2. Stack
물건을 쌓아 올리듯 자료를 쌓아 올린 형태의 자료구조 <br>
Stack에 저장된 자료는 `선형구조`를 가진다. <br>
가장 마지막에 들어간 자료가 가장 먼저 나오는 `후입선출(LIFO)`특징을 지닌다.

### 2.1. 구현
스택에 저장되는 자료구조의 형태는 자료를 선형으로 저장해야 한다. <br>
가장 간단한 방법은 `배열`을 이용하여 구현한다. <br><br>

**배열을 이용한 구현** <br><br>
구현하기는 쉬우나, Stack의 크기를 변경하기 어렵다. (배열은 정적이기 때문에) <br><br>

**연결리스트를 이용한 구현** <br><br>
배열에서의 정적의 문제를 해결할 수 있도록 저장의 크기를 동적으로 할당하여 구현한다. <br>
다만, 배열의 구현에 비해서 구현이 복잡하다. (버그가 일어날 가능성이 있다!) <br>

### 2.2. 필요한 연산
연산 | 기능
--- | ---
`push`    |스택에 자료를 넣는 연산이다.
`pop`     |스택에 자료를 빼는 연산이다. 여기서 뺄 때, 해당 자료를 스택에서 삭제한다.
`isEmpty` |스택이 현재 비어있는지를 확인해주는 연산이다.
`size`    |현재 스택에 몇 개의 요소들이 저장되어있는지 알려주는 연산이다.
`peek`    |스택에 `top`에 있는 원소가 무엇인지 알려준다. `pop`과 다른 점은 top의 원소를 알려주되, 삭제를 하지 않는다는 것이다.

* 스택의 push와 pop을 하는 과정

![stack](https://images.velog.io/post-images/ollabu3/9c1b6840-2a7a-11ea-b060-3102f9b60d17/%EC%8A%A4%ED%83%9DIMG.PNG) <br>
출처: https://velog.io/@ollabu3/codestates-immersive-TIL-2

* push의 슈도코드

```cpp
push(s, x)
{
   top <- top + 1;
   if(top > stack_size) then
        overflow;
   else
        s[top] <- x;
}
end push()
```

* pop의 슈도코드

```cpp
pop(s)
{
   if(top == 0) 
        then underflow;
   else
   {
        return s[top];
        top <- top - 1;
   }
}
end pop()
```

### 2.3. Stack의 응용
#### 2.3.1. 괄호검사
  - 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야한다.
  - 괄호의 종류는 `()` `{}` `[]` 가 있다.
  - 괄호의 짝을 검사할 때 `Stack`을 이용할 수 있다.
  - 동작 방식은 문자열에 있는 괄호를 차례대로 하나씩 확인하면서, 여는 괄호이면 stack에 push한다.
  - 닫는 괄호이면 stack의 top에 있는 괄호와 비교해서 맞으면 pop한다.
  - pop을 할 때 이미 stack이 비어있거나, 괄호의 짝이 맞지 않거나, pop을 한 후에 문자열이 끝나게 되고 stack에 남아있다면 실패한다.

#### 2.3.2. 함수호출
  - 가장 마지막에 호출된 함수가 가장 먼저 실행을 완료하고 복귀하는 후입선출 구조이므로 이를 `stack`을 이용해서 수행순서를 관리한다.
  - 함수 호출이 발생하면 호출할 함수 수행에 필요한 `지역변수`, `매개변수` 및 수행후 복귀할 `복귀주소`의 정보를 stack 프레임에 저장한다.
  - 함수의 실행이 끝나게 되면 시스템 stack의 top 원소를 pop하면서 stack 프레임에 저장되어있던 복귀주소를 확인하고 복귀한다.
  - 함수 호출과 복귀에 따라 이 과정을 반복하면서 전체 프로그램 수행이 종료되면 시스템 stack은 공백상태가 된다.

#### 2.3.3. 재귀호출
  - 자기 자신을 호출하여 순환 수행된다.
  - 일반적으로 재귀호출을 이용해서 구현하면 가독성이 높아지며, 프로그램의 크기가 줄어들게 된다.
  - 다만, 디버깅이 어려우며 잘못 작성하게 되면 수행 시간이 많이 소요된다. (깊이가 깊어지게 되면 `stack overflow`가 발생한다.)
  - 재귀호출의 대표적인 것은 `factorial`구현이다.

#### 2.3.4. Memoization
  - 일반적으로 `피보나치 수열`을 구현할 때, 재귀호출을 이용해서 구현할 수 있다. (다만, 중복 호출이라는 문제점이 생기게 된다.)
  
  ```cpp
  fibo(n)
  {
        if(n == 0) then return 0;
        if(n == 1) then return 1;
        else return fibo(n-1) + fibo(n-2);
  }
  end fibo()
  ```
  
  - 위 코드의 문제점은 함수를 한 번 호출할 때마다, 내부적으로 2번의 함수를 호출한다.
  - 이는 호출의 깊이가 깊어질수록 중복 호출이 발생하게 된다.
  ![fibonacci](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Recursions/pix/fib.bmp) <br>
  출처 : http://1ambda.github.io/data-analysis/intro-to-data-science-3/ <br>
  - 한 번 호출할 때마다, 내부적으로 2번을 하므로 결국 시간복잡도는 `O(2^N)`이 되게 된다.
  - 이를 해결하기 위한 solution은 `Memoization`이다.
  
  - Memoization의 핵심은 한 번 구한 답은 메모해놓고, 다시 계산하지 않도록 전체적인 실행속도를 빠르게 하는 기술이다.
  - 이는 DP(동적계획법)에서 쓰이는 테크닉이다.
  - Memoization을 이용해 다시 피보나치 수열을 구현하면 아래와 같다.
  
  ```cpp
  memset(memo, -1, sizeof(memo));
  memo[0] = 0, memo[1] = 1;
  fibo(n)
  {
        if(memo[n] == -1)
                memo[n] = fibo(n-1) + fibo(n-2);
        else
                return memo[n];
  }
  ```
   - 이처럼 기존에 계산하여 저장된 값이 있는 경우에는 다시 계산하지 않고 저장된 메모리에서 값을 찾아 쓰기만 하면 된다.

#### 2.3.5. DFS(깊이우선탐색)
   - 그래프 알고리즘 중 하나이다.
   - 이 알고리즘에서 `stack`은 현재 정점에서 다음 정점으로 갈 곳이 없다면, 기존으로 돌아가기위해 기록하는 역할을 한다.
   - 동작 방식은 다음과 같다.
   - 시작 정점의 한 방향으로 갈 수 있는 경로가 있는 곳까지 깊이 있게 탐색한다.
   - 더 이상 갈 곳이 없게 되면, 가장 마지막에 왔던 길로 되돌아간다. (스택을 사용하는 이유)
   - 다른 방향의 정점으로 탐색을 계속 반복하여 결국 모든 정점을 방문하는 원리이다.
   - 더 자세한 내용은 따로 분류해서 작성한다.

#### 2.3.6. 계산식 사용
`중위 표기식`을 `후위 표기식`으로 변환하는 방법
1. 입력받은 중위표기식에서 `token`을 읽는다.
2. 토큰이 피연산자이면 토큰을 출력한다.
3. 토큰이 연산자(괄호포함)일 경우
	- 우선순위가 높으면 `stack`에 `push`한다.
	- 우선순위가 높지않으면 `token`의 우선순위보다 작을 때까지 `stack`에서 `pop`한 후에 `token`의 연산자를 `push`한다.
4. 토큰이 오른쪽 괄호`)`일 경우
	- `stack`의 `top`에 있는 `(`가 나올 때까지 스택에서 `pop`연산을 수행한다.
	- 여기서 `pop`한 연산자들은 출력하고, `(`를 만나면 `pop`하고 출력하지 않는다. (괄호는 무마하는 방식)
5. 중위표기식에 더 이상 읽을 문자열이 없다면 종료하고, 아니라면 1 ~ 4단계를 반복한다.
6. `stack`에 남아 있는 연산자를 모두 `pop`하여 출력한다.

`후위 표기식`을 `stack`을 이용하여 계산할 수 있다.
1. 피연산자를 만나면 `stack`에  `push`한다.
2. 연산자를 만나면 필요한 만큼의 피연산자를 `stack`에서 `pop`하여 연산하고, 그 연산결과를 다시 `stack`에 `push`한다.
	- 보통 `이항연산자`는 피연산자를 2개를 필요로 하므로, 뽑을 때 먼저 뽑은 것은 뒤로 그 다음 뽑은 것은 앞으로 해서 계산한다.
	- 가장 먼저 뽑은 것을 `second`, 그 다음으로 뽑은 것을 `first`라고할 때
	- `first` + `second` 형식이 되야 한다.
3. 수식이 끝나면, 마지막으로 `stack`에서 `pop`하면 그 결과가 원하는 계산의 결과를 얻을 수 있다.

#### 2.3.7. Backtracking (백트래킹)
해를 찾는 도중에 '막히면' 되돌아가서 다시 해를 찾아가는 기법이다. <br>
어떤 노드의 유망성을 검사한 후에 `유망(Promising)`하지 않다고 결정되면 그 노드의 부모로 `되돌아가(Backtracking)`다음 자식 노드로 간다. <br>
여기서 유망하지 않는 것은 어떤 노드를 방문했을 때 그 노드를 포함한 경로가 해답이 될 수 없다면 그 노드는 유망하지 않은 것이다. <br>
백트래킹을 이용해서 `Optimization(최적화)문제`와 `Decision(결정)문제`를 해결할 수 있다. <br>
* `Decision`문제들의 list
	- 미로찾기
	- N-Queen 문제
	- Map coloring
	- 부분 집합의 합(Subset Sum) 문제

**백트래킹 vs 깊이우선탐색** <br>

* 백트래킹의 특징
	- 어떤 노드에 출발하는 경로가 유망하지 않을 것 같으면 더 이상 그 경로를 가지 않는다.
	- 가치치기(Prunning)이며 불필요한 경로를 조기에 차단한다.
	- 가치치기는 유망하지 않는 노드가 포함되는 경로는 더 이상 고려하지 않는 것이다. `상태공간트리`로도 나타낸다.
	- N!가지의 경우의 수를 가진 문제에 대해서는 일반적으로 DFS보다는 경우의 수는 줄어드나 최악의 경우 지수함수 시간복잡도를 가진다.
	- 모든 후보를 검사하지 않는다.

* 깊이우선탐색의 특징
	- 모든 경로를 추척한다. (다 돌아본다는 뜻)
	- N!가지의 경우의 수를 가진 문제에 대해서는 문제를 해결할 수 없다. (지수 함수의 시간복잡도를 가지므로), 그러나 가짓수가 적으면 가능
	- 모든 후보를 검사한다.

**백트래킹의 동작 방식**
1. 상태공간트리의 깊이 우선 검색을 한다.
2. 각 노드가 유망한지를 점검한다.
3. 만일 그 노드가 유망하지 않는다면, 그 노드의 부모 노드로 백트래킹하여 검색을 계속한다.

**백트래킹을 이용한 다양한 문제들**

1. 미로찾기
	- 스택에 이동한 좌표를 push한다.
	- 막히면 스택의 top에 있는 좌표를 pop하여 되돌아와서 다음에 갈 수 있는 경로를 찾아 다시 스택에 push한다.
	- 여기서 막힌다의 뜻은 더 이상 진행할 수 없으면 진행할 수 있는 상태로 되돌아가야함을 의미한다.
	- 보통 미로찾기의 경우 상,하,좌,우 4방향으로 움직이므로 되돌아온 상태에서는 그 상태에서 아직 방문하지 않은 곳을 방문한다.

2. N-Queen 문제
	- 4 x 4 타일에서 4개의 Queen을 놓는 방법 <br>
![nQueen](https://mblogthumb-phinf.pstatic.net/MjAxOTEyMjZfNDEg/MDAxNTc3MzU4NTkzMTMz.Pf0dYJ8wZJ0UGUJGcDIip4ApUL6v9Nuz3b_YfKO_zMwg.Bvr6Qa0nYsT9ziIxCU053_3ApfMhKPQT4xSw-Ee4QJYg.PNG.do9562/image.png?type=w800) <br>

	- 아래의 두 코드는 권오흠 교수님의 제 2-3강 Recursion의 응용: N queens problem을 공부하고 작성한 방법입니다.<br>
```cpp
int cols[N+1]; // cols[i] = j : i번째 행에 j열에 Queen을 뒀다는 표시
return-type Queens(int level)
{
    if(!Promising(level))         // 유망한지 테스트
       report failure and return; // 유망하지 않다면 백트래킹
    else if (level == N)          // Queen을 N개를 뒀다면 이는 성공을 의미
       report answer and return;
    else
    {
       for(int i = 1; i <= N; i++) // level + 1 행에 1~N까지의 열에 Queen을 놓는다.
       {
           cols[level+1] = i;
           Queens(level+1);
       }
    }
    return false; // 1~N 열에 다 시도해봤지만 다 실패를 의미
}
```

```cpp
bool Promising(int level)
{
   for(int i = 1; i < level; i++)
   {
      if(cols[i] == cols[level]) // 같은 열에 있는지 검사
        return false;
      else if ((level - i) == abs(cols[level] - cols[i])) // 대각선 검사
        return false;
   }
   return true; // 같은 열에도 없고, 대각선에도 걸리지 않는 다면 제대로 Queen을 둔 것이다.
}
```
3. Power Set 문제
	- 어떤 집합의 공집합과 자기자신을 포함한 모든 부분집합을 구하는 문제
	- 구하고자 하는 어떤 집합의 원소 개수가 n개일 경우 부분집합의 개수는 `2^n`이 나온다.
	- 백트래킹 기법으로 Power Set을 만들 수 있다.

	- 일반적인 백트래킹 접근 방법을 이용한다.
	- `True` 또는 `False`값을 가지는 항목들로 구성된 n개의 배열을 만들어서 사용한다.
	- 배열의 i번째는 해당 i번째의 원소가 부분집합의 값인지 아닌지를 나타내는 값이다. `True`면 포함, `False`면 포함하지 않는다.
	- ex) n = 3인 경우
		- `{}`, `{1}`, `{2}`, `{3}`, `{1,2}`, `{1,3}`, `{2,3}`, `{1,2,3}` 총 8가지 이므로, 2^3 = 8이다.

**백트래킹의 주의할 점**
1. 가지치기를 많이 하지 않으면 시간초과 발생한다.
2. 유망한지를 검사할 때 비효율적으로 계산하면 시간초과가 발생한다.
3. 유망하지 않아서 백트래킹을 시도할 때, 값을 제대로 바꿔놓지 않으면 제대로 된 답을 얻을 수 없다.
4. 배열 대신 vector와 같은 STL을 사용했을 때, 함수의 인자로 참조자를 넘기지 않고 직접 넘기면 복사비용이 생겨서 시간초과가 발생할 수 있다.
    


## 3. DP (동적계획법, Dynamic Programming)
그리디 알고리즘 설계 기법과 같이 최적화 문제를 해결하는 알고리즘 설계기법이다. <br><br>
입력의 크기가 작은 부분 문제들을 모두 해결한 후에 그 해들을 이용해서 보다 큰 크기의 부분 문제들을 해결하여 결국에 최종적으로 구해야하는 문제를 해결하는 기법이다. <br><br>

핵심은 풀었던 답을 이용해서 더 큰 문제를 해결하는 기법이다. <br>

### 3.1. Overlapping Subproblem
**`중복되는 부분문제`여야 한다.** <br>
피보나치 수열에서의 중복되는 부분문제는 다음과 같다.<br>

    fibo(5) = fibo(4) + fibo(3)
    fibo(4) = fibo(3) + fibo(2)
    fibo(3) = fibo(2) + fibo(1)
    fibo(2) = fibo(1) + fibo(0)
 
### 3.2. Optimal Substructure
**문제의 정답을 작은 문제의 정답에서 구할 수 있다.** <br>
기존에 `fibo(3)`과 `fibo(2)`를 구했으면 `fibo(4)`를 구할 때 이용할 수 있다. <br>
여기에서 사용하는 테크닉은 `Memoization`이다. <br>
한 번 구한 답은 다시 구할 필요가 없으며, 구한 답을 이용해서 문제를 해결하는 기술이다. <br>

### 3.3. DP 구현방식
`Top-down`과 `bottom-up`방식이 있다.

### 3.3.1 Top-down
`stack`이나 `recursive`방식을 이용해서 구현한다. <br>
다만 문제는, 깊이가 깊어지게 되면 `overflow`가 발생할 수 있다. <br>

* 기존에 문제가 되었던 피보나치 수열을 재귀로 푼 방식

```cpp
#include <stdio.h>

int fibo(int n) {
	if (n == 1) return 1; //fibo(1)
	if (n == 2) return 2; //fibo(2)
	return fibo(n - 1) + fibo(n - 2); //fibo(3)이상
}

int main() {
	printf("%d\n", fibo(5));
	return 0;
}
```

* Memoization 기법을 이용해서 조금 더 효율적으로 작성한 방식

```cpp
#include <stdio.h>

int memo[100]; //푼 답을 저장할 공간

int fibo(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
    /* 이미 문제를 푼 답이 있다면? */
	if (memo[n] > 0) return memo[n];
    /* 처음 보는 문제이면 */ 
	else {
		memo[n] = fibo(n - 1) + fibo(n - 2);
		return memo[n];
	}
}

int main() {
	printf("%d\n", fibo(45)); //아까는 fibo(5)를 구했지만, fibo(45)도 구할 수 있다.
	return 0;
}
```
이렇게 구현함으로써 얻을 수 있는 성능의 이점은 다음과 같다. <br>
기존에 함수를 한 번 호출하면 2번이 호출되어 시간복잡도 `O(2^N)`이였다면, Memoization을 이용하여 `O(N)`으로 단축했다.<br>

### 3.3.2. Bottom-up
재귀적으로 구현하는 것보다 반복적 구조를 이용해서 구현하면 성능면에서 보다 효율적이다.

```cpp
#include <stdio.h>

int memo[100]; //푼 답을 저장하는 공간

int fibo(int n) {
	memo[1] = 1; //fibo(1)
	memo[2] = 2; //fibo(2)
	for (int i = 3; i <= n; i++) {
		/* 차근차근 아래의 작은 문제부터 푼다.*/
		memo[i] = memo[i - 1] + memo[i - 2];
	}
	return memo[n]; //구하려고 하는 fibo(n)
}

int main() {
	printf("%d\n", fibo(45));
	return 0;
}
```

### 3.4. DP VS Divide & Conquer
DP | Divide & Conquer
---|---
문제가 -1로 줄어듬 | 문제가 절반으로 줄어듬
결과가 여러 번 사용 | 결과가 한 번 사용
결과 재사용이 성능 향상됨 | 분할이 성능 향상됨

### 3.5. DP tip
중요한 것은 `점화식`을 세워야 한다. <br>
이 점화식을 이용해서 테이블을 차곡차곡 쌓아서 나중에 더 큰 문제를 해결하는 방식이기 때문이다. <br>
또한, 점화식을 이용해서 다음의 해를 구할 수 있다. <br>
그러나 다음의 해에서 알 수 없는 것은 변수를 추가적으로 둬서 `BruteForce` 방식으로 접근하는 법도 있다. <br>

## 4. Divide & Conquer (분할 정복)
`분할(Divide)`, `정복(Conquer)`, `통합(Combine)` 각 단계를 거쳐서 문제를 해결하는 기법이다. <br><br>
`분할(Divide)`은 해결할 문제를 여러 개의 작은 문제들로 나눈다. <br>
`정복(Conquer)`은 나눈 작은 문제들을 각각 해결한다.<br>
`통합(Combine)`은 각각 작은 문제들을 해결했으니, 그 해답들을 다시 합친다. <br>

* 분할 정복의 예시
	- 합병 정렬(Merge Sort)
	- 퀵 정렬(Quick Sort)
	- 거듭 제곱(Exponentiation)

### 4.1. 거듭 제곱(Exponentiation)
일반적으로 2의 2승은 `2^2 = 2x2`를 의미한다. <br>
거듭 제곱 알고리즘을 단순하게 구현하면 다음과 같다. <br>
```cpp
int Power(int Base, int Exponent)
{
	int result = 1;
      
	if (Exponent == 0) return 1;
	if (Exponent == 1) return Base;
	if (Base == 0) return 1;

	for (int i = 0; i < Exponent; i++)
		result = result * Base;

	return result;
}
```
위의 알고리즘은 시간복잡도가 `O(N)`이 된다. Exponent에 따라서 결정되기 때문이다. <br>
이를 좀 더 빠르게 할 수 있도록 `분할 정복`기법을 이용해서 해결하면 다음과 같다. <br>
```cpp
int Power(int Base, int Exponent)
{
	if (Exponent == 0) return 1;
	if (Exponent == 1) return Base;
	if (Base == 0) return 1;
	
	if (Exponent % 2 == 0)
	{
		int temp = Power(Base, Exponent/2);
		return temp * temp;
	}
	else
	{
		int temp = Power(Base, (Exponent-1)/2);
		return temp * temp * Base;
	}
}
```
위의 알고리즘은 시간복잡도가 `O(logN)`이 된다. <br>
이유는 한 번 함수를 호출할 때, 구하려고 하는 문제가 두개씩 쪼개지기 때문이다. <br>
예를 들어서 `2^8`을 구한다고 가정하면 다음과 같다. <br>
`2^8 = 2x2x2x2x2x2x2x2` 이런식이면 8번을 곱해야지만 구할 수 있지만, <br>
`2^8 = 2^4 x 2^4 = (2^2 x 2^2) x (2^2 x 2^2) = (2x2) x (2x2) x (2x2) x (2x2)`으로 총 4번의 연산으로 구할 수 있게 된다.

## 5. 정렬 (Sorting)
컴퓨터 과학과 수학에서 정렬 알고리즘은 다음과 같이 정의한다. <br>
원소들을 번호순이나 사전 순서와 같이 일정한 순서대로 열거하는 알고리즘 기법이다. <br>

* 정렬 알고리즘 종류
	- 버블 정렬(Bubble Sort)
	- 선택 정렬(Selection Sort)
	- 삽입 정렬(Insertion Sort)
	- 병합 정렬(Merge Sort)
	- 힙 정렬(Heap Sort)
	- 퀵 정렬(Quick Sort)
	- 쉘 정렬(Shell Sort)
	-  정렬(Counting Sort)
	- 기수 정렬(Radix Sort)
	
### 5.1. 버블 정렬(Bubble Sort)
두 인접한 원소를 검사하여 정렬하는 방법이다. <br>
시간 복잡도가 상당히 느리지만, 코드가 단순해서 자주 사용된다고 한다. <br>
원소의 이동이 거품이 수면으로 올라오는 듯한 모습을 보여주기 때문에 `버블`이라고 지어졌다. <br>

* 장점
	- 구현이 쉽다.
	
* 단점
	- 굉장히 비효율적이다.
	- 최악이든 최선이든 시간복잡도 `O(N^2)`을 가진다.
	
### 5.2. 선택 정렬(Selection Sort)
제자리 정렬 알고리즘 중 하나이다. <br>
주어진 리스트 중에서 최소값을 찾고, 그 값을 맨 앞에 위치한 값과 교체한다. <br>
맨 처음 위치를 뺀 나머지 리스트를 위와 같은 방법으로 반복한다.

* 장점
	- 구현이 쉽다.
	- 많은 교환이 일어나야 하는 자료상태에서 효율적으로 사용할 수 있다.
	- 실제로 교환되는 횟수가 `버블 정렬`보다 적다.
	- 그래서, `버블 정렬`보다는 조금 더 빠른 정렬 기법이다.
* 단점
	- 역시 시간복잡도 `O(N^2)`를 가진다.
	- 데이터의 양이 많을수록 오래걸리는 알고리즘이다.
	
### 5.3. 삽입 정렬(Insertion Sort)
자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교해서, 자신의 위치를 찾아 삽입하는 정렬 기법이다. <br>
이미 `정렬된 부분`과 `정렬되지 않은 부분`으로 나뉜다. <br>

* 장점
	- Best Case의 경우에 `O(N)`이라는 시간복잡도를 가진다.
	- 성능이 좋아서 다른 정렬 알고리즘의 일부로 사용되기도 한다.
* 단점
	- Worst Case의 경우 `O(N^2)`이라는 시간복잡도를 가진다.
	- 데이터의 양에 따라서 성능의 편차가 심한 정렬 기법이다.
	
### 5.4. 병합 정렬(Merge Sort, 합병 정렬)
이 정렬은 `안정 정렬`에 속하며, `분할 정복`알고리즘 중 하나이다. <br>

* 장점
	- 주어진 배열을 반씩 분할해가면서 정렬하는 기법으로 기존 정렬보다는 훨씬 빠르다.
	- 전체 시간복잡도는 `O(NlogN)`이며, 분할하는 과정의 시간복잡도는 `O(logN)`이다.
	- `퀵 정렬`(Pivot에 따라서 성능이 달라짐)과 달리 무조건 반씩 쪼개므로 항상 `O(NlogN)`이라는 시간복잡도를 가지게 된다.
* 단점
	- 추가적인 메모리가 필요하다. (병합 정렬은 임시배열에 주어진 배열을 계속해서 옮겨주면서 정렬하므로)
	- `O(N^2)`이 걸리는 정렬 기법에 비해서 구현 복잡도가 어렵다.
	
### 5.5. 힙 정렬(Heap Sort)
최대 힙 트리나 최소 힙 트리를 구성해 정렬을 하는 방법이다. 여기에서는 `힙(Heap)` 자료구조를 기반으로 한다. <br>
`내림차순`으로 정렬을 위해서는 `Max-Heap`을 구성한다. <br>
`오름차순`으로 정렬을 위해서는 `Min-Heap`을 구성한다. <br>
`불안정 정렬`에 속한다. <br>

* 장점
	- 추가적인 메모리를 사용하지 않으면서 `O(NlogN)`이라는 시간복잡도를 가진다.
	- 효율적인 정렬 기법이다.
* 단점
	- 실제 시간으로 측정하면 `병합 정렬`과 `퀵 정렬`에 비해서 느리다고 한다.
	
* 다만 `힙(Heap)` 자체의 장점을 가지고 있다.
	- 가장 크거나 작은 값을 구할 때 유용하다.
	
### 5.6. 퀵 정렬(Quick Sort)
다른 원소와의 비교만으로 정렬을 수행하는 `비교 정렬`에 속한다. <br>
`합병 정렬`과 비슷하게 주어진 배열을 분할하고, 각각을 정렬하는 방법이다. <br>
분할할 때, `피벗(Pivot)`을 기준으로 이보다 작은 것은 왼편으로, 큰 것은 오른편에 위치시키면서 정렬한다. <br>
`피벗(Pivot)`을 설정하는 기준에 따라서 알고리즘의 성능차가 있다. <br>
가장 좋은 성능을 내는 방법은 리스트 내에서 크기순으로 `중간 값(medium)`을 피벗으로 선택하는 방법이다. <br>

* 장점
	- 속도가 빠르다. (이름부터가 퀵이다.)
	- 시간복잡도 `O(NlogN)`을 가지면서 다른 정렬 알고리즘과 비교했을 때도 가장 빠르다.
	- 추가적인 메모리 공간을 사용하지 않는다.
* 단점
	- 정렬된 리스트에 대해서는 퀵 정렬의 불균형 분할에 의해서 오히려 더 수행시간이 오래 걸린다.
	- Worst Case의 경우 시간복잡도는 `O(N^2)`을 가지게 된다.
	
출처 : https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html

### 5.7. 쉘 정렬(Shell Sort)
`삽입 정렬`을 보완한 알고리즘이다. <br>
삽입 정렬이 어느 정도 정렬된 배열에 대해서는 대단히 빠른 것을 착안하여 만든 기법이다. <br>

삽입 정렬의 문제점은 요소를 삽입할 때, 이웃한 위치로 한 칸씩만 이동한다는 점이다. <br>
쉘 정렬에서는 요소들이 멀리 떨어진 위치로 이동할 수 있다는 장점을 가진다. <br>
이런 것이 가능한 이유는 쉘 정렬은 전체의 배열을 한 번에 정렬하지 않는다는 점이다. <br><br>

먼저 정렬해야 할 배열을 일정한 기준에 따라 분류해서 연속적이지 않은 여러 개의 부분 배열을 만들고, 각 부분 배열을 삽입 정렬을 이용해서 정렬한다. <br>
실제로는 `간격(Gap)`으로 간격을 주어 부분 배열이 만들어진 것처럼 구현한다. 모든 부분 배열이 정렬이 된다면 다시 전체 배열을 더 적은 개수의 부분 배열로 만든 후에 이를 반복한다. 이러한 과정은 부분 배열의 개수가 1이 될 때까지 반복한다.


* 장점
	- `삽입 정렬`의 단점을 보완해서 만든 정렬법으로 더 뛰어난 성능을 가진다.
	- Average case의 경우 `O(N^1.5)`의 성능을 지닌다.
* 단점
	- 일정한 간격에 따라서 배열을 바라봐야 한다.
	- `간격(Gap)`을 잘못 설정하면 성능이 나뻐질 수 있다.
	- Worst case의 경우 `O(N^2)`의 성능을 지닌다.

** 구체적인 구현을 위한 개념**
1. 정렬해야 할 리스트의 각 k번째 요소를 추출해서 부분 리스트를 만든다. 이때, k를 `간격(Gap)`이라고 한다.
	- 간격의 초깃값은 `(정렬할 값의 수) / 2
	- 생성된 부분 리스트의 개수는 `gap`과 같다.
2. 각 회전마다 간격 k를 절반으로 줄인다.
	- 간격은 홀수로 하는 것이 좋다고 한다.
	- 만약에 짝수가 나오면 +1을 해서 홀수로 만든다.
3. 간격 k가 1이 될 때까지 반복한다.

![shell](https://gmlwjd9405.github.io/images/algorithm-shell-sort/shell-sort.png) <br>
출처 : https://gmlwjd9405.github.io/2018/05/08/algorithm-shell-sort.html <br>

### 5.8. 계수 정렬(Counting Sort)
작은 정수인 키에 따라 객체 모음을 정렬하는 알고리즘이다. <br>

* 장점
	- `O(N)`이라는 시간복잡도를 가지면서, 엄청나게 빠른 정렬 기법이다.
	- 조건에만 맞는다면, 기존에 `퀵 정렬`보다 더 빠른 정렬이다.
* 단점
	- 추가적인 메모리가 필요하다. 생각보다 많은 메모리를 소비한다.
	- 데이터의 양이 N이면 N의 메모리가 필요하다.
	- 안 쓰는 메모리가 존재한다. (즉, 일부 값을 위해서 메모리의 낭비가 심해진다.)

### 5.9. 기수 정렬(Radix Sort)
낮은 자리수부터 비교하여 정렬해 가는 기법이다. <br>

* 장점
	- `계수 정렬`과 같은 시간복잡도 `O(N)`을 가진다.
	- 조건에만 맞는다면, 기존에 `퀵 정렬`보다 더 빠른 정렬이다.
* 단점
	- `버킷`이라는 추가적인 메모리가 필요하다.
	- 데이터 타입이 같아야만 가능하다.
	- 구현을 위한 조건이 굉장히 많이 있으므로 많이 사용하지 않는다고 한다.

![Radix](https://t1.daumcdn.net/cfile/tistory/99792B495A6EDBD631) <br>


출처 : https://sexycoder.tistory.com/74
# C, C++
## 1. String
### 1.1. string::find 와 string::npos
`string::find` 찾는 문자열의 첫 번째 인덱스를 반환하는 함수 <br>
`string::npos` 찾는 문자열이 없는 경우에는 `string::npos`를 반환한다. <br>

```cpp
string str = "Hello World";
if(str.find("World") != string::npos)
{
  cout << "찾는 문자열이 있습니다. 해당 문자열의 시작 인덱스 번호는 << str.find("World") << "입니다. << endl;
}
else
{
  cout << "찾는 문자열이 없습니다." << endl;
}
```
### 1.2. C언어에서 string 처리
문자열을 배열 형태로 구현된 응용 자료형을 의미한다. <br>
문자배열에 string을 저장할 때는 항상 마지막에 끝을 표시하는 `\0` 문자를 넣어준다.

```c
char a1[] = {'a', 'b', 'c', '\0'};
char a2[] = "abc";
```
C언어에서는 string 처리를 위한 다양한 함수들을 제공한다. <br>
`strlen()` 문자열의 길이를 반환하는 함수 <br>
`strcpy()` 문자열을 복사하는 함수 <br>
`strcmp()` 문자열을 비교하는 함수 <br>

**string을 복사하는 알고리즘** <br><br>
src로부터 한 글자씩 읽어서 des에 한 글자씩 복사하는 방법
```c
void strcpy(char* des, char* src)
{
    while(*src != '\0')
    {
      *des = *src;
      src++;
      des++;
    }
    *des = '\0';
}
```
**string을 역순으로 바꾸는 방법** <br>
1. 자기 string을 직접 뒤집는 방법
2. 새로운 빈 string을 만들어서 소스의 뒤에서부터 읽어서 복사하는 방법

1번의 경우 `swap함수`를 위한 임시변수가 필요하고, Loop를 string의 길이의 반만큼 수행하면 된다. <br>
2번의 경우 뒤에서부터 읽는 방식이니, Loop를 string의 길이만큼 수행하면 된다. <br>

**string 비교** <br><br>
`strcmp()`함수를 이용한다.

strcmp에서 반환되는 값에 따라 다음과 같은 결과를 가진다. <br>
`0`이면 두 문자열은 서로 같은 문자열 <br> 
`-1`이면 문자열이 사전순으로 앞인 문자열 <br>
`1`이면 문자열이 사전순으로 뒤인 문자열 <br>

**string로 된 숫자를 정수로 변환하는 방법** <br><br>
C언어에서는 `atoi()` 함수가 제공된다. <br>

  
