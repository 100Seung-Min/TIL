from konlpy.tag import Kkma

kkma = Kkma()

text = "아버지가 방에 들어갑니다."

# 형태소 단위로 토크 나이징함
morphs = kkma.morphs(text)
print(morphs)

# 품사를 붙여줌
pos = kkma.pos(text)
print(pos)

# 품사가 명사인 것만 출력
nouns = kkma.nouns(text)
print(nouns)

# 인자로 입력한 여러 문장을 분리해주는 역할
sentences = "오늘 날씨는 어때요? 내일은 덥다던데."
s = kkma.sentences(sentences)
print(s)

# 품사 태그 정리
# NNG = 일반명사
# JKS = 주격 조사
# JKM = 부사격 조사
# VV = 동사
# EFN = 평서형 종결 어미
# SF = 마침표, 물음표, 느낌표