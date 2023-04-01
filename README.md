# sorting with multiple fields
여러 개의 필드가 존재할 때, 선택된 필드를 기준으로 입력받은 파일을 정렬하여 새로운 파일로 작성하기

## 입력
입력은 세가지 요소로 이루어져 있다.
- 정렬할 줄의 개수*
- 필드의 정의
  + **정렬 기준이 될 필드는 \* 이 포함되어 있음**
- 정렬할 줄의 정보들

## 입력 예시
hw1_input.txt

> 3 <br>
> $ <br>
> Field1*:Field2:Field3 <br>
> $ <br>
> 3:A:Z <br>
> 2:B:X <br>
> 1:C:Y <br>

## 출력
선택된 필드를 기준으로 정렬한 결과

## 출력 예시
hw1_output.txt
> 1:C:Y <br>
> 2:B:X <br>
> 3:A:Z <br>
