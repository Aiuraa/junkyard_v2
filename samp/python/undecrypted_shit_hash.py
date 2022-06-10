import random, string

def random_word(length):
   letters = string.ascii_lowercase
   return ''.join(random.choice(letters) for i in range(length))

def udb_hash(buf: str) -> int:
    str_len: int = len(buf)
    s1: int = 1
    s2: int = 0
    n: int = 0

    #print(f'length = {str_len}')

    while n < str_len:
        #print(f'n = {n}')
        s1 = (s1 + ord(buf[n])) % 65521
        #print(f's1 = {s1}')

        s2 = (s2 + s1) % 65521
        #print(f's2 = {s2}')
        
        n+=1
    
    ret = (s2 << 16) + s1
    return ret

# Maps
# 1 = 1 (Found)
# 2 = 3 (Not Found)
# 3 = 3 (Found)
# 4 = 3 (Not Found)
# 5 = 6 (Not Found)
# 6 = 6 (Found)
# 7 = 6 (Not Found)
# 8 = 6 (Not Found)
# 9 = 6 (Not Found)
# 10 = 6 (Not Found)
# 11 = 6 (Not Found)
# 12 = 6 (Not Found)
# 13 = 6 (Not Found)
# 14 = 6 (Not Found)
# 15 = 6 (Not Found)
# 16 = 18 (Not Found)
# 17 = 18 (Not Found)
# 18 = 18 (Found)

def find_collision(hash: int, len: int) -> str:
    guessed_length: int = 1
    any_hash = -1

    print(f'Hash = {hash}')

    while any_hash != hash:
        rand_str: str = random_word(len)
        any_hash: int = udb_hash(rand_str)  

    return rand_str

if __name__ == '__main__':
    hash = udb_hash('xd123')
    collisionText = find_collision(hash, 5)
    print(f'Orig: xd123 | Hash: {hash} | Collision Text: {collisionText} | Collision Hash: {udb_hash(collisionText)}')
   
