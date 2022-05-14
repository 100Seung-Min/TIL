from konlpy.tag import Komoran

komoran = Komoran()

text = "아버지가 방에 들어갑니다."

# 형태소 단위로 토크 나이징함
morphs = komoran.morphs(text)
print(morphs)

# 품사를 붙여줌
pos = komoran.pos(text)
print(pos)

# 품사가 명사인 것만 출력
nouns = komoran.nouns(text)
print(nouns)

# 품사 태그 정리
# NNG = 일반명사
# JKS = 주격 조사
# JKB = 부사격 조사
# VV = 동사
# EFN= 종결 어미
# SF = 마침표, 물음표, 느낌표