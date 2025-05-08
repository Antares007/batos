def inject_func_sections(default_ld_path, output_ld_path, func_count=10, max_func_size=256):
    with open(default_ld_path) as f:
        lines = f.readlines()

    new_lines = []
    inserted = False

    for line in lines:
        new_lines.append(line)
        if not inserted and "*(SORT(.text.sorted.*))" in line:
            new_lines.append("  /* === BEGIN CUSTOM FUNCTIONS === */\n")
            for book in sys.argv[5:]:
                new_lines.append("  chapter_index = .;\n")
                for i in range(func_count):
                    new_lines.append(f"  KEEP(*(.{book}{i}))\n")
                    new_lines.append(f"  . = chapter_index + {max_func_size * (i + 1)};\n")
            new_lines.append("  /* === END CUSTOM FUNCTIONS === */\n")
            inserted = True

    with open(output_ld_path, "w") as f:
        f.writelines(new_lines)

    print(f"[+] Patched linker script saved to {output_ld_path}")
import sys
if __name__ == "__main__":
    inject_func_sections(sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4]))
