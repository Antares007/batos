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
    with open(default_ld_path) as f:
        lines = f.readlines()

    new_lines = []
    inserted = False

    for line in lines:
        new_lines.append(line)
        if not inserted and "*(SORT(.text.sorted.*))" in line:
            new_lines.append("  /* === BEGIN Chapters === */\n")
            for book, indices in chapter_layout:
                new_lines.append(f"  chapters_index_base = .;\n")
                for i, __LINE__ in enumerate(indices):
                    new_lines.append(f"  KEEP(*(.{book}.c{__LINE__}))\n")
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

    chapter_layout = extract_indices()
    print(chapter_layout)
    inject_func_sections(input_ld, output_ld, max_func_size, chapter_layout)
