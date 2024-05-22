def main() :
	str1, str2 = input(), input()
	f = [[i for i in range(len(str2) + 1)]]
	for i in range(1, len(str1) + 1) :
		f.append([i] + [0] * len(str2)) 
	for i in range(1, len(str1) + 1) :
		for j in range(1, len(str2) + 1) :
			f[i][j] = min(f[i - 1][j - 1] + (1 if str1[i - 1] != str2[j - 1] else 0), f[i - 1][j] + 1, f[i][j - 1] + 1)
	print(f[len(str1)][len(str2)])
if __name__ == "__main__" :
	main()