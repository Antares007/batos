import re
import sys
from pathlib import Path

def extract_indices() -> list[tuple[str, list[int]]]:
    results = []
    for path in Path(".").glob("*.c"):
        lines = path.read_text().splitlines(keepends=True)
        indices = [i + 1 for i, line in enumerate(lines) if line.startswith("Chapter ")]
        if len(indices):
            book_name = path.stem
            results.append((book_name, indices))
    return results

def inject_func_sections(default_ld_path: str, output_ld_path: str,
                         max_func_size: int = 256,
                         chapter_layout: list[tuple[str, list[int]]] = []):
    """
    Modifies a linker script to inject custom function sections based on chapter layout.
    """

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
