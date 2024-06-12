file = open("kvadrat.svg", "r").read().strip()
file = file[file.find("<path"):file.find("/>")]
file = file[file.find('"')+1:]
file = file[file.find('="')+2:file.find('z')]
file = file.strip()
coordstr=""
for i in file:
	if i == "-":
		coordstr+=",-"
	elif i!=" ":
		coordstr+=i
	


temp = ""
sez = []
for i in  coordstr:

	if i.isalpha() == True:
		sez.append(temp)
		temp = i
	else:
		temp += i
sez.append(temp)
sez.remove("")

finalcoords = []

for j in sez:
	if j[0] == "M":
		j = j[1:]
		finalcoords.append([j.split(",")[0], j.split(",")[1]])
	if j[0] == "L":
		j = j[1:]
		finalcoords.append([j.split(",")[0], j.split(",")[1]])
	if j[0] == "H":
		j = j[1:]
		finalcoords.append([float(finalcoords[len(finalcoords)-1][0]), float(finalcoords[len(finalcoords)-1][1])+float(j)])
	if j[0] == "V":
		j = j[1:]
		finalcoords.append([float(finalcoords[len(finalcoords)-1][0])+float(j), float(finalcoords[len(finalcoords)-1][1])])
	if j[0] == "C":
		j = j[1:]
		finalcoords.append([j.split(",")[0], j.split(",")[1]])
		finalcoords.append([j.split(",")[4], j.split(",")[5]])
		finalcoords.append([j.split(",")[2], j.split(",")[3]])
	if j[0] == "m":
		j = j[1:]
		finalcoords.append([float(finalcoords[len(finalcoords)-1][0])+float(j.split(",")[0]), float(finalcoords[len(finalcoords)-1][1])+float(j.split(",")[1])])
	if j[0] == "l":
		j = j[1:]
		finalcoords.append([float(finalcoords[len(finalcoords)-1][0])+float(j.split(",")[0]), float(finalcoords[len(finalcoords)-1][1])+float(j.split(",")[1])])
	if j[0] == "h":
		j = j[1:]
		finalcoords.append([float(finalcoords[len(finalcoords)-1][0]), float(finalcoords[len(finalcoords)-1][1])+float(j)])
	if j[0] == "v":
		j = j[1:]
		finalcoords.append([float(finalcoords[len(finalcoords)-1][0])+float(j), float(finalcoords[len(finalcoords)-1][1])])
	if j[0] == "c":
		j = j[1:]
		finalcoords.append([j.split(",")[0], j.split(",")[1]])
		finalcoords.append([j.split(",")[4], j.split(",")[5]])
		finalcoords.append([j.split(",")[2], j.split(",")[3]])

print(finalcoords)




