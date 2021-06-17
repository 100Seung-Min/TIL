from bs4 import BeautifulSoup
from urllib.request import urlopen
with urlopen('https://search.musinsa.com/ranking/keyword') as response:
    soup = BeautifulSoup(response, 'html.parser')
    for anchor in soup.select('p.p_srank'):
        print(anchor.get_text())