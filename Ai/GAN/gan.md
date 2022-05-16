# gan이란
---
1. 생성기 신경망과 판별기 신경망이라고 하는 두 신경망으로 구성된 심층 신경망 아키텍처이다.
> 1. 생성기 신경망이란?   
> 기존 데이터를 이용해 신규데이터를 생성해 내는 것
> 2. 판별기 신경망이란?   
> 진짜 데이터와 생성기 신경망이 생성한 데이터 중 진짜 데이터를 판별하는 것
2. gan의 훈련과정
> ex ) 예술품을 위조하는 과정
> 1. 첫번째 생성기 신경망이 진짜같은 예술품을 만든다.
> 2. 두번째 판별기 신경망이 식별을 한다.
> 3. 이런과정을 반복해 생성기 신경망은 계속해서 진짜같은 예술품을 만들어 낸다.
> 4. 판별기 신경망 또한 계속해서 구별하는 기준을 조정함으로써 생성기 신경망보다 앞서려고 한다.
> 5. 이러한 과정을 통해서 서로 진로를 유도하게 된다.
> 6. 궁극적으로는 판별기가 진짜와 가짜를 구분하지 못한다.
3. gan 애플리케이션
> 1. 이미지 생성   
> 표본 이미지를 가지고 훈련을 받은 뒤 이미지를 생성
> 2. 텍스트 대 이미지 합성   
> 서술된 문장으로 이미지를 생성
> 3. 얼굴노화   
> age-cGAN을 바탕으로 여러 연령대의 얼굴이미지를 생성
> 4. 이미지 대 이미지 변환   
> 이미지를 원하는 이미지로 변환하는 것
> 5. 비디오 합성   
> GAN으로 비디오를 생성해내는 것
> 6. 고해상도 이미지 생성   
> 고해상도 이미지로 바꾸는 것
> 7. 이미지 결함 보정   
> 결함이 있는 이미지를 복원