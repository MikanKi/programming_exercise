# 前半は Anagram
echo 1 | python3 anagram.py
echo 1 2 1 | python3 anagram.py
echo 1 2 2 1 | python3 anagram.py
echo 1 2 3 2 1 | python3 anagram.py
echo 1 2 3 4 5 6 7 8 8 7 6 5 4 3 2 1 | python3 anagram.py
# 後半は非 Anagram
echo 1 2 | python3 anagram.py
echo 1 2 3 2 2 | python3 anagram.py
echo 1 2 3 4 2 1 | python3 anagram.py
