


def main():
	with open("c_stopwords", "r") as f:
		for line in f:
			line = line[:-1]
			print("{\"" + line + "\",\"\"},")

	# with open("c_abbreviations", "r") as f:
	# 	for line in f:
	# 		line = line[:-1]
	# 		pair = line.split("\t",1)
	# 		print("{\"" + pair[0] + "\",\"" +pair[1]+"\"},")
	# 		print("{\"" + pair[0].lower() + "\",\"" +pair[1]+"\"},")


if __name__ == '__main__':
	main()