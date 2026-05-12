# あいこの場合
( echo 1; echo 1 ) | python3 janken01.py
( echo 2; echo 2 ) | python3 janken01.py
( echo 3; echo 3 ) | python3 janken01.py
# 勝ちの場合
( echo 1; echo 2 ) | python3 janken01.py
( echo 2; echo 3 ) | python3 janken01.py
( echo 3; echo 1 ) | python3 janken01.py
# 負けの場合
( echo 1; echo 3 ) | python3 janken01.py
( echo 2; echo 1 ) | python3 janken01.py
( echo 3; echo 2 ) | python3 janken01.py
