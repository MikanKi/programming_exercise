#454403 フェリシアアイヴィー

import sys

dic = {}
years = set()

with open(sys.argv[1], "r") as f:
    f.readline()                # 1行目を読み飛ばす．
    for line in f.readlines():
        (date, max_s, min_s, rests) = line.split(",") # 行をコンマで分割し，それぞれを代入する．
        (year, max, min) = (date[:4], float(max_s), float(min_s))
        (extremely_hot, hot, summer, ice, frost) = (0, 0, 0, 0, 0)
        years.add(year)      # 年を集合に追加しておく．

        # 猛暑日，真夏日，夏日，真冬日，冬日を判定する．
        # extermely_hot, hot, summer, ice, frost いずれかを1にする or 0 のままにする．
        if max >= 35:
            extremely_hot = 1
        elif max >= 30:
            hot = 1
        elif max >= 25:
            summer = 1
        elif max < 0:
            ice = 1
        elif min < 0:
            frost = 1
        
        hantei = [extremely_hot,hot,summer,ice,frost]   #簡単に判定するようにリストに格納する

        if year in dic:
            dic_list = list(dic[year])      # タプルが変更できないため、dic[year] からリストとして，猛暑日，真夏日，夏日，真冬日，冬日，日数を取り出す．
            for i in range(5):
                dic_list[i] += hantei[i]    # 判定とところで得られた extermely_hot, hot, summer, ice, frost をそれぞれに加算する．
            dic_list[5] += 1                # 日数は1増やす．
            dic[year] = tuple(dic_list)     # dic[year] にタプルとして，猛暑日，真夏日，夏日，真冬日，冬日，日数を格納する．
            
        else:
            dic[year] = (extremely_hot, hot, summer, ice, frost, 1) # dic[year] にタプルとして，猛暑日，真夏日，夏日，真冬日，冬日，日数を格納する．

for year in sorted(years): # 年を昇順にソートして繰り返す．
    (extremely_hot, hot, summer, ice, frost, days) = dic[year]
    print(f"{year}  猛暑日 {extremely_hot:>3}, 真夏日 {hot:>2}, 夏日 {summer:>2}, 真冬日 {ice:>2}, 冬日 {frost:>2} ({days:>3}日)")
