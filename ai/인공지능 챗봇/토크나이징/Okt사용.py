from konlpy.tag import Okt

okt = Okt()

text = "아버지가 방에 들어갑니다."

# 형태소 단위로 토크 나이징함
morphs = okt.morphs(text)
print(morphs)

# 품사를 붙여줌
pos = okt.pos(text)
print(pos)

# 품사가 명사인 것만 출력
nouns = okt.nouns(text)
print(nouns)

# 문장을 정규화
normalize = okt.normalize(text)
print(normalize)

# 어구를 출력
phrases = okt.phrases(text)
print(text)

# 품사 태그 정리
# Noun = 명사
# Verb = 동사
# Adjective = 형용사
# Josa = 조사
# Punctuation = 구두점