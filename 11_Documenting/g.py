import roman

f = open("1.txt", "w")
for i in range(0,101):
    f.write("else if (strcmp(number, \"" + roman.toRoman(i) + "\")) {\n")
    f.write("    return " + str(i) + ";\n")
    f.write("}\n")
f.close()

f = open("2.txt", "w")
f.write("char number[100] = {\n")
for i in range(0,101):
    f.write("    \"" + roman.toRoman(i) + "\",\n")
f.write("}\n")
f.close()