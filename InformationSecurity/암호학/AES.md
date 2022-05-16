## AES
### AES (Advanced Encryption Standard)
---
#### SPN (Substitution Permutation Network)
곱 암호의 일종으로, S-BOX를 사용하는 치환과 P-BOX를 사용하는 순열을 여러 라운드에 걸쳐 반복한다. 페이스텔 구조와 달리 라운드마다 입력 전체에 라운드 함수를 적용해서, 같은 수의 라운드를 사용할 때 페이스텔보다 두 배의 암호학적 안전성을 갖는다.
#### AES 구조
라운드마다 128비트 크기의 블록을 암호화하는 암호 블록이다. 키의 길이는 128, 192, 256비트 중 선택할 수 있고, 라운드의 수는 키의 길이에 따라 10, 12, 14로 결정된다. 암호화를 할 때, 가장 먼저 각 블록을 4행 4열의 **State**(상태 배열)로 재구성한다. State의 각 칸에는 8비트가 저장된다. 이후에는 재구성된 입력에 **AddRoundKey**함수를 적용하고, 마지막 라운드 전까지 매 라운드마다 **SubBytes**, **ShiftRows**, **MixColumns**, **AddRoundKey**함수를 반복해서 적용한다. 마지막 라운드에서는 MixColumns를 제외한 나머지 함수를 적용한다. 역함수가 존재하므로, 역함수를 이용하여 복호화가 이루어진다.
#### AES 라운드 함수
* SubBytes
State의 각 바이트를 S-BOX를 참조하여 치환하는 함수이다. 바이트의 상위 4비트가 행, 하위 4비트가 열을 결정한다. 

![이미지](https://kr.object.ncloudstorage.com/dreamhack-content/page/5010c36777dfdcab396c3087f4507dfc27be42879d68415ac9557118a185fa62.png)

* ShiftRows
State의 각 행을 구성하는 바이트들을 쉬프트하는 함수이다. 4함수 중 유일하게 순열의 역할을 수행한다.
* MixColums
열 단위로 치환을 수행하는 함수이다. 갈루아 필드 내에서의 행렬연산으로 구해진다.
* AddRoundKey
**Key Schedule**(키 생성 함수)로 생성된 라운드 키의 state를 각 바이트 별로 XOR한다. 복호화할때는 동일한 키를 XOR한다.
* Key Schedule
입력된 키로부터 각 라운드에 쓰일 라운드 키를 생성한다. 
  * RotWord
  열을 위로 한 번 회전시킨다.
  * SubWord
  S-BOX를 사용하여 각 바이트를 취환한다.
  * Rcon
  하나의 R을 정하여 R중 임의의 값과 XOR한다.