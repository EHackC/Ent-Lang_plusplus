# 둣-랭++

# 설명
[https://replit.com/@parkbird/dus-raeng](https://replit.com/@parkbird/dus-raeng) 이거보고 만들었습니다.

# 만든 이유
c++ 공부, 재미있겠당 헤헤ㅔ헤ㅔ헤헤헤

# 사용법
cmd에서 `elpp 파일이름.elpp`
## replit
test.elpp입력

# 문법

## 숫자
미구현

`.` - 하나당 +1

`,` - 하나당 -1

### 예시
`....` : 4

`,,,` : -3

`..,,,` : -1

## 연산
미구현

`~` - 곱하기

`-` - 나누기

`&` - AND

`|` - OR

`^` - XOR

### 예시
`...~....` : 3*4

`,,,,,,-..` : (-6)/2

`....|.` : 4|1

`.....&.` : 5&1

`.....^..` : 5^2

## 변수
미구현

`(에)엔트리`로 변수를 불러올수 있고 변수 번호만큼 `에`를 추가하면 됨니다.

`엔트리!<값>`

### 예시
`엔트리!.` : 첫번째 변수에 1을 저장

`엔트리!에엔트리에에엔트리` : 첫번째 변수에 두번째 변수+세번째 변수을 저장

## 조건문
미구현

`?`로 조건문을 만들수 있고 ?왼쪽의 값이 1이상이면 오른쪽에 있는 코드를 실행합니다

### 예시
`엔트리?에엔트리!...` : 만약 첫번째 변수가 0보다 크면 두번째 변수에 3을 저장

## 점프
미구현

`우리는 무엇이든 될수있어요 <점>`를 적고 점프 번호에 따라 맨 뒤에 `.`을 추가하면 됨니다

`커뮤니티 <점>`으로 점프를 할수 있습니다. 점프할 위치는 번호에 따라 맨 뒤에 `.`을 추가하면 됨니다.

### 예시
```
우리는 무엇이든 될수 있어요.
커뮤니티.
```
무한루프

## 함수
미구현

```
소프트웨어 교육의 첫걸음 <이름>
```
함수 이름은 `둣교`로만 지정할수 있고 함수 번호에 따라 맨 앞에 `두`를 붙이면 됨니다

### 예시
`소프트웨어 교육의 첫걸음 둣교` : main 함수
`소프트웨어 교육의 첫걸음 두둣교` : 1번 함수
`소프트웨어 교육의 첫걸음 두두둣교` : 2번 함수

## 리턴
미구현

`탈트리 <값>`으로 리턴을 할수 있습니다.

### 예시
`탈트리 ...` : 3을 리턴함
`탈트리 에엔트리` : 두번째 변수의 내용을 리턴함

# 라이선스
[MIT License](https://opensource.org/licenses/MIT)를 사용하고 있습니다.

Copyright (c) 2023 EHackC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
