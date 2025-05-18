import sys
import re
if __name__ == "__main__":
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <input.c> <output.ldfragment>")
        sys.exit(1)
    input_c = sys.argv[1]
    output_ldfragment = sys.argv[2]
    with open(input_c, "r") as file:
        output = []
        content = file.read()
        lines = content.splitlines(keepends=True)
        indices = [i + 1 for i, line in enumerate(lines) if line.startswith("Chapter ")]
        if len(indices):
            match = re.search(r'#define\s+ChapterSize\s+(\d+)', content)
            chapterSize = int(match.group(1))
            if match:
                output.append(f"  chapters_index_base = .;\n")
                for i, __LINE__ in enumerate(indices):
                    output.append(f"  KEEP(*(.{input_c}{__LINE__}))\n")
                    output.append(f"  . = chapters_index_base + {chapterSize * (i + 1)};\n")
            else:
                print(f"error: #define ChapterSize (int)n", file=sys.stderr)
                sys.exit(1)
        with open(output_ldfragment, "w") as f:
            f.writelines(output)
