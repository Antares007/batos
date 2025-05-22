import re
import sys

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print(f"Usage: {sys.argv[0]} <input.ld> <output.ld> [1 ... book.ld.fragmens]")
        sys.exit(1)

    input_ld = sys.argv[1]
    output_ld = sys.argv[2]
    file_list = sys.argv[3:]

    combined_content = ""
    for file_name in file_list:
        with open(file_name, "r", encoding="utf-8") as f:
            combined_content += f.read()

    with open(input_ld) as f:
        lines = f.readlines()

    new_lines = []
    inserted = False
    for line in lines:
        new_lines.append(line)
        if not inserted and "*(SORT(.text.sorted.*))" in line:
            new_lines.append("  /* === BEGIN Chapters === */\n")
            new_lines.append(combined_content)
            new_lines.append("  /* === END Chapters === */\n")
            inserted = True
    if not inserted:
        sys.exit(1)

    with open(output_ld, "w") as f:
        f.writelines(new_lines)
