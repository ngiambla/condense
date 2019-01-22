


def main():
	with open("stop.txt", "r") as f:
		for line in f:
			line = line[:-1]
			print("{\"" + line + "\",\"\"},")
			print("{\"" + line + "\",\"\"},")

	with open("temp.txt", "r") as f:
		for line in f:
			line = line[:-1]
			pair = line.split("\t",1)
			print("{\"" + pair[0] + "\",\"" +pair[1]+"\"},")
			print("{\"" + pair[0].lower() + "\",\"" +pair[1]+"\"},")


if __name__ == '__main__':
	main()