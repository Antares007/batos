import re
import sys
from pathlib import Path

def extract_max_chapter_counts() -> list[tuple[str, int]]:
    """
    Scans all .c files in the current directory and extracts the highest Chapter(x) value (plus 1)
    from each file. Returns a list of tuples: (base filename without extension, max_chapter_count).
    """
    results = []
    for path in Path(".").glob("*.c"):
        content = path.read_text()
        matches = re.findall(r'C\((\d+)\)', content)
        chapter_numbers = [int(num) for num in matches]
        if chapter_numbers:
            max_chapter = max(chapter_numbers) + 1  # +1 to include the max chapter itself
            book_name = path.stem  # Use stem (filename without extension) for section names
            results.append((book_name, max_chapter))
    return sorted(results)

def inject_func_sections(default_ld_path: str, output_ld_path: str,
                         max_func_size: int = 256,
                         chapter_layout: list[tuple[str, int]] = []):
    """
    Modifies a linker script to inject custom function sections based on chapter layout.
    """
    with open(default_ld_path) as f:
        lines = f.readlines()

    new_lines = []
    inserted = False

    for line in lines:
        new_lines.append(line)
        if not inserted and "*(SORT(.text.sorted.*))" in line:
            new_lines.append("  /* === BEGIN Chapters === */\n")
            for book, chapter_count in chapter_layout:
                new_lines.append(f"  chapters_index_base = .;\n")
                for i in range(chapter_count):
                    new_lines.append(f"  KEEP(*(.{book}.c{i}))\n")
                    new_lines.append(f"  . = chapters_index_base + {max_func_size * (i + 1)};\n")
            new_lines.append("  /* === END Chapters === */\n")
            inserted = True
    if not inserted:
        sys.exit(1)

    with open(output_ld_path, "w") as f:
        f.writelines(new_lines)

    print(f"[+] Patched linker script saved to {output_ld_path}")

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print(f"Usage: {sys.argv[0]} <input.ld> <output.ld> <max_func_size>")
        sys.exit(1)

    input_ld = sys.argv[1]
    output_ld = sys.argv[2]
    max_func_size = int(sys.argv[3])

    chapter_layout = extract_max_chapter_counts()
    print(chapter_layout)
    inject_func_sections(input_ld, output_ld, max_func_size, chapter_layout)
