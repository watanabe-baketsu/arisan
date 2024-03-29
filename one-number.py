# 問題
# 1からNまでの整数を書いていく時に、"1"が何回出現するかを返すプログラムを作成せよ。
# 1<=N<=10**20とする。

import re
import sys

("Nを入力してください")
print("N : ")
N = input()
if re.search(N,'[^0-9]') != False:
	print("正の整数を入力してください。")
	sys.exit()

n = len(N) # Nの桁数を求める。
if n == 1:
	ans = 1
	print("Nまでの1の出現数 : {}個".format(ans))
	sys.exit()
cell_dic = {} # 10^(n-1)までの各桁の1の出現数の最大値を辞書化。
for i in range(n):
	# example: 2桁の数の1の最大出現回数
	# 2*10**(2-1)=20　一般化するとしたの式に
	cell_dic[str(i)] = i*10**(i-1)

new = int(N)
ans = 0
for i in N:
	if i == '1':
		ans += new-10**(n-1)+1
		ans += cell_dic[str(n-1)]
		if re.search(str(new)[1:],'[1-9]') == False:
			break
		
	elif i == '0':
		if re.search(str(new),'[1-9]') == False and n != 1:
			ans += n*10**(n-1)
			break

	else:
		ans += 10**(n-1)
		ans += int(i)*cell_dic[str(n-1)]
		if re.search(str(new)[1:],'[1-9]') == False:
			break
		
	new = new-(int(i)*10**(n-1))
	n -= 1
	
print("Nまでの1の出現数 : {}個".format(ans))
