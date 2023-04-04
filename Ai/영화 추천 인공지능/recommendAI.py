import numpy as np
import pandas as pd
import json

# 장르 가중치
GENRE_WEIGHT = 0.1

# 영화 장르 추출 함수
def parse_genres(genres_str):
    genres = json.loads(genres_str.replace('\'', '"'))

    genres_list = []
    for g in genres:
        genres_list.append(g['name'])
    
    return genres_list

# 피어슨 상관계수 구하기
def pearsonR(s1, s2):
    s1_c = s1 - s1.mean()
    s2_c = s2 - s2.mean()
    if np.sqrt(np.sum(s1_c ** 2) * np.sum(s2_c ** 2)) == 0:
        return 0
    return np.sum(s1_c * s2_c) / np.sqrt(np.sum(s1_c ** 2) * np.sum(s2_c ** 2))


# 추천 알고리즘
def recommend(input_movie, matrix, n, similar_genre=True):
    if meta[meta['original_title'] == input_movie].size == 0: return []
    input_genres = meta[meta['original_title'] == input_movie]['genres'].iloc(0)[0]

    result = []
    for title in matrix.columns:
        if title == input_movie:
            continue

        cor = pearsonR(matrix[input_movie], matrix[title])

        if similar_genre and len(input_genres) > 0:
            temp_genres =  meta[meta['original_title'] == title]['genres'].iloc(0)[0]

            same_count = np.sum(np.isin(input_genres, temp_genres))
            cor += (GENRE_WEIGHT * same_count)

        if np.isnan(cor):
            continue
        else:
            result.append((title, '{:.2f}'.format(cor), temp_genres))
    
    result.sort(key=lambda r:r[1], reverse=True)
    return result[:n]

def callAi(movieName):
    # pd.DataFrame(recommend_result, columns=['Title', 'Correlation', 'Genre'])
    recommend_result = recommend(movieName, matrix, 10, similar_genre=True)
    json_result = []
    if len(recommend_result) < 1 : json_result
    for data in recommend_result:
        json_data = {}
        json_data['Title'] = data[0]
        json_data['Correlation'] = data[1]
        json_data['Genre'] = data[2]
        json_result.append(json_data)
    return json_result


# 데이터 불러오기
meta = pd.read_csv('movies_metadata.csv', low_memory=False)
ratings = pd.read_csv('ratings_small.csv', low_memory=False)

# 영화 데이터 가공
meta = meta[['id', 'original_title', 'original_language', 'genres']]
meta = meta.rename(columns={'id':'movieId'})
meta = meta[meta['original_language'] == 'en']

ratings = ratings[['userId', 'movieId', 'rating']]

# 데이터 통계보기
# print(meta.describe())
# print(ratings.describe())

# id numeric타입으로 변경
meta.movieId = pd.to_numeric(meta.movieId, errors='coerce')
ratings.movieId = pd.to_numeric(ratings.movieId, errors='coerce')

# 장르 구분
meta['genres'] = meta['genres'].apply(parse_genres)

# 데이터 합치기
data = pd.merge(ratings, meta, on='movieId', how='inner')

# 피벗 테이블 만들기
matrix = data.pivot_table(index='userId', columns='original_title', values='rating')